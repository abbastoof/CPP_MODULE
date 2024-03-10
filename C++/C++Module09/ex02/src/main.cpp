/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:20:19 by atoof             #+#    #+#             */
/*   Updated: 2024/03/10 11:15:20 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " [list of integers]" << std::endl;
        return 1;
    }

    std::vector<int> numbers;
    std::deque<int> numbers2;
    for (int i = 1; i < argc; ++i)
    {
        std::istringstream iss(argv[i]);
        int num;
        if (!(iss >> num) || !iss.eof()) // Check for conversion failure or trailing characters
        {
            std::cerr << "Invalid input: " << argv[i] << ". Please enter only integers." << std::endl;
            return 1;
        }
        numbers.push_back(num);
        numbers2.push_back(num);
    }

    // Display the "Before" sequence (which is the same for both containers)
    std::cout << "Before: ";
    for (int num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Sort the vector and measure the duration
    PmergeMe<int, std::vector> sorter;
    double vectorDuration = sorter.sortContainer(numbers);

    // Sort the deque and measure the duration
    PmergeMe<int, std::deque> sorter2;
    double dequeDuration = sorter2.sortContainer(numbers2);

    // Display the "After" sequence using the sorted vector (or deque, since they should be identical)
    std::cout << "After: ";
    for (int num : numbers)  // You could also use numbers2 here since both should have been sorted identically
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Print the durations for both sorts
    std::cout << "Time to process a range of " << numbers.size() << " elements with std::vector: " << std::fixed << std::setprecision(5) << vectorDuration << " us" << std::endl;
    std::cout << "Time to process a range of " << numbers2.size() << " elements with std::deque: " << std::fixed << std::setprecision(5) << dequeDuration << " us" << std::endl;

    return 0;
}

