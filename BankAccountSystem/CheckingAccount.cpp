#include "CheckingAccount.h"
#include <sstream>
#include <iomanip>

CheckingAccount::CheckingAccount(const double& MONEY) : Account(MONEY) {}

std::string CheckingAccount::GetData() const
{
	return Account::GetData() + " Тип: Расчётный\n";
}

std::string CheckingAccount::GetShortData() const
{
	std::ostringstream outputStream;
	outputStream << Account::GetShortData() << " " << std::fixed << std::setprecision(2) << money << " " << GetNumberOfOperations() << " Расчётный\n";
	return outputStream.str();
}