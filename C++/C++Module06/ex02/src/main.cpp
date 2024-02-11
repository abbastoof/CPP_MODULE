/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 01:00:28 by atoof             #+#    #+#             */
/*   Updated: 2024/02/12 01:00:28 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Base.hpp"

int main()
{
	Base *test = generate();
	Base &test_ref = *test;
	std::cout << "Pointer: ";
	identify(test);
	std::cout << "Reference: ";
	identify(test_ref);
	delete test;
	return(0);
}
