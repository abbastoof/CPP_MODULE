/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:20:23 by atoof             #+#    #+#             */
/*   Updated: 2024/02/26 19:58:49 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &rhs)
{
	*this = rhs;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
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

	for (size_t i = 0; i < a.size(); i += 2)
	{
		std::vector<int> pair;
		pair.push_back(a[i]);
		// Check if there's a next element to form a complete pair
		if (i + 1 < a.size())
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

void PmergeMe::mergePairs(const std::vector<std::vector<int>>& pairs, std::vector<int>& merged) {
    std::vector<int> elements; // To hold the second elements for merging

    // Extract the second elements of each pair for merging
    for (const auto& pair : pairs)
	 {
        if (pair.size() > 1)// Ensure the pair has a second element
            elements.push_back(pair[1]); // Add the second element to the elements vector
    }

    // Perform a standard merge sort on the extracted elements
    mergeSort(elements, 0, elements.size() - 1, merged);
}

void PmergeMe::mergeSort(std::vector<int>& elements, int left, int right, std::vector<int>& merged) {
    if (left >= right) return; // Base case

    int mid = left + (right - left) / 2;
    mergeSort(elements, left, mid, merged); // Sort the left half
    mergeSort(elements, mid + 1, right, merged); // Sort the right half
    merge(elements, left, mid, right, merged); // Merge the sorted halves
}

void PmergeMe::merge(std::vector<int>& elements, int left, int mid, int right, std::vector<int>& merged)
{
    int n1 = mid - left + 1; // Size of the left subarray
    int n2 = right - mid; // Size of the right subarray

    // Create temp arrays
    std::vector<int> L(n1), R(n2);

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++) L[i] = elements[left + i];
    for (int j = 0; j < n2; j++) R[j] = elements[mid + 1 + j];

    // Merge the temp arrays back into elements[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
	{
        if (L[i] <= R[j])
            elements[k] = L[i++];
        else
            elements[k] = R[j++];
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1)
        elements[k++] = L[i++];

    // Copy the remaining elements of R[], if there are any
    while (j < n2)
        elements[k++] = R[j++];

    merged = elements; // Update merged with the sorted elements
}

void PmergeMe::insertElements(std::vector<int> &sorted, const std::vector<std::vector<int>> &pairs) {
    for (const auto &pair : pairs)
	{
        if (pair.size() > 1)
		{
            int elementToInsert = pair[0]; // Get the first element of the pair because second element is already in the sorted list.
            auto it = std::lower_bound(sorted.begin(), sorted.end(), elementToInsert);
            sorted.insert(it, elementToInsert);  // Insert element at the correct position.
        }
    }
}

void PmergeMe::fordJohnson(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return;

	std::vector<std::vector<int>> pairs = createPairs(vec);
	sortPairs(pairs);

	std::vector<int> merged;
	mergePairs(pairs, merged); // Merge the pairs into a sorted list.

	insertElements(merged, pairs); // Insert the remaining elements into the sorted list.

	vec.swap(merged); // Replace the original vector with the sorted one.
}