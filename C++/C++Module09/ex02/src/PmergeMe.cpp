/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:08:42 by atoof             #+#    #+#             */
/*   Updated: 2024/03/08 11:20:19 by atoof            ###   ########.fr       */
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
	// Display the unsorted sequence
	std::cout << "Before: ";
	for (const auto &item : cont)
	{
		std::cout << item << " ";
	}
	std::cout << std::endl;

	// Start the timer
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	fordJohnson(cont);
	// Stop the timer
	std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> difference = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	// Display the sorted sequence
	std::cout << "After: ";
	for (const auto &item : cont)
	{
		std::cout << item << " ";
	}
	std::cout << std::endl;

	// Display the time taken for sorting
	std::string containerType = (std::is_same<Container<T>, std::vector<T>>::value) ? "std::vector" : "std::deque";
	std::cout << "Time to process a range of " << cont.size() << " elements with " << containerType << " : " << difference.count() << " us" << std::endl;

	if (std::is_sorted(cont.begin(), cont.end()))
		std::cout << "The sequence is sorted.\n";
	else
		std::cout << "The sequence is not sorted.\n";
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
std::vector<int> PmergeMe<T, Container>::generatePowerSequence(int length)
{
	std::vector<int> sequence;

	// Start with 2 to maintain the property of the power sequence
	int current = 2;

	// The first two groups should always be of size 2 according to the algorithm
	sequence.push_back(2);
	if (length > 1)
		sequence.push_back(2);

	// Generate subsequent group sizes
	while (sequence.size() < static_cast<size_t>(length))
	{
		current = std::pow(2, sequence.size() + 1) - std::accumulate(sequence.begin(), sequence.end(), 0);
		if (current <= 0)
			break; // If the calculated size is not positive, stop generating more sizes
		sequence.push_back(current);
	}

	return sequence;
}

template <typename T, template <typename...> typename Container>
std::vector<Container<T>> PmergeMe<T, Container>::partition(const Container<T> &elements, const std::vector<int> &groupSizes)
{
	std::vector<Container<T>> partitions;
	size_t start = 0;

	for (int size : groupSizes)
	{
		size_t end = start + size;
		if (end > elements.size())
			end = elements.size(); // Ensure the end index does not exceed the container's size

		// Create a partition and reverse it
		Container<T> partition(elements.begin() + start, elements.begin() + end);
		std::reverse(partition.begin(), partition.end());
		partitions.push_back(partition);

		start = end; // Update the start index for the next partition
		if (start >= elements.size())
			break; // If all elements have been partitioned, stop
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

	// Split pairs into larger and smaller elements.
	Container<T> largerElements, smallerElements;
	for (auto &pair : pairs)
	{
		largerElements.push_back(pair[1]);	// Assuming the second element is larger.
		smallerElements.push_back(pair[0]); // Assuming the first element is smaller.
	}

	// Recursively sort the larger elements.
	fordJohnson(largerElements);

	// Merge smaller elements into the sorted list of larger elements.
	// The first smaller element is merged directly before handling the rest.
	if (!smallerElements.empty())
	{
		auto pos = std::lower_bound(largerElements.begin(), largerElements.end(), smallerElements.front());
		largerElements.insert(pos, smallerElements.front());
		smallerElements.erase(smallerElements.begin()); // Remove the first smaller element after merging.
	}

	// Generate the power sequence for the remaining smaller elements.
	auto powerSequence = generatePowerSequence(smallerElements.size());
	auto partitions = partition(smallerElements, powerSequence);

	// Merge the partitioned smaller elements back into the larger elements.
	for (const auto &partition : partitions)
	{
		for (auto it = partition.rbegin(); it != partition.rend(); ++it)
		{ // Insert in reverse order
			auto pos = std::lower_bound(largerElements.begin(), largerElements.end(), *it);
			largerElements.insert(pos, *it); // Merge into the sorted larger elements list.
		}
	}

	// Reinsert the straggler element, if any, at its correct position.
	if (hasStraggler)
	{
		auto pos = std::lower_bound(largerElements.begin(), largerElements.end(), stragglerElement);
		largerElements.insert(pos, stragglerElement);
	}

	// Update the original container with the now fully sorted sequence.
	container = largerElements;
}

template class PmergeMe<int, std::vector>;
template class PmergeMe<int, std::deque>;
