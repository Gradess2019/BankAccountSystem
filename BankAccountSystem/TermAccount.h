#pragma once
#include "Account.h"
#include "basetsd.h"

class TermAccount : public Account
{
public:
	TermAccount(const double& MONEY, const float& INTEREST_RATE, const short int& TERM, const double& TERM_MONEY);

	virtual ~TermAccount() = 0;

	virtual std::string GetData() const;
	virtual std::string GetShortData() const;
	
protected:

	float interestRate;

	short int term;

	double termMoney;
};

