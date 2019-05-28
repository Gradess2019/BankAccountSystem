#pragma once
#include "TermAccount.h"
class CreditAccount : public TermAccount
{
public:

	CreditAccount(const double& MONEY, const float& INTEREST_RATE, const short int& TERM, const double& TERM_MONEY);
	
	std::string GetData() const;
	std::string GetShortData() const;

};

