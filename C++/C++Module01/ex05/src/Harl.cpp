/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:38:12 by atoof             #+#    #+#             */
/*   Updated: 2023/11/02 12:37:31 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void	Harl::complain(std::string level)
{
	HarlFunc	funcs[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}; // array of pointers to member functions
	std::string	levels[4] = {"debug", "info", "warning", "error"};
	int			i;

	i = 0;
	while (i < 4)
	{
		if (levels[i] == level)
		{
			(this->*funcs[i])();
			return ;
		}
		i++;
	}
}

void	Harl::debug(void)
{
	std::cout << "DEBUG: I love having extra bacon for my" \
		"7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO: I cannot believe adding extra bacon costs more money." \
	"You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING: I think I deserve to have some extra bacon for free." \
	" I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}
