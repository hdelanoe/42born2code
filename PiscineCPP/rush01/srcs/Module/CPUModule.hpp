/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:32:13 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/05 18:32:14 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP

# include <sys/sysctl.h>
# include <mach/mach.h>
# include "IMonitorModule.hpp"

class 	CPUModule : public IMonitorModule
{
	public:

		CPUModule(void);
		CPUModule(unsigned int i);
		CPUModule(CPUModule const & src);
		~CPUModule(void);

		CPUModule & operator=(CPUModule const & rhs);

		virtual void	update(void);
		virtual void	shellDisplay(int const & nb);
		virtual void	graphicalDisplay(sf::RenderWindow&, sf::Font&);

		virtual void	displayShellWindow(int const & nb);

		uint64_t		rdtsc(void);
		float			getCPULoad(void);
		float			calculateCPULoad(unsigned long idleTicks, unsigned long totalTicks);

	private:

		float				m_CPULoad;
		
		char				m_CPUBrand[256];
		int32_t				m_CPUCores;
		
		uint64_t			m_start;
		uint64_t			m_end;
		uint64_t			m_frequency;

		unsigned long		m_previousTotalTicks;
		unsigned long		m_previousIdleTicks;
};
#endif
