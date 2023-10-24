/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:53:36 by atoof             #+#    #+#             */
/*   Updated: 2023/10/24 16:21:06 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


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
	this->first_name = first_name;
}

std::string	Contact::get_first_name(void)
{
	return (this->first_name);
}

std::string Contact::get_last_name(void)
{
	return (this->last_name);
}

void	Contact::set_last_name(std::string last_name)
{
	this->last_name = last_name;
}

std::string	Contact::get_nickname(void)
{
	return (this->nickname);
}

void	Contact::set_nickname(std::string nickname)
{
	this->nickname = nickname;
}

std::string Contact::get_login(void)
{
	return (this->login);
}

void	Contact::set_login(std::string login)
{
	this->login = login;
}

std::string Contact::get_postal_address(void)
{
	return (this->postal_address);
}

void	Contact::set_postal_address(std::string postal_address)
{
	this->postal_address = postal_address;
}

std::string Contact::get_email_address(void)
{
	return (this->email_address);
}

void	Contact::set_email_address(std::string email_address)
{
	this->email_address = email_address;
}

std::string Contact::get_phone_number(void)
{
	return (this->phone_number);
}

void	Contact::set_phone_number(std::string phone_number)
{
	this->phone_number = phone_number;
}

std::string Contact::get_birthday_date(void)
{
	return (this->birthday_date);
}

void	Contact::set_birthday_date(std::string birthday_date)
{
	this->birthday_date = birthday_date;
}

std::string Contact::get_darkest_secret(void)
{
	return (this->darkest_secret);
}

void	Contact::set_darkest_secret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}