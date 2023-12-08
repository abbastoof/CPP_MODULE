/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:12:50 by atoof             #+#    #+#             */
/*   Updated: 2023/12/08 16:40:38 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:

	public:
		// constructor(s)
		WrongCat(void); // default constructor
		WrongCat(const WrongCat &copy); // copy constructor
		~WrongCat(void); // destructor

		//operator overload
		WrongCat &operator=(const WrongCat &assigned); // assignment operator overload
		
		// member function
		void makeSound(void) const;
		std::string getType(void) const;
};

#endif