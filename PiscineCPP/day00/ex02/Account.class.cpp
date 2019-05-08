/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:52:07 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/25 16:52:11 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <string>
#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>

int 	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int 	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int 	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int 	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	if (Account::_nbAccounts > 0) {	
		_displayTimestamp();
		std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
	}
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
	_nbAccounts += 1;
	return ;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;

	return ;
}

void	Account::makeDeposit( int deposit )
{
	if (deposit > 0)
	{
		this->_nbDeposits += 1;
		_totalNbDeposits += 1;
		_displayTimestamp();

		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit << ";amount:" << this->_amount + deposit << ";nb_deposits:" << this->_nbDeposits << std::endl;
		this->_amount += deposit;
		_totalAmount += deposit;
	}
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (this->_amount - withdrawal > 0) {
		this->_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:" << withdrawal << ";amount:" << this->_amount - withdrawal << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		this->_amount -= withdrawal;
		_totalAmount -= withdrawal;
		return true;
	}
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
	return false;
}

int 	Account::checkAmount( void ) const
{
	return this->_amount;	
}

void	Account::displayStatus( void ) const
{

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposit:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
	
}

void	Account::_displayTimestamp( void ) {
	time_t now = time(0);
	const tm time = *std::localtime(&now);
	std::stringstream s;
	s << std::put_time(&time, "[%Y%m%d_%H%M%S] ");
	std::string timeStamp = s.str();
	std::cout << timeStamp;
}

Account::Account( void )
{
	return ;
}

int 	Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;