/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:15:56 by atoof             #+#    #+#             */
/*   Updated: 2024/02/06 14:49:45 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP


# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;

	public:
		// Default constructor
		RobotomyRequestForm();
		// Parameter constructor
		RobotomyRequestForm(std::string target);
		// Copy constructor
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		// Destructor
		~RobotomyRequestForm();

		// Operator overloads
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &other);
		// member functions
		virtual void	execute(Bureaucrat const &executor) const override;
};

#endif
