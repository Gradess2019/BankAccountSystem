#include "SortingByOperationsDialog.h"
#include <set>
#include <vector>
#include <algorithm>
#include "IAccountsOwner.h"

SortingByOperationsDialog::SortingByOperationsDialog(IDialogManager* dialogManager) : Dialog(dialogManager) 
{
	std::set<Account*> userAccountsSet = dialogManager->GetAccountOwner()->GetAccounts();
	std::vector<Account*> userAccountsVector(userAccountsSet.begin(), userAccountsSet.end());

	std::sort(userAccountsVector.begin(), userAccountsVector.end(),
		[] (Account* a, Account* b) { return a->GetNumberOfOperations() > b->GetNumberOfOperations(); });

	for (Account* account : userAccountsVector)
	{
		data.push_back(account->GetShortData());
	}

	data.push_back("Назад");
	backLine = data.size() - 1;
}

void SortingByOperationsDialog::HandleInput(int& currentLine, const char& INPUT)
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