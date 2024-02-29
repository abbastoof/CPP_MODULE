/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:20:23 by atoof             #+#    #+#             */
/*   Updated: 2024/02/29 11:03:14 by atoof            ###   ########.fr       */
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
	std::vector<std::vector<int>> pairs;
	for (size_t i = 0; i < a.size(); i += 2)
	{
		std::vector<int> pair = {a[i], a[i + 1]};
		pairs.push_back(pair);
	}
	return pairs;
}

void PmergeMe::sortPairs(std::vector<std::vector<int>> &pairs)
{
	for (std::vector<int> &pair : pairs)
	{
		if (pair[0] > pair[1])
			std::swap(pair[0], pair[1]);
	}
}

// void PmergeMe::sortPairsByLargerValue(std::vector<std::vector<int>> &pairs)
// {
// 	std::sort(pairs.begin(), pairs.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
// 		return a[1] < b[1];
// 	});
// 	printf("sortPairsByLargerValue :\n");
// 	for (auto &pair : pairs)
// 		printf("[%d, %d] ", pair[0], pair[1]);
// 	printf("\n");
// }

void PmergeMe::recursiveSortPairsByLargerValue(std::vector<std::vector<int>> &pairs, int n)
{
	if (n <= 1)
		return;

	int max_idx = 0;
	for (int i = 1; i < n; i++)
	{
		if (pairs[i][1] > pairs[max_idx][1])
			max_idx = i;
	}

	std::swap(pairs[max_idx], pairs[n-1]);

	recursiveSortPairsByLargerValue(pairs, n-1);
}



void PmergeMe::fordJohnson(std::vector<int> &vec)
{
	if (vec.size() < 2)
		return;

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

	// Step 3: Sort pairs by their larger value and create 'largerElements' and 'smallerElements' arrays
	recursiveSortPairsByLargerValue(pairs, pairs.size());

	std::vector<int> largerElements, smallerElements;
	for (auto &pair : pairs)
	{
		largerElements.push_back(pair[1]); // Larger value of each pair
		smallerElements.push_back(pair[0]);	   // Smaller value of each pair
	}

	// Print sorted pairs and initial 'largerElements' and 'smallerElements' arrays
	std::cout << "Sorted pairs by larger value: ";
	for (auto &pair : pairs)
		std::cout << "[" << pair[0] << ", " << pair[1] << "] ";
	std::cout << "\n";

	std::cout << "largerElements: ";
	for (int num : largerElements)
		std::cout << num << " ";
	std::cout << "\nsmallerElements: ";
	for (int num : smallerElements)
		std::cout << num << " ";
	std::cout << "\n";

	// Step 4: Insert 'smallerElements' into 'largerElements' in sorted order
	for (int value : smallerElements)
	{
		auto it = std::lower_bound(largerElements.begin(), largerElements.end(), value);
		largerElements.insert(it, value);

		// Print 'largerElements' after each insertion
		std::cout << "After inserting " << value << " into largerElements: ";
		for (int num : largerElements)
			std::cout << num << " ";
		std::cout << "\n";
	}

	// Step 5: Insert the straggler into 'largerElements' if necessary
	if (hasStraggler)
	{
		auto it = std::lower_bound(largerElements.begin(), largerElements.end(), straggler);
		largerElements.insert(it, straggler);

		// Print 'largerElements' after inserting the straggler
		std::cout << "After inserting straggler " << straggler << " into largerElements: ";
		for (int num : largerElements)
			std::cout << num << " ";
		std::cout << "\n";
	}

	// Update the original vector with the sorted values
	vec = largerElements;
}
