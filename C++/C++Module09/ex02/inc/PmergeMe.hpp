/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:20:16 by atoof             #+#    #+#             */
/*   Updated: 2024/02/26 13:26:35 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &rhs);
		PmergeMe &operator=(const PmergeMe &rhs);
		~PmergeMe();

		void sortList(std::list<int> &lst);
		void sortVector(std::vector<int> &vec);
	private:
		static void fordjohnson(std::vector<int> &vec, int left, int right);
		static void fordjohnson(std::list<int> &lst, int left, int right);
		static void merge(std::vector<int> &vec, int left, int middle, int right);
		static void merge(std::list<int> &lst, int left, int middle, int right);
};

#endif /* PMERGEME_HPP */