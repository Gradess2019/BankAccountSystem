#pragma once
#include "Dialog.h"
class MenuDialog : public Dialog
{
public:
	MenuDialog(IDialogManager* dialogManager);

private:

	enum ELine
	{
		AddAccount,
		DeleteAccount,
		CloseProgram
	};

	void HandleInput(int& currentLine, const char& INPUT) const override;
};

