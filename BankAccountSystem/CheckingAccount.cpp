#include "CheckingAccount.h"
#include <iostream>

std::string CheckingAccount::GetData() const
{
	return Account::GetData() + " ���: ���������\n";
}

std::string CheckingAccount::GetShortData() const
{
	return Account::GetShortData() + " ���������\n";
}