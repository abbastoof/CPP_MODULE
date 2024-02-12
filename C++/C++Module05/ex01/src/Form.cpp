/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:35:59 by atoof             #+#    #+#             */
/*   Updated: 2024/02/12 10:12:57 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/Colors.hpp"

// Default constructor
Form::Form() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << Colors::YELLOW << "Form default constructor is called" << Colors::RESET << std::endl;
}

// Destructor
Form::~Form()
{
	std::cout << Colors::RED << "Form destructor is called" << Colors::RESET << std::endl;
}

// Parameter constructor
Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << Colors::YELLOW << "Form parameter constructor is called" << Colors::RESET << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

// Copy constructor
Form::Form(const Form &rhs) : _name(rhs._name), _signed(rhs._signed), _gradeToSign(rhs._gradeToSign), _gradeToExecute(rhs._gradeToExecute)
{
	std::cout << Colors::YELLOW <<  "Form copy constructor is called" << Colors::RESET << std::endl;
}

// Operator overloads
Form &Form::operator=(const Form &rhs)
{
	// check for self-assignment, self-assignment can lead to problems and is often inefficient
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
	}
	return (*this);
}

// member functions
const std::string &Form::getName() const
{
	return (this->_name);
}

bool Form::getSign() const
{
	return (this->_signed);
}

int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute() const
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

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

// non-member functions
// Output stream operator overload

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form name: " << form.getName() << ", "
	   << " signature : " << std::boolalpha << form.getSign() << ", "
	   << " grade to be signed off: " << form.getGradeToSign() << ", "
	   << " grade to be executed: " << form.getGradeToExecute() << std::endl;
	return (os);
}
