/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IIMonitorDisplayDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:29:23 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/06 15:58:56 by tfontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

# include <vector>

# include "../Module/IMonitorModule.hpp"
# include "../Module/HostnameModule.hpp"

class IMonitorDisplay
{
	public:
		virtual ~IMonitorDisplay(void);

		virtual	bool	update(std::vector<IMonitorModule*> const &) = 0;

};
#endif
