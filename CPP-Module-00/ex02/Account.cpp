#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int i )
{
    Account::_accountIndex = Account::getNbAccounts();
    Account::_amount = i;
    Account::_totalAmount += i;
    Account::_nbDeposits = 0;
    Account::_nbWithdrawals = 0;
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_accountIndex;
    std::cout << ";amount:" << Account::checkAmount();
    std::cout << ";created" << std::endl;
    Account::_nbAccounts++;
}

int Account::getNbAccounts() {
    return (Account::_nbAccounts);
}

int Account::getTotalAmount() {
    return (Account::_totalAmount);
}

int Account::getNbDeposits() {
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals() {
    return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos()
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts();
    std::cout << ";total:" << Account::getTotalAmount();
    std::cout << ";deposits:" << Account::getNbDeposits();
    std::cout << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    Account::_nbDeposits++;
    Account::_totalNbDeposits++;
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_accountIndex;
    std::cout << ";p_amount:" << Account::checkAmount();
    std::cout << ";deposit:" << deposit;
    Account::_amount += deposit;
    Account::_totalAmount += deposit;
    std::cout << ";amount:" << Account::checkAmount();
    std::cout << ";nb_deposits:" << Account::_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_accountIndex;
    std::cout << ";p_amount:" << Account::checkAmount();
    if (Account::_amount - withdrawal < 0)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return (false);
    }
    Account::_amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    Account::_nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    std::cout << ";withdrawal:" << withdrawal;
    std::cout << ";amount:" << Account::_amount;
    std::cout << ";nb_withdrawals:" << Account::_nbWithdrawals << std::endl;
    return (true);
}

int		Account::checkAmount() const
{
    return (Account::_amount);
}

void	Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << Account::_accountIndex;
    std::cout << ";amount:" << Account::checkAmount();
    std::cout << ";deposits:" << Account::_nbDeposits;
    std::cout << ";withdrawals:" << Account::_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp()
{
	std::time_t	curr_time = std::time(NULL);

	std::tm* timep = std::localtime(&curr_time);
	std::cout << std::put_time(timep, "[%Y%m%d_%H%M%S] ");
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << Account::_accountIndex;
    std::cout << ";amount:" << Account::checkAmount();
    std::cout << ";closed" << std::endl;
    Account::_nbAccounts--;
}
