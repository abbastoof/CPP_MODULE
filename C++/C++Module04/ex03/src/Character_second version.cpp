/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:56:08 by atoof             #+#    #+#             */
/*   Updated: 2023/12/11 13:49:51 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

Character::FloorNode::FloorNode(AMateria* mat) : data(mat), next(NULL) {}
Character::Character(): _name("Default name"), _floor(NULL)
{
	std::cout << "Character Default Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string name) : _name(name), _floor(NULL)
{
	std::cout << "Character Argument Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character &copy) : _floor(NULL)
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
	FloorNode* current = _floor;
	while (current != NULL)
	{
		FloorNode* next = current->next;
		delete current->data;
		delete current;
		current = next;
	}
	for (FloorNode* node = rhs._floor; node != NULL; node = node->next)
		_floor = new FloorNode(node->data);
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
	FloorNode* current = _floor;
	while (current != NULL)
	{
		FloorNode* next = current->next;
		delete current->data;
		delete current;
		current = next;
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
		FloorNode* newNode = new FloorNode(_inventory[idx]);
		newNode->next = _floor; // link the rest of the list at the end of the new node
		_floor = newNode; // set the new node as the head of the list
		std::cout << GREEN "Materia " << _inventory[idx]->getType() << " unequipted successfully" RESET << std::endl;
		_inventory[idx] = NULL;  // remove the node from the inventory
	}
	else
		std::cout << RED "Invalid slot index number" RESET << std::endl;
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
