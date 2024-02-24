/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:38:58 by atoof             #+#    #+#             */
/*   Updated: 2024/02/24 13:38:58 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

template<typename T>
RPN<T>::RPN() {}

template<typename T>
RPN<T>::RPN(const RPN &rhs) {*this = rhs;}

template<typename T>
RPN<T>::~RPN() {}

// Operator overload
template<typename T>
RPN<T> &RPN<T>::operator=(const RPN &rhs){
	void(rhs);
	return (*this);
}

template<typename T>
T RPN<T>::readLine(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;
	std::stack<T> stack;

	while (iss >> token)
		processToken(token, stack);
	if (stack.size() != 1)
		throw std::runtime_error("Invalid expression.");
	return stack.top();
}

template<typename T>
void RPN<T>::processToken(const std::string &token, std::stack<T> &stack)
{
	if (isdigit(token[0]))
		stack.push(static_cast<T>(std::stoi(token)));
	else if (token.size() == 1 std::string("+-*/").find(token[0]) != std::string::npos) // in this line, the size of the token is checked and the token is compared to the string of operators to see if it is a valid operator or not, if it is not, the function will throw an error
	{
		if (stack.size() < 2)
			throw std::runtime_error("Invalid expression.");
		T b = stack.top();
		stack.pop();
		T a = stack.top();
		stack.pop();
		stack.push(performOperation(token[0], a, b));
	}
	else
		throw std::runtime_error("Invalid token.");
}

template<typename T>
int RPN<T>::performOperation(char op, T a, T b)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		if (b == 0)
			throw std::runtime_error("Division by zero.");
		return a / b;
	default:
		throw std::runtime_error("Invalid operator.");
	}
}
