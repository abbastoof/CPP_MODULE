/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:02:21 by atoof             #+#    #+#             */
/*   Updated: 2024/02/14 13:28:09 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"
#include "../inc/color.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
    // Test with a standard list
    std::list<int> myList = {1, -2, 3, 4, 5, -6};
    std::list<int>::iterator itList = easyfind(myList, -2);
    std::cout << setColor(GREEN) << "Found -2 in list at position: " << std::distance(myList.begin(), itList) << setColor(RESET) << std::endl;

    // Test with an empty vector
    std::vector<int> emptyVec;
    try {
        easyfind(emptyVec, 1);
        std::cout << setColor(RED) << "Found 1 in empty vector, which should not happen." << setColor(RESET) << std::endl;
    } catch (std::exception &e) {
        std::cout << setColor(YELLOW) << "Correctly caught error for empty vector: " << e.what() << setColor(RESET) << std::endl;
    }

    // Test with multiple occurrences
    std::vector<int> multiVec = {7, 1, 7, 3, 7};
    std::vector<int>::iterator itMulti = easyfind(multiVec, 7);
    std::cout << setColor(GREEN) << "Found 7 in vector with multiple occurrences at position: " << std::distance(multiVec.begin(), itMulti) << setColor(RESET) << std::endl;

    // Test with first and last elements
    std::vector<int> edgeVec = {9, 2, 3, 4, 8};
    std::vector<int>::iterator itFirst = easyfind(edgeVec, 9);
    std::cout << setColor(GREEN) << "Found first element 9 at position: " << std::distance(edgeVec.begin(), itFirst) << setColor(RESET) << std::endl;
    std::vector<int>::iterator itLast = easyfind(edgeVec, 8);
    std::cout << setColor(GREEN) << "Found last element 8 at position: " << std::distance(edgeVec.begin(), itLast) << setColor(RESET) << std::endl;

    // Test with a large vector
    std::vector<int> largeVec(100000, 1);
    largeVec[50000] = 2;
    std::vector<int>::iterator itLarge = easyfind(largeVec, 2);
    std::cout << setColor(GREEN) << "Found 2 in large vector at position: " << std::distance(largeVec.begin(), itLarge) << setColor(RESET) << std::endl;

    // Test for non-existent values near container bounds
    std::vector<int> boundVec = {0, 1, 2, 3, 4};
    try {
        easyfind(boundVec, -1);
        std::cout << setColor(RED) << "Incorrectly found -1 in boundVec." << setColor(RESET) << std::endl;
    } catch (std::exception &e) {
        std::cout << setColor(YELLOW) << "Correctly did not find -1: " << e.what() << setColor(RESET) << std::endl;
    }

    try {
        easyfind(boundVec, 5); // Test for a value just above the upper bound
        std::cout << setColor(RED) << "Incorrectly found 5 in boundVec." << setColor(RESET) << std::endl;
    } catch (std::exception &e) {
        std::cout << setColor(YELLOW) << "Correctly did not find 5: " << e.what() << setColor(RESET) << std::endl;
    }

    return 0;
}
