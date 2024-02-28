/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:20:16 by atoof             #+#    #+#             */
/*   Updated: 2024/02/28 15:23:57 by atoof            ###   ########.fr       */
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

	private:
		void fordJohnson(std::vector<int> &vec);
		bool hasStraggler;
		int straggler;
};

#endif /* PMERGEME_HPP */
