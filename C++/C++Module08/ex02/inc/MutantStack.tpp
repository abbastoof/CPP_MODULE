/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:49:38 by atoof             #+#    #+#             */
/*   Updated: 2024/02/15 20:21:20 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() {}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& src) : std::stack<T, Container>(src)
{
	*this = src;
}

template <typename T, typename Container>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
    std::stack<T>::operator=(other);
    return *this;
}

template <typename T, typename Container>
MutantStack<T>::~MutantStack() {}

template <typename T, typename Container>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return std::stack<T>::c.begin();
}

template <typename T, typename Container>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return std::stack<T>::c.end();
}

template <typename T, typename Container>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return std::stack<T>::c.begin();
}

template <typename T, typename Container>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return std::stack<T>::c.end();
}

template <typename T, typename Container>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return std::stack<T>::c.rbegin();
}

template <typename T, typename Container>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return std::stack<T>::c.rend();
}

template <typename T, typename Container>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin() const
{
	return std::stack<T>::c.crbegin();
}

template <typename T, typename Container>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend() const
{
	return std::stack<T>::c.crend();
}