/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:48:36 by atoof             #+#    #+#             */
/*   Updated: 2024/02/20 18:49:50 by atoof            ###   ########.fr       */
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
	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream iss(line); // istringstream is used to read from the string
		std::string key; // key is the first part of the line
		std::getline(iss, key, ','); // read from the line until the comma, and store it in key variable
		std::string value; // value is the second part of the line
		std::getline(iss, value); // read from the line until the end, and store it in value variable
		_data[key] = value; // store the key and value in the map
	}
}

void BitcoinExchange::printData() const
{
	for (auto &i : _data)
	{
		std::cout << i.first << " " << i.second << std::endl;
	}
}



