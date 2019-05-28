#pragma once
#include "Dialog.h"
#include "Account.h"
class AddAccountDialog : public Dialog
{
public:

	AddAccountDialog(IDialogManager* dialogManager);

private:

	enum ELine
	{
		CreditAccount = 0,
		DepositAccount = 1,
		CheckingAccount = 2,
		Back = 3
	};

	void HandleInput(int& currentLine, const char& INPUT) override;
	void ClearWindow() const;
	void PassNewAccount(Account* newAccount) const;

};

