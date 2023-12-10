/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:57:46 by atoof             #+#    #+#             */
/*   Updated: 2023/12/10 15:02:05 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  _AMATERIA_HPP_
# define _AMATERIA_HPP_

#include <iostream>
#include <string>
#include "colors.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria();
		AMateria(const AMateria &copy);
		AMateria(std::string const & type);
		AMateria &operator=(const AMateria &rhs);
		virtual ~AMateria();
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif