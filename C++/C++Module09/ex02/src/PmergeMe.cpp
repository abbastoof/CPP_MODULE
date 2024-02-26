/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:20:23 by atoof             #+#    #+#             */
/*   Updated: 2024/02/26 16:58:05 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &rhs)
{
	*this = rhs;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::sortList(std::list<int> &lst)
{
	fordjohnson(lst, 0, lst.size() - 1);
}

void PmergeMe::sortVector(std::vector<int> &vec)
{
	fordjohnson(vec, 0, vec.size() - 1);
}

void PmergeMe::fordjohnson(std::vector<int> &vec, int left, int right)
{
	if (left > right) return; // base case, because we are going to divide the vector into two parts and we need to know when to stop
	int middle = left + (right - left) / 2; // find the middle of the vector
	fordjohnson(vec, left, middle); // sort the left part of the vector
	fordjohnson(vec, middle + 1, right); // sort the right part of the vector
	merge(vec, left, middle, right); // merge the two parts of the vector
}

void PmergeMe::fordjohnson(std::list<int> &lst, int left, int right)
{
	if (left > right) return;
	int middle = left + (right - left) / 2;
	fordjohnson(lst, left, middle);
	fordjohnson(lst, middle + 1, right);
	merge(lst, left, middle, right);
}

void PmergeMe::merge(std::vector<int>& data, int left, int mid, int right)
{
	std::vector<int> tempHoldMerged(right - left + 1);
	int left_index = left, right_index = mid + 1, temp_index = 0;
	while (left_index <= mid && right_index <= right)
	{
		if (data[left_index] < data[right_index])
			tempHoldMerged[temp_index++] = data[left_index++];
		else
			tempHoldMerged[temp_index++] = data[right_index++];
	}

	while (left_index <= mid)
		tempHoldMerged[temp_index++] = data[left_index++];

	while (right_index <= right)
		tempHoldMerged[temp_index++] = data[right_index++];

	for (int i = left; i <= right; ++i, ++temp_index)
		data[i] = tempHoldMerged[temp_index];
}

