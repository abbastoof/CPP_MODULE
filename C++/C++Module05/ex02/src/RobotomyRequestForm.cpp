/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:13:31 by atoof             #+#    #+#             */
/*   Updated: 2024/02/05 15:13:31 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


// Default constructor

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm",false, 72, 45), _target("default")
{
	std::cout << "RobotomyRequestForm default constructor for " << this->getName() << " is called" << std::endl;
}

// Parameter constructor

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", false, 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm parameter constructor for " << this->getName() << " is called" << std::endl;
}

// Copy constructor

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs) : AForm(rhs), _target(rhs._target)
{
	std::cout << "RobotomyRequestForm copy constructor for " << this->getName() << " is called" << std::endl;
}

// Destructor

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor for " << this->getName() << " is called" << std::endl;
}

// Operator overloads

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return (*this);
}

// member functions

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	std::cout << "RobotomyRequestForm execute for " << this->getName() << " is called" << std::endl;
	if (this->getSigned() == true) // if form is signed
	{
		if (executor.getGrade() <= this->getGradeToExecute()) // if executor's grade is high enough
		{
			std::cout << "Drilling noises" << std::endl;
			if (rand() % 2 == 0)
				std::cout << this->_target << " has been robotomized successfully" << std::endl;
			else
				std::cout << this->_target << " robotomization failed" << std::endl;
		}
		else
			throw AForm::GradeTooLowException();
		}
	else
		throw AForm::FormNotSignedException();
}
