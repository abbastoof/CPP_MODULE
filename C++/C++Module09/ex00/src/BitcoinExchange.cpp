/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:48:36 by atoof             #+#    #+#             */
/*   Updated: 2024/02/21 17:43:28 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs)
{
	*this = rhs;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		_data = rhs._data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::readData(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("File not found");
    }
	std::stringstream ss;
	ss << file.rdbuf();
	std::string key, value;
	int line = 0;
	while (!ss.eof())
	{
		std::getline(ss, key, ',');
		std::getline(ss, value, '\n');
		if (line == 0 && key == "date")
		{
			++line;
			continue;
		}
		_data.insert(std::pair<std::string, std::string>(key, value));
		++line;
	}
	file.close();
	checkData();
}

void BitcoinExchange::printData() const
{
	for (const auto &pair : _data)
	{
		std::cout << pair.first << " " << pair.second << std::endl;
	}
}

void BitcoinExchange::checkData() const
{
	for (const auto &pair : _data)
	{
		checkDate(pair.first);
		checkPrice(pair.second);
	}
}

void BitcoinExchange::checkDate(const std::string &date) const
{
    if (!std::regex_match(date, std::regex("^\\d{4}-(\\d{1,2})-(\\d{1,2})$")))
    {
        throw InvalidDate();
    }

    int year = std::stoi(date.substr(0, 4));

    size_t firstDash = date.find('-');
    size_t secondDash = date.find('-', firstDash + 1);

    int month = std::stoi(date.substr(firstDash + 1, secondDash - firstDash - 1));
    int day = std::stoi(date.substr(secondDash + 1));

    if (year < 2009 || year > 2024 || month < 1 || month > 12 || day < 1)
    {
        throw InvalidDate();
    }

    if (!isValidDay(year, month, day))
    {
        throw InvalidDate();
    }
}

void BitcoinExchange::checkPrice(const std::string &price) const
{
	if (price.find_first_not_of("0123456789.") != std::string::npos)
	{
		throw InvalidPrice();
	}
}

bool BitcoinExchange::isLeapYear(int year) const
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

bool BitcoinExchange::isValidDay(int year, int month, int day) const
{
	if (month == 2)
	{
		if (isLeapYear(year))
		{
			return day <= 29;
		}
		return day <= 28;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11) // April, June, September, November
	{
		return day <= 30;
	}
	return day <= 31;
}