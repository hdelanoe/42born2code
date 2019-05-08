/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:32:29 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/05 18:32:30 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMMODULE_HPP
# define RAMMODULE_HPP

# include <sys/sysctl.h>
# include <mach/mach_types.h>
# include <mach/mach_init.h>
# include <mach/mach_host.h>

# include "IMonitorModule.hpp"

class RAMModule : public IMonitorModule
{
	public:
		RAMModule(void);
		RAMModule(unsigned int i);
		RAMModule(RAMModule const & src);
		~RAMModule(void);

		RAMModule & operator=(RAMModule const & rhs);

		virtual void	update(void);
		virtual void	shellDisplay(int const & nb);
		virtual void	graphicalDisplay(sf::RenderWindow&, sf::Font&);

		virtual void	displayShellWindow(int const & nb);
		
		void			init(void);

	private:

		int*					m_mib;
		uint64_t				m_physical_memory;

		uint64_t				m_memSize;
		uint64_t				m_userMem;
		uint64_t				m_physMem;


		vm_size_t				m_page_size;
		mach_port_t				m_mach_port;
		mach_msg_type_number_t	m_count;
		vm_statistics64_data_t	m_vm_stats;

		uint64_t					m_free_memory;
		uint64_t					m_used_memory;
	
};
#endif
