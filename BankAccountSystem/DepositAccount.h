#pragma once
#include "TermAccount.h"
class DepositAccount : public TermAccount
{
public:
	
	std::string GetData() const;
	std::string GetShortData() const;

};

