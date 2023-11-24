/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:48:04 by atoof             #+#    #+#             */
/*   Updated: 2023/11/24 19:07:12 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

enum	levels
{
	DEBUG,
	INFO,
	WARNING,	
	ERROR
};

class Harl
{
	public :
		Harl(void);
		~Harl(void);
		void	complain(std::string level);

	private :
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

typedef void (Harl::*HarlFunc)(void); // This is a pointer to a member function of class Harl.

#endif
