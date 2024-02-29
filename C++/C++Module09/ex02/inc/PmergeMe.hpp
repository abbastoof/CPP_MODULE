#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
# include <sstream>
# include <chrono>

template<typename T, template<typename...> typename Container>
class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &rhs);
        PmergeMe &operator=(const PmergeMe &rhs);
        ~PmergeMe();

        void sortContainer(Container<T>& cont);

        Container<Container<T>> createPairs(const Container<T>& a);

        void sortPairs(Container<Container<T>>& pairs);

        void recursiveSortPairsByLargerValue(Container<Container<T>>& pairs, int n);

    private:
        void fordJohnson(Container<T>& cont);
        bool hasStraggler;
        T straggler;
};

#endif	// PMERGEME_HPP
