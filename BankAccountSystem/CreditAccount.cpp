#include "CreditAccount.h"
#include <sstream>


std::string CreditAccount::GetData() const
{
	std::ostringstream outputStream;
	outputStream << TermAccount::GetData() << "\n Тип: Кредитный" << "\n Долг: " << termMoney - money << " " << currency << std::endl;
	return outputStream.str();
}

std::string CreditAccount::GetShortData() const
{
	return TermAccount::GetShortData() + " Кредитный\n";
}