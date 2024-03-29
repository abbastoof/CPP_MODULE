/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:05:06 by atoof             #+#    #+#             */
/*   Updated: 2024/03/05 13:27:46 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <exception>
# include <vector>
# include <list>

template <typename T>
typename T::const_iterator easyfind(T const &container, int value)
{
	typename T::const_iterator it = container.begin();
	typename T::const_iterator ite = container.end();

	while (it != ite)
	{
		if (*it == value)
			return it;
		++it;
	}
	throw std::out_of_range("Value not found in container.");
}

#endif
