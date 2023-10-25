/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:56:22 by atoof             #+#    #+#             */
/*   Updated: 2023/10/25 15:52:49 by atoof            ###   ########.fr       */
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
		Contact		_contacts[MAX_CONTACTS];
		int			_index;

	public:
		PhoneBook();
		~PhoneBook();
		void		search_contact(void);
		void		ft_display(void);
		void		ft_add(void);
		std::string	truncate(std::string str);
};

void	ft_input(std::string &input);

#endif