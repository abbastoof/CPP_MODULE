/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:56:08 by atoof             #+#    #+#             */
/*   Updated: 2023/12/10 17:52:43 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

Character::Character(): _name("Default name")
{
	std::cout << "Character Default Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < FLOOR_LIM; i++)
		_floor[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
	std::cout << "Character Argument Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < FLOOR_LIM; i++)
		_floor[i] = NULL;
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
	for (int i = 0; i < FLOOR_LIM; i++)
	{
		if (_floor[i] != NULL)
			delete _floor[i];
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete _inventory[i];
	}
	for (int i = 0; i < 4; i++)
	{
		if (rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	for (int index = 0; index < FLOOR_LIM; index++)
	{
		if (rhs._floor[index] != NULL)
			this->_floor[index] = rhs._floor[index]->clone();
		else
			this->_floor[index] = NULL;
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
	for (int i = 0; i < FLOOR_LIM; i++)
	{
		if (_floor[i] != NULL)
			delete _floor[i];
	}
}

void Character::equip(AMateria* materia)
{
	if (materia == NULL)
	{
		std::cout << RED << _name << " couldn't equip the Materia, Materia is empty" RESET << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = materia;
			std::cout << GREEN "Materia " << materia->getType() << " equipted successfully by " << _name << RESET << std::endl;
			break;
		}
	}
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && _inventory[idx] != NULL)
	{
		for (int i = 0; i < FLOOR_LIM; i++)
		{
			if (_floor[i] == NULL)
			{
				_floor[i] = _inventory[idx];
				std::cout << GREEN "Materia " << _inventory[idx]->getType() << " unequipped successfully" RESET << std::endl;
				_inventory[idx] = NULL;
				break;
			}
			else if (i == FLOOR_LIM - 1 && _floor[i] != NULL)
				std::cout << RED "Floor does not have space to unequip the item" RESET << std::endl;
		}
	}
	else
		std::cout << RED "Invalid index" RESET << std::endl;
	
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4)
	{
		if (_inventory[idx])
			_inventory[idx]->use(target);
		else
			std::cout << RED "Slot number " << idx << " is empty" RESET << std::endl;
	}
	else
		std::cout << RED "Invalid slot index number" RESET << std::endl;
}