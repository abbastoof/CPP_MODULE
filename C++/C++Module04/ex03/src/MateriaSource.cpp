/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:07:42 by atoof             #+#    #+#             */
/*   Updated: 2023/12/08 18:14:02 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"
#include "../include/AMateria.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &rhs)
{
	std::cout << "MateriaSource Copy constructor called" << std::endl;
	if (this != &rhs)
		*this = rhs;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	std::cout << "MateriaSource Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] != NULL)
				delete this->_inventory[i];
		}
		for (int i = 0; i < 4; i++)
		{
			if (rhs._inventory[i] != NULL)
				this->_inventory[i] = rhs._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}	
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete (this->_inventory[i]);
	}
}

void MateriaSource::learnMateria(AMateria* learnMaterial)
{
	if (learnMaterial != NULL)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] == NULL)
			{
				this->_inventory[i] = learnMaterial;
				std::cout << GREEN "Learned " << learnMaterial->getType() << " successfully" RESET << std::endl;
				break;
			}
		}
	}
	else
		std::cout << RED "Material is NULL" RESET << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	AMateria* tmp = NULL;
	if (!type.empty())
	{
		for (int index = 0; index < 4;index++)
		{
			if (this->_inventory[index] != NULL && \
			!_inventory[index]->getType().compare(type))
			{
				tmp = _inventory[index]->clone();
				std::cout << GREEN "Created " << type << " successfully" RESET << std::endl;
				break;
			}
		}
	}
	else
		std::cout << RED "Materia type is empty the result is NULL" RESET << std::endl;
	return (tmp);
}
