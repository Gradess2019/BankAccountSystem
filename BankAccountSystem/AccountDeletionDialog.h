#pragma once
#include "Dialog.h"
#include "Account.h"
#include <set>

class AccountDeletionDialog : public Dialog
{
public:

	AccountDeletionDialog(IDialogManager* dialogManager);

private:

	std::set<Account*> userAccounts;

	void HandleInput(int& currentLine, const char& INPUT) override;
	void SetBackLineId();
};

