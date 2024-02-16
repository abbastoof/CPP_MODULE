/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:49:38 by atoof             #+#    #+#             */
/*   Updated: 2024/02/16 15:14:01 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/*
 Resources:
	https://cplusplus.com/reference/vector/vector/rbegin/
	https://cplusplus.com/reference/vector/vector/begin/
*/

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() {}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& src) : std::stack<T, Container>(src)
{
	*this = src;
}

template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& other)
{
    std::stack<T, Container>::operator=(other);
    return *this;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return std::stack<T, Container>::c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
	return std::stack<T, Container>::c.end();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const
{
	return std::stack<T, Container>::c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const
{
	return std::stack<T, Container>::c.end();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin()
{
	return std::stack<T, Container>::c.rbegin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend()
{
	return std::stack<T, Container>::c.rend();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::crbegin() const
{
	return std::stack<T, Container>::c.crbegin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::crend() const
{
	return std::stack<T, Container>::c.crend();
}