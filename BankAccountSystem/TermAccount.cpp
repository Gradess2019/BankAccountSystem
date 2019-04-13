#include "TermAccount.h"
#include <sstream>

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

	outputStream << Account::GetShortData() << " " << term << std::endl;

	return outputStream.str();
	
}