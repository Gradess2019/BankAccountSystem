#include "MenuDialog.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "AddAccountDialog.h"
#include "AccountDeletionDialog.h"

MenuDialog::MenuDialog(IDialogManager* dialogManager) : Dialog(dialogManager) 
{
	data = { "������� ����\n", "������� ����\n", "����� �� ���������" };
}

void MenuDialog::HandleInput(int& currentLine, const char& INPUT) const
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
			
			case ELine::CloseProgram:
			{
				exit(0);
				break;
			}
		}
	} 
	else
	{
		Dialog::HandleInput(currentLine, INPUT);
	}
}