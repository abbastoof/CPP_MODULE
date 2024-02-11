#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>
#include <stdexcept>
#include <regex>

typedef enum TYPE
{
    NONE,
    NAN_VALUE,
    INFPOS,
    INFNEG,
    DOUBLE,
    FLOAT,
    INT,
    CHAR,
} TYPE;

class ScalarConverter
{
public:
    static void convert(std::string const &literal);
private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const &src);
    ScalarConverter &operator=(ScalarConverter const &src);
    ~ScalarConverter();
	static TYPE getType(const std::string& scalar);
    static void convertToChar(const std::string scalar);
    static void convertToInt(const std::string scalar);
    static void convertToFloat(const std::string scalar);
    static void convertToDouble(const std::string scalar);
	static void handleSpecialValues(TYPE type);
};

#endif

