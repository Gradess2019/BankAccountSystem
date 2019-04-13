#include "AddAccountDialog.h"

AddAccountDialog::AddAccountDialog(IDialogManager* dialogManager) : Dialog(dialogManager) 
{
	data = { "��������� ����\n", "���������� ����\n", "��������� ����\n", "��������� ����\n", "�����" };
}

void AddAccountDialog::HandleInput(int& currentLine, const char& INPUT) const
{
	if (INPUT == Keys::Enter && currentLine == ELine::Back)
	{
		dialogManager->CloseDialog();
	}
	Dialog::HandleInput(currentLine, INPUT);
}