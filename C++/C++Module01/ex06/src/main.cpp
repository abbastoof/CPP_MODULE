/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:48:07 by atoof             #+#    #+#             */
/*   Updated: 2023/10/28 19:10:16 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int		main(int argc, char **argv)
{
	Harl	harl;
	std::string	level;
	if (argc != 2)
	{
		std::cout << "Usage: ./harl <level>" << std::endl;
		std::cout << "Levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return (1);
	}
	level = argv[1];
	harl.complain(level);
	return (0);
}
