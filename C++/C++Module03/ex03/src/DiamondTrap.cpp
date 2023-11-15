/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:16:12 by atoof             #+#    #+#             */
/*   Updated: 2023/11/15 19:33:01 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("unknown_clap_name"), _name("unknown")
{
	std::cout << "DiamondTrap Default Constructor Called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << "DiamondTrap Constructor Called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
{
	std::cout << "DiamondTrap Copy Constructor Called" << std::endl;
	*this = copy;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor Called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	std::cout << "DiamondTrap Assignment Operator Called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "My DiamondTrap name is: " << this->_name << std::endl;
	std::cout << "My ClapTrap name is: " << ClapTrap::_name << std::endl;
}

void DiamondTrap::reportStatus(void) const
{
	std::cout << "\n\n--- DiamondTrap Status Report ---" << std::endl;
	std::cout << "\n|" << BOLD << "ClapTrap" << RESET << "|" << std::endl;
	std::cout << "Name: " << ClapTrap::_name << std::endl;
	std::cout << "Hit Points: " << ClapTrap::_hitPoints << std::endl;
	std::cout << "Energy Points: " << ClapTrap::_energyPoints << std::endl;
	std::cout << "Attack Damage: " << ClapTrap::_attackDamage << std::endl;
	std::cout << "\n---------------------------------\n" << std::endl;
}