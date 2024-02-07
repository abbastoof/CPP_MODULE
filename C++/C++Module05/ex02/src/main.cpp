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
#include "../inc/Colors.hpp"

void test1()
{
	try
	{
		std::cout << "\n" << Colors::BG_CYAN << "Test 1: ShrubberyCreationForm execution by a high-grade Bureaucrat" << Colors::RESET << std::endl;
		Bureaucrat highGradeBureaucrat("HighGrade", 1);
		ShrubberyCreationForm shrubberyForm("Home");
		highGradeBureaucrat.signForm(shrubberyForm);
		highGradeBureaucrat.executeForm(shrubberyForm);
	}
	catch (std::exception &e)
	{
		std::cerr << Colors::RED << e.what() << Colors::RESET << std::endl;
	}
}

void test2()
{
	try
	{
		std::cout << "\n" << Colors::BG_CYAN << "Test 2: RobotomyRequestForm execution with random outcome" << Colors::RESET << std::endl;
		Bureaucrat midGradeBureaucrat("MidGrade", 45);
		RobotomyRequestForm robotomyForm("Bender");
		midGradeBureaucrat.signForm(robotomyForm);
		midGradeBureaucrat.executeForm(robotomyForm);
		//why Bender robotomization failed every time? :( because of rand() % 2 == 0 in RobotomyRequestForm.cpp line 52 , to fix this, we can use srand(time(0)) in main.cpp before calling executeForm function to get different result every time or in RobotomyRequestForm.cpp line 52, we can use rand() % 2 == 1 to get different result every time
	}
	catch (std::exception &e)
	{
		std::cerr << Colors::RED << e.what() << Colors::RESET << std::endl;
	}
}

void test3()
{
	try
	{
		std::cout << "\n" << Colors::BG_CYAN << "Test 3: PresidentialPardonForm execution by a low-grade Bureaucrat" << Colors::RESET << std::endl;
		Bureaucrat lowGradeBureaucrat("LowGrade", 150);
		PresidentialPardonForm pardonForm("Zaphod Beeblebrox");
		lowGradeBureaucrat.signForm(pardonForm);
		lowGradeBureaucrat.executeForm(pardonForm);
	}
	catch (std::exception &e)
	{
		std::cerr << Colors::RED << e.what() << Colors::RESET << std::endl;
	}
}

void test4()
{
	try
	{
		std::cout << "\n" << Colors::BG_CYAN << "Test 4: Attempt to execute unsigned form" << Colors::RESET << std::endl;
		Bureaucrat highGradeBureaucrat("HighGradeAgain", 1);
		ShrubberyCreationForm unsignedShrubberyForm("Office");

		highGradeBureaucrat.executeForm(unsignedShrubberyForm);
	}
	catch (std::exception &e)
	{
		std::cerr << Colors::RED << e.what() << Colors::RESET << std::endl;
	}
}

int main()
{
	test1();
	test2();
	test3();
	test4();

	return 0;
}
