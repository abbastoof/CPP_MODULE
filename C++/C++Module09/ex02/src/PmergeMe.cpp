/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:08:42 by atoof             #+#    #+#             */
/*   Updated: 2024/03/01 11:55:41 by atoof            ###   ########.fr       */
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

template<typename T, template<typename...> typename Container>
PmergeMe<T, Container>::PmergeMe() : hasStraggler(false), straggler(T()) {}

template<typename T, template<typename...> typename Container>
PmergeMe<T, Container>::PmergeMe(const PmergeMe &rhs) : hasStraggler(rhs.hasStraggler), straggler(rhs.straggler) {}

template<typename T, template<typename...> typename Container>
PmergeMe<T, Container> &PmergeMe<T, Container>::operator=(const PmergeMe &rhs)
{
    if (this != &rhs)
    {
        hasStraggler = rhs.hasStraggler;
        straggler = rhs.straggler;
    }
    return *this;
}

template<typename T, template<typename...> typename Container>
PmergeMe<T, Container>::~PmergeMe() {}

template<typename T, template<typename...> typename Container>
void PmergeMe<T, Container>::sortContainer(Container<T> &cont)
{
	// Start the timer
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    fordJohnson(cont);
	// Stop the timer
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	// Calculate the duration
	std::chrono::duration<double, std::micro> duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	// std::cout << std::endl;
	std::cout << "Time taken by FordJohnson: " << Colors::GREEN << duration.count() << Colors::RESET <<" microseconds" << std::endl;
}

template<typename T, template<typename...> typename Container>
Container<Container<T>> PmergeMe<T, Container>::createPairs(const Container<T>& a)
{
    Container<Container<T>> pairs;

    for (size_t i = 0; i < a.size(); i += 2) {
        Container<T> pair = {a[i], a[i + 1]};
        pairs.push_back(pair);
    }

    return pairs;
}

template<typename T, template<typename...> typename Container>
void PmergeMe<T, Container>::sortPairs(Container<Container<T>> &pairs)
{
    for (Container<T> &pair : pairs)
    {
        if (pair.size() >= 2 && pair[0] > pair[1])
            std::swap(pair[0], pair[1]);
    }
}

template<typename T, template<typename...> typename Container>
void PmergeMe<T, Container>::recursiveSortPairsByLargerValue(Container<Container<T>> &pairs, int n)
{
    if (n <= 1)
        return;

    int max_idx = 0;
    for (int i = 1; i < n; i++) {
        if (pairs[i][1] > pairs[max_idx][1])
            max_idx = i;
    }

    std::swap(pairs[max_idx], pairs[n-1]);

    recursiveSortPairsByLargerValue(pairs, n-1);
}

template<typename T, template<typename...> typename Container>
void PmergeMe<T, Container>::fordJohnson(Container<T>& container)
{
    if (container.size() < 2)
        return;

    if (container.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = container.back();
        container.pop_back();
    }

    Container<Container<T>> pairs = createPairs(container);
    sortPairs(pairs);

    recursiveSortPairsByLargerValue(pairs, pairs.size());

    Container<T> largerElements, smallerElements;
    for (Container<T> & pair : pairs)
    {
        largerElements.push_back(pair[1]);
        smallerElements.push_back(pair[0]);
    }

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
