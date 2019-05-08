/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:35:58 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/01 19:35:59 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

# include <stdexcept>
# include <string>

# include "Bureaucrat.hpp"
# include "Intern.hpp"

class OfficeBlock {

	private:

		OfficeBlock(OfficeBlock const &rhs);
		OfficeBlock &operator=(OfficeBlock const &rhs);

		Intern*		_intern;
		Bureaucrat*	_signer;
		Bureaucrat* _executor;

	public:

		OfficeBlock(void);
		OfficeBlock(Intern &intern, Bureaucrat &signer, Bureaucrat &executor);
		~OfficeBlock(void);

		void	setIntern(Intern*);
		void	setSigner(Bureaucrat*);
		void	setExecutor(Bureaucrat*);

		Bureaucrat* getSigner();
		Bureaucrat* getExecutor();



		void	doBureaucracy(std::string const &formName, std::string const &formTarget);

		class InternException: public std::exception { virtual const char* what() const throw(); };
		class SignerException: public std::exception { virtual const char* what() const throw(); };
		class ExecutorException: public std::exception { virtual const char* what() const throw(); };
		class BureaucracyException: public std::exception { virtual const char* what() const throw(); };



};

#endif
