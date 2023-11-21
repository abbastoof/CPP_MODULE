/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:56:29 by atoof             #+#    #+#             */
/*   Updated: 2023/11/21 16:45:59 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>


class Contact
{
	private:
		std::string		_first_name;
		std::string		_last_name;
		std::string		_nickname;
		std::string		_phone_number;
		std::string		_darkest_secret;

	public:
		Contact();
		~Contact();

		//Getters and setters
		void			set_first_name(std::string first_name);
		std::string		get_first_name(void) const;
		void			set_last_name(std::string last_name);
		std::string		get_last_name(void) const;
		void			set_nickname(std::string nickname);
		std::string		get_nickname(void) const;
		void			set_phone_number(std::string phone_number);
		std::string		get_phone_number(void) const;
		void 			set_darkest_secret(std::string darkest_secret);
		std::string		get_darkest_secret(void) const;
		void			print_contact(void) const;
		static Contact	add_contact(void);
		
};

#endif