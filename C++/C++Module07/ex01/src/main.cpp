/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:52:38 by atoof             #+#    #+#             */
/*   Updated: 2024/02/13 10:17:11 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"

int main()
{
	std::cout << "Testing with int" << std::endl;
	int array[] = { 1, 2, 3, 4, 5 };
	size_t size = sizeof(array) / sizeof(int);
	iter<int>(array, size, print<int>);
	std::cout << "Testing with char" << std::endl;
	char array2[] = { 'a', 'b', 'c', 'd', 'e' };
	size = sizeof(array2) / sizeof(char);
	iter<char>(array2, size, print<char>);
	std::cout << "Testing with string" << std::endl;
	std::string array3[] = { "one", "two", "three", "four", "five" };
	size = sizeof(array3) / sizeof(std::string);
	iter<std::string>(array3, size, print<std::string>);
	std::cout << "Testing with double" << std::endl;
	double array4[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	size = sizeof(array4) / sizeof(double);
	iter<double>(array4, size, print<double>);
	std::cout << "Testing with float" << std::endl;
	float array5[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	size = sizeof(array5) / sizeof(float);
	iter<float>(array5, size, print<float>);
	std::cout << "Testing with bool" << std::endl;
	bool array6[] = { true, false, true, false, true };
	std::cout << std::boolalpha;
	size = sizeof(array6) / sizeof(bool);
	iter<bool>(array6, size, print<bool>);
	std::noboolalpha;
	return 0;
}