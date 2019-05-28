#include "AccountsListDialog.h"
#include "Account.h"
#include "IAccountsOwner.h"
#include <set>

AccountsListDialog::AccountsListDialog(IDialogManager* dialogManager) : Dialog(dialogManager)
{
	std::set<Account*> userAccounts = dialogManager->GetAccountOwner()->GetAccounts();
	for (Account* currentAccount : userAccounts)
	{
		data.push_back(currentAccount->GetData());
	}
	data.push_back("Назад");
	backLine = data.size() - 1;
}

void AccountsListDialog::HandleInput(int& currentLine, const char& INPUT)
{
	if (INPUT == Keys::Enter && currentLine == backLine)
	{
		dialogManager->CloseDialog();
	} else
	{
		Dialog::HandleInput(currentLine, INPUT);
	}
}