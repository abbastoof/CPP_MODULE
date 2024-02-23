/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:48:44 by atoof             #+#    #+#             */
/*   Updated: 2024/02/23 12:22:16 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <exception>
#include <regex>
#include <chrono>
#include <memory>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &rhs);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);
	~BitcoinExchange();

	void readData(const std::string &filename);
	void printData() const;
	bool checkDate(const std::string &date, int line) const;
	bool checkPrice(const std::string &price, int line, bool isFromFile) const;
	bool isLeapYear(int year) const;
	bool isValidDay(int year, int month, int day) const;
	int checkFileLines(const char *filename);
	void printFileData() const;

	typedef struct s_fileData
	{
		std::string date;
		std::string price;
		std::shared_ptr<s_fileData> next;
	} t_fileData;

	
private:
	std::map<std::string, std::string> _data;
	std::shared_ptr<t_fileData> _fileData;
};

#endif