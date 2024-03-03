/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:34:29 by atoof             #+#    #+#             */
/*   Updated: 2024/03/03 18:46:49 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal)
{
	TYPE type = getType(literal);
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
	case INFPOS:
	case INFNEG:
		handleSpecialValues(type);
		break;
	default:
		std::cerr << "Error: Unsupported or invalid type/value" << std::endl;
	}
}

TYPE ScalarConverter::getType(const std::string &scalar)
{
	if (std::regex_match(scalar, std::regex("^nan$"))) {return NAN_VALUE;}
	if (std::regex_match(scalar, std::regex("^(\\+)?inf(f)?$"))) {return INFPOS;}
	if (std::regex_match(scalar, std::regex("^-inf(f)?$"))) {return INFNEG;}
	if (std::regex_match(scalar, std::regex("^[^0-9]?$")) && scalar.size() == 1) { return CHAR;}
	if (std::regex_match(scalar, std::regex("^[+-]?\\d+\\.\\d+f$"))) {return FLOAT;}
	if (std::regex_match(scalar, std::regex("^[+-]?\\d*\\.\\d+$"))) {return DOUBLE;}
	if (std::regex_match(scalar, std::regex("^[+-]?\\d+$"))) {return INT;}
	return NONE;
}


// TYPE ScalarConverter::getType(const std::string &scalar)
// {
// 	if (scalar == "nan")
// 		return NAN_VALUE;
// 	if (scalar == "inf" || scalar == "+inf" || scalar == "inff" || scalar == "+inff")
// 		return INFPOS;
// 	if (scalar == "-inf" || scalar == "-inff")
// 		return INFNEG;

// 	if (scalar.size() == 1 && std::isprint(scalar[0]) && !std::isdigit(scalar[0]))
// 		return CHAR;

// 	bool hasDot = false;
// 	bool hasF = false;
// 	bool hasDigitAfterDot = false;
// 	bool hasDigit = false;
// 	for (size_t i = 0; i < scalar.size(); ++i)
// 	{
// 		if (scalar[i] == '.' && !hasDot && i != 0 && i != scalar.size() - 1) // if it has a dot and it's not the first or last character
// 		{
// 			hasDot = true;
// 			if (i + 1 < scalar.size() && std::isdigit(scalar[i + 1])) // if there is a digit after the dot and it's not the last character
// 				hasDigitAfterDot = true;
// 		}
// 		else if (scalar[i] == 'f' && !hasF && i == scalar.size() - 1 && hasDot && hasDigitAfterDot)
// 			hasF = true;
// 		else if (std::isdigit(scalar[i]))
// 			hasDigit = true;
// 		else if (!(i == 0 && scalar[i] == '-' && scalar.size() > 1))
// 			return NONE;
// 	}

// 	if (hasDot && hasDigitAfterDot)
// 	{
// 		if (hasF)
// 			return FLOAT;
// 		return DOUBLE;
// 	}

// 	if (hasDigit && !hasDot && !hasF)
// 		return INT;

// 	return NONE;
// }

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
	try
	{
		int i = std::stoi(scalar);
		std::cout << "char: ";
		if (std::isprint(static_cast<unsigned char>(i)) && i >= 32 && i < 127)
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;

		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(i) << std::endl;
	}
	catch (const std::invalid_argument &)
	{
		std::cerr << "Error: Invalid argument for conversion to int" << std::endl;
	}
	catch (const std::out_of_range &)
	{
		std::cerr << "Error: Value out of range for conversion to int" << std::endl;
	}
}

void ScalarConverter::convertToFloat(const std::string scalar)
{
	try
	{
		float f = std::stof(scalar);
		std::cout << "char: ";
		if (std::isprint(static_cast<unsigned char>(f)))
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
	}
	catch (const std::invalid_argument&)
	{
		std::cerr << "Error: Invalid argument for conversion to float" << std::endl;
	}
	catch (const std::out_of_range&)
	{
		std::cerr << "Error: Value out of range for conversion to float" << std::endl;
	}
}

void ScalarConverter::convertToDouble(const std::string scalar)
{
	try
	{
		double d = std::stod(scalar);
		std::cout << "char: ";
		if (std::isprint(static_cast<unsigned char>(std::lround(d))) && d >= 0 && d < 256)
			std::cout << "'" << static_cast<char>(std::lround(d)) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;

		std::cout << "int: ";
		if (d >= std::numeric_limits<int>::lowest() && d < std::numeric_limits<int>::max())
			std::cout << static_cast<int>(std::lround(d)) << std::endl;
		else
			std::cout << "impossible" << std::endl;

		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	catch (const std::invalid_argument &)
	{
		std::cerr << "Error: Invalid argument for conversion to double" << std::endl;
	}
	catch (const std::out_of_range &)
	{
		std::cerr << "Error: Value out of range for conversion to double" << std::endl;
	}
}


void ScalarConverter::handleSpecialValues(TYPE type)
{
	std::cout << "char: impossible\nint: impossible\n";
	switch (type)
	{
	case NAN_VALUE:
		std::cout << "float: nanf\ndouble: nan" << std::endl;
		break;
	case INFPOS:
		std::cout << "float: inff\ndouble: inf" << std::endl;
		break;
	case INFNEG:
		std::cout << "float: -inff\ndouble: -inf" << std::endl;
		break;
	default:
		std::cerr << "Error: Unknown special value type" << std::endl;
	}
}
