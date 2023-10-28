/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:38:14 by atoof             #+#    #+#             */
/*   Updated: 2023/10/28 17:25:09 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

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

typedef void (Harl::*HarlFunc)(void);

#endif
