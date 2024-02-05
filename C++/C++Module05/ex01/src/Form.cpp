/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:35:59 by atoof             #+#    #+#             */
/*   Updated: 2024/02/02 23:35:59 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

// Default constructor
Form::Form() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form default constructor " << this->getName() << " called" << std::endl;
}

// Destructor
Form::~Form()
{
	std::cout << "Form destructor " << this->getName() << " called" << std::endl;
}

// Parameter constructor
Form::Form(std::string name, bool sign, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form parameter constructor " << this->getName() << " called" << std::endl;
}

// Copy constructor
Form::Form(const Form &rhs) : _name(rhs._name), _signed(rhs._signed), _gradeToSign(rhs._gradeToSign), _gradeToExecute(rhs._gradeToExecute)
{
	std::cout << "Form copy constructor " << this->getName() << " called" << std::endl;
}

// Operator overloads
Form	&Form::operator=(const Form &rhs)
{
	// check for self-assignment, self-assignment can lead to problems and is often inefficient
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
	}
	return (*this);
}

// member functions
const std::string	&Form::getName() const
{
	return (this->_name);
}

bool	Form::getSigned() const
{
	return (this->_signed);
}

int	Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (this->_signed == false)
	{
		if (bureaucrat.getGrade() <= this->_gradeToSign)
			this->_signed = true;
		else
			throw Form::GradeTooLowException();
	}
	else
		std::cout << "Form is already signed." << std::endl;

}

// exceptions

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

// non-member functions
// Output stream operator overload

std::ostream	&operator<<(std::ostream &os, const Form &form)
{
	if (form.getSigned())
		os << form.getName() << " form is signed." << std::endl;
	else
		os << form.getName() << " form is not signed." << std::endl;
	return (os);
}
