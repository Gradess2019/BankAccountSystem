#pragma once
#include "Dialog.h"
class AccountDeletionDialog : public Dialog
{
public:

	AccountDeletionDialog(IDialogManager* dialogManager);


private:

	int backLine;

	void HandleInput(int& currentLine, const char& INPUT) const override;
};

