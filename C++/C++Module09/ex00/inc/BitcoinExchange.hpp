/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:48:44 by atoof             #+#    #+#             */
/*   Updated: 2024/03/06 21:11:59 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <exception>
#include <regex>
#include <chrono>
#include <memory>
#include <iomanip>

class BitcoinExchange
{
public:

	BitcoinExchange();
	~BitcoinExchange();
	void calculatePrice() const;
	int checkFileLines(const char *filename);
	void readData(const std::string &filename);


private:
	typedef struct s_fileData
	{
		std::string date;
		std::string price;
		std::shared_ptr<s_fileData> next;
	} t_fileData;

	BitcoinExchange(const BitcoinExchange &rhs);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);

	void printData() const;
	void printFileData() const;
	bool isLeapYear(int year) const;
	bool checkDate(const std::string &date) const;
	bool isValidDay(int year, int month, int day) const;
	bool checkPrice(const std::string &price, bool isFromFile) const;
	std::shared_ptr<t_fileData> createNode(const std::string& line);

	std::map<std::string, std::string> _data;
	std::shared_ptr<t_fileData> _fileData;
};

#endif
