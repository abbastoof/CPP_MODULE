/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:35:06 by atoof             #+#    #+#             */
/*   Updated: 2024/03/03 14:30:33 by atoof            ###   ########.fr       */
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
Intern::Intern(const Intern &rhs)
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
Intern &Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	return (*this);
}

// Function to create ShrubberyCreationForm
std::shared_ptr<AForm> makeShrubberyForm(const std::string &target)
{
	return std::make_shared<ShrubberyCreationForm>(target);
}

// Function to create RobotomyRequestForm
std::shared_ptr<AForm> makeRobotomyForm(const std::string &target)
{
	return std::make_shared<RobotomyRequestForm>(target);
}

// Function to create PresidentialPardonForm
std::shared_ptr<AForm> makePresidentialForm(const std::string &target)
{
	return std::make_shared<PresidentialPardonForm>(target);
}

// Function to create form based on formName

std::shared_ptr<AForm> Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	std::shared_ptr<AForm> (*formFunctions[3])(const std::string &target) = {makeShrubberyForm, makeRobotomyForm, makePresidentialForm};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << Colors::BRIGHT_CYAN << "Intern creates " << formName << " form" << Colors::RESET << std::endl;
			return formFunctions[i](target);
		}
	}

	// Throw an exception if the form name is invalid
	throw std::runtime_error("Intern cannot create '" + formName + "' form. Invalid form name provided.");
}
