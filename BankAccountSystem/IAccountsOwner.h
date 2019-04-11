#pragma once
#include "Account.h"
#include <set>
class IAccountsOwner
{
public:

	virtual void AddAccount(Account*) = 0;
	virtual void DeleteAccount(Account*) = 0;
	virtual std::set<Account*>& GetAccounts() = 0;

};

