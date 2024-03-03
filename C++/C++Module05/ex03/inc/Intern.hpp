/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:34:51 by atoof             #+#    #+#             */
/*   Updated: 2024/03/03 14:31:18 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string.h>
#include <memory>

class Intern
{
	public:
		Intern(void);
		Intern(const Intern& rhs);
		~Intern(void);

		Intern& operator=(const Intern& rhs);
		std::shared_ptr<AForm> makeForm(const std::string &formName, const std::string &target);

};

#endif
