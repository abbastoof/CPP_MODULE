/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:13:27 by atoof             #+#    #+#             */
/*   Updated: 2024/02/06 13:29:11 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "../inc/Colors.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << Colors::GREEN << "PresidentialPardonForm default constructor for " << this->getName() << " is called" << Colors::RESET << std::endl;
}

// Parameter constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << Colors::GREEN << "PresidentialPardonForm parameter constructor for " << this->getName() << " is called" << Colors::RESET << std::endl;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs) : AForm(rhs), _target(rhs._target)
{
	std::cout << Colors::GREEN << "PresidentialPardonForm copy constructor for " << this->getName() << " is called" << Colors::RESET << std::endl;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << Colors::RED << "PresidentialPardonForm destructor for " << this->getName() << " is called" << Colors::RESET << std::endl;
}

// Operator overloads
PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return (*this);
}

// member functions
void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	std::cout << Colors::BRIGHT_MAGENTA << "PresidentialPardonForm execute is called" << std::endl;
	if (this->getSign() == true)
	{
		if (executor.getGrade() <= this->getGradeToExecute())
		{
			std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
		}
		else
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::FormNotSignedException();
}
