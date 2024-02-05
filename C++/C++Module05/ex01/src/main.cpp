/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:40:06 by atoof             #+#    #+#             */
/*   Updated: 2024/02/01 12:40:15 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int		main(void)
{
	Form form1("Form1", 10, 10);
	Bureaucrat bureaucrat("Bureaucrat1", 10);

	std::cout << form1;
	std::cout << bureaucrat;

	try
	{
		form1.beSigned(bureaucrat);
		std::cout << form1;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << form1;
	try
	{
		Bureaucrat bureaucrat2("Bureaucrat2", 11);
		std::cout << bureaucrat2 << std::endl;
		bureaucrat2.signForm(form1);
		std::cout << form1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form form2("Form2", 0, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
