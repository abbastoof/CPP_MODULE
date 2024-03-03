/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:40:10 by atoof             #+#    #+#             */
/*   Updated: 2024/03/03 19:06:08 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"

Base::~Base() {}

Base *generate(void)
{
	std::srand(time(NULL));
	int i = rand() % 3;
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else
		return new C;
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}
/*
	In this function, we are using dynamic_cast to check if the pointer is pointing to an object of a specific class.
	If the pointer is pointing to an object of a specific class, dynamic_cast returns a pointer to the object of that class.

	Dynamic_cast primarily used with pointers or references to objects in a class hierarchy involving virtual functions (polymorphism).
	It safely converts pointers or references up, down, or sideways along the inheritance hierarchy.
	It performs a runtime check to ensure the validity of the cast.
	If the cast is not possible (for example, casting from a base class to a derived class where the actual object is not of the derived type),
	it will return nullptr for pointers or throw std::bad_cast for references.

*/
void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (...)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch (...)
		{
			try
			{
				C &c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch (...)
			{
				std::cout << "Unknown" << std::endl;
			}
		}
	}
}
