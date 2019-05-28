#pragma once
#include "Account.h"
class CheckingAccount : public Account
{
public:

	CheckingAccount(const double& MONEY);
	
	std::string GetData() const override;
	std::string GetShortData() const override;

};

