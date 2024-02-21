/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:48:36 by atoof             #+#    #+#             */
/*   Updated: 2024/02/21 17:22:06 by atoof            ###   ########.fr       */
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
}

void BitcoinExchange::checkPrice(const std::string &price) const
{
	if (price.find_first_not_of("0123456789.") != std::string::npos)
	{
		throw InvalidPrice();
	}
}

// iteratotr
// for (std::map<std::string, std::string>::iterator it = _data.begin(); it != _data.end(); ++it)
// {
// 	std::cout << it->first << " " << it->second << std::endl;
// }