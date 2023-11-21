/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:12:54 by atoof             #+#    #+#             */
/*   Updated: 2023/11/21 15:23:35 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain *brain;
	public:
		Cat(void);
		Cat(const Cat &copy);
		~Cat(void);
		Cat &operator=(const Cat &assigned);
		virtual void makeSound(void) const;
		std::string getType(void) const;
		//MyTest
		void setIdea(int index, std::string idea);
		std::string getIdea(int index) const;
};

#endif