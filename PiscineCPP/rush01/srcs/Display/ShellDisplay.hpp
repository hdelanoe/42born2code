/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShellDisplay.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:30:01 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/06 15:53:23 by tfontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELLDISPLAY_HPP
# define SHELLDISPLAY_HPP

# include "IMonitorDisplay.hpp"
# include "../Module/HostnameModule.hpp"

class ShellDisplay : public IMonitorDisplay
{
public:
	ShellDisplay(void);
	virtual ~ShellDisplay(void);

	virtual bool update(std::vector<IMonitorModule*> const & modules);

private:
	ShellDisplay(ShellDisplay const & src);
	ShellDisplay & operator=(ShellDisplay const & rhs);
};

#endif
