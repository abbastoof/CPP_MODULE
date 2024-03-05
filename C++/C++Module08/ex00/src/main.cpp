/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:02:21 by atoof             #+#    #+#             */
/*   Updated: 2024/03/05 10:59:27 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Easyfind.hpp"
#include "../inc/color.hpp"
#include <vector>
#include <iostream>
#include <list>
#include <vector>

template <typename Container>
void testFind(Container const & container, int value, const std::string& testName)
{
    try
	{
        typename Container::const_iterator it = easyfind(container, value);
        std::cout << setColor(GREEN) << "Test " << testName << ": Found " << value << " at position: "
                  << std::distance(container.begin(), it) << setColor(RESET) << std::endl;
    }
	catch (std::exception& e)
	{
        std::cout << setColor(YELLOW) << "Test " << testName << ": " << e.what() << setColor(RESET) << std::endl;
    }
}


int main() {
    // Test with a standard list
    std::list<int> myList = {1, -2, 3, 4, 5, -6};
    testFind(myList, -2, "Standard List");

    // Test with an empty vector
    std::vector<int> emptyVec;
    testFind(emptyVec, 1, "Empty Vector");

    // Test with multiple occurrences
    std::vector<int> multiVec = {7, 1, 7, 3, 7};
    testFind(multiVec, 7, "Multiple Occurrences");

    // Test with first and last elements
    std::vector<int> edgeVec = {9, 2, 3, 4, 8};
    testFind(edgeVec, 9, "First Element");
    testFind(edgeVec, 8, "Last Element");

    // Test with a large vector
    std::vector<int> largeVec(100000, 1);
    largeVec[50000] = 2;
    testFind(largeVec, 2, "Large Vector");

    // Test for non-existent values near container bounds
    std::vector<int> boundVec = {0, 1, 2, 3, 4};
    testFind(boundVec, -1, "Lower Bound");
    testFind(boundVec, 5, "Upper Bound");

    return 0;
}
