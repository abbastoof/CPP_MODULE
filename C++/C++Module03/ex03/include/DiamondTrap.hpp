/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:16:20 by atoof             #+#    #+#             */
/*   Updated: 2023/11/15 16:25:13 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string		_name;
	public:
		//constructor
		DiamondTrap(); // default constructor
		DiamondTrap(std::string name); // Constructor Overload
		DiamondTrap(const DiamondTrap &copy); // Copy constructor
		~DiamondTrap(); // Destructor
		//operator overload
		DiamondTrap &operator=(const DiamondTrap &rhs); // Assignation operator overload
		//methods
		void whoAmI(void);
};

#endif