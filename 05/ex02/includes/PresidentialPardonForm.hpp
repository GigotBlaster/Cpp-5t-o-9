#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const std::string	_target;
		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &presidential);
		
	public:
		PresidentialPardonForm(const std::string &target);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm	&operator=(const PresidentialPardonForm &presidential);

		void					execute(const Bureaucrat &Bureaucrat) const;
};

#endif