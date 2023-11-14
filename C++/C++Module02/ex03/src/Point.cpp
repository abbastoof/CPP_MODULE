/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:22:30 by atoof             #+#    #+#             */
/*   Updated: 2023/11/10 15:45:14 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const Point &copy) : x(copy.x), y(copy.y) // copy constructor
{
}

Point::Point(const float x, const float y) : x(x), y(y) // constructor that takes two float arguments that will be used to set the x and y coordinates
{
}

Point::~Point() // destructor
{
}

Point &Point::operator=(const Point &rhs)
{
	if (this != &rhs)
	{
		const_cast<Fixed&>(this->x) = rhs.x;
		const_cast<Fixed&>(this->y) = rhs.y;
	}
	return (*this);
}

Fixed	Point::getX(void) const // returns the x coordinate
{
	return (this->x);
}

Fixed	Point::getY(void) const // returns the y coordinate
{
	return (this->y);
}