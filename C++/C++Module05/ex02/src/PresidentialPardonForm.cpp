/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:13:27 by atoof             #+#    #+#             */
/*   Updated: 2024/02/05 15:13:27 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


// Default constructor

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", false, 25, 5), _target("default")
{
	std::cout << "PresidentialPardonForm default constructor for " << this->getName() << " is called" << std::endl;
}

// Parameter constructor

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", false, 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm parameter constructor for " << this->getName() << " is called" << std::endl;
}

// Copy constructor

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs) : AForm(rhs), _target(rhs._target)
{
	std::cout << "PresidentialPardonForm copy constructor for " << this->getName() << " is called" << std::endl;
}

// Destructor

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor for " << this->getName() << " is called" << std::endl;
}

// Operator overloads

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs) // check for self-assignment, self-assignment can lead to problems and is often inefficient
	{
		this->_target = rhs._target;
	}
	return (*this);
}

// member functions

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	std::cout << "PresidentialPardonForm execute for " << this->getName() << " is called" << std::endl;
	if (this->getSigned() == true) // if form is signed
	{
		if (executor.getGrade() <= this->getGradeToExecute()) // if bureaucrat has enough grade
		{
			std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
		}
		else
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::FormNotSignedException();
}
