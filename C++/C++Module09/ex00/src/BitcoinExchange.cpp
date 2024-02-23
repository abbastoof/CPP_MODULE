/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:48:36 by atoof             #+#    #+#             */
/*   Updated: 2024/02/23 12:22:12 by atoof            ###   ########.fr       */
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
	int line = 1;
	while (!ss.eof())
	{
		std::getline(ss, key, ',');
		std::getline(ss, value, '\n');
		if (line == 1 && key == "date" && value == "exchange_rate")
		{
			++line;
			continue;
		}
		if (checkDate(key, line) && checkPrice(value, line, false))
		{
			_data.insert(std::pair<std::string, std::string>(key, value));
			++line;
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

bool BitcoinExchange::checkDate(const std::string &date, int line) const
{
	if (!std::regex_match(date, std::regex("^\\d{4}-(\\d{1,2})-(\\d{1,2})$")))
	{
		std::cerr << "Date is not in the correct format at line " << line << std::endl;
		return false;
	}

	int year = std::stoi(date.substr(0, 4));

	size_t firstDash = date.find('-');
	size_t secondDash = date.find('-', firstDash + 1);

	int month = std::stoi(date.substr(firstDash + 1, secondDash - firstDash - 1));
	int day = std::stoi(date.substr(secondDash + 1));

	if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
	{
		std::cerr << "Date is out of range at line " << line << std::endl;
		return false;
	}

	if (!isValidDay(year, month, day))
	{
		std::cerr << "invalid day at line " << line << std::endl;
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

bool BitcoinExchange::checkPrice(const std::string &price, int line, bool isFromFile) const
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
			std::cerr << "Price is negative at line " << line << std::endl;
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

int BitcoinExchange::checkFileLines(const char *filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("File not found");
    std::string line;
    std::shared_ptr<t_fileData> last = nullptr;

    while (getline(file, line))
    {
        auto newNode = std::make_shared<t_fileData>();
        newNode->next = nullptr;

        if (line == "date | value")
            continue;
        size_t pipe = line.find(" | ");
        if (pipe != std::string::npos)
        {
            newNode->date = line.substr(0, pipe);
            newNode->price = line.substr(pipe + 3);

            // if (!BitcoinExchange::isValidDay(newNode->date) || BitcoinExchange::isValidPrice(newNode->price))
			// {
            //     newNode->date = "Error";
            //     newNode->price = "Error";
            // }
        }
        else
        {
            newNode->date = "Error";
            newNode->price = "Error";
        }
        if (last == nullptr)
            _fileData = newNode;
        else
            last->next = newNode;
        last = newNode;
    }

    file.close();
    return 0;
}


void BitcoinExchange::printFileData() const
{
    auto current = _fileData;
    std::cout << "File data:" << std::endl;
    while (current != nullptr)
    {
        std::cout << current->date << " " << current->price << std::endl;
        current = current->next;
    }
}
