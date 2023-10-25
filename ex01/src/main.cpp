/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:52:15 by atoof             #+#    #+#             */
/*   Updated: 2023/10/25 14:09:35 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	ft_input(std::string &input)
{
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << YELLOW << "\n+----------------		GOOD BYE	----------------+\n" RESET << std::endl;
		exit(0);
	}
}

int main()
{
	std::string		command;
	PhoneBook		phonebook;
	while (true)
	{
		phonebook.ft_display();
		ft_input(command);
		if (command == "ADD")
			phonebook.ft_add();
		else if (command == "SEARCH")
			phonebook.search_contact();
		else if (command == "EXIT")
		{
			std::cout << YELLOW << "GOOD BYE" << std::endl;
			exit(0);
		}
		else
			std::cout << RED "COMMAND NOT FOUND!" RESET << std::endl;
	}
	return (0);
}
