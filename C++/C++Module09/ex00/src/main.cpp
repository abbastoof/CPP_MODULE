/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:26:09 by atoof             #+#    #+#             */
/*   Updated: 2024/02/21 17:46:12 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	BitcoinExchange exchange;
	try
	{
		exchange.readData("data.csv");
		// exchange.printData();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	(void)argc;
	(void)argv;
	// read file from command line
	// if (argc == 2)
	// {
	// 	try
	// 	{
			
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}
	return 0;
}