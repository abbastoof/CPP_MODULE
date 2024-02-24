/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:39:33 by atoof             #+#    #+#             */
/*   Updated: 2024/02/24 13:39:33 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <stdexcept>
# include <cctype> // for std::isdigit
# include <string>

template <typename T>
class RPN{
	public:
		RPN();
		RPN(const RPN& rhs);
		~RPN();

		RPN& operator=(const RPN& rhs);

		T readLine(const std::string& expression);

	private:
		void processToken(const std::string& token, std::stack<T>& stack);
		int performOperation(char op, T a, T b);

};


#endif
