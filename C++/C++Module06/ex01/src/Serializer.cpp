/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 23:39:40 by atoof             #+#    #+#             */
/*   Updated: 2024/02/11 23:39:40 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

// unsigned integer types large enough to hold a pointer
uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Serializer::Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
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
