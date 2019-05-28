#include "AddAccountDialog.h"
#include "AccountFactory.h"
#include "IAccountsOwner.h"

AddAccountDialog::AddAccountDialog(IDialogManager* dialogManager) : Dialog(dialogManager) 
{
	data = { "Кредитный счёт\n", "Депозитный счёт\n", "Расчётный счёт\n", "Назад" };
}

void AddAccountDialog::HandleInput(int& currentLine, const char& INPUT)
{
	if (INPUT == Keys::Enter)
	{
		switch (currentLine)
		{

		case ELine::Back:
		{
			dialogManager->CloseDialog();
			break;
		}
		
		case ELine::CreditAccount:
		{
			ClearWindow();
			Account* newAccount = AccountFactory::MakeCreditAccount();
			PassNewAccount(newAccount);
			break;
		}

		case ELine::DepositAccount:
		{
			ClearWindow();
			Account* newAccount = AccountFactory::MakeDepositAccount();
			PassNewAccount(newAccount);
			break;
		}

		case ELine::CheckingAccount:
		{
			ClearWindow();
			Account* newAccount = AccountFactory::MakeCheckingAccount();
			PassNewAccount(newAccount);
			break;
		}

		}
	} 
	else
	{
		Dialog::HandleInput(currentLine, INPUT);
	}
}

void AddAccountDialog::ClearWindow() const
{
	system("cls");
}

void AddAccountDialog::PassNewAccount(Account* newAccount) const
{
	dialogManager->GetAccountOwner()->AddAccount(newAccount);
	system("pause");
}