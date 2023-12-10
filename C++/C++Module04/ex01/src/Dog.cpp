/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:14:51 by atoof             #+#    #+#             */
/*   Updated: 2023/12/10 14:45:45 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	brain = new Brain();
	std::cout << this->_type << " called from Dog default constructor" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = NULL;
	*this = copy;
}

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
		delete this->brain;
		if (rhs.brain)
			this->brain = new Brain(*rhs.brain);
		else
			this->brain = NULL;
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << this->_type << " says woof woof" << std::endl;
}

std::string Dog::getType() const
{
	return (this->_type);
}

void Dog::setIdea(int index, std::string idea)
{
	brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
	return (brain->getIdea(index));
}