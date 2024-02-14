/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:20:41 by atoof             #+#    #+#             */
/*   Updated: 2024/02/14 13:23:58 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_HPP
#define COLOR_HPP

#include <iostream>

enum ColorCode
{
    RESET,
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
};

const char* setColor(ColorCode color)
{
    switch(color)
	{
        case BLACK: return "\033[30m";
        case RED: return "\033[31m";
        case GREEN: return "\033[32m";
        case YELLOW: return "\033[33m";
        case BLUE: return "\033[34m";
        case MAGENTA: return "\033[35m";
        case CYAN: return "\033[36m";
        case WHITE: return "\033[37m";
        case RESET:
        default: return "\033[0m";
    }
}

#endif
