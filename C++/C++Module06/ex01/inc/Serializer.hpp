/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 23:40:17 by atoof             #+#    #+#             */
/*   Updated: 2024/02/13 15:35:32 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>
#include "struct.hpp"

class Serializer
{
public:

	static uintptr_t serialize(Data* ptr);
	static Data *deserialize(uintptr_t raw);
private:
	Serializer(void);
	Serializer(Serializer const &src);
	Serializer &operator=(Serializer const &rhs);
	~Serializer();
};

#endif
