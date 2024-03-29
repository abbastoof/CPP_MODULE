/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:43:17 by atoof             #+#    #+#             */
/*   Updated: 2024/03/01 11:49:21 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_HPP
#define COLORS_HPP


struct Colors
{
    static constexpr const char* RESET = "\033[0m";
    static constexpr const char* BLACK = "\033[30m";
    static constexpr const char* RED = "\033[31m";
    static constexpr const char* GREEN = "\033[32m";
    static constexpr const char* YELLOW = "\033[33m";
    static constexpr const char* BLUE = "\033[34m";
    static constexpr const char* MAGENTA = "\033[35m";
    static constexpr const char* CYAN = "\033[36m";
    static constexpr const char* WHITE = "\033[37m";

    static constexpr const char* BRIGHT_BLACK = "\033[90m";
    static constexpr const char* BRIGHT_RED = "\033[91m";
    static constexpr const char* BRIGHT_GREEN = "\033[92m";
    static constexpr const char* BRIGHT_YELLOW = "\033[93m";
    static constexpr const char* BRIGHT_BLUE = "\033[94m";
    static constexpr const char* BRIGHT_MAGENTA = "\033[95m";
    static constexpr const char* BRIGHT_CYAN = "\033[96m";
    static constexpr const char* BRIGHT_WHITE = "\033[97m";

    static constexpr const char* BG_BLACK = "\033[40m";
    static constexpr const char* BG_RED = "\033[41m";
    static constexpr const char* BG_GREEN = "\033[42m";
    static constexpr const char* BG_YELLOW = "\033[43m";
    static constexpr const char* BG_BLUE = "\033[44m";
    static constexpr const char* BG_MAGENTA = "\033[45m";
    static constexpr const char* BG_CYAN = "\033[46m";
    static constexpr const char* BG_WHITE = "\033[47m";
};

#endif
