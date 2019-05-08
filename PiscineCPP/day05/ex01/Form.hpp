/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:27:10 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/02 15:23:32 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <stdexcept>
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form {

	public:

		Form(void);
		Form(std::string const &name, int const &signedGrade, int const &executGrade);
		Form(Form const & src);
		~Form(void);
		Form &	operator=(Form const & rhs);

		std::string	const	getName() const;
		std::string	const	getTarget() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecutGrade() const;

		void				beSigned(Bureaucrat const & signer);
		void				execute(Bureaucrat const & executor);

		class GradeTooHighException: public std::exception { virtual const char* what() const throw(); };
		class GradeTooLowException: public std::exception { virtual const char* what() const throw(); };
		class FormNotSignedException: public std::exception { virtual const char* what() const throw(); };


	protected:

		std::string	const _name;
		int			const _signGrade;
		int			const _executGrade;
		bool		_signed;

};

std::ostream & operator<<(std::ostream & o, Form const *b);


#endif
