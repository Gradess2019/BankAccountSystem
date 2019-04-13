#pragma once
#include "Dialog.h"
class AddAccountDialog : public Dialog
{
public:
	AddAccountDialog(IDialogManager* dialogManager);

private:

	enum ELine
	{
		Back = 4
	};

	void HandleInput(int& currentLine, const char& INPUT) const override;

};

