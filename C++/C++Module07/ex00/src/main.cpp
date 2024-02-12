/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:47:18 by atoof             #+#    #+#             */
/*   Updated: 2024/02/12 15:34:54 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/whatever.hpp"

int main(void)
{
    std::cout << "Enter two numbers:\n";

    std::string input;
    int x, y;
    std::cout << "x: ";
    std::getline(std::cin, input);
    x = stoi(input);

    std::cout << "y: ";
    std::getline(std::cin, input);
    y = stoi(input);

    int max_num = ::max(x, y);
    std::cout << "Max number is " << max_num << "\n";
    std::cout << "Min number is " << ::min(x, y) << "\n";
    swap(x, y);

    std::cout << "Enter two strings:\n";
    std::string s1, s2;

    std::cout << "s1: ";
    std::getline(std::cin, s1);
    std::cout << "s2: ";
    std::getline(std::cin, s2);

    std::cout << "Max string is " << ::max(s1, s2) << "\n";
    std::cout << "Min string is " << ::min(s1, s2) << "\n";
    swap(s1, s2);

    std::cout << "Strings after swap:\n";
    std::cout << "s1: " << s1 << "\n";
    std::cout << "s2: " << s2 << "\n";
    return 0;
}