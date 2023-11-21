/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:15:01 by atoof             #+#    #+#             */
/*   Updated: 2023/11/20 13:52:05 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &assigned) // assignment operator overload
{
	std::cout << "WrongCat assignment operator called" << std::endl;
	this->_type = assigned.getType();
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << this->getType() << " Meoooooowwwwwwww" << std::endl;
}

std::string WrongCat::getType() const
{
	return (this->_type);
}