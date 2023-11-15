/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:52:00 by atoof             #+#    #+#             */
/*   Updated: 2023/11/15 14:58:09 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	private:
		/* data */
	public:
		//constructor
		FragTrap(); // default constructor
		FragTrap(std::string name); // Constructor Overload
		FragTrap(const FragTrap &copy); // Copy constructor
		~FragTrap(); // Destructor
		//operator overload
		FragTrap &operator=(const FragTrap &rhs); // Assignation operator overload
		//methods
		void highFivesGuys(void);
};

#endif