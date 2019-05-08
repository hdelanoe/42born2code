/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 10:48:04 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/01 10:48:05 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <stdexcept>
# include <iostream>
# include <string>

class Form;


class Bureaucrat {

	public:

		Bureaucrat(void);
		Bureaucrat(Bureaucrat const &rhs);
		~Bureaucrat(void);
		Bureaucrat &operator=(Bureaucrat const &rhs);

		Bureaucrat(std::string const name, int grade);


		std::string	const	getName() const;
		int					getGrade() const;

		void				upGrade();
		void				downGrade();

		void				signForm(Form & form);
		void				executeForm(Form & form);



		class GradeTooHighException: public std::exception { virtual const char* what() const throw(); };
		class GradeTooLowException: public std::exception { virtual const char* what() const throw(); };



	private:

		std::string const	_name;
		int					_grade;



};

std::ostream & operator<<(std::ostream & o, Bureaucrat const *b);

#endif
