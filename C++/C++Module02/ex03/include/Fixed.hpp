/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:59:46 by atoof             #+#    #+#             */
/*   Updated: 2023/11/10 16:26:58 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath> // for roundf()

class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8; // 8 bits after the decimal point
	public:

		// constructors and destructor
		Fixed(); // default constructor
		Fixed(const Fixed &copy); // copy constructor
		Fixed(const int value); // constructor from int
		Fixed(const float value); // constructor from float
		~Fixed(); // destructor

		// assignment operator overloads		
		Fixed &operator=(const Fixed &rhs); // assignment operator overload, why reference? because we are returning the object itself
		Fixed operator+(const Fixed &rhs) const; // assignment operator overload
		Fixed operator-(const Fixed &rhs) const;// assignment operator overload
		Fixed operator/(const Fixed &rhs) const;// assignment operator overload
		Fixed operator*(const Fixed &rhs) const;// assignment operator overload
		
		
		// operator overloads
		bool operator>(const Fixed &copy) const;
		bool operator<(const Fixed &copy) const;
		bool operator>=(const Fixed &copy) const;
		bool operator<=(const Fixed &copy) const;
		bool operator==(const Fixed &copy) const;
		bool operator!=(const Fixed &copy) const;
		Fixed &operator++(); // pre-increment operator overload, why is this a reference? because we are returning the object itself, why we don't have arg bcause hidden arg is *this
		Fixed operator++(int); // post-increment operator overload, why is this not a reference? because we are returning a copy of the object
		Fixed &operator--(); // pre-decrement operator overload, why is this a reference? because we are returning the object itself
		Fixed operator--(int); // post-decrement operator overload, why is this not a reference? because we are returning a copy of the object
		
		// member functions
		int getRawBits(void) const; // returns the raw value of the fixed point value
		void setRawBits(int const raw); // sets the raw value of the fixed point value
		float toFloat(void) const; // converts the fixed point value to a floating point value
		int toInt(void) const; // converts the fixed point value to an integer value

		// static member functions
		static Fixed &min(Fixed &a, Fixed &b); // returns the minimum of a and b
		static Fixed &max(Fixed &a, Fixed &b); // returns the maximum of a and b
		static const Fixed &min(const Fixed &a, const Fixed &b); // returns the minimum of a and b
		static const Fixed &max(const Fixed &a, const Fixed &b); // returns the maximum of a and b
};

 // insertion operator overload
std::ostream &operator<<(std::ostream &out, const Fixed &rhs);

#endif