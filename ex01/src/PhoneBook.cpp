/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:47:04 by atoof             #+#    #+#             */
/*   Updated: 2023/10/24 17:13:37 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::add_contact(Contact contact)
{
	if (this->_index < MAX_CONTACTS)
	{
		this->_contacts[this->_index] = contact;
		this->_index++;
	}
	else
		std::cout << "Phonebook is full." << std::endl;
}

void	PhoneBook::print_contact(int index)
{
	std::cout << "First name: " << this->_contacts[index].get_first_name() << std::endl;
	std::cout << "Last name: " << this->_contacts[index].get_last_name() << std::endl;
	std::cout << "Nickname: " << this->_contacts[index].get_nickname() << std::endl;
	std::cout << "Login: " << this->_contacts[index].get_login() << std::endl;
	std::cout << "Postal address: " << this->_contacts[index].get_postal_address() << std::endl;
	std::cout << "Email address: " << this->_contacts[index].get_email_address() << std::endl;
	std::cout << "Phone number: " << this->_contacts[index].get_phone_number() << std::endl;
	std::cout << "Birthday date: " << this->_contacts[index].get_birthday_date() << std::endl;
	std::cout << "Darkest secret: " << this->_contacts[index].get_darkest_secret() << std::endl;
}

void	PhoneBook::search_contact(void)
{
	int		i;
	int		index;

	i = 0;
	if (this->_index == 0)
	{
        std::cout << "No contacts added yet." << std::endl;
        return;
	}
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	while (i < this->_index)
	{
		std::cout << std::setw(10) << i << "|";
		if (this->_contacts[i].get_first_name().length() > 10)
			std::cout << this->_contacts[i].get_first_name().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << this->_contacts[i].get_first_name() << "|";
		if (this->_contacts[i].get_last_name().length() > 10)
			std::cout << this->_contacts[i].get_last_name().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << this->_contacts[i].get_last_name() << "|";
		if (this->_contacts[i].get_nickname().length() > 10)
			std::cout << this->_contacts[i].get_nickname().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << this->_contacts[i].get_nickname() << "|";
		std::cout << std::endl;
		i++;
	}
	std::cout << "Enter index of the contact you want to see: ";
    std::cin >> index;
	std::cin.clear();
	std::cin.ignore(10000, '\n');
    if (std::cin.fail())
    {
        std::cout << "Invalid input." << std::endl;
    }
    else if (index >= 0 && index < this->_index)
        this->print_contact(index);
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

void	PhoneBook::ft_input(std::string *input)
{
	std::getline(std::cin, *input);
}

void	PhoneBook::ft_add(void)
{
	Contact		contact;
	std::string	input;

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	contact.set_first_name(input);
	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	contact.set_last_name(input);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	contact.set_nickname(input);
	std::cout << "Enter login: ";
	std::getline(std::cin, input);
	contact.set_login(input);
	std::cout << "Enter postal address: ";
	std::getline(std::cin, input);
	contact.set_postal_address(input);
	std::cout << "Enter email address: ";
	std::getline(std::cin, input);
	contact.set_email_address(input);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	contact.set_phone_number(input);
	std::cout << "Enter birthday date: ";
	std::getline(std::cin, input);
	contact.set_birthday_date(input);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	contact.set_darkest_secret(input);
	this->add_contact(contact);
}
