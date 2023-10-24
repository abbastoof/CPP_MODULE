/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:52:15 by atoof             #+#    #+#             */
/*   Updated: 2023/10/24 17:20:15 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	std::string		command;
	PhoneBook		phonebook;
	while (true)
	{
		phonebook.ft_display();
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.ft_add();
		else if (command == "SEARCH")
			phonebook.search_contact();
		else if (command == "EXIT")
		{
			std::cout << YELLOW << "GOOD BYE" << std::endl;
			break ;
		}
		else if (std::cin.eof())
		{
			std::cout << YELLOW << "\n+----------------		GOOD BYE	----------------+\n" RESET << std::endl;
			break;
		}
		else
				std::cout << RED "COMMAND NOT FOUND!" RESET << std::endl;
	}
	return (0);
}
