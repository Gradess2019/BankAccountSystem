#pragma once
#include "Dialog.h"
class SortingByMoneyDialog : public Dialog
{
public:

	SortingByMoneyDialog(IDialogManager* dialogManager);


private:

	void HandleInput(int& currentLine, const char& INPUT);
};

