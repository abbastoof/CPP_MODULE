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
#include "../inc/Colors.hpp"

// Default constructor
AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(MIN_GRADE), _gradeToExecute(MIN_GRADE)
{
	std::cout << Colors::GREEN << "AForm default constructor is called" << Colors::RESET << std::endl;
}

// Destructor
AForm::~AForm()
{
	std::cout << Colors::RED << "AForm destructor is called" << Colors::RESET << std::endl;
}

// Parameter constructor
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << Colors::GREEN << "AForm parameter constructor is called" << Colors::RESET << std::endl;
	if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
		throw AForm::GradeTooLowException();
}

// Copy constructor
AForm::AForm(const AForm &rhs) : _name(rhs._name), _signed(rhs._signed), _gradeToSign(rhs._gradeToSign), _gradeToExecute(rhs._gradeToExecute)
{
	std::cout << Colors::GREEN << "AForm copy constructor is called" << Colors::RESET << std::endl;
}

// Operator overloads
AForm	&AForm::operator=(const AForm &rhs)
{
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

bool	AForm::getSign() const
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

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Form name: " << form.getName() << ", "
	   << " signature : " << std::boolalpha << form.getSign() << ", "
	   << " grade to be signed off: " << form.getGradeToSign() << ", "
	   << " grade to be executed: " << form.getGradeToExecute() << std::endl;
	return (os);
}
