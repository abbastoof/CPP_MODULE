/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:11:45 by atoof             #+#    #+#             */
/*   Updated: 2023/11/16 14:53:31 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		// Constructor and Destructor
		ScavTrap(); // default constructor
		ScavTrap(std::string nameVal); // Constructor Overload
		ScavTrap(const ScavTrap &copy); // Copy constructor
		~ScavTrap(); // Destructor
		
		// Operator Overloads
		ScavTrap &operator=(const ScavTrap &rhs); // Assignation operator overload
		
		// Member Functions
		virtual void attack(std::string const &target);
		void guardGate();
		void setEnergyPoints(void);
};

#endif