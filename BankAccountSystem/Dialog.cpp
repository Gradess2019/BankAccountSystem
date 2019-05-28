#include "Dialog.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

Dialog::Dialog(IDialogManager* dialogManager) : dialogManager(dialogManager), isClose(false) {}

void Dialog::Close()
{
	isClose = true;
}

void Dialog::SetColor(const Color text, const Color background) const
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void Dialog::SetSelectorColor() const
{
	SetColor(Color::LightGreen, Color::Black);
}

void Dialog::SetDefaultColor() const
{
	SetColor(Color::White, Color::Black);
}

void Dialog::Show()
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int currentLine = 0;

	while (!isClose)
	{
		PrintData(currentLine);

		const char INPUT = _getch();
		HandleInput(currentLine, INPUT);

		system("cls");
	}
}

void Dialog::PrintData(const int& CURRENT_LINE) const
{
	for (unsigned int id = 0; id < data.size(); id++)
	{
		if (CURRENT_LINE == id)
		{
			SetSelectorColor();
		}
		std::cout << data[id];
		SetDefaultColor();
	}
}

void Dialog::HandleInput(int& currentLine, const char& INPUT)
{
	if (INPUT == Keys::Up && currentLine > 0)
	{
		currentLine--;
	} else if (INPUT == Keys::Down && currentLine < (data.size() - 1))
	{
		currentLine++;
	}
}