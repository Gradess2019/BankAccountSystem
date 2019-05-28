#include "MenuDialog.h"
#include <conio.h>
#include <Windows.h>
#include "AddAccountDialog.h"
#include "AccountDeletionDialog.h"
#include "AccountsListDialog.h"
#include "SortingByOperationsDialog.h"
#include "SortingByMoneyDialog.h"
#include "TransferMoneyDialog.h"

MenuDialog::MenuDialog(IDialogManager* dialogManager) : Dialog(dialogManager) 
{
	data = { 
		"Открыть счёт\n", 
		"Закрыть счёт\n", 
		"Перевести деньги на другой счёт\n",
		"Вывести все счета\n",
		"Вывести счета, отсортированные по операциям\n", 
		"Вывести счета, отсортированные по доходности\n",
		"Выйти из программы" 
	};
}

void MenuDialog::HandleInput(int& currentLine, const char& INPUT) 
{
	if (INPUT == Keys::Enter)
	{
		switch (currentLine)
		{
			case ELine::AddAccount:
			{
				dialogManager->ShowDialog(new AddAccountDialog(dialogManager));
				break;
			}

			case ELine::DeleteAccount:
			{
				dialogManager->ShowDialog(new AccountDeletionDialog(dialogManager));
				break;
			}

			case ELine::TransferMoney:
			{
				dialogManager->ShowDialog(new TransferMoneyDialog(dialogManager));
				break;
			}

			case ELine::ShowAllAccounts:
			{
				dialogManager->ShowDialog(new AccountsListDialog(dialogManager));
				break;
			}

			case ELine::SortByOperations:
			{
				dialogManager->ShowDialog(new SortingByOperationsDialog(dialogManager));
				break;
			}

			case ELine::SortByMoney:
			{
				dialogManager->ShowDialog(new SortingByMoneyDialog(dialogManager));
				break;
			}
			
			case ELine::CloseProgram:
			{
				exit(0);
			}
		}
	} 
	else
	{
		Dialog::HandleInput(currentLine, INPUT);
	}
}