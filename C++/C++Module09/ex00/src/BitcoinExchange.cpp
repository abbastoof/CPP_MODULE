/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:48:36 by atoof             #+#    #+#             */
/*   Updated: 2024/02/23 17:21:20 by atoof            ###   ########.fr       */
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
		throw std::runtime_error("File not found");
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
		if (checkDate(key) && checkPrice(value, false))
		{
			_data.insert(std::pair<std::string, std::string>(key, value));
			++line;
			continue;
		}
		line++;
	}
	file.close();
}

bool BitcoinExchange::checkDate(const std::string &date) const
{
	if (!std::regex_match(date, std::regex("^\\d{4}-(\\d{1,2})-(\\d{1,2})$")))
	{
		// std::cerr << "Invalid date format" << std::endl;
		return false;
	}

	int year = std::stoi(date.substr(0, 4));

	size_t firstDash = date.find('-');
	size_t secondDash = date.find('-', firstDash + 1);

	int month = std::stoi(date.substr(firstDash + 1, secondDash - firstDash - 1)); // substr(start, length)
	int day = std::stoi(date.substr(secondDash + 1));

	if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
	{
		// std::cerr << "invalid date" << std::endl;
		return false;
	}

	if (!isValidDay(year, month, day))
	{
		// std::cerr << "Invalid day for month " << month << " and year " << year << std::endl;
		return false;
	}
	std::chrono::system_clock::time_point today = std::chrono::system_clock::now();
	std::time_t today_time = std::chrono::system_clock::to_time_t(today); // convert to C-style time_t
	std::tm *today_tm = std::localtime(&today_time);					  // convert to tm struct

	int today_year = today_tm->tm_year + 1900;
	int today_month = today_tm->tm_mon + 1;
	int today_day = today_tm->tm_mday;

	if (year > today_year || (year == today_year && month > today_month) || (year == today_year && month == today_month && day > today_day))
	{
		// std::cerr << "Date is in the future" << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::checkPrice(const std::string &price, bool isFromFile) const
{
	try
	{
		double priceValue = std::stod(price);

		if (isFromFile)
		{
			if (priceValue < 0 || priceValue > 1000)
			{
				// std::cerr << "Price should be between 0 and 1000" << std::endl;
				return false;
			}
		}
		else
		{
			if (priceValue < 0)
			{
				// std::cerr << "Price should be positive" << std::endl;
				return false;
			}
			if (!std::regex_match(price, std::regex("^\\d*(\\.\\d+)?$")))
			{
				// std::cerr << "Invalid price format" << std::endl;
				return false;
			}
		}
		return true;
	}
	catch (const std::invalid_argument &e)
	{
		// std::cerr << "Price is not a number" << std::endl;
		return false;
	}
	catch (const std::out_of_range &e)
	{
		// std::cerr << "Price is out of range" << std::endl;
		return false;
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
			return day <= 29;
		return day <= 28;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return day <= 30;
	return day <= 31;
}

int BitcoinExchange::checkFileLines(const char *filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
		throw std::runtime_error("File not found");
	std::string line;
	std::shared_ptr<t_fileData> last = nullptr;
	int count = 0;
	while (getline(file, line))
	{
		std::shared_ptr<t_fileData> newNode = std::make_shared<t_fileData>();
		newNode->next = nullptr;

		size_t pipe = line.find(" | ");
		if (pipe != std::string::npos)
		{
			newNode->date = line.substr(0, pipe);
			newNode->price = line.substr(pipe + 3);
			++count;
			if (count == 1)
				continue;
			if (!checkDate(newNode->date) || !checkPrice(newNode->price, true))
			{
				newNode->date = "Error";
				newNode->price = "Error";
			}
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
	std::shared_ptr<t_fileData> current = _fileData;
	std::cout << "File data:" << std::endl;
	while (current != nullptr)
	{
		std::cout << current->date << " " << current->price << std::endl;
		current = current->next;
	}
}

void BitcoinExchange::printData() const
{
	std::cout << "Data:" << std::endl;
	for (const auto &pair : _data)
		std::cout << pair.first << " " << pair.second << std::endl;
}

void BitcoinExchange::calculatePrice() const
{
	auto current = _fileData;
	while (current != nullptr)
	{
		if (current->date == "Error" || current->price == "Error")
		{
			std::cerr << "Skipping error line with date " << current->date << " and price " << current->price << std::endl;
			current = current->next;
			continue;
		}

		std::map<std::string, std::string>::const_iterator it = _data.find(current->date);
		if (it != _data.end())
		{
			double calculatedPrice = std::stod(current->price) * std::stod(it->second);
			std::cout << current->date << " => " << calculatedPrice << std::endl;
		}
		else
		{
			auto lower = _data.lower_bound(current->date);
			if (lower != _data.begin())
			{
				--lower;
				double calculatedPrice = std::stod(current->price) * std::stod(lower->second);
				std::cout << current->date << " => " << calculatedPrice << std::endl;
			}
			else
				std::cerr << "No earlier date found in the database for " << current->date << std::endl;
		}
		current = current->next;
	}
}
