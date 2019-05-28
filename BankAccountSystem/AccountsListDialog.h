#pragma once
#include "Dialog.h"
class AccountsListDialog : public Dialog
{
public:
	AccountsListDialog(IDialogManager* dialogManager);

private:

	void HandleInput(int& currentLine, const char& INPUT) override;

};

