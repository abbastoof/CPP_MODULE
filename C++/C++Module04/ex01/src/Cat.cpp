/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:14:45 by atoof             #+#    #+#             */
/*   Updated: 2023/12/10 14:43:54 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	brain = new Brain();
	std::cout << this->_type << " called from Cat default constructor" << std::endl;
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = NULL;
	*this = copy;
}

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
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

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << this->_type << " says meow meow" << std::endl;
}

std::string Cat::getType() const
{
	return (this->_type);
}

void Cat::setIdea(int index, std::string idea)
{
	brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
	return (brain->getIdea(index));
}