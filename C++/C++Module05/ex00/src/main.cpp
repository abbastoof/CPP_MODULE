/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:40:06 by atoof             #+#    #+#             */
/*   Updated: 2024/03/01 11:36:46 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Colors.hpp"

void testBureaucrat(const std::string &name, int grade)
{
	try
	{
		Bureaucrat bureaucrat(name, grade);
		std::cout << Colors::GREEN << bureaucrat << Colors::RESET;
		try
		{
			bureaucrat.decrementGrade();
			std::cout << "After decrement: " << Colors::CYAN << bureaucrat << Colors::RESET;
		}
		catch (const std::exception &e)
		{
			std::cout << Colors::RED << "Exception while decrementing for " << name << ": " << e.what() << Colors::RESET << std::endl;
		}
		try
		{
			bureaucrat.incrementGrade();
			std::cout << "After increment: " << Colors::CYAN << bureaucrat << Colors::RESET;
		}
		catch (const std::exception &e)
		{
			std::cout << Colors::RED << "Exception while incrementing for " << name << ": " << e.what() << Colors::RESET << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cout << Colors::RED << "Exception for " << name << ": " << e.what() << Colors::RESET << std::endl;
	}
}

int main(void)
{
	std::cout << "\n" << Colors::BG_BLUE << "Test 1" << Colors::RESET << std::endl;
	testBureaucrat("Bureaucrat1", MIN_GRADE);

	std::cout << "\n" << Colors::BG_BLUE << "Test 2" << Colors::RESET << std::endl;
	testBureaucrat("Bureaucrat2", MAX_GRADE);

	std::cout << "\n" << Colors::BG_BLUE << "Test 3" << Colors::RESET << std::endl;
	testBureaucrat("Bureaucrat3", 100);

	std::cout << "\n" << Colors::BG_BLUE << "Test 4" << Colors::RESET << std::endl;
	testBureaucrat("Bureaucrat4", 0);

	std::cout << "\n" << Colors::BG_BLUE << "Test 5" << Colors::RESET << std::endl;
	testBureaucrat("Bureaucrat5", 151);

	return 0;
}
