/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:20:23 by atoof             #+#    #+#             */
/*   Updated: 2024/02/29 11:16:33 by atoof            ###   ########.fr       */
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

    // Step 3: Recursively sort pairs by their larger value
    recursiveSortPairsByLargerValue(pairs, pairs.size());

    std::vector<int> largerElements, smallerElements;
    for (auto &pair : pairs)
    {
        largerElements.push_back(pair[1]); // Larger value of each pair
        smallerElements.push_back(pair[0]); // Smaller value of each pair
    }

    // Insert the smallest element (which is paired with the first element in 'largerElements') at the start
    largerElements.insert(largerElements.begin(), smallerElements.front());
    smallerElements.erase(smallerElements.begin());

	// Step 5: Insert the remaining elements using a special ordering
	// Insertion starts from the second smallest element in 'smallerElements'
	for (std::vector<int>::size_type i = 0; i < smallerElements.size(); ++i)
	{
		// Find the position using binary search in the already sorted 'largerElements'
		auto pos = std::lower_bound(largerElements.begin(), largerElements.end(), smallerElements[i]);
		largerElements.insert(pos, smallerElements[i]);
	}


    // If there's a straggler, insert it into the appropriate position
    if (hasStraggler)
    {
        auto pos = std::lower_bound(largerElements.begin(), largerElements.end(), straggler);
        largerElements.insert(pos, straggler);
    }

    // Update the original vector with the sorted values
    vec = largerElements;
}
