/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:14:45 by atoof             #+#    #+#             */
/*   Updated: 2023/10/31 12:09:57 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					_fixedPointValue; // fixed point value
	static const int	_fractionalBits = 8; // number of fractional bits
public:
	Fixed(); // default constructor
	~Fixed(); // destructor
	Fixed(const Fixed &rhs); // this is a copy constructor that creates a copy of the object passed as a parameter to the constructor
	Fixed& operator=(const Fixed &rhs); // this is an assignation operator overload that assigns a new value to the fixed point value
	int		getRawBits(void) const; // returns the raw value of the fixed point value
	void	setRawBits(int const raw); // sets the raw value of the fixed point value
};


#endif