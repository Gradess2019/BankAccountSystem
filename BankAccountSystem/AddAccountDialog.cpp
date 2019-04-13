#include "AddAccountDialog.h"

AddAccountDialog::AddAccountDialog(IDialogManager* dialogManager) : Dialog(dialogManager) 
{
	data = { "Кредитный счёт\n", "Депозитный счёт\n", "Расчётный счёт\n", "Бюджетный счёт\n", "Назад" };
}

void AddAccountDialog::HandleInput(int& currentLine, const char& INPUT) const
{
	if (INPUT == Keys::Enter && currentLine == ELine::Back)
	{
		dialogManager->CloseDialog();
	}
	Dialog::HandleInput(currentLine, INPUT);
}