/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:48:48 by atoof             #+#    #+#             */
/*   Updated: 2024/02/01 12:57:27 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(MIN_GRADE)
{
	std::cout << "Bureaucrat default constructor " << this->getName() << " called" << std::endl;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor " << this->getName() << " called" << std::endl;
}

// Parameter constructor
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	std::cout << "Bureaucrat parameter constructor " << this->getName() << " called" << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << "Bureaucrat copy constructor " << this->getName() << " called" << std::endl;
}

// Operator overloads
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	// check for self-assignment, self-assignment can lead to problems and is often inefficient
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

// member functions

// getters
const std::string	&Bureaucrat::getName() const
{
	return (this->_name);
}

int		Bureaucrat::getGrade() const
{
	return (this->_grade);
}


// increment and decrement grade
void	Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

// exceptions

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

// non-member functions

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (os);
}


// sign Aform
void	Bureaucrat::signForm(AForm &form)
{
	if (form.getSigned())
		std::cout << this->_name << " cannot sign " << form.getName() << " because it's already signed." << std::endl;
	else if (this->_grade > form.getGradeToSign())
		std::cout << this->_name << " cannot sign " << form.getName() << " because bureaucrat's grade is too low." << std::endl;
	else
	{
		form.beSigned(*this);
		std::cout << this->_name << " signs " << form.getName() << std::endl;
	}
}

// execute Aform

void	Bureaucrat::executeForm(AForm const &form)
{
	if (!form.getSigned())
		std::cout << this->_name << " cannot execute " << form.getName() << " because it's not signed." << std::endl;
	else if (this->_grade > form.getGradeToExecute())
		std::cout << this->_name << " cannot execute " << form.getName() << " because bureaucrat's grade is too low." << std::endl;
	else
	{
		form.execute(*this);
		std::cout << this->_name << " executes " << form.getName() << std::endl;
	}
}