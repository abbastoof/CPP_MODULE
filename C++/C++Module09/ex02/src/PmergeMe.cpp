/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:20:23 by atoof             #+#    #+#             */
/*   Updated: 2024/02/27 18:12:10 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() : hasStraggler(false), straggler(0)
{
}

PmergeMe::PmergeMe(const PmergeMe &rhs) : hasStraggler(false), straggler(0)
{
	*this = rhs;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		hasStraggler = rhs.hasStraggler;
		straggler = rhs.straggler;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::sortVector(std::vector<int> &vec)
{
	fordJohnson(vec);
}

std::vector<std::vector<int>> PmergeMe::createPairs(const std::vector<int> &a)
{
	std::vector<std::vector<int>> splitArray;

	// since our array is even we can just split it in half
	for (size_t i = 0; i < a.size(); i += 2)
	{
		std::vector<int> pair;
		pair.push_back(a[i]);
		pair.push_back(a[i + 1]);
		splitArray.push_back(pair);
	}
	return splitArray;
}

void PmergeMe::sortPairs(std::vector<std::vector<int>> &pairs)
{
	for (std::vector<int> &pair : pairs)
	{
		if (pair.size() == 2 && pair[0] > pair[1])
			std::swap(pair[0], pair[1]);
	}
}

bool PmergeMe::isPairGreaterThan(const std::vector<int> &a, const std::vector<int> &b)
{
	int maxA = *std::max_element(a.begin(), a.end());
	int maxB = *std::max_element(b.begin(), b.end());
	return maxA < maxB;
}

void PmergeMe::sortPairsByLargerValue(std::vector<std::vector<int>> &pairs)
{
	if (pairs.size() <= 1)
		return;

	for (size_t i = 0; i < pairs.size(); i++)
	{
		for (size_t j = i + 1; j < pairs.size(); j++)
		{
			if (pairs[i][1] > pairs[j][1]) // If the larger value of the first pair is greater than the larger value of the second pair
				std::swap(pairs[i], pairs[j]);
		}
	}

	// printf("Sorted pairs by larger value: ");
	// for (auto &pair : pairs)
	// {
	// 	printf("[%d, %d] ", pair[0], pair[1]);
	// }
}

// void PmergeMe::mergePairs(const std::vector<std::vector<int>> &pairs, std::vector<int> &merged)
// {
// 	std::vector<int> elements; // To hold the second elements for merging

// 	// Extract the second elements of each pair for merging
// 	for (const auto &pair : pairs)
// 	{
// 		if (pair.size() > 1)			 // Ensure the pair has a second element
// 			elements.push_back(pair[1]); // Add the second element to the elements vector
// 	}

// 	// Perform a standard merge sort on the extracted elements
// 	mergeSort(elements, 0, elements.size() - 1, merged);
// }

// void PmergeMe::mergeSort(std::vector<int> &elements, int left, int right, std::vector<int> &merged)
// {
// 	if (left >= right)
// 		return; // Base case

// 	int mid = left + (right - left) / 2;
// 	mergeSort(elements, left, mid, merged);		 // Sort the left half
// 	mergeSort(elements, mid + 1, right, merged); // Sort the right half
// 	merge(elements, left, mid, right, merged);	 // Merge the sorted halves
// }

// void PmergeMe::merge(std::vector<int> &elements, int left, int mid, int right, std::vector<int> &merged)
// {
// 	int n1 = mid - left + 1; // Size of the left subarray
// 	int n2 = right - mid;	 // Size of the right subarray

// 	// Create temp arrays
// 	std::vector<int> L(n1), R(n2);

// 	// Copy data to temp arrays
// 	for (int i = 0; i < n1; i++)
// 		L[i] = elements[left + i];
// 	for (int j = 0; j < n2; j++)
// 		R[j] = elements[mid + 1 + j];

// 	// Merge the temp arrays back into elements[left..right]
// 	int i = 0, j = 0, k = left;
// 	while (i < n1 && j < n2)
// 	{
// 		if (L[i] <= R[j])
// 			elements[k] = L[i++];
// 		else
// 			elements[k] = R[j++];
// 		k++;
// 	}

// 	// Copy the remaining elements of L[], if there are any
// 	while (i < n1)
// 		elements[k++] = L[i++];

// 	// Copy the remaining elements of R[], if there are any
// 	while (j < n2)
// 		elements[k++] = R[j++];

// 	merged = elements; // Update merged with the sorted elements
// }

// void PmergeMe::insertElements(std::vector<int> &sorted, const std::vector<std::vector<int>> &pairs)
// {
// 	for (const auto &pair : pairs)
// 	{
// 		for (int element : pair)
// 		{
// 			auto it = std::lower_bound(sorted.begin(), sorted.end(), element);
// 			sorted.insert(it, element);
// 		}
// 	}
// }

int PmergeMe::jacobsthal(int n)
{
	std::vector<int> dp(n + 1); // Create a vector to store the Jacobsthal numbers
								// Base cases for J(0) and J(1) are 0 and 1 respectively
	dp[0] = 0;
	dp[1] = 1;
	// Calculate the Jacobsthal number for each index in the vector using the formula J(n) = J(n-1) + 2*J(n-2)
	for (int i = 2; i <= n; ++i)
		dp[i] = dp[i - 1] + 2 * dp[i - 2];
	return dp[n];
}

std::vector<int> PmergeMe::buildJacobInsertionSequence(int length)
{
	std::vector<int> sequence;
	for (int i = 0; i < length; ++i)
		sequence.push_back(jacobsthal(i));
	return sequence;
}

int PmergeMe::calculateInsertionIndex(const std::vector<int>& largNumber, int pendValue, const std::vector<int>& jacobSequence) {
    // Start searching from the beginning of 'largNumber'
    int index = 0;

    for (size_t i = 0; i < jacobSequence.size() && index < static_cast<int>(largNumber.size()); ++i) {
        // Calculate the next index using the Jacobsthal sequence, ensuring it doesn't exceed the size of 'largNumber'
        int nextIndex = std::min(index + jacobSequence[i], static_cast<int>(largNumber.size()) - 1);

        // If 'pendValue' is less than 'largNumber[nextIndex]', we've found our insertion point
        if (pendValue < largNumber[nextIndex])
            return index; // Insert before 'largNumber[nextIndex]'

        // Otherwise, move to 'nextIndex' for the next iteration, ensuring we advance at least one position
        index = nextIndex + 1;
    }

    // If we reach here, 'pendValue' should be inserted at the end
    return static_cast<int>(largNumber.size());
}

int PmergeMe::binarySearchInsertionIndex(const std::vector<int>& S, int value)
{
    auto it = std::lower_bound(S.begin(), S.end(), value);
    return std::distance(S.begin(), it);
}


void PmergeMe::fordJohnson(std::vector<int> &vec)
{
	if (vec.size() % 2 != 0)
	{
		hasStraggler = true;
		straggler = vec.back();
		vec.pop_back();
	}

	// Create and sort pairs
	std::vector<std::vector<int>> pairs = createPairs(vec);
	sortPairs(pairs);

	// Sort pairs by the larger value in each pair
	sortPairsByLargerValue(pairs);
	// Creating 'largNumber' and 'pend' arrays
	std::vector<int> largNumber, pend;
	for (auto &pair : pairs)
	{
		largNumber.push_back(pair[1]); // Add the larger value of the pair to 'largNumber'
		pend.push_back(pair[0]);	   // Add the smaller value to 'pend'
	}
	// Immediately, since we know the first element in ‘pend’ ( we call it: ‘p1’) is smaller than the first element in the ‘largNumber’ array (‘l1’), we insert it in the ‘0’ index of largNumber.

	largNumber.insert(largNumber.begin(), pend[0]);
	std::vector<int> jacobSequence = buildJacobInsertionSequence(pend.size()); // Create the Jacobsthal insertion sequence

	// // Merge the pairs into a sorted list and insert the remaining elements
	// std::vector<int> merged;
	// mergePairs(pairs, merged);
	// insertElements(merged, pairs);

	// If there was a straggler, insert it into the sorted vector at its correct position
	// 	if (hasStraggler)
	// 	{
	// 		auto it = std::lower_bound(merged.begin(), merged.end(), straggler);
	// 		merged.insert(it, straggler);
	// 	}

	// 	// Replace the original vector with the sorted one
	// 	vec.swap(merged);
}
