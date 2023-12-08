/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:34:52 by atoof             #+#    #+#             */
/*   Updated: 2023/12/08 17:57:00 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "colors.hpp"
class AMateria;

class Character : public ICharacter
{
	private:
		AMateria*	_inventory[4];
		std::string	_name;
	public:
		Character();
		Character(std::string name);
		Character(const Character &copy);
		Character &operator=(const Character &rhs);
		~Character();
		virtual std::string const & getName() const;
		virtual void equip(AMateria* materia);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif