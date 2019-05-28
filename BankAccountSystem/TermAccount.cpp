#include "TermAccount.h"
#include <sstream>

TermAccount::TermAccount(const double& MONEY, const float& INTEREST_RATE, const short int& TERM, const double& TERM_MONEY) :
	Account(MONEY), interestRate(INTEREST_RATE), term(TERM), termMoney(TERM_MONEY) {}

TermAccount::~TermAccount() {}

std::string TermAccount::GetData() const
{
	std::ostringstream outputStream;

	outputStream << "Номер счёта: " << number << 
		"\n Процентная ставка: " << interestRate << 
		"\n Срок: " << term << std::endl;

	return outputStream.str();
}

std::string TermAccount::GetShortData() const
{
	std::ostringstream outputStream;

	outputStream << Account::GetShortData() << " Cрок: " << term << " " << interestRate << "%";

	return outputStream.str();
	
}