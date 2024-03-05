/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:13:00 by atoof             #+#    #+#             */
/*   Updated: 2024/03/05 11:36:14 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

Span::Span(int n) : _n(n)
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

int Span::shortestSpan()
{
	if (_vec.size() <= 1) {
		throw NotEnoughElementsException();
	}

	std::vector<int> sortedVec(_vec);
	std::sort(sortedVec.begin(), sortedVec.end());

	int minSpan = std::numeric_limits<int>::max(); // why we initialize it with max value? because we want to find the minimum span and we want to compare it with the first span we find in the vector

	for (size_t i = 0; i < sortedVec.size() - 1; ++i)
	{
		int currentSpan = sortedVec[i + 1] - sortedVec[i];
		minSpan = std::min(minSpan, currentSpan);
	}

	return minSpan;
}

/*
	https://www.cplusplus.com/reference/algorithm/sort/
	template <class RandomAccessIterator>void sort (RandomAccessIterator first, RandomAccessIterator last);
*/

// Longest Span Calculation
int Span::longestSpan()
{
	if (_vec.size() <= 1)
		throw NotEnoughElementsException();
	std::vector<int> sortedVec(_vec);
	std::sort(sortedVec.begin(), sortedVec.end());
	return sortedVec.back() - sortedVec.front();
}


// Add a Single Number
void Span::addNumber(int number)
{
    if (_vec.size() >= _n)
        throw FullSpanException();
    _vec.push_back(number);
}

/*
	https://www.cplusplus.com/reference/vector/vector/insert/
	template <class InputIterator>iterator insert (const_iterator position, InputIterator first, InputIterator last);
*/

void Span::addNumber(std::vector<int>::const_iterator position, std::vector<int>::const_iterator first, std::vector<int>::const_iterator last)
{
	if (_vec.size() + std::distance(first, last) > _n)
		throw FullSpanException();
	_vec.insert(position, first, last);
	std::cout << "Added " << std::distance(first, last) << " numbers to the span" << std::endl;
}

void Span::printVec() const
{
	std::cout << "Span contents: ";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << _vec[i] << (i < _vec.size() - 1 ? ", " : "");
	std::cout << std::endl;
}

std::vector<int>::const_iterator Span::begin()
{
	return _vec.begin();
}

std::vector<int>::const_iterator Span::end()
{
	return _vec.end();
}

std::vector<int>::const_iterator Span::pos(unsigned int position)
{
	if (_vec.begin() + position <= _vec.end())
		return _vec.begin() + position;
	else
		throw std::out_of_range("Position is out of range");
}
