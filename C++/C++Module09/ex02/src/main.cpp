/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:20:19 by atoof             #+#    #+#             */
/*   Updated: 2024/02/26 20:02:32 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <sstream>


int main(int argc, char* argv[])
{
    // Check if at least one integer is provided
    if (argc < 2)
	{
        std::cerr << "Usage: " << argv[0] << " [list of integers]" << std::endl;
        return 1;
    }

    std::vector<int> numbers;
    // Start from 1 to skip the program name
    for (int i = 1; i < argc; ++i)
	{
        std::istringstream iss(argv[i]);
        int num;
		if (argv[i][0] == '-')
		{
			std::cerr << "Invalid input: " << argv[i] << ". Please enter only positive integers." << std::endl;
			return 1;
		}
        if (iss >> num) { // Check if the input is a valid integer
            numbers.push_back(num);
        } else {
            std::cerr << "Invalid input: " << argv[i] << ". Please enter only integers." << std::endl;
            return 1;
        }
    }
	
    PmergeMe sorter;

    sorter.sortVector(numbers);

    // Print the sorted sequence
    std::cout << "Sorted sequence: ";
    for (const int& num : numbers)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;

}