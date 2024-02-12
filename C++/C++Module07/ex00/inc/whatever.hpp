/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:49:17 by atoof             #+#    #+#             */
/*   Updated: 2024/02/12 15:35:00 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>

template< typename T>
void swap(T & x, T & y) {
	T tmp = x;
	x = y;
	y = tmp;
}

template< typename T>
const T & min(const T & x, const T & y)
{
	return (x <= y ? x : y);
}

template< typename T>
const T & max(const T & x, const T & y)
{
	return (x >= y ? x : y);
}

#endif