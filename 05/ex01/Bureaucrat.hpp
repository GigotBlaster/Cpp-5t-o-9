#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define PURPLE "\x1B[35m"
# define END "\033[0m"
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
		
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);
		virtual ~Bureaucrat();

		Bureaucrat	&operator=(const Bureaucrat &bureaucrat);

		//member functions
		const std::string	getName(void) const;
		int					getGrade(void) const;
		void				upGrade(void);
		void				downGrade(void);
		void				signForm(Form &form) const;

		//exceptions
		class GradeTooHighExeption : public std::exception
		{
			public:
				virtual const char *what() const throw() 
				{
					return ("Bureaucrat::exception : Grade is too high");
				}
		};

		class GradeTooLowExeption : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Bureaucrat::exception : Grade is too low");
				}
		};

};

std::ostream	&operator<<(std::ostream &flux, const Bureaucrat &bureaucrat);

#endif