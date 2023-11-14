/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:03:44 by atoof             #+#    #+#             */
/*   Updated: 2023/11/13 19:03:44 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"


int main()
{
	ScavTrap fury(BOLD BLUE "Fury" RESET);
	ScavTrap iron_man(BOLD RED "Iron Man" RESET);

	fury.attack(BOLD RED "Iron man" RESET);
	iron_man.takeDamage(fury.getAttackDamage());
	fury.setAttackDamage(50);
	fury.attack(BOLD RED "Iron man" RESET);
	iron_man.takeDamage(fury.getAttackDamage());
	fury.attack(BOLD RED "Iron man" RESET);
	iron_man.takeDamage(fury.getAttackDamage());
	fury.attack(BOLD RED "Iron man" RESET);
	iron_man.takeDamage(fury.getAttackDamage());
	iron_man.guardGate();
    return (0);
}
