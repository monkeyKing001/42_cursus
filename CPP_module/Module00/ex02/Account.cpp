# include "Account.hpp"
# include <iostream>
# include <vector>
# include <algorithm>
# include <functional>
# include <ctime>
# include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts( void ){ return (_nbAccounts); }
int Account::getTotalAmount( void ){ return (_totalAmount); }
int Account::getNbDeposits( void ){ return (_totalNbDeposits); }
int Account::getNbWithdrawals( void ){ return (_totalNbWithdrawals); }

//constructor , cont can't have return type
Account::Account()
{
	this -> _accountIndex = 0;
	this -> _amount = 0;
	this -> _nbDeposits = 0;
	this -> _nbWithdrawals = 0;
}

Account::Account(int initial_deposit)
{
	this -> _accountIndex = _nbAccounts++;
	this -> _amount = initial_deposit;
	this -> _nbDeposits = 0;
	this -> _nbWithdrawals = 0;
	_totalAmount += this -> _amount; 
	_displayTimestamp();
	std::cout 
		<< "index:"
		<< this -> _accountIndex
		<< ";amount:"
		<< this -> _amount
		<< ";created\n";
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout 
		<< "accounts:" << getNbAccounts() 
		<< ";total:"<< getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals()
		<< std::endl;
}

void	Account::makeDeposit( int deposit )
{
	this -> _nbDeposits++;
	_displayTimestamp();
	std::cout 
		<< "index:" << this -> _accountIndex
		<< ";pamount:" << checkAmount()
		<< ";deposits:" << deposit
		<< ";amount:" << _amount + deposit
		<< ";nb_deposits:" << this -> _nbDeposits
		<< std::endl;
		this -> _amount+= deposit;
		_totalAmount+= deposit;
		_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout 
		<< "index:" << this -> _accountIndex
		<< ";pamount:" << checkAmount();
	//unable withdrawal
	if (withdrawal > checkAmount())
	{
		std::cout
			<<";withdrawal:refused\n";
		return (false);
	}
	//withdrawal
	std::cout
		<< "withdrawal:"
		<< withdrawal
		<< ";amount:" << _amount - withdrawal
		<< ";nb_withdrawals:" << ++(this -> _nbWithdrawals)
		<< std::endl;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	this -> _amount -= withdrawal;
	return (true);
}

int		Account::checkAmount( void ) const { return (this->_amount); }

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout 
		<< "index:" << this -> _accountIndex
		<< ";amount:" << checkAmount()
		<< ";deposits:" << this -> _nbDeposits
		<< ";withdrawals:" << this -> _nbWithdrawals
		<< std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t t = time(NULL);
	std::tm buf;
	std::tm tm = *localtime_r(&t, &buf);

	std::cout << "[" << tm.tm_year + 1900
    << std::setfill('0') << std::setw(2) << tm.tm_mon + 1 // tm_mon range from 0 ~ 11
    << std::setfill('0') << std::setw(2) << tm.tm_mday << "_"
    << std::setfill('0') << std::setw(2) << tm.tm_hour
    << std::setfill('0') << std::setw(2) << tm.tm_min
    << std::setfill('0') << std::setw(2) << tm.tm_sec << "] ";
}

Account::~Account()
{
	_displayTimestamp();
	std::cout 
		<< "index:" << this -> _accountIndex
		<< ";amount:" << checkAmount()
		<< ";closed\n";
}
