/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:12:15 by atoof             #+#    #+#             */
/*   Updated: 2023/12/08 17:57:05 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "colors.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure &rhs);
		Cure &operator=(const Cure &rhs);
		~Cure();
		
		
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target); 	
};

#endif