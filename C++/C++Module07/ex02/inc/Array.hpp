/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:53:05 by atoof             #+#    #+#             */
/*   Updated: 2024/02/13 11:06:13 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
	private:
		T *_array;
		size_t _size;
	public:
	Array();
	Array(size_t n);
	Array(Array const &rhs);
	~Array();
	
	Array &operator=(Array const &rhs);
	
	/* The subscript operator [] is normally used to access array elements. */
	T &operator[](size_t index);
	size_t getSize() const;
};
#include "Array.tpp"

#endif