/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:45:44 by cgray             #+#    #+#             */
/*   Updated: 2024/06/12 18:47:09 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime> //time_t

//static variables initialization
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits= 0;
int	Account::_totalNbWithdrawals = 0;

// [timestamp] index:#;amount:#;created
//initialize _amount with init deposit
Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	std::cout << "index:" << _accountIndex << ";"
			<< "amount:" << initial_deposit << ";"
			<< "created\n";
	_totalAmount += initial_deposit;
	_nbAccounts++;
}

// [timestamp] index:#;amount:#;closed
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			<< "amount" << _amount << ";"
			<< "closed" << "\n";
}

// format[year month day_hour min sec]
// log [19920104_091532]
void	Account::_displayTimestamp(void)
{
	const time_t	time_now = time(0);
	tm				*local_timer = localtime(&time_now);

	std::cout << "["
		<< std::setfill('0') << std::setw(2) << local_timer->tm_mon + 1 //month starts at 0
		<< std::setfill('0') << std::setw(2) << local_timer->tm_mday << '_'
		<< std::setfill('0') << std::setw(2) << local_timer->tm_hour
		<< std::setfill('0') << std::setw(2) << local_timer->tm_min
		<< std::setfill('0') << std::setw(2) << local_timer->tm_sec << "] ";
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

// [timestamp] accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:"	<< getNbAccounts()		<< ";"
			<< "total:"			<< getTotalAmount()		<< ";"
			<< "deposits:"		<< getNbDeposits()		<< ";"
			<< "withdrawls:"	<< getNbWithdrawals()	<< ";\n";
}

// [timestamp] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:"	<< _accountIndex	<< ";"
			<< "p_amount:"	<< _amount			<< ";"
			<< "deposit:"	<< deposit			<< ";";
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalAmount++;
	std::cout << "amount"	<< _amount			<< ";"
			<< "nb_deposits:"	<< _nbDeposits << '\n';
}

//[timestamp] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
// if amount < withdrawal
//		[timestamp] index:0;p_amount:47;withdrawal:refused
bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:"		<< _accountIndex	<< ";"
			<< "p_amount:"		<< _amount			<< ";"
			<< "withdrawal:";
	if (_amount < withdrawal)
	{
		std::cout << "refused\n";
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout					<< withdrawal		<< ";"
			<< "amount"			<< _amount			<< ";"
			<< "nb_withdrawals:" << _nbWithdrawals << '\n';
	return (true);
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

//[timestamp] index:0;amount:47;deposits:1;withdrawals:0
void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout	<< "index:"		<< _accountIndex	<< ";"
				<< "amount:"	<< _amount			<< ";"
				<< "deposits:"	<< _nbDeposits		<< ";"
				<< "Withdrawals" << _nbWithdrawals	<< ";\n";
}

