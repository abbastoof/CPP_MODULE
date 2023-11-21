/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:12:47 by atoof             #+#    #+#             */
/*   Updated: 2023/11/20 16:03:11 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		// constructor(s)
		Dog(void);
		Dog(const Dog &copy);
		~Dog(void);
		
		// operator overload
		Dog &operator=(const Dog &assigned); // assignment operator overload
		
		// member function
		virtual void makeSound(void) const;
		std::string getType(void) const;
		void setIdea(int index, std::string idea);
		std::string getIdea(int index) const;
};

#endif