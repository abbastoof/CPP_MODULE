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

void testBureaucrat(const std::string& name, int grade) {
    try {
        Bureaucrat bureaucrat(name, grade);
        std::cout << bureaucrat << std::endl;

        // Decrementing the grade
        bureaucrat.decrementGrade();
        std::cout << "After decrement: " << bureaucrat << std::endl;

        // Incrementing the grade
        bureaucrat.incrementGrade();
        std::cout << "After increment: " << bureaucrat << std::endl;
    } catch (const std::exception& e) {
        // Catching all exceptions derived from std::exception
        std::cout << "Exception for " << name << ": " << e.what() << std::endl;
    }
}

int main(void) {
    std::cout << "Test 1" << std::endl;
    testBureaucrat("Bureaucrat1", MIN_GRADE);

    std::cout << "Test 2" << std::endl;
    testBureaucrat("Bureaucrat2", MAX_GRADE);

    std::cout << "Test 3" << std::endl;
    testBureaucrat("Bureaucrat3", 100);

    std::cout << "Test 4" << std::endl;
    testBureaucrat("Bureaucrat4", 0); // This might trigger an exception depending on the Bureaucrat class implementation

    std::cout << "Test 5" << std::endl;
    testBureaucrat("Bureaucrat5", 151); // This might also trigger an exception

    return 0;
}
