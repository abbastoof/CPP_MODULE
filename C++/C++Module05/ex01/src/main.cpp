/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:40:06 by atoof             #+#    #+#             */
/*   Updated: 2024/03/03 13:30:02 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
#include "../inc/Colors.hpp"

int main(void)
{
	try
	{
		Bureaucrat seniorBureaucrat("Senior John", 5);
		Form importantForm("ImportantForm", 5, 5);
		std::cout << Colors::GREEN << importantForm << Colors::RESET << std::endl;
		std::cout << Colors::CYAN << seniorBureaucrat << Colors::RESET;
		importantForm.beSigned(seniorBureaucrat);
		std::cout << Colors::GREEN << importantForm << Colors::RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << Colors::RED << "Error: " << e.what() << Colors::RESET << std::endl;
	}

	try
	{
		Bureaucrat juniorBureaucrat("Junior Jim", 15);
		Form standardForm("StandardForm", 20, 10);
		std::cout << Colors::CYAN << juniorBureaucrat << Colors::RESET << std::endl;
		juniorBureaucrat.signForm(standardForm);
		std::cout << Colors::GREEN << standardForm << Colors::RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << Colors::RED << "Error: " << e.what() << Colors::RESET << '\n';
	}

	try
	{
		Form invalidForm("InvalidForm", 0, -1);
	}
	catch (const std::exception &e)
	{
		std::cerr << Colors::RED << "Error: " << e.what() << Colors::RESET << '\n';
	}

	// New Test: Bureaucrat with grade too low attempts to sign a form
	try
	{
		Bureaucrat internBureaucrat("Intern Ivan", 50);
		Form challengingForm("ChallengingForm", 10, 10);
		internBureaucrat.signForm(challengingForm);
	}
	catch (const std::exception &e)
	{
		std::cerr << Colors::RED << "Attempt failed: " << e.what() << Colors::RESET << '\n';
	}

	// New Test: Attempting to re-sign an already signed form
	try
	{
		Bureaucrat seniorBureaucrat("Senior Julia", 5);
		Form signedForm("SignedForm", 20, 20);
		seniorBureaucrat.signForm(signedForm); // First attempt to sign
		seniorBureaucrat.signForm(signedForm); // Second attempt to sign
	}
	catch (const std::exception &e)
	{
		std::cerr << Colors::RED << "Re-sign attempt: " << e.what() << Colors::RESET << '\n';
	}

	return 0;
}
