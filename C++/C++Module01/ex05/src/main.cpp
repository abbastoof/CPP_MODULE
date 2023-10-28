/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:38:16 by atoof             #+#    #+#             */
/*   Updated: 2023/10/28 17:34:22 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int		main(void)
{
	Harl	harl;
	std::string	level;

	std::cout << "Usage: debug, info, warning, error, exit" << std::endl;
	std::cout << "Enter level: ";
	std::getline(std::cin, level);
	while (level != "exit")
	{
		harl.complain(level);
		std::cout << "Enter level: ";
		std::getline(std::cin, level);
	}
	return (0);
}
