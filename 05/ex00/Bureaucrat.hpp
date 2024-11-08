/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:16:35 by npetitpi          #+#    #+#             */
/*   Updated: 2024/11/08 12:23:31 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &bureaucrat);
		virtual ~Bureaucrat();

		Bureaucrat&operator=(Bureaucrat const &bureaucrat);

		// member functions
		const std::string	getName(void) const;
		int					getGrade(void) const;
		void				upGrade(void);
		void				downGrade(void);

		// redefining exceptions with what()
		class GradeTooHighExeption : public std:: exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("The grade is too high");
				}
		};

		class GradeTooLowExeption: public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("The grade is too low");
				}
		};

};

std::ostream	&operator<<(std::ostream &flux, const Bureaucrat &bureaucrat);

#endif