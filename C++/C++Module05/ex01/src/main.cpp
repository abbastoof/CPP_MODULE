/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:40:06 by atoof             #+#    #+#             */
/*   Updated: 2024/02/06 13:24:42 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main(void)
{
    try
    {
        Bureaucrat seniorBureaucrat("Senior John", 5);
        Form importantForm("ImportantForm", 5, 5);
        std::cout << importantForm << std::endl;
        std::cout << seniorBureaucrat << std::endl;
        importantForm.beSigned(seniorBureaucrat);
        std::cout << importantForm << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat juniorBureaucrat("Junior Jim", 15);
        Form standardForm("StandardForm", 20, 10);
        std::cout << juniorBureaucrat << std::endl;
        juniorBureaucrat.signForm(standardForm);
        std::cout << standardForm << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }

    try
    {
        Form invalidForm("InvalidForm", 0, -1);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return 0;
}
