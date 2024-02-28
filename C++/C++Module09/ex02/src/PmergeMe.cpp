/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:20:23 by atoof             #+#    #+#             */
/*   Updated: 2024/02/28 15:20:12 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() : hasStraggler(false), straggler(0) {}

PmergeMe::PmergeMe(const PmergeMe &rhs) : hasStraggler(rhs.hasStraggler), straggler(rhs.straggler) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		hasStraggler = rhs.hasStraggler;
		straggler = rhs.straggler;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sortVector(std::vector<int> &vec)
{
	fordJohnson(vec);
}

std::vector<std::vector<int>> PmergeMe::createPairs(const std::vector<int> &a)
{
	std::vector<std::vector<int>> splitArray;
	for (size_t i = 0; i < a.size(); i += 2)
	{
		std::vector<int> pair = {a[i], i + 1 < a.size() ? a[i + 1] : a[i]}; // Handle odd case by duplicating the last element if necessary
		splitArray.push_back(pair);
	}
	return splitArray;
}

void PmergeMe::sortPairs(std::vector<std::vector<int>> &pairs)
{
	for (std::vector<int> &pair : pairs)
	{
		if (pair[0] > pair[1])
			std::swap(pair[0], pair[1]);
	}
}

void PmergeMe::sortPairsByLargerValue(std::vector<std::vector<int>> &pairs)
{
	std::sort(pairs.begin(), pairs.end(), [](const std::vector<int> &a, const std::vector<int> &b)
			  {
				  return a[1] < b[1]; // Sort by the second element of each pair
			  });
	printf("sortPairsByLargerValue :\n");
	for (auto &pair : pairs)
		printf("[%d, %d] ", pair[0], pair[1]);
	printf("\n");
}

void PmergeMe::fordJohnson(std::vector<int> &vec)
{
	if (vec.empty())
        return; // Nothing to sort

	// Step 1: Handle an odd-sized array
	if (vec.size() % 2 != 0)
	{
		hasStraggler = true;
		straggler = vec.back();
		vec.pop_back();
	}

	// Step 2: Create and sort pairs
	std::vector<std::vector<int>> pairs = createPairs(vec);
	sortPairs(pairs);

	// Step 3: Sort pairs by their larger value and create 'largNumber' and 'pend' arrays
	sortPairsByLargerValue(pairs);
	std::vector<int> largNumber, pend;
	for (auto &pair : pairs)
	{
		largNumber.push_back(pair[1]); // Larger value of each pair
		pend.push_back(pair[0]);	   // Smaller value of each pair
	}

	// Print sorted pairs and initial 'largNumber' and 'pend' arrays
	std::cout << "Sorted pairs by larger value: ";
	for (auto &pair : pairs)
		std::cout << "[" << pair[0] << ", " << pair[1] << "] ";
	std::cout << "\n";

	std::cout << "largNumber: ";
	for (int num : largNumber)
		std::cout << num << " ";
	std::cout << "\npend: ";
	for (int num : pend)
		std::cout << num << " ";
	std::cout << "\n";

	// Step 4: Insert 'pend' into 'largNumber' in sorted order
	for (int value : pend)
	{
		auto it = std::lower_bound(largNumber.begin(), largNumber.end(), value);
		largNumber.insert(it, value);

		// Print 'largNumber' after each insertion
		std::cout << "After inserting " << value << " into largNumber: ";
		for (int num : largNumber)
			std::cout << num << " ";
		std::cout << "\n";
	}

	// Step 5: Insert the straggler into 'largNumber' if necessary
	if (hasStraggler)
	{
		auto it = std::lower_bound(largNumber.begin(), largNumber.end(), straggler);
		largNumber.insert(it, straggler);

		// Print 'largNumber' after inserting the straggler
		std::cout << "After inserting straggler " << straggler << " into largNumber: ";
		for (int num : largNumber)
			std::cout << num << " ";
		std::cout << "\n";
	}

	// Update the original vector with the sorted values
	vec = largNumber;
}
