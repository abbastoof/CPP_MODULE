/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:57:19 by atoof             #+#    #+#             */
/*   Updated: 2024/02/11 14:00:12 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
	if (this != &src)
	{
		*this = src;
	}
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(std::string const &literal)
{
	TYPE type = getType(literal);
	printType(type);
	switch (type)
	{
	case CHAR:
		convertToChar(literal);
		break;
	case INT:
		convertToInt(literal);
		break;
	case FLOAT:
		convertToFloat(literal);
		break;
	case DOUBLE:
		convertToDouble(literal);
		break;
	case NAN_VALUE:
		std::cout << "char: impossible" << std::endl
				  << "int: impossible" << std::endl
				  << "float: nanf" << std::endl
				  << "double: nan" << std::endl;
		break;
	case INFPOS:
		std::cout << "char: impossible" << std::endl
				  << "int: impossible" << std::endl
				  << "float: inff" << std::endl
				  << "double: inf" << std::endl;
		break;
	case INFNEG:
		std::cout << "char: impossible" << std::endl
				  << "int: impossible" << std::endl
				  << "float: -inff" << std::endl
				  << "double: -inf" << std::endl;
		break;
	default:
		break;
	}
}

TYPE ScalarConverter::getType(const std::string scalar)
{
	if (scalar.length() == 1 && !isdigit(scalar[0]))
		return CHAR;
	try
	{
		if (scalar == "nan" || scalar == "nanf")
			return NAN_VALUE;
		if (scalar == "inf" || scalar == "inff")
			return INFPOS;
		if (scalar == "-inf" || scalar == "-inff") 
			return INFNEG;
		std::stod(scalar);
	}
	catch (std::exception &e)
	{
		return NONE;
	}
	if (scalar.find('.') != std::string::npos && scalar.find('f') != std::string::npos)
		return FLOAT;
	if (scalar.find('.') != std::string::npos)
		return DOUBLE;
	return INT;
}

void ScalarConverter::convertToChar(const std::string scalar)
{
	char c = 0;
	try
	{
		c = std::stoi(scalar);
		if (isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "char: impossible" << std::endl;
	}
}

void ScalarConverter::convertToInt(const std::string scalar)
{
	int i = 0;
	try
	{
		i = std::stoi(scalar);
		std::cout << "int: " << i << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "int: impossible" << std::endl;
	}
}

void ScalarConverter::convertToFloat(const std::string scalar)
{
	float f = 0;
	try
	{
		f = std::stof(scalar);
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "float: impossible" << std::endl;
	}
}

void ScalarConverter::convertToDouble(const std::string scalar)
{
	double d = 0;
	try
	{
		d = std::stod(scalar);
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "double: impossible" << std::endl;
	}
}

void ScalarConverter::printType(const TYPE type)
{
	switch (type)
	{
	case CHAR:
		std::cout << "char: ";
		break;
	case INT:
		std::cout << "int: ";
		break;
	case FLOAT:
		std::cout << "float: ";
		break;
	case DOUBLE:
		std::cout << "double: ";
		break;
	default:
		break;
	}
}