/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:40:06 by atoof             #+#    #+#             */
/*   Updated: 2024/03/03 14:36:57 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Intern.hpp"
#include "../inc/Colors.hpp"
#include <iostream>

void testFormExecution(const std::string &testName, Bureaucrat &bureaucrat, AForm &form) {
    std::cout << "\n" << Colors::BG_BLUE << testName << Colors::RESET << std::endl;
    try {
        std::cout << bureaucrat;
        std::cout << form;
        bureaucrat.signForm(form);
        bureaucrat.executeForm(form);
    } catch (std::exception &e) {
        std::cout << Colors::RED << e.what() << Colors::RESET << std::endl;
    }
}

void testInternFormCreation(const std::string &formName, const std::string &target) {
    std::cout << "\n" << Colors::BG_BLUE << "Test Intern creating " << formName << Colors::RESET << std::endl;
    try {
        Intern intern;
        std::shared_ptr<AForm> form = intern.makeForm(formName, target);
        std::cout << *form;
    } catch (std::exception &e) {
        std::cout << Colors::RED << e.what() << Colors::RESET << std::endl;
    }
}

int main() {
    Bureaucrat low("Low", 150);
    Bureaucrat high("High", 1);
    ShrubberyCreationForm shrubberyForm("home");
    RobotomyRequestForm robotomyForm("home");
    PresidentialPardonForm pardonForm("home");

    testFormExecution("Low grade ShrubberyCreationForm", low, shrubberyForm);
    testFormExecution("High grade ShrubberyCreationForm", high, shrubberyForm);
    testFormExecution("RobotomyRequestForm", high, robotomyForm);
    testFormExecution("PresidentialPardonForm", high, pardonForm);

    testInternFormCreation("robotomy request", "Bender");
    testInternFormCreation("presidential pardon", "Bender");
    testInternFormCreation("shrubbery creation", "Bender");
    testInternFormCreation("invalid form", "Target"); // Expected to throw an exception

    return 0;
}
