/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:10:41 by atoof             #+#    #+#             */
/*   Updated: 2023/11/16 15:12:17 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

int main(void)
{
	DiamondTrap	*p1 = new DiamondTrap("NO NAME");
	p1->attack("Fury");
	p1->whoAmI();
	delete p1;

	DiamondTrap diamondTrap("monster");
	diamondTrap.whoAmI();
	diamondTrap.reportStatus();
	diamondTrap.attack("target");
	diamondTrap.takeDamage(10);
	diamondTrap.beRepaired(10);
	diamondTrap.guardGate();
	diamondTrap.highFivesGuys();
	diamondTrap.reportStatus();
	return (0);
}