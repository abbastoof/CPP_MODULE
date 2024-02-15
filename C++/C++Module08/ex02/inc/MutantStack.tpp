/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:49:38 by atoof             #+#    #+#             */
/*   Updated: 2024/02/15 20:03:01 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
    std::stack<T>::operator=(other);
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return std::stack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return std::stack<T>::c.end();
}
