/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:37:48 by atoof             #+#    #+#             */
/*   Updated: 2024/03/04 18:40:35 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/whatever.hpp"

// class CustomType
// {
// public:
//     CustomType(int value) : value(value) {}
//     int getValue() const;

// private:
//     int value;
// };

// int CustomType::getValue() const
// {
//     return value;
// }

// std::ostream &operator<<(std::ostream &outputStream, CustomType const &src)
// {
//     outputStream << src.getValue();
//     return outputStream;
// }

// void testCustomType()
// {
//     CustomType c1(5);
//     CustomType c2(10);
// 	std::cout << "c1 = " << c1 << ", c2 = " << c2 << std::endl;
//     ::swap(c1, c2);
//     std::cout << "c1 after swap = " << c1 << ", c2 after swap = " << c2 << std::endl;
//     // This line would result in a compilation error
//     // because CustomType lacks comparison operators
//     // std::cout << "min(c1, c2) = " << ::min(c1, c2) << std::endl;
// }

int main( void )
{
	// My OWN TESTS
	// std::cout << "Enter two numbers:\n";

    // std::string input;
    // int x, y;
    // std::cout << "x: ";
    // std::getline(std::cin, input);
    // x = stoi(input);

    // std::cout << "y: ";
    // std::getline(std::cin, input);
    // y = stoi(input);

    // int max_num = ::max(x, y);
    // std::cout << "Max number is " << max_num << "\n";
    // std::cout << "Min number is " << ::min(x, y) << "\n";
    // swap(x, y);

    // std::cout << "Enter two strings:\n";
    // std::string s1, s2;

    // std::cout << "s1: ";
    // std::getline(std::cin, s1);
    // std::cout << "s2: ";
    // std::getline(std::cin, s2);

    // std::cout << "Max string is " << ::max(s1, s2) << "\n";
    // std::cout << "Min string is " << ::min(s1, s2) << "\n";
    // swap(s1, s2);

    // std::cout << "Strings after swap:\n";
    // std::cout << "s1: " << s1 << "\n";
    // std::cout << "s2: " << s2 << "\n";
	// testCustomType();
    // return 0;
	
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}