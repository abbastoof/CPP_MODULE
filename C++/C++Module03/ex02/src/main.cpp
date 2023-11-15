/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:59:54 by atoof             #+#    #+#             */
/*   Updated: 2023/11/15 15:07:52 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

int main(){
	FragTrap fragTrap(BOLD RED "FragTrap 1" RESET);
	FragTrap fragTrap2(BOLD BLUE "FragTrap 2" RESET);
	
	fragTrap.attack("FragTrap 2");
	fragTrap2.takeDamage(fragTrap.getAttackDamage());
	fragTrap2.highFivesGuys();
	fragTrap2.beRepaired(10);
	fragTrap2.setAttackDamage(50);
	fragTrap2.attack("FragTrap 1");
	fragTrap.takeDamage(fragTrap2.getAttackDamage());
	fragTrap.highFivesGuys();
	fragTrap2.attack("FragTrap 1");
	fragTrap.takeDamage(fragTrap2.getAttackDamage());
	fragTrap.highFivesGuys();
	fragTrap.beRepaired(10);
	fragTrap.attack("FragTrap 2");
	fragTrap2.highFivesGuys();
	return (0);
}