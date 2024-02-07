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
#include "../inc/Colors.hpp"

int main()
{
	std::cout << "\n" << Colors::BG_BLUE << "First test Low grade ShrubberyCreationForm" << Colors::RESET << std::endl;
	try
	{
		Bureaucrat low("Low", 150);
		std::cout << low;
		ShrubberyCreationForm form("home");
		std::cout << form;
		low.signForm(form);
		low.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << Colors::RED << e.what() << Colors::RESET << std::endl;
	}

	std::cout << "\n" << Colors::BG_BLUE << "Second test High grade ShrubberyCreationForm" << Colors::RESET << std::endl;
	try
	{
		Bureaucrat high("High", 1);
		std::cout << high;
		ShrubberyCreationForm form("home");
		std::cout << form;
		high.signForm(form);
		high.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << Colors::RED << e.what() << Colors::RESET << std::endl;
	}

	std::cout << "\n" << Colors::BG_BLUE << "Third test RobotomyRequestForm" << Colors::RESET << std::endl;
	try
	{
		Bureaucrat high("High", 1);
		std::cout << high;
		RobotomyRequestForm form("home");
		std::cout << form;
		high.signForm(form);
		high.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << Colors::RED << e.what() << Colors::RESET << std::endl;
	}

	std::cout << "\n" << Colors::BG_BLUE << "Fourth test PresidentialPardonForm" << Colors::RESET << std::endl;
	try
	{
		Bureaucrat high("High", 1);
		std::cout << high;
		PresidentialPardonForm form("home");
		std::cout << form;
		high.signForm(form);
		high.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << Colors::RED << e.what() << Colors::RESET << std::endl;
	}

	std::cout << "\n" << Colors::BG_BLUE << "Fifth test Intern" << Colors::RESET << std::endl;

	try
	{
		Intern someRandomIntern;
		std::shared_ptr<AForm> rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf;
	}
	catch (std::exception &e)
	{
		std::cout << Colors::RED << e.what() << Colors::RESET << std::endl;
	}

	try
	{
		Intern someRandomIntern;
		std::shared_ptr<AForm> ppf;
		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
		std::cout << *ppf;
	}
	catch (std::exception &e)
	{
		std::cout << Colors::RED << e.what() << Colors::RESET << std::endl;
	}

	try
	{
		Intern someRandomIntern;
		std::shared_ptr<AForm> scf;
		scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		std::cout << *scf;
	}
	catch (std::exception &e)
	{
		std::cout << Colors::RED << e.what() << Colors::RESET << std::endl;
	}

	return (0);
}
