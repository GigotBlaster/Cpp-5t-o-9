#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define ORANGE "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE "\x1B[36m"
# define END "\033[0m"
# include <iostream>
# include "AForm.hpp"

class AForm;

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

		// member functions
		const std::string	getName(void) const;
		int					getGrade(void) const;
		void				upGrade(void);
		void				downGrade(void);
		void				signForm(AForm &form) const;
		void				executeForm(const AForm &form) const;

		// exceptions
		class GradeTooHigh : public std::exception
		{
			public:
				virtual const char *what() const throw() 
				{
					return ("Bureaucrat::exception : Grade is too high");
				}
		};

		class GradeTooLow : public std::exception
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