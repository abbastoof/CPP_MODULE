#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
# include <sstream>
# include <chrono>
# include "../inc/colors.hpp"
# include <typeinfo>
# include <cmath>
# include <numeric>

template<typename T, template<typename...> typename Container>
class PmergeMe
{
    public:
        PmergeMe();
        ~PmergeMe();
        void sortContainer(Container<T>& cont);

    private:
        PmergeMe(const PmergeMe &rhs);
        PmergeMe &operator=(const PmergeMe &rhs);
        Container<Container<T>> createPairs(const Container<T>& a);
        void sortPairs(Container<Container<T>>& pairs);
        void recursiveSortPairsByLargerValue(Container<Container<T>> &pairs, int n, int start);
		void printFunc(Container<Container<T>> pairs, int step);
		std::vector<Container<T>> partition(const Container<T>& elements, const std::vector<int>& groupSizes);
		std::vector<int> generatePowerSequence(int length);
        void fordJohnson(Container<T>& cont);
        bool hasStraggler;
        T straggler;
};

#endif	// PMERGEME_HPP
