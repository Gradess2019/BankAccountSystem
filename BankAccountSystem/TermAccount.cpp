#include "TermAccount.h"
#include <sstream>

TermAccount::~TermAccount() {}

std::string TermAccount::GetData() const
{
	std::ostringstream outputStream;

	outputStream << "����� �����: " << number << 
		"\n ���������� ������: " << interestRate << 
		"\n ����: " << term << std::endl;

	return outputStream.str();
}

std::string TermAccount::GetShortData() const
{
	std::ostringstream outputStream;

	outputStream << Account::GetShortData() << " " << term << std::endl;

	return outputStream.str();
	
}