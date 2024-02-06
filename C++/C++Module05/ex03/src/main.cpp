/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:40:06 by atoof             #+#    #+#             */
/*   Updated: 2024/02/06 15:03:41 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Intern.hpp"

int main()
{
	//Low grade ShrubberyCreationForm
	std::cout << "First test" << std::endl;
	try
	{
		Intern jimmy;
		std::shared_ptr<AForm> ptr = jimmy.makeForm("test", "test2");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "2nd test" << std::endl;
	//Successfull sign and execute ShrubberyCreationForm
	try
	{

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "3rd test" << std::endl;
	//Low grade Presidentialpardonform
	try
	{

	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "4th test" << std::endl;
	try
	{

	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
