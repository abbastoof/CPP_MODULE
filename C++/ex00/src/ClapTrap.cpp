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

#include "../Include/ClapTrap.hpp"

// Constructor and Destructor

ClapTrap::ClapTrap() : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) // default constructor
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) // Constructor Overload
{
    std::cout << BOLD << ITALIC << CYAN << "ClapTrap " << this->_name << " has been created" RESET << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap &copy) // Copy Constructor
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap() // Destructor
{
	std::cout << BOLD "ClapTrap destructor for " << BOLD BLUE << this->_name << RESET << BOLD << " called " RESET << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) // Assignation operator overload
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
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
        std::cout << BOLD << CYAN << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << RESET << std::endl;
        this->_energyPoints--;
    }
    else if (this->_energyPoints == 0)
        std::cout << BOLD << RED << "ClapTrap " << this->_name << " is not able to attack " << target << ", because he has no energy points left." << RESET << std::endl;
    else
        std::cout << BOLD << RED << "ClapTrap " << this->_name << " is not able to attack " << target << ", because he has not enough hit points." << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << ITALIC BOLD RED "ClapTrap " << this->_name << " is already dead" RESET << std::endl;
		return ;
	}
	if (this->_hitPoints <= amount)
	{
		std::cout << BOLD MAGENTA "ClapTrap " << this->_name << " takes " << this->_hitPoints << " points of damage!" RESET << std::endl;
		this->_hitPoints = 0;
		std::cout << BOLD RED "ClapTrap " << this->_name << " is dead" RESET << std::endl;
	}
	else
	{
		std::cout << BOLD MAGENTA "ClapTrap " << this->_name << " takes " << amount << " points of damage!" RESET << std::endl;
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
		std::cout << "\033[31mClapTrap " << this->_name << " is not able to repair itself, because he doesn't have enough energy points.\033[0m" << std::endl;
	else if (this->_hitPoints == 0)
		std::cout << "\033[31mClapTrap " << this->_name << " is not able to repair itself, because he doesn't have enough hit points.\033[0m" << std::endl;
	else
		std::cout << "\033[33mClapTrap " << this->_name << " can't be repaired to have more than 10 hit points.\033[0m" << std::endl;
}
