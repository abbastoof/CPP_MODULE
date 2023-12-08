/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:07:47 by atoof             #+#    #+#             */
/*   Updated: 2023/12/08 17:57:21 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "colors.hpp"
#include <string>

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _inventory[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &rhs);
		MateriaSource &operator=(const MateriaSource &rhs);
		~MateriaSource();
		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
};

#endif