/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:32:50 by atoof             #+#    #+#             */
/*   Updated: 2024/02/23 23:32:50 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " \"expression\"" << std::endl;
		return 1;
	}

	RPN<int> calculator;

	try
	{
		int result = calculator.evaluate(argv[1]);
		std::cout << "Result: " << result << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
