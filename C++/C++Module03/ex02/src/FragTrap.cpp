/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:51:26 by atoof             #+#    #+#             */
/*   Updated: 2023/11/15 17:21:23 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

// Constructor and Destructor

FragTrap::FragTrap() : ClapTrap() // default constructor
{
	this->_name = "unknown";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap Default Constructor Called" << std::endl;
}

FragTrap::FragTrap(std::string nameVal) : ClapTrap(nameVal) // Constructor overload
{
	std::cout << "FragTrap " << nameVal << " Constructor Called" << std::endl;
	this->_name = nameVal;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) // Copy constructor
{
	std::cout << "FragTrap " << copy._name << " Copy Constructor Called" << std::endl;
	*this = copy;
}

FragTrap::~FragTrap() // Destructor
{
	std::cout << "FragTrap Destructor Called" << std::endl;
}

// Operator Overloads

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	std::cout << "FragTrap Assignment Operator Called" << std::endl;
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

void FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints > 0)
		std::cout << "FragTrap " << this->_name << " requests a high five!" << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " is dead and cannot request a high five!" << std::endl;
}