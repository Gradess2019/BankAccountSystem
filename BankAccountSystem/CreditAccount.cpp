#include "CreditAccount.h"
#include <sstream>


std::string CreditAccount::GetData() const
{
	std::ostringstream outputStream;
	outputStream << TermAccount::GetData() << "\n ���: ���������" << "\n ����: " << termMoney - money << " " << currency << std::endl;
	return outputStream.str();
}

std::string CreditAccount::GetShortData() const
{
	return TermAccount::GetShortData() + " ���������\n";
}