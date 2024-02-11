/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:34:29 by atoof             #+#    #+#             */
/*   Updated: 2024/02/11 19:00:31 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal)
{
    TYPE type = getType(literal);
    switch (type)
	{
        case CHAR: convertToChar(literal); break;
        case INT: convertToInt(literal); break;
        case FLOAT: convertToFloat(literal); break;
        case DOUBLE: convertToDouble(literal); break;
        case NAN_VALUE: case INFPOS: case INFNEG: handleSpecialValues(type); break;
        default: std::cerr << "Error: Unsupported or invalid type/value" << std::endl;
    }
}

TYPE ScalarConverter::getType(const std::string& scalar)
{
    if (scalar == "nan") return NAN_VALUE;
    if (scalar == "inf" || scalar == "+inf" || scalar == "inff" || scalar == "+inff") return INFPOS;
    if (scalar == "-inf" || scalar == "-inff") return INFNEG;

    if (scalar.size() == 1 && std::isprint(scalar[0])) return CHAR;
    try {
        if (scalar.find('.') != std::string::npos || scalar.find('f') != std::string::npos)
		{
            std::stof(scalar);
            	return FLOAT;
            std::stod(scalar);
            	return DOUBLE;
        }
		else
		{
            std::stoi(scalar);
            return INT;
        }
    }
	catch (...) {}
    return NONE;
}

void ScalarConverter::convertToChar(const std::string scalar)
{
	char c = scalar[0];
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertToInt(const std::string scalar)
{
	int i = std::stoi(scalar);
	std::cout << "char: ";
	if (std::isprint(i))
		std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void ScalarConverter::convertToFloat(const std::string scalar)
{
    try {
        float f = std::stod(scalar);
        std::cout << "char: ";
        if (std::isprint(static_cast<int>(f)))
            std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
        std::cout << "int: ";
        if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
            std::cout << static_cast<int>(f) << std::endl;
        else
            std::cout << "impossible" << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    } catch (const std::invalid_argument&) {
        std::cerr << "Error: Invalid argument for conversion to float" << std::endl;
    }
}

void ScalarConverter::convertToDouble(const std::string scalar)
{
	try {
		double d = std::stod(scalar);
		std::cout << "char: ";
		if (std::isprint(static_cast<int>(d)))
			std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		std::cout << "int: ";
		if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
			std::cout << static_cast<int>(d) << std::endl;
		else
			std::cout << "impossible" << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	} catch (const std::invalid_argument&) {
		std::cerr << "Error: Invalid argument for conversion to double" << std::endl;
	}
}

void ScalarConverter::handleSpecialValues(TYPE type)
{
    std::cout << "char: impossible\nint: impossible\n";
    switch (type)
	{
        case NAN_VALUE: std::cout << "float: nanf\ndouble: nan" << std::endl; break;
        case INFPOS: std::cout << "float: inff\ndouble: inf" << std::endl; break;
        case INFNEG: std::cout << "float: -inff\ndouble: -inf" << std::endl; break;
        default: std::cerr << "Error: Unknown special value type" << std::endl;
    }
}
