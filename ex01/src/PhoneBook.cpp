/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:47:04 by atoof             #+#    #+#             */
/*   Updated: 2023/10/25 15:26:09 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) :_index(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

std::string	PhoneBook::truncate(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	PhoneBook::search_contact(void)
{
	int				i;
	int				search_index;
	std::string		input;

	i = 0;
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	while (!this->_contacts[i].get_first_name().empty() && i < MAX_CONTACTS)
	{
		std::cout << std::right << std::setw(10) << i << "|" << std::setw(10) << truncate(this->_contacts[i].get_first_name()) \
		<< "|" << std::setw(10) << truncate(this->_contacts[i].get_last_name()) \
		<< "|" << std::setw(10) << truncate(this->_contacts[i].get_nickname()) << std::endl;
		i++;
	}
	std::cout << "\nEnter index of the contact you want to see: ";
	ft_input(input);
	try {(search_index = std::stoi(input));} catch (...) {}
    if (search_index >= 0 && search_index < _index)
        _contacts[search_index].print_contact();
	else
        std::cout << "Invalid index." << std::endl;
}

void	PhoneBook::ft_display(void)
{
    std::cout << CYAN;
    std::cout << "+----------------PHONEBOOK----------------+" << std::endl;
    std::cout << "|                  1-ADD                  |" << std::endl;
    std::cout << "|                 2-SEARCH                |" << std::endl;
    std::cout << "|                  3-EXIT                 |" << std::endl;
    std::cout << "+-----------------------------------------+" << std::endl;
	std::cout << "\n\n\nEnter command: ";
    std::cout << RESET;
}

void	PhoneBook::ft_add(void)
{
	Contact		contact;
	contact = Contact::add_contact();
	if (contact.get_first_name().empty() || contact.get_last_name().empty() || \
	contact.get_nickname().empty() || contact.get_darkest_secret().empty() || \
	contact.get_phone_number().empty())
	{
		std::cout << "\nError: Invalid input.\n" << std::endl;
		return ;
	}
	else
	{
		this->_contacts[_index] = contact;
		_index = (_index + 1) % MAX_CONTACTS;
		std::cout << "\nAdded successfully.\n" << std::endl;
	}
}
