/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:01:45 by atoof             #+#    #+#             */
/*   Updated: 2023/11/25 12:27:28 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;

	std::cout << "The memory address of the string variable is: " << &str << std::endl;
	std::cout << "The memory address held by stringPTR is: "  << ptr << std::endl;
	std::cout << "The memory address held by stringREF is: " << &ref << std::endl;
	std::cout << "String value = " << str << std::endl;
	std::cout << "Pointer value = " << *ptr << std::endl;
	std::cout << "Reference value = " << ref << std::endl;
	return (0);
}
