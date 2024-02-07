/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Color.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:43:17 by atoof             #+#    #+#             */
/*   Updated: 2024/02/07 13:43:17 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_HPP
#define COLORS_HPP


namespace Colors
{
	const char *const RESET = "\033[0m";
	const char *const BLACK = "\033[30m";
	const char *const RED = "\033[31m";
	const char *const GREEN = "\033[32m";
	const char *const YELLOW = "\033[33m";
	const char *const BLUE = "\033[34m";
	const char *const MAGENTA = "\033[35m";
	const char *const CYAN = "\033[36m";
	const char *const WHITE = "\033[37m";


	const char *const BRIGHT_BLACK = "\033[90m";
	const char *const BRIGHT_RED = "\033[91m";
	const char *const BRIGHT_GREEN = "\033[92m";
	const char *const BRIGHT_YELLOW = "\033[93m";
	const char *const BRIGHT_BLUE = "\033[94m";
	const char *const BRIGHT_MAGENTA = "\033[95m";
	const char *const BRIGHT_CYAN = "\033[96m";
	const char *const BRIGHT_WHITE = "\033[97m";


	const char *const BG_BLACK = "\033[40m";
	const char *const BG_RED = "\033[41m";
	const char *const BG_GREEN = "\033[42m";
	const char *const BG_YELLOW = "\033[43m";
	const char *const BG_BLUE = "\033[44m";
	const char *const BG_MAGENTA = "\033[45m";
	const char *const BG_CYAN = "\033[46m";
	const char *const BG_WHITE = "\033[47m";
}

#endif
