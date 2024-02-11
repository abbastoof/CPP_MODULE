/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 23:40:17 by atoof             #+#    #+#             */
/*   Updated: 2024/02/11 23:40:17 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>

class Serializer
{
public:
	struct Data
	{
		std::string s1;
		int n;
		std::string s2;
	};
	static uintptr_t serialize(Data* ptr);
	static Data *deserialize(uintptr_t raw);
private:
	Serializer(void);
	Serializer(Serializer const &src);
	Serializer &operator=(Serializer const &rhs);
	~Serializer();
};

#endif
