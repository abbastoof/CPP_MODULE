/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:08:42 by atoof             #+#    #+#             */
/*   Updated: 2024/03/04 21:05:53 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

/*
	My references for this project:
	https://en.wikipedia.org/wiki/Merge-insertion_sort
	http://www.progdoc.de/papers/ttp/psi-ttp/psi-ttp.html
	Especially "C templates complete guide 2nd-edition by David Vandevoorde, Nicolai M. Josuttis and Douglas Gregor" helped
	me a lot to understand templates better
*/

template <typename T, template <typename...> typename Container>
PmergeMe<T, Container>::PmergeMe() : hasStraggler(false), straggler(T()) {}

template <typename T, template <typename...> typename Container>
PmergeMe<T, Container>::PmergeMe(const PmergeMe &rhs) : hasStraggler(rhs.hasStraggler), straggler(rhs.straggler) {}

template <typename T, template <typename...> typename Container>
PmergeMe<T, Container> &PmergeMe<T, Container>::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		hasStraggler = rhs.hasStraggler;
		straggler = rhs.straggler;
	}
	return *this;
}

template <typename T, template <typename...> typename Container>
PmergeMe<T, Container>::~PmergeMe() {}

#include <iostream>
#include <chrono>
#include <vector>
#include <deque>
#include <typeinfo>
#include <type_traits>

template <typename T, template <typename...> typename Container>
void PmergeMe<T, Container>::sortContainer(Container<T>& cont)
{
    // Display the unsorted sequence
    std::cout << "Before: ";
    for (const auto& item : cont) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    // Start the timer
    auto start = std::chrono::high_resolution_clock::now();

    // Sort the container (replace this with your sorting algorithm)
    std::sort(cont.begin(), cont.end());

    // Stop the timer
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    // Display the sorted sequence
    std::cout << "After: ";
    for (const auto& item : cont) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    // Display the time taken for sorting
    std::string containerType = (std::is_same<Container<T>, std::vector<T>>::value) ? "std::vector" : "std::deque";
    std::cout << "Time to process a range of " << cont.size() << " elements with " << containerType << " : " << duration.count() << " us" << std::endl;
}



template <typename T, template <typename...> typename Container>
Container<Container<T>> PmergeMe<T, Container>::createPairs(const Container<T> &a)
{
	Container<Container<T>> pairs;

	for (size_t i = 0; i < a.size(); i += 2)
	{
		Container<T> pair = {a[i], a[i + 1]};
		pairs.push_back(pair);
	}

	return pairs;
}

template <typename T, template <typename...> typename Container>
void PmergeMe<T, Container>::sortPairs(Container<Container<T>> &pairs)
{
	for (Container<T> &pair : pairs)
	{
		if (pair.size() >= 2 && pair[0] > pair[1])
			std::swap(pair[0], pair[1]);
	}
}

template <typename T, template <typename...> typename Container>
void PmergeMe<T, Container>::recursiveSortPairsByLargerValue(Container<Container<T>> &pairs, int n, int start)
{
	if (n <= 1)
		return; // If there is only one or no pair, there's nothing to sort.

	int mid = n / 2; // Find the middle index to divide the pairs into two halves.

	recursiveSortPairsByLargerValue(pairs, mid, start);
	recursiveSortPairsByLargerValue(pairs, n - mid, start + mid);

	Container<Container<T>> temp;

	// Initialize pointers for the two halves.
	int left = start, right = start + mid, end = start + n;

	while (left < start + mid && right < end)
	{
		if (pairs[left][1] <= pairs[right][1])
		{
			temp.push_back(pairs[left]);
			left++; // Move to the next pair in the left half.
		}
		else
		{
			// Otherwise, the pair in the right half has a smaller value, add it to 'temp'.
			temp.push_back(pairs[right]);
			right++;
		}
	}

	// If there are any remaining pairs in the left half, add them to 'temp'.
	while (left < start + mid)
	{
		temp.push_back(pairs[left]);
		left++;
	}

	// If there are any remaining pairs in the right half, add them to 'temp'.
	while (right < end)
	{
		temp.push_back(pairs[right]);
		right++;
	}

	// Copy the merged pairs from 'temp' back into the original 'pairs' container.
	for (size_t i = 0; i < temp.size(); ++i)
		pairs[start + i] = temp[i];
}

template <typename T, template <typename...> typename Container>
void PmergeMe<T, Container>::printFunc(Container<Container<T>> pairs, int step)
{
    if (step == 1 || step == 2 || step == 3)
    {
        if (step == 1)
            std::cout << Colors::MAGENTA << "step 1: create pairs of numbers:" << Colors::RESET << std::endl;
        else if (step == 2)
            std::cout << Colors::MAGENTA << "step 2: sort pairs:" << Colors::RESET << std::endl;
        else if (step == 3)
            std::cout << Colors::MAGENTA << "step 3: Recursive sort pairs by larger value:" << Colors::RESET << std::endl;

        for (const Container<T> &pair : pairs)
            std::cout << "(" << pair[0] << ", " << pair[1] << ") ";
        std::cout << std::endl;
    }
    else if (step == 4)
    {
        std::cout << Colors::MAGENTA << "step 4: Extracting largers and smallers elements:" << Colors::RESET << std::endl;
        std::cout << "Larg elements: ";
        for (const Container<T> &pair : pairs)
            std::cout << pair[1] << " ";
        std::cout << std::endl;

        std::cout << "Small elements: ";
        for (const Container<T> &pair : pairs)
            std::cout << pair[0] << ", ";
        std::cout << std::endl;
    }
}

template <typename T, template <typename...> typename Container>
void PmergeMe<T, Container>::fordJohnson(Container<T> &container)
{
	int printProcess = false;

	if (container.size() < 2)
		return;

	if (container.size() % 2 != 0)
	{
		hasStraggler = true;
		straggler = container.back();
		container.pop_back();
	}

	Container<Container<T>> pairs = createPairs(container);
	if (printProcess)
		printFunc(pairs, 1);
	sortPairs(pairs);
	if (printProcess)
		printFunc(pairs, 2);
	recursiveSortPairsByLargerValue(pairs, pairs.size(), 0);
	if (printProcess)
		printFunc(pairs, 3);
	Container<T> largerElements, smallerElements;
	for (Container<T> &pair : pairs)
	{
		largerElements.push_back(pair[1]);
		smallerElements.push_back(pair[0]);
	}
	if (printProcess)
		printFunc(pairs, 4);

	largerElements.insert(largerElements.begin(), smallerElements.front());
	smallerElements.erase(smallerElements.begin());

	for (size_t i = 0; i < smallerElements.size(); ++i)
	{
		typename Container<T>::iterator pos = std::lower_bound(largerElements.begin(), largerElements.end(), smallerElements[i]); //why typename? https://stackoverflow.com/questions/610245/where-and-why-do-i-have-to-put-the-template-and-typename-keywords
		largerElements.insert(pos, smallerElements[i]);
	}

	if (hasStraggler)
	{
		typename Container<T>::iterator pos = std::lower_bound(largerElements.begin(), largerElements.end(), straggler);
		largerElements.insert(pos, straggler);
		hasStraggler = false;
	}

	container = largerElements;
}

template class PmergeMe<int, std::vector>;
template class PmergeMe<int, std::deque>;
