/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:57:46 by atoof             #+#    #+#             */
/*   Updated: 2023/11/21 16:15:15 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  _AMATERIA_HPP_
# define _AMATERIA_HPP_

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:

public:
	AMateria(std::string const & type);

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif