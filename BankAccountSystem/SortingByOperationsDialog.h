#pragma once
#include "Dialog.h"
class SortingByOperationsDialog : public Dialog
{
public:
	SortingByOperationsDialog(IDialogManager* dialogManager);

private:

	void HandleInput(int& currentLine, const char& INPUT) override;
};

