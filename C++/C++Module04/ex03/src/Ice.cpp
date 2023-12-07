/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:41:03 by atoof             #+#    #+#             */
/*   Updated: 2023/12/07 18:07:02 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"

Ice::Ice()
{
	std::cout << "Ice Constructor called" << std::endl;
	this->_type = "ice";
}

Ice::Ice(const Ice &copy)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

Ice::~Ice() {std::cout << "Ice Destructor called" << std::endl;}

Ice &Ice::operator=(const Ice &rhs)
{
	if ((!rhs.getType().empty() && !this->getType().compare(rhs.getType()))\
		|| (this->_type.empty() && !rhs.getType().empty()))
		this->_type = rhs.getType();
	return (*this);
}

AMateria *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}