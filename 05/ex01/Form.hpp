#ifndef FORM_HPP
# define FORM_HPP
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define PURPLE "\x1B[35m"
# define END "\033[0m"
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		const int			_gradeSign;
		const int			_gradeExec;
		bool				_signed;
		
	public:
		Form(void);
		Form(const std::string name, int gradeSign, int gradeExec);
		Form(const Form &form);
		virtual ~Form();

		Form	&operator=(const Form &form);

		// member functions
		const std::string	getName(void) const;
		int					getGradeSign(void) const;
		int					getGradeExec(void) const;
		bool				getSigned(void) const;
		void				beSigned(const Bureaucrat &bureaucrat);

		// exceptions
		class GradeTooHighExeption : public std::exception
		{
			public:
				virtual const char *what() const throw() { return ("grade is too high"); }
		};

		class GradeTooLowExeption : public std::exception
		{
			public:
				virtual const char *what() const throw() { return ("grade is too low"); }
		};
};

std::ostream	&operator<<(std::ostream &flux, const Form &form);

#endif