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

void test1()
{
	try
	{
		std::cout << "Test 1: ShrubberyCreationForm execution by a high-grade Bureaucrat" << std::endl;
		Bureaucrat highGradeBureaucrat("HighGrade", 1);
		ShrubberyCreationForm shrubberyForm("Home");
		highGradeBureaucrat.signForm(shrubberyForm);
		highGradeBureaucrat.executeForm(shrubberyForm);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void test2()
{
	try
	{
		std::cout << "\nTest 2: RobotomyRequestForm execution with random outcome" << std::endl;
		Bureaucrat midGradeBureaucrat("MidGrade", 45);
		RobotomyRequestForm robotomyForm("Bender");
		midGradeBureaucrat.signForm(robotomyForm);
		midGradeBureaucrat.executeForm(robotomyForm);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void test3()
{
	try
	{
		std::cout << "\nTest 3: PresidentialPardonForm execution by a low-grade Bureaucrat" << std::endl;
		Bureaucrat lowGradeBureaucrat("LowGrade", 150);
		PresidentialPardonForm pardonForm("Zaphod Beeblebrox");
		// Should throw an exception
		lowGradeBureaucrat.signForm(pardonForm);
		lowGradeBureaucrat.executeForm(pardonForm);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void test4()
{
	try
	{
		std::cout << "\nTest 4: Attempt to execute unsigned form" << std::endl;
		Bureaucrat highGradeBureaucrat("HighGradeAgain", 1);
		ShrubberyCreationForm unsignedShrubberyForm("Office");
		// Not signing the form on purpose
		highGradeBureaucrat.executeForm(unsignedShrubberyForm);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
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
