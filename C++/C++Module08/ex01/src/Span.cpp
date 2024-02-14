/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:13:00 by atoof             #+#    #+#             */
/*   Updated: 2024/02/14 17:37:43 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(Span const &rhs)
{
	*this = rhs;
}

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		_n = rhs._n;
		_vec = rhs._vec;
	}
	return *this;
}

Span::~Span()
{
}


// Shortest span is the difference between the two closest numbers in the vector for example: 1 2 3 4 5 6 7 8 9 10
// The shortest span is 1, because the difference between 10 and 9 is 1

unsigned int Span::shortestSpan()
{
	if (_vec.size() <= 1)
		throw std::exception(); // if the vector is empty or has only one element, there is no span
	std::vector<unsigned int> sorted = _vec;
	std::sort(sorted.begin(), sorted.end());
	unsigned int shortest = UINT_MAX;
	for (unsigned int i = 0; i < sorted.size() - 1; i++)
	{
		if (sorted[i + 1] - sorted[i] < shortest)
			shortest = sorted[i + 1] - sorted[i];
	}
	return shortest;
}

/*
	https://www.cplusplus.com/reference/algorithm/sort/
	template <class RandomAccessIterator>void sort (RandomAccessIterator first, RandomAccessIterator last);
*/

unsigned int Span::longestSpan()
{
	if (_vec.size() <= 1)
		throw std::exception();
	std::vector<unsigned int> sorted = _vec;
	std::sort(sorted.begin(), sorted.end());
	return sorted.back() - sorted.front();
}


void Span::addNumber(int number)
{
	if (_vec.size() == _n) // if the vector is full, n acts as the max size
		throw std::exception();
	_vec.push_back(number);
}

/*	
	https://www.cplusplus.com/reference/vector/vector/insert/
	template <class InputIterator>iterator insert (const_iterator position, InputIterator first, InputIterator last);
*/

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_vec.size() + std::distance(begin, end) > _n)
		throw std::exception();
	_vec.insert(_vec.end(), begin, end);
}
