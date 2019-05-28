#pragma once
#include "IAccountsOwner.h"
#include "Dialog.h"
#include "IDialogManager.h"
#include <stack>

class GUI : public IDialogManager
{
public:

	GUI(IAccountsOwner* owner);

	void ShowDialog(Dialog*) override;
	void CloseDialog() override;
	IAccountsOwner* GetAccountOwner() override;

private:

	IAccountsOwner* accountsOwner;

	std::stack<Dialog*> dialogStack;
	
};

