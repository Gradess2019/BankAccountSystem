#pragma once
#include "IAccountsOwner.h"
#include "Account.h"
#include <set>

class User : public IAccountsOwner
{
public:

	void AddAccount(Account*) override;
	void DeleteAccount(Account*) override;
	std::set<Account*>& GetAccounts() override;

private:

	std::set<Account*> accounts;
};

