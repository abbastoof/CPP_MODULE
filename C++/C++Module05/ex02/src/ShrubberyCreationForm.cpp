/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:13:37 by atoof             #+#    #+#             */
/*   Updated: 2024/02/05 15:13:37 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm default constructor for " << this->getName() << " is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", false, 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm parameter constructor for " << this->getName() << " is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & rhs) : AForm(rhs), _target(rhs._target)
{
	std::cout << "ShrubberyCreationForm copy constructor for " << this->getName() << " is called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor for " << this->getName() << " is called" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::cout << "ShrubberyCreationForm execute for " << this->getName() << " is called" << std::endl;
	if (this->getSigned() == true) // if form is signed
	{
		if (executor.getGrade() <= this->getGradeToExecute()) // if executor's grade is high enough
		{
			std::ofstream file;
			file.open(this->_target + "_shrubbery"); // create file with target name
			std::string tree = R"(
			<< "      /\\      "
			<< "     /\\*\\     "
			<< "    /\\O\\*\\    "
			<< "   /*/\\/\\/\\   "
			<< "  /\\O\\/\\*\\/\\  "
			<< " /\\*\\/\\*\\/\\/\\ "
			<< "/\\O\\/\\/*/\\/O/\\"
			<< "      ||      "
			<< "      ||      "
			<< "      ||      ")";
			file << tree;
			file.close();
		}
		else
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::FormNotSignedException();

}
