/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:07:13 by atoof             #+#    #+#             */
/*   Updated: 2024/02/19 16:56:33 by atoof            ###   ########.fr       */
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

int main()
{
	try
	{
		Span sp = {5};
		std::vector<int> vec = {1, 2, 3, 4, 5};
        sp.addNumber(sp.begin(), vec.begin(), vec.end());
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
		std::vector<int> vec = {1, 2, 3, 4, 5, 6};
		sp.addNumber(vec.begin(), vec.begin(), vec.end());
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