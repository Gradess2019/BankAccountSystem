#pragma once
#include "Dialog.h"
#include "Account.h"
#include <set>

class TransferMoneyDialog :
	public Dialog
{
public:
	TransferMoneyDialog(IDialogManager* dialogManager);

private:

	std::set<Account*> userAccounts;
	
	Account* sender;
	Account* receiver;

	void UpdateData();
	void HandleInput(int& currentLine, const char& INPUT) override;
	Account* GetAccountById(const int& id);

	bool CanSendMoney();
	void SendMoney();

};

