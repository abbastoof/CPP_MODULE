/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:20:19 by atoof             #+#    #+#             */
/*   Updated: 2024/02/26 17:03:38 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int main(int argc, char **argv)
{
	std::vector<int> integers;
	for (int i = 1; i < argc; ++i)
	{
		int value = std::atoi(argv[i]);
		if (value <= 0)
		{
			std::cerr << "Error: All inputs must be positive integers." << std::endl;
			return 1;
		}
		integers.push_back(value);
	}
	PmergeMe p;
	p.sortVector(integers);
}