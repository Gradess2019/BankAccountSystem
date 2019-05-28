#include "GUI.h"
#include "MenuDialog.h"

GUI::GUI(IAccountsOwner* owner) : accountsOwner(owner) 
{
	ShowDialog(new MenuDialog(this));
}

void GUI::ShowDialog(Dialog* dialog)
{
	dialogStack.push(dialog);
	dialogStack.top()->Show();
}

void GUI::CloseDialog()
{
	if (dialogStack.size() > 1)
	{
		dialogStack.top()->Close();
		dialogStack.pop();
		dialogStack.top()->Show();
	}
}

IAccountsOwner* GUI::GetAccountOwner()
{
	return accountsOwner;
}