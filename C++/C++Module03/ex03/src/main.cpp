/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:10:41 by atoof             #+#    #+#             */
/*   Updated: 2023/11/15 19:38:00 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

int main(void)
{
	DiamondTrap diamondTrap("DiamondTrap");
	diamondTrap.whoAmI();
	diamondTrap.attack("target");
	diamondTrap.takeDamage(10);
	diamondTrap.beRepaired(10);
	diamondTrap.guardGate();
	diamondTrap.highFivesGuys();
	diamondTrap.reportStatus();
	return (0);
}