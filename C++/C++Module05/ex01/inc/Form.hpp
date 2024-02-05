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
		Form(std::string name, bool sign, int gradeToSign, int gradeToExecute);
		// Copy constructor
		Form(const Form &rhs);

		// Destructor
		~Form();

		//Operator Overload
		Form &operator=(const Form &rhs);

		//getter
		const std::string	&getName() const;
		bool			getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		//member functions
		void			beSigned(Bureaucrat &bureaucrat);

		// Exceptions classes
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

};

std::ostream	&operator<<(std::ostream &out, const Form &rhs);

#endif
