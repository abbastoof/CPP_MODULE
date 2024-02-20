/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:48:44 by atoof             #+#    #+#             */
/*   Updated: 2024/02/20 17:15:54 by atoof            ###   ########.fr       */
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
#include <iomanip>
#include <cmath>
#include <exception>
#include <stdexcept>
#include <cctype>
#include <locale>
#include <functional>
#include <numeric>
#include <list>
#include <stack>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &rhs);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);
	~BitcoinExchange();

	void readData(const std::string &filename);
	void printData() const;
	
private:
	std::map<std::string, std::string> _data;
};

#endif



	// void printData(const std::string &filename) const;
	// void printData(const std::string &filename, const std::string &currency) const;
	// void printData(const std::string &filename, const std::string &currency, const std::string &date) const;
	// void printData(const std::string &filename, const std::string &currency, const std::string &date, const std::string &time) const;
	// void printData(const std::string &filename, const std::string &currency, const std::string &date, const std::string &time, const std::string &price) const;
	// void printData(const std::string &filename, const std::string &currency, const std::string &date, const std::string &time, const std::string &price, const std::string &amount) const;
	// void printData(const std::string &filename, const std::string &currency, const std::string &date, const std::string &time, const std::string &price, const std::string &amount, const std::string &type) const;
	// void printData(const std::string &filename, const std::string &currency, const std::string &date, const std::string &time, const std::string &price, const std::string &amount, const std::string &type, const std::string &tid) const;
	// void printData(const std::string &filename, const std::string &currency, const std::string &date, const std::string &time, const std::string &price, const std::string &amount, const std::string &type, const std::string &tid, const std::string &price_currency) const;
	// void printData(const std::string &filename, const std::string &currency, const std::string &date, const std::string &time, const std::string &price, const std::string &amount, const std::string &type, const std::string &tid, const std::string &price_currency, const std::string &item) const;
	// void printData(const std::string &filename, const std::string &currency, const std::string &date, const std::string &time, const std::string &price, const std::string &amount, const std::string &type, const std::string &tid, const std::string &price_currency, const std::string &item, const std::string &trade_id) const;
