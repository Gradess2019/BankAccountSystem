#include "CreditAccount.h"
#include <sstream>

CreditAccount::CreditAccount(const double& MONEY, const float& INTEREST_RATE, const short int& TERM, const double& TERM_MONEY) :
	TermAccount(MONEY, INTEREST_RATE, TERM, TERM_MONEY) {}

std::string CreditAccount::GetData() const
{
	std::ostringstream outputStream;
	outputStream << TermAccount::GetData() << " ���: ���������" << "\n ����: " << termMoney - money << std::endl;
	return outputStream.str();
}

std::string CreditAccount::GetShortData() const
{
	return TermAccount::GetShortData() + " ���: ���������\n";
}