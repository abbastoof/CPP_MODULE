/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 23:44:43 by atoof             #+#    #+#             */
/*   Updated: 2024/02/11 23:44:43 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
		std::cout << "------------TEST 1------------" << std::endl;
		Serializer::Data data;
		data.s1 = "Hello";
		data.n = 42;
		data.s2 = "World";
		std::cout << "Original: " << data.s1 << " " << data.n << " " << data.s2 << std::endl;
		uintptr_t raw = Serializer::serialize(&data);
		std::cout << "Serialized: " << "0x" << std::hex << raw << std::dec << std::endl;
		Serializer::Data *ptr = Serializer::deserialize(raw);
		std::cout << "Deserialized: " << ptr->s1 << " " << ptr->n << " " << ptr->s2 << std::endl;
		delete ptr;
		std::cout << "------------TEST 2------------" << std::endl;
		Serializer::Data data2;
		data2.s1 = "Goodbye";
		data2.n = 21;
		data2.s2 = "Cruel World";
		std::cout << "Original: " << data2.s1 << " " << data2.n << " " << data2.s2 << std::endl;
		uintptr_t raw2 = Serializer::serialize(&data2);
		std::cout << "Serialized: " << "0x" << std::hex << raw2 << std::dec << std::endl;
		Serializer::Data *ptr2 = Serializer::deserialize(raw2);
		std::cout << "Deserialized: " << ptr2->s1 << " " << ptr2->n << " " << ptr2->s2 << std::endl;
		delete ptr2;
		return 0;
}
