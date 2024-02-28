/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:20:16 by atoof             #+#    #+#             */
/*   Updated: 2024/02/28 12:11:23 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
#include <vector>
#include <sstream>
#include <algorithm>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &rhs);
		PmergeMe &operator=(const PmergeMe &rhs);
		~PmergeMe();

		void sortVector(std::vector<int> &vec);
		std::vector<std::vector<int>> createPairs(const std::vector<int> &a);
		void sortPairs(std::vector<std::vector<int>> &pairs);
		void sortPairsByLargerValue(std::vector<std::vector<int>> &pairs);
		int jacobsthal(int n);
		bool isPairGreaterThan(const std::vector<int> &a, const std::vector<int> &b);
		std::vector<int> buildJacobInsertionSequence(int length);
		int calculateInsertionIndex(const std::vector<int>& S, int pendValue, const std::vector<int>& jacobSequence);
		int binarySearchInsertionIndex(const std::vector<int>& S, int value);

	private:
		void fordJohnson(std::vector<int> &vec);
		bool hasStraggler;
		int straggler;
};

#endif /* PMERGEME_HPP */
