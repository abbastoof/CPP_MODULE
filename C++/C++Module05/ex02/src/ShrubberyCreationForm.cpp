/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:13:37 by atoof             #+#    #+#             */
/*   Updated: 2024/02/06 15:10:57 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Colors.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << Colors::GREEN << "ShrubberyCreationForm default constructor for " << this->getName() << " is called" << Colors::RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << Colors::GREEN << "ShrubberyCreationForm parameter constructor for " << this->getName() << " is called" << Colors::RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &rhs) : AForm(rhs), _target(rhs._target)
{
	std::cout << Colors::GREEN << "ShrubberyCreationForm copy constructor for " << this->getName() << " is called" << Colors::RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << Colors::RED << "ShrubberyCreationForm destructor for " << this->getName() << " is called" << Colors::RESET << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::cout << Colors::BRIGHT_MAGENTA << "ShrubberyCreationForm execute is called" << Colors::RESET << std::endl;
	if (this->getSign() == true)
	{
		if (executor.getGrade() <= this->getGradeToExecute())
		{
			std::ofstream file;
			file.open(this->_target + "_shrubbery");
			std::string tree = R"(
                         *
                        /\\
                      /\\/\\
                     /\\*\\/\\
                    /\\O\\*\\/\\
                   /*/\\/\\/\/\\
                  /\\O\\/\\*\\/\\
                 /\\*\\/\\*\\/\\/\\
                /\\O\\/\\/*/\\/O/\\
                      ||
                      ||
                      ||        )";
			file << tree;
			file.close();
		}
		else
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::FormNotSignedException();
}
