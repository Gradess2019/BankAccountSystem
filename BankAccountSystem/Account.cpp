#include "Account.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#define SUCCESS true
#define FAILURE false
#define AVAILABLE true
#define NOT_AVAILABLE false

Account::Account(const double& MONEY) : money(MONEY), isClosed(false)
{
	srand(time(NULL));

	for (int i = 0; i < 4; i++)
	{
		int randNumber = rand() % 10000 + 20000;
		number += std::to_string(randNumber);
	}

	numberOfOperations = 0;
}

Account::~Account() {}

void Account::PrintData() const
{
	std::cout << GetData();
}

std::string Account::GetData() const
{
	std::ostringstream outputStream;
	outputStream << "Номер счёта: " << number << "\n Баланс: " << std::fixed << std::setprecision(2) << money << std::endl;
	return outputStream.str();
}

void Account::PrintShortData() const
{
	std::cout << GetShortData();
}

std::string Account::GetShortData() const
{
	std::ostringstream outputStream;
	outputStream << "№ " << number;
	return outputStream.str();
}

bool Account::TransferMoney(Account* receiver, const double& AMOUNT_OF_MONEY)
{
	if (IsAvailableAmountOfMoney(AMOUNT_OF_MONEY) && receiver != nullptr && receiver != this)
	{
		receiver->AddMoney(AMOUNT_OF_MONEY);
		DecreaseMoney(AMOUNT_OF_MONEY);
		numberOfOperations++;
		return SUCCESS;
	}
	else
	{
		return FAILURE;
	}
}

bool Account::IsAvailableAmountOfMoney(const double& AMOUNT_OF_MONEY)
{
	return AMOUNT_OF_MONEY < money;
}

void Account::AddMoney(const double& TRANSFERRED_MONEY)
{
	money += TRANSFERRED_MONEY;
	numberOfOperations++;
}

void Account::DecreaseMoney(const double& MONEY_DECREMENT)
{
	money -= MONEY_DECREMENT;
}

void Account::Close()
{
	isClosed = true;
}

bool Account::IsClosed() const
{
	return isClosed;
}

double Account::GetMoney() const
{
	return money;
}

int Account::GetNumberOfOperations() const
{
	return numberOfOperations;
}