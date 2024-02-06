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

Intern::Intern()
{ std::cout << "Intern Default constructor is called" << std::endl;}

Intern::Intern(const Intern& rhs)
{
	*this = rhs;
	std::cout << "Intern Copy constructor is called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor is called" << std::endl;
}

Intern& Intern::operator=(const Intern& rhs)
{
	(void)rhs;
	return (*this);
}

std::shared_ptr<AForm> makeShrubberyForm(std::string const target) {return (std::make_shared<ShrubberyCreationForm>(target));}
std::shared_ptr<AForm> makeRobotomyForm(std::string const target) {return (std::make_shared<RobotomyRequestForm>(target));}
std::shared_ptr<AForm> makePresidentialForm(std::string const target) {return (std::make_shared<PresidentialPardonForm>(target));}

std::shared_ptr<AForm> Intern::makeForm(std::string const formName, std::string const target)
{
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	std::shared_ptr<AForm> (*formFunctions[3])(std::string const target) = {makeShrubberyForm, makeRobotomyForm, makePresidentialForm}; //std::shared_ptr<AForm> in here means that the function returns a shared pointer to AForm, (*formFunctions[3])(std::string const target) means that formFunctions is an array of 3 pointers to functions that take a string as an argument and return a shared pointer to AForm

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << " form" << std::endl;
			return (formFunctions[i](target));
		}
	}
	std::cout << "Intern cannot create " << formName << " form" << std::endl;
	return (nullptr);
}
