/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:52:15 by atoof             #+#    #+#             */
/*   Updated: 2023/11/21 19:32:17 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	ft_input(std::string &input)
{
	std::getline(std::cin, input);
	if (std::cin.eof()) //checks if user has pressed ctrl+d
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
		phonebook.ft_display(); // this is called every time the user is prompted for input
		ft_input(command);
		if (command == "ADD")
			phonebook.ft_add();
		else if (command == "SEARCH")
			phonebook.search_contact();
		else if (command == "EXIT")
		{
			std::cout << YELLOW << "GOOD BYE" RESET << std::endl;
			exit(0);
		}
		else
			std::cout << RED "COMMAND NOT FOUND!" RESET << std::endl;
	}
	return (0);
}
