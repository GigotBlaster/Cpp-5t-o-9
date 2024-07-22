#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

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

		// exceptions
		class GradeTooHigh : public std:: exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("The grade is too high");
				}
		};

		class GradeTooLow : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("The grade is too low");
				}
		};

};

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &bureaucrat);

#endif