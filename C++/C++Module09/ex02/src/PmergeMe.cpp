/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:08:42 by atoof             #+#    #+#             */
/*   Updated: 2024/03/01 13:29:08 by atoof            ###   ########.fr       */
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

template <typename T, template <typename...> typename Container>
void PmergeMe<T, Container>::sortContainer(Container<T> &cont)
{
	// Start the timer
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	fordJohnson(cont);
	// Stop the timer
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	// Calculate the duration
	std::chrono::duration<double, std::micro> duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	// Check the type of the container and print the appropriate message
	if (typeid(Container<T>) == typeid(std::vector<T>))
		std::cout << Colors::BRIGHT_BLUE << "This is numbers sorted in vector:" << Colors::RESET << std::endl;
	else if (typeid(Container<T>) == typeid(std::deque<T>))
		std::cout << Colors::BRIGHT_BLUE << "This is numbers sorted in deque:" << Colors::RESET << std::endl;
	for (int num : cont)
		std::cout << num << " ";
	std::cout << std::endl;
	std::cout << "Time taken by FordJohnson: " << Colors::GREEN << duration.count() << Colors::RESET << " microseconds" << std::endl;
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
void PmergeMe<T, Container>::recursiveSortPairsByLargerValue(Container<Container<T>> &pairs, int n)
{
	if (n <= 1)
		return;

	int mid = n / 2;

	// Temporarily store the left and right halves
	Container<Container<T>> left_side(pairs.begin(), pairs.begin() + mid);
	Container<Container<T>> right_side(pairs.begin() + mid, pairs.end());

	/**************************************** Recursively sort the left and right halves ****************************************/
	recursiveSortPairsByLargerValue(left_side, left_side.size());
	recursiveSortPairsByLargerValue(right_side, right_side.size());

	/************************************** Merge the sorted halves back into the original container **************************************/
	typename Container<Container<T>>::iterator leftIt = left_side.begin();
	typename Container<Container<T>>::iterator rightIt = right_side.begin();
	typename Container<Container<T>>::iterator mergeIt = pairs.begin();

	while (leftIt != left_side.end() && rightIt != right_side.end())
	{
		if ((*leftIt)[1] <= (*rightIt)[1])
		{
			*mergeIt = *leftIt;
			++leftIt;
		}
		else
		{
			*mergeIt = *rightIt;
			++rightIt;
		}
		++mergeIt;
	}

	/****************************** Copy any remaining elements from the left or right halves ******************************/
	while (leftIt != left_side.end())
	{
		*mergeIt = *leftIt;
		++leftIt;
		++mergeIt;
	}

	while (rightIt != right_side.end())
	{
		*mergeIt = *rightIt;
		++rightIt;
		++mergeIt;
	}
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
		for (const auto &pair : pairs)
			std::cout << "(" << pair[0] << ", " << pair[1] << ") ";
		std::cout << std::endl;
	}
	else if (step == 4)
	{
		std::cout << Colors::MAGENTA << "step 4: Extracting largers and smallers elements:" << Colors::RESET << std::endl;
		std::cout << "Larg elements: ";
		for (const auto &pair : pairs)
			std::cout << pair[1] << " ";
		std::cout << std::endl;
		std::cout << "Small elements: ";
		for (const auto &pair : pairs)
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
	recursiveSortPairsByLargerValue(pairs, pairs.size());
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
		typename Container<T>::iterator pos = std::lower_bound(largerElements.begin(), largerElements.end(), smallerElements[i]);
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
