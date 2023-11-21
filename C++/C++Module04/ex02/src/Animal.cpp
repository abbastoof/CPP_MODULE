/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:14:41 by atoof             #+#    #+#             */
/*   Updated: 2023/11/21 15:23:03 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout << this->_type << " called from AAnimal default constructor" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << this->_type << " called from AAnimal constructor overload" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = copy;
}

AAnimal &AAnimal::operator=(const AAnimal &assigned)
{
	std::cout << "AAnimal assignment operator called" << std::endl;
	this->_type = assigned._type;
	return (*this);
}

std::string AAnimal::getType() const
{
	return (this->_type);
}

void AAnimal::makeSound() const
{
	std::cout << this->_type << " makes a sound" << std::endl;
}