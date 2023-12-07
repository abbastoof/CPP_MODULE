/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:40:59 by atoof             #+#    #+#             */
/*   Updated: 2023/12/07 16:24:21 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cure.hpp"

Cure::Cure()
{
	std::cout << "Cure Constructor called" << std::endl;
	this->_type = "Cure";
}

Cure::Cure(const Cure &copy)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

Cure::~Cure() {std::cout << "Cure Destructor called" << std::endl;}

Cure &Cure::operator=(const Cure &rhs)
{
	if (!rhs.getType().empty() && !this->getType().compare(rhs.getType()))
		this->_type = rhs.getType();
	return (*this);
}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}