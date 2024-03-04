/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:07:05 by atoof             #+#    #+#             */
/*   Updated: 2024/03/04 17:51:27 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

/* The default constructor that should create an empty array. */
template <typename T>
Array<T>::Array() : _array(nullptr), _size(0) {}

/* The constructor that takes a single parameter n. It should allocate an array of size n. */
template <typename T>
Array<T>::Array(size_t n) : _array(new T[n]), _size(n) {}

/* The copy constructor. */
template <typename T>
Array<T>::Array(Array const &rhs) : _array(nullptr), _size(0)
{
	*this = rhs;
}

/* The assignment operator= that should do deep copy of the array. */
template <typename T>
Array<T> &Array<T>::operator=(Array const &rhs)
{
	if (this != &rhs)
	{
		delete[] _array;
		_size = rhs._size;
		_array = new T[_size];
		for (size_t i = 0; i < _size; i++)
			_array[i] = rhs._array[i];
	}
	return *this;
}

// Non-const version of operator[] for reading and writing
template <class T>
T &Array<T>::operator[](size_t index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _array[index];
}

// Const version of operator[] for read-only access
template <class T>
const T &Array<T>::operator[](size_t index) const
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _array[index];
}

/* Destructor */
template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

/* Getter */
template <typename T>
size_t Array<T>::getSize() const
{
	return (this->_size);
}

#endif