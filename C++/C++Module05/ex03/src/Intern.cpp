/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:35:06 by atoof             #+#    #+#             */
/*   Updated: 2024/02/06 18:04:30 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern()
{ std::cout << "Intern Default constructor is called" << std::endl;}

Intern::Intern(const Intern& rhs)
{
	*this = rhs;
	std::cout << "Intern Copy constructor is called";
}

Intern::~Intern()
{
	"Intern Destructor is called";
}

Intern& Intern::operator=(const Intern& rhs)
{
	(void)rhs;
	return (*this);
}

std::shared_ptr<AForm> makeShrubberyForm(std::string const target) {return (std::make_shared<ShrubberyCreationForm>(target));}
std::shared_ptr<AForm> makeShrubberyForm(std::string const target) {return (std::make_shared<ShrubberyCreationForm>(target));}
std::shared_ptr<AForm> makeShrubberyForm(std::string const target) {return (std::make_shared<ShrubberyCreationForm>(target));}
