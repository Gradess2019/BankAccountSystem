#include "User.h"

void User::AddAccount(Account* newAccount)
{
	accounts.insert(newAccount);
}

void User::DeleteAccount(Account* account)
{
	accounts.erase(account);
	delete account;
}

std::set<Account*>& User::GetAccounts()
{
	return accounts;
}