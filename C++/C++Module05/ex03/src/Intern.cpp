/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:35:06 by atoof             #+#    #+#             */
/*   Updated: 2024/02/06 18:04:30 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"
#include "../inc/Colors.hpp"

// Default constructor
Intern::Intern()
{
	std::cout << Colors::GREEN << "Intern Default constructor is called" << Colors::RESET << std::endl;
}

// Copy constructor
Intern::Intern(const Intern& rhs)
{
	*this = rhs;
	std::cout << Colors::GREEN << "Intern Copy constructor is called" << Colors::RESET << std::endl;
}

// Destructor
Intern::~Intern()
{
	std::cout << Colors::RED << "Intern Destructor is called" << Colors::RESET << std::endl;
}

// Assignment operator
Intern& Intern::operator=(const Intern& rhs)
{
	(void)rhs;
	return (*this);
}

// Function to create ShrubberyCreationForm
std::shared_ptr<AForm> makeShrubberyForm(std::string const target) {return (std::make_shared<ShrubberyCreationForm>(target));}

// Function to create RobotomyRequestForm
std::shared_ptr<AForm> makeRobotomyForm(std::string const target) {return (std::make_shared<RobotomyRequestForm>(target));}

// Function to create PresidentialPardonForm
std::shared_ptr<AForm> makePresidentialForm(std::string const target) {return (std::make_shared<PresidentialPardonForm>(target));}

// Function to create form based on formName
std::shared_ptr<AForm> Intern::makeForm(std::string const formName, std::string const target)
{
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	std::shared_ptr<AForm> (*formFunctions[3])(std::string const target) = {makeShrubberyForm, makeRobotomyForm, makePresidentialForm};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << Colors::BRIGHT_CYAN << "Intern creates " << formName << " form" << Colors::RESET << std::endl;
			return (formFunctions[i](target));
		}
	}
	std::cout << Colors::RED << "Intern cannot create " << formName << " form" << Colors::RESET << std::endl;
	return (nullptr);
}
