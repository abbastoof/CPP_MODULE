/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:48:01 by atoof             #+#    #+#             */
/*   Updated: 2023/11/24 19:11:22 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void	Harl::complain(std::string level)
{
	HarlFunc	funcs[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while (i < 4 && levels[i].compare(level))
		i++;
	switch(i)
	{
		case DEBUG:
			(this->*funcs[DEBUG])();
		case INFO:
			(this->*funcs[INFO])();
		case WARNING:
			(this->*funcs[WARNING])();
		case ERROR:
			(this->*funcs[ERROR])();
			break;
 		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}


void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my "\
	"7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon cost more money. "\
	"You don't put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. "\
	"I've been coming here for years and you just started working here last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]\nThis is unacceptable, I want to speak to the manager now." << std::endl;
}
