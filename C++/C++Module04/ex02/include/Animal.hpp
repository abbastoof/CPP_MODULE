/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:43:41 by atoof             #+#    #+#             */
/*   Updated: 2023/11/21 15:22:37 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class AAnimal
{
	protected:
		std::string _type;
	public:
		AAnimal(); // default constructor
		AAnimal(std::string type); // constructor overload
		AAnimal(const AAnimal &copy); // copy constructor
		virtual ~AAnimal(); //	Always make base classes' destructors virtual when they're meant to be manipulated polymorphically.
		
		// Operator Overloads
		AAnimal &operator=(const AAnimal &rhs); // assignment operator overload
		
		// member function
		std::string getType() const;
		virtual void makeSound() const = 0;
};

#endif