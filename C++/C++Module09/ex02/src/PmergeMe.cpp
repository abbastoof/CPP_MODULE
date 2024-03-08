/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:08:42 by atoof             #+#    #+#             */
/*   Updated: 2024/03/05 18:07:33 by atoof            ###   ########.fr       */
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

	recursiveSortPairsByLargerValue(pairs, mid, start);			  // leftside
	recursiveSortPairsByLargerValue(pairs, n - mid, start + mid); // rightside

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
        return; // Base case: the container is already sorted or has a single element

    // Handling the straggler if the number of elements in the container is odd
    T stragglerElement;
    bool hasStraggler = container.size() % 2 != 0;
    if (hasStraggler)
    {
        stragglerElement = container.back();
        container.pop_back(); // Temporarily remove the straggler element
    }

    // Creating and sorting pairs of elements
    Container<Container<T>> pairs = createPairs(container);
    sortPairs(pairs);

    // Extracting larger and smaller elements from the sorted pairs
    Container<T> largerElements, smallerElements;
    for (const auto& pair : pairs)
    {
        largerElements.push_back(pair[1]); // Assuming the larger element is the second in the pair
        smallerElements.push_back(pair[0]); // Assuming the smaller element is the first in the pair
    }

    // Recursive sorting of the larger elements
    fordJohnson(largerElements);

    // Inserting the first smaller element at the beginning of the sorted larger elements
    if (!smallerElements.empty())
    {
        largerElements.insert(largerElements.begin(), smallerElements.front());
        smallerElements.erase(smallerElements.begin());
    }

    // Generating a power sequence for the sizes of groups to partition the remaining smaller elements
    std::vector<int> powerSequence = generatePowerSequence(smallerElements.size());

    // Partitioning the remaining smaller elements according to the power sequence
    auto partitions = partition(smallerElements, powerSequence);

    // Inserting partitioned smaller elements into the sorted sequence of larger elements
    for (const auto& group : partitions)
    {
        for (auto it = group.rbegin(); it != group.rend(); ++it) // Insert in reverse order
        {
            auto pos = std::lower_bound(largerElements.begin(), largerElements.end(), *it);
            largerElements.insert(pos, *it);
        }
    }

    // Inserting the straggler element, if it exists
    if (hasStraggler)
    {
        auto pos = std::lower_bound(largerElements.begin(), largerElements.end(), stragglerElement);
        largerElements.insert(pos, stragglerElement);
    }

    // Updating the original container with the sorted sequence
    container = largerElements;
}


template class PmergeMe<int, std::vector>;
template class PmergeMe<int, std::deque>;
