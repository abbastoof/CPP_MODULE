/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:05:10 by atoof             #+#    #+#             */
/*   Updated: 2023/10/26 16:21:55 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );

int main(void)
{
	int N;
	std::string name;

	std::cout << "Enter a name for your zombie horde: " << std::flush;
	std::getline(std::cin, name);
	std::cout << "Enter the number of zombies in your horde: " << std::flush;
	std::cin >> N;
	Zombie *zombie = zombieHorde(N, name);
	for (int i = 0; i < N; i++)
		zombie[i].announce();
	delete [] zombie;
	return (0);
}