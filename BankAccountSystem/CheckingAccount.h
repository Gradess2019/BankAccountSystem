#pragma once
#include "Account.h"
class CheckingAccount : public Account
{
public:
	
	std::string GetData() const override;
	std::string GetShortData() const override;

};

