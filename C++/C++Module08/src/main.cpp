/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:02:21 by atoof             #+#    #+#             */
/*   Updated: 2024/02/13 20:15:26 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"

int main()
{
/*	The std::list range constructor accepts two iterators as arguments, 
	which define a range of elements (in this case, pointers marking the beginning and the end of a C-style array).
	The constructor initializes the list with the elements within the specified range.
*/

	std::cout << "---- TEST LIST ----" << std::endl;
	std::cout << "Initializing int list { 1, -2, 3, 4, 5 }..." << std::endl;
	int myInts[5] = { 1, -2, 3, 4, 5 };
	std::list<int> ints(myInts, myInts + sizeof(myInts) / sizeof(int)); // the iterator constructor can also be used to construct from arrays

	std::cout << "Finding 1 from the list..." << std::endl;
	std::list<int>::const_iterator it = ::easyfind(ints, 1);
	if (*it != 1)
		std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "Finding 6 from the list..." << std::endl;
	try
	{
		it = ::easyfind(ints, 6);
		if (*it == 6)
			std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\033[32mTEST OKAY: \033[33m" << e.what() << "\033[0m" << std::endl;
	}
		
	std::cout << "--------------------" << std::endl;
	std::cout << "Using template with wrong type..." << std::endl;
	try
	{
		it = ::easyfind(ints, 6.0);
		std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\033[32mTEST OKAY: \033[33m" << e.what() << "\033[0m" << std::endl;
	}

	std::cout << "--------------------" << std::endl;
	
	std::cout << "---- TEST VECTOR ----" << std::endl;
	std::cout << "Initializing int vector { 1, 2, 3, 4, 5 }..." << std::endl;
	std::vector<int> vec(myInts, myInts + sizeof(myInts) / sizeof(int));
	std::cout << "Finding 1 from the vector..." << std::endl;
	std::vector<int>::const_iterator it2 = ::easyfind(vec, 1);
	if (*it2 != 1)
		std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "Finding 6 from the vector..." << std::endl;
	try
	{
		it2 = ::easyfind(vec, 6);
		if (*it2 == 6)
			std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\033[32mTEST OKAY: \033[33m" << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "--------------------" << std::endl;
	// Example with vector
    std::vector<int> vec2 = {1, 2, 3, 4, 5};
    auto it_vec = easyfind(vec2, 3);
    if (it_vec != vec2.end()) {
        std::cout << "Found value in vector: " << *it_vec << std::endl;
    }

    // Example with string
    std::string str = "Hello";
	std::cout << "Finding 'e' from \"Hello\" string..." << std::endl;
    auto it_str = easyfind(str, 'e');
    if (it_str != str.end()) {
        std::cout << "Found character in string: " << *it_str << std::endl;
    }

    // Example with float
    float fValue = 3.14f;
    if (easyfind(fValue, 3.14f)) {
        std::cout << "Found value in float: " << fValue << std::endl;
    }

    // Example with double
    double dValue = 6.28;
    if (easyfind(dValue, 6.28)) {
        std::cout << "Found value in double: " << dValue << std::endl;
    }
	return 0;
}