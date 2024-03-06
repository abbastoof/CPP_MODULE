/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:20:19 by atoof             #+#    #+#             */
/*   Updated: 2024/03/06 19:25:23 by atoof            ###   ########.fr       */
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
		if (!(iss >> num) || !iss.eof())
		{ // Checks if the conversion failed or there are trailing characters
			std::cerr << "Invalid input: " << argv[i] << ". Please enter only integers." << std::endl;
			return 1;
		}
		if (num <= 0)
		{
			std::cerr << "Invalid input: " << argv[i] << ". Please enter only positive integers." << std::endl;
			return 1;
		}
		numbers.push_back(num);
		numbers2.push_back(num);
	}

	std::cout << "Unsorted positive integer sequence: ";
	for (int i = 1; i < argc; ++i)
	{
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;

	std::cout << Colors::BRIGHT_BLUE << "******************** Vector ********************" << Colors::RESET << std::endl;
	PmergeMe<int, std::vector> sorter;
	sorter.sortContainer(numbers);

	std::cout << Colors::BRIGHT_BLUE << "******************** deque ********************" << Colors::RESET << std::endl;
	PmergeMe<int, std::deque> sorter2;
	sorter2.sortContainer(numbers2);

	return 0;
}
