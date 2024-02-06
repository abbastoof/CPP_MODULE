/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:15:49 by atoof             #+#    #+#             */
/*   Updated: 2024/02/06 14:49:52 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP


# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;

	public:
		// Default constructor
		PresidentialPardonForm();
		// Parameter constructor
		PresidentialPardonForm(std::string target);
		// Copy constructor
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		// Destructor
		~PresidentialPardonForm();

		// Operator overloads
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &other);
		// member functions
		virtual void	execute(Bureaucrat const &executor) const override;
};

#endif
