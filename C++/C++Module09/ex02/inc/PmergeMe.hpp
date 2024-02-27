/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:20:16 by atoof             #+#    #+#             */
/*   Updated: 2024/02/27 10:59:17 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
#include <vector>
#include <sstream>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &rhs);
		PmergeMe &operator=(const PmergeMe &rhs);
		~PmergeMe();

		void sortList(std::list<int> &lst);
		void sortVector(std::vector<int> &vec);
		std::vector<std::vector<int>> createPairs(const std::vector<int> &a);
		void sortPairs(std::vector<std::vector<int>> &pairs);
		void mergePairs(const std::vector<std::vector<int>>& pairs, std::vector<int>& merged);
		void merge(std::vector<int>& elements, int left, int mid, int right, std::vector<int>& merged);
		void mergeSort(std::vector<int>& elements, int left, int right, std::vector<int>& merged);
		void insertElements(std::vector<int> &sorted, const std::vector<std::vector<int>> &pairs);
	private:

		void fordJohnson(std::vector<int> &vec);
};

#endif /* PMERGEME_HPP */
