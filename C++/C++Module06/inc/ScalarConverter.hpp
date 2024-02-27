/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:39:10 by atoof             #+#    #+#             */
/*   Updated: 2024/02/10 14:06:33 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string> // for std::string and std::stoi and std::stof and std::stod
# include <limits> // for std::numeric_limits and std::isnan and std::isinf
# include <cstdlib> // for std::atof
# include <cfloat> // for FLT_MAX, FLT_MIN, DBL_MAX, DBL_MIN
# include <math.h> // for NAN

/*
Conversion of scalar types Files to turn in : Makefile, *.cpp, *.{h, hpp}
Write a class ScalarConverter that will contain only one static methods "convert" that will takes as parameter a string representation of a C++ literal in its most common form and output its value in the following serie of scalar types :
• char
• int
• float
• double
As this class doesn’t need to store anything at all, this class must not be instanciable by users.
Except for char parameters, only the decimal notation will be used.
Examples of char literals: ’c’, ’a’, ...
To make things simple, please note that non displayable characters shouldn’t be used as inputs. If a conversion to char is not displayable, prints an informative message.
Examples of int literals: 0, -42, 42... Examples of float literals: 0.0f, -4.2f, 4.2f...
You have to handle these pseudo literals as well (you know, for science): -inff, +inff and nanf.
Examples of double literals: 0.0, -4.2, 4.2...
You have to handle these pseudo literals as well (you know, for fun): -inf, +inf and nan.
Turn-in directory : ex00/
Allowed functions : Any function to convert from a string to an int, a float or a double. This will help, but won’t do the whole job.

*/

class ScalarConverter
{
	private:
		ScalarConverter(void);
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& rhs);

		ScalarConverter & operator=(const ScalarConverter& rhs);
		enum Type
		{
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			NAN,
			INF,

		};
	public:
		static void convert(std::string const & input);
};
