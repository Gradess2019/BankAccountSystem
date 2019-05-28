#pragma once
#include "Account.h"

class AccountFactory
{
public:
	
	static Account* MakeCreditAccount();
	static Account* MakeDepositAccount();
	static Account* MakeCheckingAccount();

private:

	template<typename T>
	static void Input(T& destination);

};

