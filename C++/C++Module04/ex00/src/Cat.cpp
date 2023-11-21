/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:14:45 by atoof             #+#    #+#             */
/*   Updated: 2023/11/20 13:50:27 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << this->_type << " called from Cat default constructor" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat &Cat::operator=(const Cat &assigned)
{
	std::cout << "Cat assignment operator called" << std::endl;
	this->_type = assigned._type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << this->_type << " says meow meow" << std::endl;
}