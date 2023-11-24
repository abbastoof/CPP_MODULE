/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:34:17 by atoof             #+#    #+#             */
/*   Updated: 2023/11/24 17:28:39 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	public: 
		Zombie(std::string name);
		~Zombie();
		void	announce(void);
	private:
		std::string	_name;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif