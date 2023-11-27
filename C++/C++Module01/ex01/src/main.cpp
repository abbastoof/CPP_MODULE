/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:05:10 by atoof             #+#    #+#             */
/*   Updated: 2023/11/27 13:15:46 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );

static int my_atoi(std::string str)
{
	int i = 0;
	if (str.at(i) == '-' || str.empty())
		throw std::invalid_argument("Invalid argument");
	else if ((i == 0) && str.at(i) == '+')
		i++;
	while (i < (int)str.length())
	{
		if (!isdigit(str.at(i)))
			throw std::invalid_argument("Invalid argument");
		i++;
	}
	return (atoi(str.c_str()));
}

int main(void)
{
	std::string N;
	int n;
	std::string name;

	std::cout << "Enter a name for your zombie horde: " << std::flush;
	std::getline(std::cin, name);
	std::cout << "Enter the number of zombies in your horde: " << std::flush;
	std::cin >> N;
	try 
	{
		n = my_atoi(N);
		if (n <= 0 || n > 20)
		{
            std::cout << "Invalid number of zombies. Must be greater than 0 and less than or equal to 20." << std::endl;
            return -1;
		}
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << "Invalid argument: " << e.what() << std::endl;
        return -1;
	}
	catch (...)
	{
		std::cout << "Unexpected exception occurred" << std::endl;
        return -1;
	}
	Zombie *zombie = zombieHorde(n, name);
	for (int i = 0; i < n; i++)
		zombie[i].announce();
	delete [] zombie;
	return (0);
}