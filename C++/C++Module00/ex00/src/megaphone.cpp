/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:32:36 by atoof             #+#    #+#             */
/*   Updated: 2023/08/30 17:27:22 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    int j = 1;
    if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 1;
	}
	else
    {
        while (j < argc)
        {
            int i = 0;
            while (argv[j][i])
            {
                std::cout << (char)std::toupper(argv[j][i]);
                i++;
            }
            j++;
        }
		std::cout << std::endl;
    }
    return 0;
}
