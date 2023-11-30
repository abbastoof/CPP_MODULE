/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:59:50 by atoof             #+#    #+#             */
/*   Updated: 2023/11/16 15:33:03 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
}

Fixed::Fixed(const Fixed &rhs) // copy constructor
{
	*this = rhs;
}

Fixed::Fixed(const int value) : _fixedPointValue(value << _fractionalBits) // for int, we are shifting the bits to the left by the number of fractional bits to get the fixed point value
{
}

Fixed::Fixed(const float value) : _fixedPointValue(std::roundf(value * (1 << _fractionalBits)))
{
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(_fixedPointValue) / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> _fractionalBits);
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	if (this == &rhs) // self-assignment check
		return (*this);
	this->_fixedPointValue = rhs.getRawBits();
	return (*this); // we dereference this pointer to return the object itself
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
	Fixed result;
	
	result.setRawBits(this->getRawBits() + rhs.getRawBits()); //we are calling the setRawBits function of the result object and passing the sum of the fixed point values of the two objects
	return (result); //we return a copy of the object because we don't want to change the value of the object itself.
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	Fixed result;
	
	result.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (result);
}

// Fixed Fixed::operator/(const Fixed &rhs) const
// {
// 	Fixed result;
	
// 	result.setRawBits(this->getRawBits() / rhs.getRawBits() * (1 << _fractionalBits));
// 	return (result);
// }

Fixed Fixed::operator/(const Fixed &rhs) const
{
    Fixed result;

    // Use long long for intermediate calculation
    long long numerator = static_cast<long long>(this->getRawBits());
    long long denominator = rhs.getRawBits();

    // Perform the division with 64-bit precision
    result.setRawBits(static_cast<int>((numerator << _fractionalBits) / denominator));
    return result;
}

// Fixed Fixed::operator*(const Fixed &rhs) const
// {
// 	Fixed result;
	
// 	result.setRawBits(this->getRawBits() * rhs.getRawBits() / (1 << _fractionalBits));
// 	return (result);
// }

Fixed Fixed::operator*(const Fixed &rhs) const
{
    Fixed result;

    // Use long long for intermediate calculation
    long long product = static_cast<long long>(this->getRawBits()) * rhs.getRawBits();

    // Perform the division with 64-bit precision
    result.setRawBits(static_cast<int>(product / (1 << _fractionalBits)));
    return result;
}

std::ostream &operator<<(std::ostream &out, const Fixed &rhs)
{
	out << rhs.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

Fixed &Fixed::operator++() // pre-increment operator overload, why is this a reference? because we are returning the object itself, we don't have arg bcause hidden arg is *this
{
	this->_fixedPointValue++;
	return (*this);
}

Fixed &Fixed::operator--() // pre-decrement operator overload, why is this a reference? because we are returning the object itself
{
	this->_fixedPointValue--;
	return (*this);
}

Fixed Fixed::operator++(int) // post-increment operator overload
{
	Fixed temp = *this; // we are creating a copy of the object
	++(this->_fixedPointValue); // we are incrementing the object itself
	return (temp); // we are returning the copy of the object
}

Fixed Fixed::operator--(int) // post-decrement operator overload
{
	Fixed temp = *this; // we are creating a copy of the object
	--(this->_fixedPointValue); // we are decrementing the object itself
	return (temp); // we are returning the copy of the object
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}
