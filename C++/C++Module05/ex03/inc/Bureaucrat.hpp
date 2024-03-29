/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:16:08 by atoof             #+#    #+#             */
/*   Updated: 2024/02/06 14:53:34 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP


# include <iostream>

class AForm; // forward declaration

class Bureaucrat
{
	private:
		const std::string	_name;
		int		_grade;

	public:
		// Default constructor
		Bureaucrat();
		// Parameter constructor
		Bureaucrat(std::string name, int grade);
		// Copy constructor
		Bureaucrat(const Bureaucrat &copy);
		// Destructor
		~Bureaucrat();

		// Operator overloads
		Bureaucrat	&operator=(const Bureaucrat &other);

		const std::string	&getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(AForm &form);
		void				executeForm(AForm const &form);
		// Exceptions classes
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const noexcept;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const noexcept;
		};

};

// Output stream operator overload
std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
