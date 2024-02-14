/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:05:06 by atoof             #+#    #+#             */
/*   Updated: 2024/02/14 13:52:17 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

/*

1) The function template easyfind that accepts a type T.  => done
2) It takes two parameters. => done
3) The first one has type T and the second one is an integer. 		=> done
4) Assuming T is a container of integers, this function has to find the first occurrence of the second parameter in the first parameter. => done
5) If no occurrence is found, you can either throw an exception or return an error value of your choice.  => done

Note* (If you need some inspiration, analyze how standard containers behave.)
Of course, implement and turn in your own tests to ensure everything works as expected.

Note2* (You don’t have to handle associative containers.) => done
 Associative containers: Containers that store elements in a sorted order. Such as set, map, multimap, multiset, etc.
 An Associative Container is a variable-sized Container that supports efficient retrieval of elements (values) based on keys. 

*/

# include <iostream>
# include <algorithm>
# include <exception>
# include <vector>
# include <list>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = container.begin();
	typename T::iterator ite = container.end();

	while (it != ite)
	{
		if (*it == value)
			return it;
		++it;
	}
	throw std::out_of_range("Value not found in container.");
}

#endif