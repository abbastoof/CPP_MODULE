/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:06:49 by atoof             #+#    #+#             */
/*   Updated: 2023/12/10 17:50:33 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/IMateriaSource.hpp"
#include "../include/MateriaSource.hpp"
#include "../include/Character.hpp"
#include "../include/Cure.hpp"
#include "../include/Ice.hpp"

int main()
{
	// IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	// ICharacter* me = new Character("me");
	// AMateria* tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = NULL;
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// tmp = NULL;
	// ICharacter* bob = new Character("bob");
	// me->use(0, *bob);
	// me->use(1, *bob);
	// delete bob;
	// delete me;
	// delete src;
	//=======================================================//
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = NULL;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = NULL;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);
	me->unequip(4);
	delete bob;
	delete me;
	delete src;
	return 0;
}