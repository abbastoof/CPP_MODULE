/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:35:59 by atoof             #+#    #+#             */
/*   Updated: 2024/02/02 23:35:59 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

// Default constructor
AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(MIN_GRADE), _gradeToExecute(MIN_GRADE)
{
	std::cout << "AForm default constructor " << this->getName() << " called" << std::endl;
}

// Destructor
AForm::~AForm()
{
	std::cout << "AForm destructor " << this->getName() << " called" << std::endl;
}

// Parameter constructor
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < MIN_GRADE || gradeToExecute < MIN_GRADE)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
		throw AForm::GradeTooLowException();
	std::cout << "AForm parameter constructor " << this->getName() << " called" << std::endl;
}

// Copy constructor
AForm::AForm(const AForm &rhs) : _name(rhs._name), _signed(rhs._signed), _gradeToSign(rhs._gradeToSign), _gradeToExecute(rhs._gradeToExecute)
{
	std::cout << "AForm copy constructor " << this->getName() << " called" << std::endl;
}

// Operator overloads
AForm	&AForm::operator=(const AForm &rhs)
{
	// check for self-assignment, self-assignment can lead to problems and is often inefficient
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
	}
	return (*this);
}

// member functions
const std::string	&AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getSigned() const
{
	return (this->_signed);
}

int	AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int	AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (this->_signed == false)
	{
		if (bureaucrat.getGrade() <= this->_gradeToSign)
			this->_signed = true;
		else
			throw AForm::GradeTooLowException();
	}
	else
		std::cout << "AForm is already signed." << std::endl;

}

// exceptions

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed!");
}

// non-member functions
// Output stream operator overload

std::ostream	&operator<<(std::ostream &os, const AForm &AForm)
{
	os <<"AForm name: " << AForm.getName()
	<< ", signed: " << AForm.getSigned()
	<< ", grade to sign: "<< AForm.getGradeToSign()
	<< ", grade to execute: " << AForm.getGradeToExecute() << std::endl;
	return (os);
}
