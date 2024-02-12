/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:48:48 by atoof             #+#    #+#             */
/*   Updated: 2024/02/12 10:16:50 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
#include "../inc/Colors.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << Colors::YELLOW <<  "Bureaucrat default constructor is called" << Colors::RESET << std::endl;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << Colors::RED << "Bureaucrat destructor is called" << Colors::RESET << std::endl;
}

// Parameter constructor
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << Colors::YELLOW << "Bureaucrat parameter constructor is called" << Colors::RESET << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << Colors::YELLOW << "Bureaucrat copy constructor is called" << Colors::RESET << std::endl;
}

// Operator overloads
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

// member functions

// getters
const std::string &Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

// increment and decrement grade
void Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

// exceptions

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

// non-member functions

std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return (os);
}

// sign form
void Bureaucrat::signForm(Form &form)
{
	if (form.getSign())
		std::cout << this->_name << " couldn't sign < " << form.getName() << " because it's already signed." << std::endl;
	else if (this->_grade > form.getGradeToSign())
		std::cout << this->_name << " couldn't sign < " << form.getName() << " because bureaucrat's grade is too low." << std::endl;
	else
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
}
