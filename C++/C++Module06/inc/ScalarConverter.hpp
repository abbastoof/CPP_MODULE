#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <corecrt.h>

class ScalarConverter
{
	public:
		static void convert(std::string const &literal);
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter &operator=(ScalarConverter const &src);
		~ScalarConverter();
		enum TYPE
		{
			NONE,
			NAN,
			INFPOS,
			INFNEG,
			DOUBLE,
			FLOAT,
			INT,
			CHAR
		};
		static void printConversion(const std::string literal, const ScalarConverter::TYPE type);
		static ScalarConverter::TYPE getType(const std::string scalar);
};

#endif
