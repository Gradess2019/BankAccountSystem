#include "DepositAccount.h"
#include <sstream>

std::string DepositAccount::GetData() const
{
	std::ostringstream outputStream;
	outputStream << TermAccount::GetData() << "\n Тип: Депозитный" << "\n Начисленные проценты: " << termMoney << " " << currency << std::endl;
	return outputStream.str();
}

std::string DepositAccount::GetShortData() const
{
	return TermAccount::GetShortData() + " Депозитный\n";
}