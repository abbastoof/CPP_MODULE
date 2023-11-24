/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:34:42 by atoof             #+#    #+#             */
/*   Updated: 2023/11/24 17:28:44 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"


int		main(void)
{
	std::string name;
	
	std::cout << "Enter a name for your zombie: " << std::flush;
	std::getline(std::cin, name);
	Zombie *zombie = newZombie(name); //on heap
	zombie->announce();
	std::cout << "Zombie " << name << " is on the heap." << std::endl;
	std::cout << "Enter a name for your zombie: " << std::flush;
	std::getline(std::cin, name);
	randomChump(name); //on stack
	delete zombie;
	return (0);
}