/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 12:10:53 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/07 12:10:59 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <ctime>

class Logger
{
	private:
	void		logToConsole(std::string const & output);
	void		logToFile(std::string const & output);
	std::string makeLogEntry(std::string const & message);

	public:
	void		log(std::string const & dest, std::string const & message);
};

#endif
