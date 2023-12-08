/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:56:08 by atoof             #+#    #+#             */
/*   Updated: 2023/12/08 18:21:41 by atoof            ###   ########.fr       */
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
}

Character::Character(std::string name) : _name(name)
{
	std::cout << "Character Argument Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
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
	if (idx >= 0 && idx < 4)
	{
		std::cout << GREEN "Materia " << _inventory[idx]->getType() << " unequipted successfully" RESET << std::endl;
		_inventory[idx] = NULL;
	}
	
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