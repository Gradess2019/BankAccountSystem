#include "DepositAccount.h"
#include <sstream>

DepositAccount::DepositAccount(const double& MONEY, const float& INTEREST_RATE, const short int& TERM, const double& TERM_MONEY) :
	TermAccount(MONEY, INTEREST_RATE, TERM, TERM_MONEY) {}

std::string DepositAccount::GetData() const
{
	std::ostringstream outputStream;
	outputStream << TermAccount::GetData() << " Тип: Депозитный" << "\n Начисленные проценты: " << termMoney << std::endl;
	return outputStream.str();
}

std::string DepositAccount::GetShortData() const
{
	return TermAccount::GetShortData() + " Тип: Депозитный\n";
}