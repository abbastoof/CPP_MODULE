/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:02:34 by atoof             #+#    #+#             */
/*   Updated: 2023/11/10 11:29:30 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed(): _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed(const int num): _fixedPointValue(num << _fractionalBits) // for example if num is 1, then 1 << 8 = 256
{
	std::cout << "Int constructor called" << std::endl;
}


/* we want to convert the float to a fixed point value, 
and we know that the fractional part of the fixed point value is 8 bits,
so we need to multiply the float by 2^8 (1 << 8) which is 256 */
Fixed::Fixed(const float num): _fixedPointValue(std::roundf(num * (1 << _fractionalBits))) // for example if num is 1.5, then 1.5 * 256 = 384, and roundf(384) = 384
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		_fixedPointValue = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPointValue = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_fixedPointValue) / (1 << _fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (static_cast<int>(std::roundf(toFloat())));
}

std::ostream &operator<<(std::ostream &out, const Fixed &rhs)
{
	return (out << rhs.toFloat());
}
