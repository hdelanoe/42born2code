/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:58:53 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/02 12:58:54 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CENTRALBUREAUCRACY_HPP
# define CENTRALBUREAUCRACY_HPP

# include <stdexcept>
# include <string>

class OfficeBlock;
class Bureaucrat;

class CentralBureaucracy {

	public:

		CentralBureaucracy(void);
		CentralBureaucracy(CentralBureaucracy const &rhs);
		~CentralBureaucracy(void);
		CentralBureaucracy &operator=(CentralBureaucracy const &rhs);

		void	feedBureaucrat(Bureaucrat* b);
		void	queueUp(std::string const & name);
		void	doBureaucracy(void);
		void	removeTarget(int const & i);


		class CentralIsFullException: public std::exception { virtual const char* what() const throw(); };
		class QueueIsFullException: public std::exception { virtual const char* what() const throw(); };


	private:

		OfficeBlock*	_officeBlocks;
		std::string*	_queue;
		int				_nbOffice;

};

#endif
