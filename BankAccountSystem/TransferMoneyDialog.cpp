#include "TransferMoneyDialog.h"
#include "IAccountsOwner.h"
#include <iostream>

TransferMoneyDialog::TransferMoneyDialog(IDialogManager* dialogManager) : Dialog(dialogManager)
{
	UpdateData();
}

void TransferMoneyDialog::UpdateData()
{
	sender = nullptr;
	receiver = nullptr;
	data.clear();

	userAccounts = dialogManager->GetAccountOwner()->GetAccounts();
	for (Account* currentAccount : userAccounts)
	{
		data.push_back(currentAccount->GetData());
	}
	data.push_back("Назад");
	backLine = data.size() - 1;
}

void TransferMoneyDialog::HandleInput(int& currentLine, const char& INPUT)
{
	if (INPUT == Keys::Enter)
	{
		if (currentLine == backLine)
		{
			dialogManager->CloseDialog();
		}
		else
		{
			if (sender == nullptr)
			{
				sender = GetAccountById(currentLine);

			} else if (receiver == nullptr)
			{
				receiver = GetAccountById(currentLine);
			} 
			
			if (CanSendMoney())
			{
				SendMoney();
			}
		}
	} else
	{
		Dialog::HandleInput(currentLine, INPUT);
	}
}

Account* TransferMoneyDialog::GetAccountById(const int& id)
{
	std::set<Account *>::iterator accountsIterator = userAccounts.begin();
	std::advance(accountsIterator, id);
	return *accountsIterator;
}

bool TransferMoneyDialog::CanSendMoney()
{
	return sender != nullptr && receiver != nullptr;
}

void TransferMoneyDialog::SendMoney()
{
	system("cls");

	std::cout << "Сумма: ";
	double money = 0.0;
	std::cin >> money;

	if (sender->TransferMoney(receiver, money))
	{
		std::cout << "Операция прошла успешно!";
	} else
	{
		std::cout << "Ошибка!";
	}
	std::cout << std::endl;

	UpdateData();

	system("pause");
}