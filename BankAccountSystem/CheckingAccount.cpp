#include "CheckingAccount.h"
#include <sstream>
#include <iomanip>

CheckingAccount::CheckingAccount(const double& MONEY) : Account(MONEY) {}

std::string CheckingAccount::GetData() const
{
	return Account::GetData() + " ���: ���������\n";
}

std::string CheckingAccount::GetShortData() const
{
	std::ostringstream outputStream;
	outputStream << Account::GetShortData() << " " << std::fixed << std::setprecision(2) << money << " " << GetNumberOfOperations() << " ���������\n";
	return outputStream.str();
}