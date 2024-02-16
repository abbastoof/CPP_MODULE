/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:43:28 by atoof             #+#    #+#             */
/*   Updated: 2024/02/15 20:17:35 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iostream>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
public:
    // Alias for iterator types
    typedef typename std::deque<T>::iterator iterator;
    typedef typename std::deque<T>::const_iterator const_iterator;
    typedef typename std::deque<T>::reverse_iterator reverse_iterator;
    typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

    // Constructors, destructor, and assignment operator
    MutantStack();
    MutantStack(const MutantStack& other);
    MutantStack& operator=(const MutantStack& other);
    virtual ~MutantStack();

    // Iterator functions
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    // Reverse iterator functions
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;
};

#include "MutantStack.tpp"
#endif
