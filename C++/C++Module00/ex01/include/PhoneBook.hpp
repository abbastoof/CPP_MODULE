/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:56:22 by atoof             #+#    #+#             */
/*   Updated: 2023/11/21 19:08:41 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_CONTACTS 8
#define CYAN "\033[36m"
#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define RED "\033[31m"



class PhoneBook
{
	private:
	//member variables(aka attributes)
		Contact		_contacts[MAX_CONTACTS];
		int			_index;
		int			_counter;

	public:
	//constructor and destructor
		PhoneBook();
		~PhoneBook();
	//member functions(aka methods)
		void		search_contact(void); //searches phonebook
		void		ft_display(void); //displays phonebook
		void		ft_add(void); //adds contact to phonebook
		std::string	truncate(std::string str); //truncates string to 10 characters
};

//non-member functions
void	ft_input(std::string &input); //gets input from user

#endif