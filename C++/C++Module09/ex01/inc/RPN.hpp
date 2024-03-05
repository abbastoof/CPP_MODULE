/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:35:10 by atoof             #+#    #+#             */
/*   Updated: 2024/03/05 22:24:44 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <iostream>

template<typename T>
class RPN
{
public:
	RPN();
    ~RPN(); // Destructor
    T evaluate(const std::string& expression);


private:
    RPN(const RPN& rhs);
    RPN& operator=(const RPN& rhs);
    int performOperation(char op, T a, T b);
    void processToken(const std::string& token, std::stack<T>& stack);
};

#endif
