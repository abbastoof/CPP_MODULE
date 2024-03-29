/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:26:09 by atoof             #+#    #+#             */
/*   Updated: 2024/03/06 16:45:11 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./btc filename" << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange exchange;
		exchange.readData("data.csv");
		// exchange.printData();
		// exchange.printFileData();
		exchange.checkFileLines(argv[1]);
		exchange.calculatePrice();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
