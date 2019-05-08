/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:58:48 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/02 12:58:49 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <unistd.h>
#include "CentralBureaucracy.hpp"
#include "OfficeBlock.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

CentralBureaucracy::CentralBureaucracy(void) : _nbOffice(0)
{
	_officeBlocks = new OfficeBlock[20];
	_queue = new std::string[100];
	for (int i = 0; i < 100 ; i++)
		_queue[i] = "";
}
CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const & rhs) { (void)rhs; }
CentralBureaucracy::~CentralBureaucracy(void) {}

CentralBureaucracy & CentralBureaucracy::operator=(CentralBureaucracy const & rhs) { (void)rhs; return *this; }

void	CentralBureaucracy::feedBureaucrat(Bureaucrat * b)
{
	if (_nbOffice == 20) { throw CentralIsFullException(); }
	for (int i = 0 ; i < 20 ; i++)
	{
		if (!_officeBlocks[i].getSigner() || !_officeBlocks[i].getExecutor())
		{
			if (!_officeBlocks[i].getSigner()) { _officeBlocks[i].setSigner(b); } 
			else if (!_officeBlocks[i].getExecutor()) { _officeBlocks[i].setExecutor(b); }
			if (_officeBlocks[i].getSigner() && _officeBlocks[i].getExecutor()) { _officeBlocks[i].setIntern(new Intern()); _nbOffice++ ; }
			return ;
		}

	}
}

void	CentralBureaucracy::queueUp(std::string const & name)
{
	int i = 0;
	for (i = 0; i < 100; i++)
	{
		if (_queue[i] == "") {
			_queue[i] = name;
			return ;
		}
	}
	if (i == 100) throw CentralBureaucracy::QueueIsFullException();
}

void	CentralBureaucracy::doBureaucracy(void)
{
	std::string formName[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int target = -1;
	for (int i = 0; i < _nbOffice; i++)
	{
		if (_queue[++target] != "") {
			srand(time(NULL));
			sleep(1);
			int rdm = rand() % 3;
			
			try { _officeBlocks[i].doBureaucracy(formName[rdm], _queue[i]); } catch (std::exception & e) {}
			removeTarget(target);
		}
	}
}

void	CentralBureaucracy::removeTarget(int const & i) { _queue[i] = ""; _queue[i] = _queue[100]; }

const char* CentralBureaucracy::CentralIsFullException::what() const throw() 	{ return ("Central is full."); }
const char* CentralBureaucracy::QueueIsFullException::what() const throw() 	{ return ("Central can't accept more than 100 target."); }


