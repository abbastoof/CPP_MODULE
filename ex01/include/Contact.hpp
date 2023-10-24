#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	private:
		std::string		first_name;
		std::string		last_name;
		std::string		nickname;
		std::string		login;
		std::string		postal_address;
		std::string		email_address;
		std::string		phone_number;
		std::string		birthday_date;
		std::string		darkest_secret;

	public:
		Contact();
		~Contact();

		void			set_first_name(std::string first_name);
		std::string		get_first_name(void);
		void			set_last_name(std::string last_name);
		std::string		get_last_name(void);
		void			set_nickname(std::string nickname);
		std::string		get_nickname(void);
		void			set_login(std::string login);
		std::string		get_login(void);
		void			set_postal_address(std::string postal_address);
		std::string		get_postal_address(void);
		void			set_email_address(std::string email_address);
		std::string		get_email_address(void);
		void			set_phone_number(std::string phone_number);
		std::string		get_phone_number(void);
		void			set_birthday_date(std::string birthday_date);
		std::string		get_birthday_date(void);
		void 			set_darkest_secret(std::string darkest_secret);
		std::string		get_darkest_secret(void);
};

#endif