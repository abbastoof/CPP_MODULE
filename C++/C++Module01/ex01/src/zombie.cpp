/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:05:16 by atoof             #+#    #+#             */
/*   Updated: 2023/10/26 16:22:30 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/zombie.hpp"

Zombie::Zombie(void)
{
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << this->_name << " is dead." << std::endl;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << "<" << this->_name << "> Braiiiiiiinnnssss..." << std::endl;
	return ;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
	return ;
}