/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:07:28 by atoof             #+#    #+#             */
/*   Updated: 2024/02/19 17:57:59 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	1. Develop a Span class that can store a maximum of N integers. -> std::vector<int> _vec;
 	2. N is an unsigned int variable and will be the only parameter passed to the constructor. -> unsigned int _n and Span(unsigned int n);
	3. This class will have a member function called addNumber() to add a single number to the Span. -> void addNumber(int number);
	It will be used in order to fill it. Any attempt to add a new element if there are already N elements stored should throw an exception. -> throw an exception if _vec.size() == _n
	4. Next, implement two member functions: shortestSpan() and longestSpan() They will respectively find out the shortest span or the longest span (or distance, if
		you prefer) between all the numbers stored, and return it. If there are no numbers stored,
		or only one, no span can be found. Thus, throw an exception.
	5. Of course, you will write your own tests and they will be way more thorough than the ones below. Test your Span at least with a minimum of 10 000 numbers. More would be even better. 


	https://www.cplusplus.com/reference/vector/vector/
*/

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <exception>
#include <limits>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _vec;
	public:
		class FullSpanException : public std::exception
		{
			public:
				virtual const char *what() const noexcept
				{
					return "Span is full";
				}
		};
		class NotEnoughElementsException : public std::exception
		{
			public:
				virtual const char *what() const noexcept
				{
					return "Not enough elements to find a span";
				}
		};
		class SpanInvalidPositionException : public std::exception
		{
			public:
				virtual const char *what() const noexcept
				{
					return "Invalid position";
				}
		};
		Span(int n);
		~Span();
		Span(const Span &rhs); // copy constructor
		Span &operator=(const Span &rhs); // assignment operator
		int shortestSpan(); // find the shortest span between all the numbers stored
		int longestSpan(); // find the longest span between all the numbers stored
		void addNumber(int number); // Add a single number to the Span
		void addNumber(std::vector<int>::const_iterator position, std::vector<int>::const_iterator start, std::vector<int>::const_iterator end);
		void addNumber(unsigned int n, std::vector<int>::const_iterator start, std::vector<int>::const_iterator end);
		void printVec() const;		
		//getters
		std::vector<int>::const_iterator begin();
		std::vector<int>::const_iterator end();
		std::vector<int>::const_iterator pos(unsigned int position);
};

#endif
