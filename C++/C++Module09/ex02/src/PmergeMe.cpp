/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:08:42 by atoof             #+#    #+#             */
/*   Updated: 2024/03/11 14:37:03 by atoof            ###   ########.fr       */
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
double PmergeMe<T, Container>::sortContainer(Container<T> &cont)
{
	// Start the timer
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    fordJohnson(cont);
    // Stop the timer
    std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();

    // Calculate and return the duration in microseconds
    std::chrono::duration<double> difference = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    return difference.count();
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
void PmergeMe<T, Container>::debugPrint(const Container<T> &cont, const std::string &message) const
{
	std::cout << message << ": ";
	std::copy(cont.begin(), cont.end(), std::ostream_iterator<T>(std::cout, " "));
	std::cout << std::endl;
}

template <typename T, template <typename...> typename Container>
void PmergeMe<T, Container>::debugPrintPairs(const Container<Container<T>> &pairs, const std::string &message) const
{
	std::cout << message << ":\n";
	for (const Container<T> &pair : pairs)
	{
		std::cout << "(";
		std::copy(pair.begin(), pair.end(), std::ostream_iterator<T>(std::cout, " "));
		std::cout << ") ";
	}
	std::cout << std::endl;
}

// template <typename T, template <typename...> typename Container>
// void PmergeMe<T, Container>::printFunc(Container<Container<T>> pairs, int step)
// {
// 	if (step == 1 || step == 2 || step == 3)
// 	{
// 		if (step == 1)
// 			std::cout << Colors::MAGENTA << "step 1: create pairs of numbers:" << Colors::RESET << std::endl;
// 		else if (step == 2)
// 			std::cout << Colors::MAGENTA << "step 2: sort pairs:" << Colors::RESET << std::endl;
// 		else if (step == 3)
// 			std::cout << Colors::MAGENTA << "step 3: Recursive sort pairs by larger value:" << Colors::RESET << std::endl;

// 		for (const Container<T> &pair : pairs)
// 			std::cout << "(" << pair[0] << ", " << pair[1] << ") ";
// 		std::cout << std::endl;
// 	}
// 	else if (step == 4)
// 	{
// 		std::cout << Colors::MAGENTA << "step 4: Extracting largers and smallers elements:" << Colors::RESET << std::endl;
// 		std::cout << "Larg elements: ";
// 		for (const Container<T> &pair : pairs)
// 			std::cout << pair[1] << " ";
// 		std::cout << std::endl;

// 		std::cout << "Small elements: ";
// 		for (const Container<T> &pair : pairs)
// 			std::cout << pair[0] << ", ";
// 		std::cout << std::endl;
// 	}
// }

template <typename T, template <typename...> typename Container>
std::vector<int> PmergeMe<T, Container>::generatePowerSequence(int length)
{
	std::vector<int> sequence;
	sequence.push_back(2);
	while (std::accumulate(sequence.begin(), sequence.end(), 0) <= length)
	{
		int term = pow(2, sequence.size() + 1) - sequence.back();
		sequence.push_back(term);
	}
	return sequence;
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
std::vector<Container<T>> PmergeMe<T, Container>::partition(const Container<T> &elements, const std::vector<int> &groupSizes)
{
	std::vector<Container<T>> partitions;
	size_t start = 0;
	bool shouldPrint = false;
	int indexOffset = 3; // Starting index for printing, i.e., y3

	for (int size : groupSizes) // Iterate over the group sizes in the sequence
	{
		size_t end = start + size; // Calculate the end index for the current group
		if (end > elements.size())
			end = elements.size(); // Ensure the end index does not exceed the container's size

		// Create a partition from the current group
		Container<T> partition(elements.begin() + start, elements.begin() + end);

		// Reverse the partition
		std::reverse(partition.begin(), partition.end());

		// Print indices after partition reversal
		if (shouldPrint)
		{
			std::cout << "Indices after partition reversal: ";
			for (int i = end - 1; i >= static_cast<int>(start); --i)
				std::cout << "y" << indexOffset + i << " ";
			std::cout << std::endl;
		}

		partitions.push_back(partition);
		start = end;				  // Update the start index for the next partition
		if (start >= elements.size()) // If all elements have been partitioned, stop
			break;
	}
	return partitions;
}


template <typename T, template <typename...> typename Container>
void PmergeMe<T, Container>::fordJohnson(Container<T> &container)
{
	if (container.size() <= 1)
		return; // Base case: already sorted or only one element.

	// Handle the straggler element for odd-sized containers.
	bool hasStraggler = container.size() % 2 != 0;
	T stragglerElement;
	if (hasStraggler)
	{
		stragglerElement = container.back();
		container.pop_back(); // Temporarily remove the straggler.
	}

	// Create and sort pairs.
	Container<Container<T>> pairs = createPairs(container);
	sortPairs(pairs);

	// fordJohnson(largerElements);

	recursiveSortPairsByLargerValue(pairs, pairs.size());
	Container<T> largerElements, smallerElements;
	for (Container<T> &pair : pairs)
	{
		largerElements.push_back(pair[1]);	// Assuming the second element is larger.
		smallerElements.push_back(pair[0]); // Assuming the first element is smaller.
	}

	// debugPrint(largerElements, "Larger elements after recursive sort");
	// debugPrint(smallerElements, "Smaller elements after recursive sort");
	// Merge smaller elements into the sorted list of larger elements.
	// The first smaller element is merged directly before handling the rest.
	if (!smallerElements.empty())
	{
		largerElements.insert(largerElements.begin(), smallerElements.front());
		smallerElements.erase(smallerElements.begin());
	}
	// Generate the power sequence for the remaining smaller elements.
	std::vector<int> powerSequence = generatePowerSequence(smallerElements.size()); // We split the smaller elements into groups of sizes that are powers of 2
	std::vector<Container<T>> partitions = partition(smallerElements, powerSequence);

	// Merge the smaller elements into the sorted list of larger elements.
	size_t index = 0;
	size_t insertedElements = 1;
	for (const Container<T> &partition : partitions)
	{
		size_t partitionSize = partition.size();
		index += partitionSize;
		for (typename Container<T>::const_iterator it = partition.begin(); it != partition.end(); ++it)
		{
			// std::cout << "Index: " << index << std::endl;
			// std::cout << "smaller[it]: " << *it << std::endl;
			// std::cout << "largerElements.begin() + index + insertedElements =" << *(largerElements.begin() + index + insertedElements - std::distance(partition.begin(), it)) << std::endl;
			typename Container<T>::iterator pos = std::lower_bound(largerElements.begin(), largerElements.begin() + index + insertedElements - std::distance(partition.begin(), it), *it);
			largerElements.insert(pos, *it);
			insertedElements++;
		}
	}

	// Reinsert the straggler element, if any, at its correct position.
	if (hasStraggler)
	{
		typename Container<T>::iterator pos = std::lower_bound(largerElements.begin(), largerElements.end(), stragglerElement);
		largerElements.insert(pos, stragglerElement);
	}

	// Update the original container with the now fully sorted sequence.
	container = largerElements;
}

template class PmergeMe<int, std::vector>;
template class PmergeMe<int, std::deque>;
