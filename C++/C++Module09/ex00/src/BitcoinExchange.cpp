/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:48:36 by atoof             #+#    #+#             */
/*   Updated: 2024/02/22 18:47:27 by atoof            ###   ########.fr       */
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
	while (getline(ss, key, '|'))
	{
		getline(ss, value, '\n');
		if (line == 0 && key == "date " && value == " value")
		{
			++line;
			continue;
		}
		_data.insert(std::pair<std::string, std::string>(key, value));
		++line;
	}
	file.close();
	// checkDatabase();
}

void BitcoinExchange::readFile(char **argv)
{
	int duplicateCount = 0;
	int formatErrorCount = 0;
	
    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        throw std::runtime_error("File not found");
    }
    std::string line, key, value;

    std::getline(file, line); // Skip header

    while (std::getline(file, line))
    {
        size_t delimiterPos = line.find('|');
        if (delimiterPos != std::string::npos)
        {
            key = line.substr(0, delimiterPos);
            value = line.substr(delimiterPos + 1);
			if (_file.find(key) != _file.end())
            {
                // Mark the current entry as a duplicate by appending a count
                key = "duplicate_" + std::to_string(++duplicateCount);
                value = "duplicate";
            }

            // Insert the key-value pair into the map
            _file[key] = value;
        }
        else
        {
            // If the line does not have the correct format, mark as a format error with a count
            key = "Format_error_" + std::to_string(++formatErrorCount);
            value = "Format_error";
            _file[key] = value;
        }
    }
    file.close();
}

void BitcoinExchange::printData() const
{
	std::cout << "Data:" << std::endl;
	for (const auto &pair : _data)
	{
		std::cout << pair.first << " " << pair.second << std::endl;
	}
}

void BitcoinExchange::printFile() const
{
	std::cout << "File:" << std::endl;
	for (const auto &pair : _file)
	{
		std::cout << pair.first << " " << pair.second << std::endl;
	}
}

void BitcoinExchange::checkDatabase() const
{
	std::map<std::string, std::string>::const_iterator it;
	for (it = _data.begin(); it != _data.end(); ++it)
	{
		if (!checkDate(it->first) || !checkPrice(it->second, false))
		{
			throw std::runtime_error("Error: bad data in database");
		}
	}
}

void BitcoinExchange::checkFile() const
{
	std::map<std::string, std::string>::const_iterator it;
	for (it = _file.begin(); it != _file.end(); ++it)
	{
		if (!checkDate(it->first) || !checkPrice(it->second, true))
		{
			std::cerr << "Error: bad data in file" << std::endl;
			continue;
		}
		// check for duplicates
		if (it->first.find("duplicate") != std::string::npos)
		{
			std::cerr << "Error: duplicate data in file" << std::endl;
		}
	}
}

bool BitcoinExchange::checkDate(const std::string &date) const
{
	if (!std::regex_match(date, std::regex("^\\d{4}-(\\d{1,2})-(\\d{1,2})$")))
	{
		std::cerr << "Error: bad input date" << std::endl;
		return false;
	}

	int year = std::stoi(date.substr(0, 4));

	size_t firstDash = date.find('-');
	size_t secondDash = date.find('-', firstDash + 1);

	int month = std::stoi(date.substr(firstDash + 1, secondDash - firstDash - 1));
	int day = std::stoi(date.substr(secondDash + 1));

	if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
	{
		std::cerr << "Error: bad input date " << std::endl;
		return false;
	}

	if (!isValidDay(year, month, day))
	{
		std::cerr << "Error: bad input date " << std::endl;
		return false;
	}
	std::chrono::system_clock::time_point today = std::chrono::system_clock::now();
	std::time_t today_time = std::chrono::system_clock::to_time_t(today);
	std::tm *today_tm = std::localtime(&today_time);

	int today_year = today_tm->tm_year + 1900;
	int today_month = today_tm->tm_mon + 1;
	int today_day = today_tm->tm_mday;

	if (year > today_year || (year == today_year && month > today_month) || (year == today_year && month == today_month && day > today_day))
	{
		throw std::runtime_error("Error: Date cannot be in the future: " + date);
	}
	return true;
}

bool BitcoinExchange::checkPrice(const std::string &price, bool isFromFile) const
{
	float priceValue = std::stof(price);

	if (isFromFile)
	{
		if (priceValue < 0 || priceValue > 1000)
		{
			std::cerr << "Price should be between 0 and 1000" << std::endl;
			return false;
		}
	}
	else
	{
		if (priceValue < 0)
		{
			std::cerr << "Price should be positive" << std::endl;
			return false;
		}
	}
	return true;
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