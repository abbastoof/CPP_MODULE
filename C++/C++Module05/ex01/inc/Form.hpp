/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:35:41 by atoof             #+#    #+#             */
/*   Updated: 2024/02/02 23:35:41 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat; // forward declaration

class Form
{
	private:
		const std::string	_name;
		bool			_signed;
		const int		_gradeToSign;
		const int		_gradeToExecute;

	public:
		// Default constructor
		Form();
		// Parameter constructor
		Form(std::string name, int gradeToSign, int gradeToExecute);
		// Copy constructor
		Form(const Form &rhs);
		// Destructor
		~Form();

		//Operator Overload
		Form &operator=(const Form &rhs);

		//getter


};

#endif
