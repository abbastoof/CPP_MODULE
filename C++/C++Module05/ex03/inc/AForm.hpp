/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:35:41 by atoof             #+#    #+#             */
/*   Updated: 2024/02/06 14:53:19 by atoof            ###   ########.fr       */
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
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &rhs);
		virtual ~AForm();
		AForm &operator=(const AForm &rhs);

		const std::string	&getName() const;
		bool			getSign() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		virtual void		beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;

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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char	*what() const noexcept;
		};

};

std::ostream	&operator<<(std::ostream &out, const AForm &rhs);

#endif
