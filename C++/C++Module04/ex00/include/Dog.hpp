/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:12:47 by atoof             #+#    #+#             */
/*   Updated: 2023/11/16 16:18:03 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		// constructor(s)
		Dog(void);
		Dog(const Dog &copy);
		~Dog(void);
		
		// operator overload
		Dog &operator=(const Dog &assigned); // assignment operator overload
		
		// member function
		void makeSound(void) const;
};

#endif