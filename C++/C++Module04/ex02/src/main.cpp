/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:34:58 by atoof             #+#    #+#             */
/*   Updated: 2023/11/21 15:42:35 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"

int main()
{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	delete j;
	delete i;
// My test
	std::cout << "My test" << std::endl;
	const AAnimal* animal[20];
	
	for (int i = 0; i < 20; i++)
	{
		if (i % 2 == 0)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}
	for (int i = 0; i < 20; i++)
		animal[i]->makeSound();
	Cat cat1;
	std::stringstream ss;
	for (int i = 0; i < 20; i++)
	{
		// std::cout << "Cat idea " << i << ": ";
		ss << "Cat idea " << i;
		cat1.setIdea(i, ss.str());
		ss.str("");
		// std::cout << cat.getIdea(i) << std::endl;
	}
	Cat cat2;
	std::cout << "cat2 idea = " << cat2.getIdea(3) << std::endl;
	cat2 = cat1;
	std::cout << cat1.getIdea(0) << std::endl;
	std::cout << cat1.getIdea(1) << std::endl;
	std::cout << cat1.getIdea(3) << std::endl;
	std::cout << "cat2 idea = " << cat2.getIdea(3) << std::endl;
	for (int i = 0; i < 20; i++)
		delete animal[i];
	
	return (0);
}