/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:21:48 by atoof             #+#    #+#             */
/*   Updated: 2024/02/12 13:36:25 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string>
// #include <utility>
// #include <iostream>

// template <typename T>
// T const & max(T const & x, T const & y)
// {
// 	return (x>=y ? x : y);
// }

// int main(void)
// {
// 	std::cout << "enter two numbers: ";
// 	int x,y = 0;
// 	std::cin >> x; std::cin >> y ; std::cout << std::endl;
// 	int max_num = max(x, y);
// 	std::cout << "Max number is " << max_num << std::endl;
// 	return 0;
// }

/* ********************************************************************************************** */

#include <iostream>
#include "Vertex.class.tpp"

int main (void) {
	Vertex<int>	v1(12, 23, 14);
	Vertex<>	v2(12, 23, 14);

	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;
}