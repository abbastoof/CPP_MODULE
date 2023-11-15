/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:20:26 by atoof             #+#    #+#             */
/*   Updated: 2023/11/15 19:42:13 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

// Constructor and Destructor
ScavTrap::ScavTrap() : ClapTrap() // default constructor
{
	this->_name = "unknown";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap Default Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(std::string nameVal) : ClapTrap(nameVal) //Constructor overload
{
	std::cout << "ScavTrap " << nameVal << " Constructor Called" <<std::endl;
	this->_name = nameVal;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy) // Copy constructor
{
	std::cout << "ScavTrap " << copy._name << " Copy Constructor Called" << std::endl;
	*this = copy;
}

ScavTrap::~ScavTrap() // Destructor
{
	std::cout << "ScavTrap Destructor Called" << std::endl;
}

// Operator Overloads
ScavTrap	&ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << "ScavTrap Assignment Operator Called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

// Member Functions
void ScavTrap::attack(std::string const &target)
{
	if (this->_energyPoints <= 0)
		std::cout << "ScavTrap " <<this->_name << " has no energy points left to attack!" << std::endl;
	if (this->_hitPoints <= 0)
		std::cout << "ScavTrap " << this->_name << " has no hit points left to attack!" << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	}
}

void ScavTrap::guardGate()
{
	if (this->_energyPoints <= 0)
		std::cout << "ScavTrap " << this->_name << " has no energy points left to guard the gate!" << std::endl;
	if (this->_hitPoints <= 0)
		std::cout << "ScavTrap " << this->_name << " has no hit points left to guard the gate!" << std::endl;
	else
		{
			std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
			this->_energyPoints -= 1;
		}
}
