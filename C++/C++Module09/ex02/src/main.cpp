/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:20:19 by atoof             #+#    #+#             */
/*   Updated: 2024/03/01 13:27:07 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"


int main(int argc, char* argv[])
{
    // Check if at least one integer is provided
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
		if (argv[i][0] == '-')
		{
			std::cerr << "Invalid input: " << argv[i] << ". Please enter only positive integers." << std::endl;
			return 1;
		}
        if (iss >> num) // if the conversion to int is successful
		{
			numbers.push_back(num);
			numbers2.push_back(num);
		}
        else
		{
            std::cerr << "Invalid input: " << argv[i] << ". Please enter only integers." << std::endl;
            return 1;
        }
    }
	std::cout << "Unsorted positive integer sequence: ";
	for (int i = 1; i < argc; ++i){std::cout <<argv[i] << " ";}
	std::cout << std::endl;

	std::cout << Colors::BRIGHT_BLUE << "******************** Vector ********************" << Colors::RESET << std::endl;
	PmergeMe<int, std::vector> sorter;
	sorter.sortContainer(numbers);
	
	std::cout << Colors::BRIGHT_BLUE << "******************** deque ********************" << Colors::RESET << std::endl;
	PmergeMe<int, std::deque> sorter2;
	sorter2.sortContainer(numbers2);


    return 0;

}
