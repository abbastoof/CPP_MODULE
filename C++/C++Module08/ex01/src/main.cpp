/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:07:13 by atoof             #+#    #+#             */
/*   Updated: 2024/02/16 14:54:14 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }

void Span::printVec() const
{
    std::cout << "Span contents: ";
    for (size_t i = 0; i < _vec.size(); ++i)
	{
        std::cout << _vec[i] << (i < _vec.size() - 1 ? ", " : "");
    }
    std::cout << std::endl;
}

int main()
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(-3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(17);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		sp.printVec();
	}
	catch (Span::FullSpanException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Span sp = Span(5);
		std::vector<int> newInts;
		newInts.push_back(1);
		newInts.push_back(2);
		newInts.push_back(3);
		newInts.push_back(4);
		newInts.push_back(5);
		// newInts.push_back(6);
		sp.addNumber(newInts.begin(), newInts.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		sp.printVec();
	}
	catch (Span::FullSpanException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Span sp = Span(5);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		sp.printVec();
	}
	catch (Span::NotEnoughElementsException &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}