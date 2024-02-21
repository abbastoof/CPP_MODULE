/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:48:44 by atoof             #+#    #+#             */
/*   Updated: 2024/02/21 17:34:21 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <exception>
#include <regex>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &rhs);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);
	~BitcoinExchange();

	void readData(const std::string &filename);
	void printData() const;
	void checkData() const;
	void checkDate(const std::string &date) const;
	void checkPrice(const std::string &price) const;
	bool isLeapYear(int year) const;
	bool isValidDay(int year, int month, int day) const;
	
	class InvalidDate : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Invalid date format";
		}
	};
	class InvalidPrice : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Invalid price format";
		}
	};
	
private:
	std::map<std::string, std::string> _data;
	std::map<std::string, std::string> _file;
};

#endif