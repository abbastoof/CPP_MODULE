/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:14:58 by atoof             #+#    #+#             */
/*   Updated: 2023/12/08 16:55:44 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
	this->_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &assigned) // assignment operator overload
{
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	this->_type = assigned.getType();
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << this->getType() << "says Roarrrrrrr" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->_type);
}