/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:48:44 by atoof             #+#    #+#             */
/*   Updated: 2024/02/22 18:45:23 by atoof            ###   ########.fr       */
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

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &rhs);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);
	~BitcoinExchange();

	void readData(const std::string &filename);
	void readFile(char **argv);
	void printData() const;
	void printFile() const;
	void checkDatabase() const;
	void checkFile() const;
	bool checkDate(const std::string &date) const;
	bool checkPrice(const std::string &price, bool isFromFile) const;
	bool isLeapYear(int year) const;
	bool isValidDay(int year, int month, int day) const;

private:
	std::map<std::string, std::string> _data;
	std::map<std::string, std::string> _file;
};

#endif