#include "AccountDeletionDialog.h"
#include "IAccountsOwner.h"

AccountDeletionDialog::AccountDeletionDialog(IDialogManager* dialogManager) : Dialog(dialogManager) 
{
	userAccounts = dialogManager->GetAccountOwner()->GetAccounts();
	for (Account* currentAccount : userAccounts)
	{
		data.push_back(currentAccount->GetShortData());
	}
	data.push_back("Назад");
	SetBackLineId();
}

void AccountDeletionDialog::SetBackLineId()
{
	backLine = data.size() - 1;
}

void AccountDeletionDialog::HandleInput(int& currentLine, const char& INPUT)
{
	if (INPUT == Keys::Enter)
	{
		if (currentLine == backLine)
		{
			dialogManager->CloseDialog();
		} 
		else
		{
			std::set<Account*>::iterator accountsIterator = userAccounts.begin();
			std::advance(accountsIterator, currentLine);
			Account* account = *accountsIterator;
			dialogManager->GetAccountOwner()->DeleteAccount(account);
			userAccounts = dialogManager->GetAccountOwner()->GetAccounts();

			data.erase(data.begin() + currentLine);
			SetBackLineId();
		}
	} 
	else
	{
		Dialog::HandleInput(currentLine, INPUT);
	}
}