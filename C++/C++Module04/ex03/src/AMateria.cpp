/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:57:52 by atoof             #+#    #+#             */
/*   Updated: 2023/12/08 17:56:25 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"
#include "../include/ICharacter.hpp"

AMateria::AMateria() {std::cout << "AMateria Default constructor called" << std::endl;}

AMateria::AMateria(const AMateria &copy)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

AMateria::AMateria(std::string const &type): _type(type) {std::cout << "AMateria Argument constructor called" << std::endl;}

AMateria::~AMateria() {std::cout << "AMateria Destructor called" << std::endl;}

std::string const &AMateria::getType() const {return this->_type;}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	std::cout << "AMateria Copy Assignment operator called" << std::endl;
	if (!rhs.getType().empty() && !this->getType().compare(rhs.getType()))
		this->_type = rhs.getType();
	return (*this);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria uses " << _type << "on " << target.getName() << std::endl;
}

