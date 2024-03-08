/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:08:42 by atoof             #+#    #+#             */
/*   Updated: 2024/03/08 19:35:54 by atoof            ###   ########.fr       */
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
	std::cout << std::fixed << std::setprecision(8) << "Time to process a range of " << cont.size() << " elements with " << containerType << " : " << difference.count() << " us" << std::endl;

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
	sequence.push_back(2);
	while (std::accumulate(sequence.begin(), sequence.end(), 0) <= length)
	{
		int term = pow(2, sequence.size() + 1) - sequence.back();
		sequence.push_back(term);
	}
	return sequence;
}

template <typename T, template <typename...> typename Container>
std::vector<Container<T>> PmergeMe<T, Container>::partition(const Container<T> &elements, const std::vector<int> &groupSizes)
{
    std::vector<Container<T>> partitions;
    size_t start = 0;
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
        std::cout << "After reversal: ";
        for (int i = end - 1; i >= static_cast<int>(start); --i)
            std::cout << "y" << indexOffset + i << " ";
        std::cout << std::endl;

        partitions.push_back(partition);
        start = end; // Update the start index for the next partition
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
	debugPrintPairs(pairs, "Pairs after sorting");
	// Split pairs into larger and smaller elements.
	Container<T> largerElements, smallerElements;
	for (auto &pair : pairs)
	{
		largerElements.push_back(pair[1]);	// Assuming the second element is larger.
		smallerElements.push_back(pair[0]); // Assuming the first element is smaller.
	}
	debugPrint(largerElements, "Larger elements before recursive sort");

	// Recursively sort the larger elements.
	fordJohnson(largerElements);
	debugPrint(largerElements, "Larger elements after recursive sort");
	// Merge smaller elements into the sorted list of larger elements.
	// The first smaller element is merged directly before handling the rest.
	if (!smallerElements.empty())
	{
		auto pos = std::lower_bound(largerElements.begin(), largerElements.end(), smallerElements.front());
		largerElements.insert(pos, smallerElements.front());
		smallerElements.erase(smallerElements.begin());
	}

	// Generate the power sequence for the remaining smaller elements.
	auto powerSequence = generatePowerSequence(smallerElements.size()); // We split the smaller elements into groups of sizes that are powers of 2
	auto partitions = partition(smallerElements, powerSequence);

	// Merge the partitioned smaller elements back into the larger elements.
	for (const Container<T> &partition : partitions)
	{
		for (auto it = partition.begin(); it != partition.end(); ++it)
		{
			auto pos = std::lower_bound(largerElements.begin(), largerElements.end(), *it);
			largerElements.insert(pos, *it);
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
