/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:03:44 by atoof             #+#    #+#             */
/*   Updated: 2023/11/13 19:03:44 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ClapTrap.hpp"


int main()
{
    ClapTrap Player1("Player1");
    ClapTrap Player2("Player2");

    Player1.attack("Player2");
    Player2.takeDamage(5);
    Player2.beRepaired(5);
    Player2.attack("Player1");
    Player1.takeDamage(5);
    Player1.beRepaired(5);
    Player1.attack("Player2");
    Player2.takeDamage(10);
    Player1.attack("Player2");
    Player2.takeDamage(10);
    Player1.attack("Player2");
    Player2.takeDamage(10);
    Player1.attack("Player2");
    Player2.attack("Player1");
    return (0);
}
