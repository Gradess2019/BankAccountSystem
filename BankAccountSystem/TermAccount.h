#pragma once
#include "Account.h"
#include "basetsd.h"

class TermAccount : public Account
{
public:

	virtual ~TermAccount() = 0;

	virtual std::string GetData() const;
	virtual std::string GetShortData() const;
	
protected:

	float interestRate;

	INT8 term;

	double termMoney;
};

