/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:53:36 by atoof             #+#    #+#             */
/*   Updated: 2023/11/21 18:45:53 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::set_first_name(std::string first_name)
{
	this->_first_name = first_name;
}

std::string	Contact::get_first_name(void) const
{
	return (this->_first_name);
}

std::string Contact::get_last_name(void) const
{
	return (this->_last_name);
}

void	Contact::set_last_name(std::string last_name)
{
	this->_last_name = last_name;
}

std::string	Contact::get_nickname(void) const
{
	return (this->_nickname);
}

void	Contact::set_nickname(std::string nickname)
{
	this->_nickname = nickname;
}

std::string Contact::get_phone_number(void) const
{
	return (this->_phone_number);
}

void	Contact::set_phone_number(std::string phone_number)
{
	this->_phone_number = phone_number;
}

std::string Contact::get_darkest_secret(void) const
{
	return (this->_darkest_secret);
}

void	Contact::set_darkest_secret(std::string darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}

void	Contact::print_contact(void) const
{
	std::cout << "First name: " << _first_name << std::endl;
	std::cout << "Last name: " << _last_name << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Darkest secret: " << _darkest_secret << std::endl;
}

Contact Contact::add_contact()
{
	Contact		contact;
	std::string	input;

	std::cout << "Enter first name: " << std::flush; //flushes the buffer, because we are using getline and cin together and cin leaves a newline character in the buffer
	ft_input(input);
	contact._first_name = (input);
	std::cout << "Enter last name: " << std::flush;
	ft_input(input);
	contact._last_name = (input);
	std::cout << "Enter nickname: " << std::flush;
	ft_input(input);
	contact._nickname = (input);
	std::cout << "Enter phone number: " << std::flush;
	ft_input(input);
	contact._phone_number = (input);
	std::cout << "Enter darkest secret: " << std::flush;
	ft_input(input);
	contact._darkest_secret = (input);
	return (contact);
}
