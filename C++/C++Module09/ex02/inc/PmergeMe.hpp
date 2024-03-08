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
# include <iomanip>

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
		    void debugPrint(const Container<T>& cont, const std::string& message) const {
        std::cout << message << ": ";
        std::copy(cont.begin(), cont.end(), std::ostream_iterator<T>(std::cout, " "));
        std::cout << std::endl;
    }

    void debugPrintPairs(const Container<Container<T>>& pairs, const std::string& message) const {
        std::cout << message << ":\n";
        for (const auto& pair : pairs) {
            std::cout << "(";
            std::copy(pair.begin(), pair.end(), std::ostream_iterator<T>(std::cout, " "));
            std::cout << ") ";
        }
        std::cout << std::endl;
    }
};


#endif	// PMERGEME_HPP
