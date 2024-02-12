/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:52:34 by atoof             #+#    #+#             */
/*   Updated: 2024/02/12 16:13:01 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename ArrayType, typename Function>
void iter(ArrayType *arr, size_t len, Function func)
{
	for (size_t i = 0; i < len; ++i)
	{
		func(arr[i]);
	}
}

#endif