/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:03:50 by atoof             #+#    #+#             */
/*   Updated: 2023/11/13 19:03:50 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

// Constructor and Destructor

ClapTrap::ClapTrap() : _name("unknown"), _hitPoints(10), _energyPoints(10), _attackDamage(0) // default constructor
{
	std::cout << "ClapTrap Default Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) // parameter constructor
{
    std::cout << "ClapTrap " << this->_name << " has been created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) // Copy Constructor
{
	std::cout << "ClapTrap copy Constructor Called" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap() // Destructor
{
	std::cout << "ClapTrap Destructor for " << this->_name << " Called " << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) // Assignation operator overload
{
	std::cout << "ClapTrap assignation operator Called" << std::endl;
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return (*this);
}

// Member functions

void ClapTrap::attack(const std::string &target)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    }
    else if (this->_energyPoints == 0)
        std::cout << "ClapTrap " << this->_name << " is not able to attack " << target << ", because he has no energy points left." << std::endl;
    else
        std::cout << "ClapTrap " << this->_name << " is not able to attack " << target << ", because he has not enough hit points." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead" << std::endl;
		return ;
	}
	if (this->_hitPoints <= amount)
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
		this->_hitPoints -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0 && this->_hitPoints + amount <= 10) // The ClapTrap can't be repaired to have more than 10 hit points
	{
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " repaired itself and gained " << amount << " of hit points, he now has " << this->_hitPoints << " hit points." << std::endl;
		this->_energyPoints--;
	}
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " is not able to repair itself, because he doesn't have enough energy points." << std::endl;
	else if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " is not able to repair itself, because he doesn't have enough hit points." << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " can't be repaired to have more than 10 hit points." << std::endl;
}

int ClapTrap::getAttackDamage() const
{
	return (this->_attackDamage);
}

void ClapTrap::setAttackDamage(unsigned int amount)
{
	this->_attackDamage = amount;
}