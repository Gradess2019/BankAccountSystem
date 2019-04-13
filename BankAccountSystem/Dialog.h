#pragma once
#include "IDialogManager.h"
#include <string>
#include <vector>

enum Color
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

enum Keys
{
	Enter = 13,
	Up = 72,
	Down = 80
};

class Dialog
{

public:

	Dialog(IDialogManager* dialogManager);

	void Show();
	void Close();

protected:

	bool isClose;
	
	std::vector<std::string> data;

	IDialogManager* dialogManager;
	
	void SetColor(const Color text, const Color background) const;
	void SetSelectorColor() const;
	void SetDefaultColor() const;

	virtual void HandleInput(int& currentLine, const char& INPUT) const;
	virtual void PrintData(const int& CURRENT_LINE) const;

};

