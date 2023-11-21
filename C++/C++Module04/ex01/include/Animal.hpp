/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:43:41 by atoof             #+#    #+#             */
/*   Updated: 2023/11/20 15:52:44 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal(); // default constructor
		Animal(std::string type); // constructor overload
		Animal(const Animal &copy); // copy constructor
		virtual ~Animal(); //	Always make base classes' destructors virtual when they're meant to be manipulated polymorphically.
		
		// Operator Overloads
		Animal &operator=(const Animal &rhs); // assignment operator overload
		
		// member function
		std::string getType() const;
		virtual void makeSound() const;
};

#endif