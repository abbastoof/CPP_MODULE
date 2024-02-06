/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:24:08 by atoof             #+#    #+#             */
/*   Updated: 2024/02/05 15:24:08 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream> // std::ofstream and std::ifstream are defined here for file I/O operations

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		// Default constructor
		ShrubberyCreationForm();
		// Parameter constructor
		ShrubberyCreationForm(std::string target);
		// Copy constructor
		ShrubberyCreationForm(ShrubberyCreationForm const & rhs);
		// Destructor
		virtual ~ShrubberyCreationForm();

		// Operator overloads
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
		// member functions
		virtual void execute(Bureaucrat const & executor) const override;
};

#endif
