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

#include "../Include/ClapTrap.hpp"


int main()
{
	ClapTrap fury(BOLD BLUE "Fury" RESET);
	ClapTrap iron_man(BOLD RED "Iron Man" RESET);
	
	fury.setAttackDamage(5);
	fury.attack(BOLD RED "Iron man" RESET);
	iron_man.takeDamage(fury.getAttackDamage());
	iron_man.beRepaired(10);
	fury.attack(BOLD RED "Iron man" RESET);
	iron_man.takeDamage(fury.getAttackDamage());
	fury.attack(BOLD RED "Iron man" RESET);
	iron_man.takeDamage(fury.getAttackDamage());
	fury.attack(BOLD RED "Iron man" RESET);
	iron_man.takeDamage(fury.getAttackDamage());
	fury.attack(BOLD RED "Iron man" RESET);
	iron_man.takeDamage(fury.getAttackDamage());
	iron_man.beRepaired(10);
    return (0);
}
