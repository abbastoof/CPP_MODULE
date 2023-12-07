/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:56:08 by atoof             #+#    #+#             */
/*   Updated: 2023/12/07 18:51:45 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"

Character::Character()
{
	std::cout << "Character Default Constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
	std::cout << "Character Argument Constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
}

Character::Character(const Character &copy)
{
	std::cout << "Character Copy Constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
}

Character &Character::operator=(const Character &rhs)
{
	std::cout << "Character Copy assignment operator called" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (this->_inventory[i] != NULL)
			delete _inventory[i];
	}
	for (int i = 0; i < 4; ++i)
	{
		if (rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character Destructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
}

void Character::equip(AMateria* materia)
{
	if (materia == NULL)
	{
		std::cout << "Can't equip the Materia, Materia is empty" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; ++i)
		this->_inventory[i] = 
}