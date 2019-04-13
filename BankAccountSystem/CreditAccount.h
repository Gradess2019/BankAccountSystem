#pragma once
#include "TermAccount.h"
class CreditAccount : public TermAccount
{
public:
	
	std::string GetData() const;
	std::string GetShortData() const;

};

