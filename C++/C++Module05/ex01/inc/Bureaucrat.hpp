#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP


# include <iostream>

class Form; // forward declaration

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
		void				signForm(Form &form);
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

// Output stream operator overload
std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
