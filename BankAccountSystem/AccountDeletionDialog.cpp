#include "AccountDeletionDialog.h"
#include "Account.h"
#include "IAccountsOwner.h"
#include <set>

AccountDeletionDialog::AccountDeletionDialog(IDialogManager* dialogManager) : Dialog(dialogManager) 
{
	std::set<Account*> userAccounts = dialogManager->GetAccountOwner()->GetAccounts();
	for (Account* currentAccount : userAccounts)
	{
		data.push_back(currentAccount->GetShortData());
	}
	data.push_back("Назад");
	backLine = data.size();
}

void AccountDeletionDialog::HandleInput(int& currentLine, const char& INPUT) const
{
	if (INPUT == Keys::Enter && currentLine == backLine)
	{
		dialogManager->CloseDialog();
	} 
	else
	{
		Dialog::HandleInput(currentLine, INPUT);
	}
}