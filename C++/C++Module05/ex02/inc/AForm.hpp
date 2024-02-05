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

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat; // forward declaration
const int MAX_GRADE = 1;
const int MIN_GRADE = 150;

class AForm
{
	private:
		const std::string	_name;
		bool			_signed;
		const int		_gradeToSign;
		const int		_gradeToExecute;

	public:
		// Default constructor
		AForm();
		// Parameter constructor
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		// Copy constructor
		AForm(const AForm &rhs);

		// Destructor
		virtual ~AForm() = 0; // Making destructor virtual as a good practice for base classes
		//Operator Overload
		AForm &operator=(const AForm &rhs);

		//getter
		const std::string	&getName() const;
		bool			getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		//member functions
		virtual void		beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0; // Pure virtual function
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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

};

std::ostream	&operator<<(std::ostream &out, const AForm &rhs);

#endif
