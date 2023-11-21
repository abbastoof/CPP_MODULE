/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:14:51 by atoof             #+#    #+#             */
/*   Updated: 2023/11/20 13:50:09 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << this->_type << " called from Dog default constructor" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog &Dog::operator=(const Dog &assigned)
{
	std::cout << "Dog assignment operator called" << std::endl;
	this->_type = assigned._type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << this->_type << " says woof woof" << std::endl;
}