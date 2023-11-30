/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:22:33 by atoof             #+#    #+#             */
/*   Updated: 2023/11/10 15:25:56 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point(); // default constructor
		Point(const Point &copy); // copy constructor
		Point(const float x, const float y); // constructor that takes two float arguments that will be used to set the x and y coordinates
		~Point(); // destructor
		Point &operator=(const Point &copy); // assignment operator overload
		Fixed getX(void) const; // returns the x coordinate
		Fixed getY(void) const; // returns the y coordinate
		void	setX(Fixed &fixed_x);
		void	setY(Fixed &fixed_y);

		
};

std::ostream &operator<<(std::ostream &out, const Point &rhs); // insertion operator overload
bool bsp(Point const a, Point const b, Point const c, Point const point); // returns true if the point is inside the triangle, or false if it's not

#endif