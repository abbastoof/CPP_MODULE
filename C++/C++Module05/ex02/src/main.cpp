/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:40:06 by atoof             #+#    #+#             */
/*   Updated: 2024/03/03 16:19:15 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


void test1()
{
	try
	{
		std::cout << "\nTest 1: ShrubberyCreationForm execution by a high-grade Bureaucrat" << std::endl;
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
		highGradeBureaucrat.executeForm(unsignedShrubberyForm);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

// Additional tests
void test5()
{
	try
	{
		std::cout << "\nTest 5: Minimum Grade Execution for PresidentialPardonForm" << std::endl;
		Bureaucrat exactGradeBureaucrat("ExactGrade", 5);
		PresidentialPardonForm pardonForm("Someone");
		exactGradeBureaucrat.signForm(pardonForm);
		exactGradeBureaucrat.executeForm(pardonForm);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void test6()
{
	try
	{
		std::cout << "\nTest 6: Grade Boundary Testing for Bureaucrat" << std::endl;
		Bureaucrat topBureaucrat("TopBureaucrat", 1);
		topBureaucrat.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bottomBureaucrat("BottomBureaucrat", 150);
		bottomBureaucrat.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void test7()
{
	std::cout << "\nTest 7: File Creation Validation for ShrubberyCreationForm" << std::endl;
	Bureaucrat highGradeBureaucrat("HighGrade", 1);
	ShrubberyCreationForm shrubberyForm("Garden");
	highGradeBureaucrat.signForm(shrubberyForm);
	highGradeBureaucrat.executeForm(shrubberyForm);

	std::ifstream file("Garden_shrubbery");
	if (file)
	{
		std::cout << "File created successfully" << std::endl;
		file.close();
	}
	else
		std::cerr << "File not created" << std::endl;
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();

	return 0;
}
