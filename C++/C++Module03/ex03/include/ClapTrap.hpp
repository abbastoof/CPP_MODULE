/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:03:47 by atoof             #+#    #+#             */
/*   Updated: 2023/11/13 19:03:47 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

// Text formatting definitions
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define ITALIC  "\033[3m"

// Color definitions
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define WEAK    "\033[90m"  // Light grey

class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	public:
		ClapTrap(); // default constructor
		ClapTrap(std::string name); // Constructor Overload
		ClapTrap(const ClapTrap &copy); // Copy constructor
		virtual ~ClapTrap(); // Destructor ,why it should be virtual? https://stackoverflow.com/questions/461203/when-to-use-virtual-destructors
		ClapTrap &operator=(const ClapTrap &copy); // Assignation operator overload
		virtual void attack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		// my own test
		int getAttackDamage() const;
		void setAttackDamage(unsigned int amount);

};

#endif
