#pragma once
class IDialogManager
{
public:
	
	virtual void ShowDialog(class Dialog*) = 0;
	virtual void CloseDialog() = 0;
	virtual class IAccountsOwner* GetAccountOwner() = 0;
};

