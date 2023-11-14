/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:22:23 by atoof             #+#    #+#             */
/*   Updated: 2023/11/10 19:10:05 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

int main( void )
{
	Point a(0, 0);
	Point b(10, 30);
	Point c(20, 0);
	Point p1(10, 15);
	Point p2(30, 15);
	Point p3(19.5, 1);
	if (bsp(a, b, c, p1))
		std::cout << "Inside the area" << std::endl;
	else
		std::cout << "Outside the area" << std::endl;
	if (bsp(a, b, c, p2))
		std::cout << "Inside the area" << std::endl;
	else
		std::cout << "outside the area" << std::endl;
	if (bsp(a, b, c, p3))
		std::cout << "Inside the area" << std::endl;
	else
		std::cout << "outside the area" << std::endl;
	return 0;
}
