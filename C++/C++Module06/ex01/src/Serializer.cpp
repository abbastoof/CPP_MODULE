/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 23:39:40 by atoof             #+#    #+#             */
/*   Updated: 2024/03/03 17:59:59 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

// unsigned integer types large enough to hold a pointer
uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr); // Converts a pointer to data into an unsigned integer to safely store the pointer's address.
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw); // Converts an unsigned integer back into a pointer to Data, restoring the original pointer from its stored address.
}

Serializer::Serializer() {}

Serializer::Serializer(Serializer const &src)
{
	*this = src;
}

Serializer &Serializer::operator=(Serializer const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

Serializer::~Serializer() {}
