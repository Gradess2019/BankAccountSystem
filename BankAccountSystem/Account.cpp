#include "Account.h"
#include <iostream>
#include <sstream>

#define SUCCESS true
#define FAILURE false
#define AVAILABLE true
#define NOT_AVAILABLE false

Account::Account()
{
	number = "1234 12345678 123456";
	money = 1000.0;
	currency = ECurrency::RUB;
}

Account::~Account() {}

void Account::PrintData() const
{
	std::cout << GetData();
}

std::string Account::GetData() const
{
	std::ostringstream outputStream;
	outputStream << "Номер счёта: " << number << "\n Баланс: " << money << " " << currency << std::endl;
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
	if (IsAvailableAmountOfMoney(AMOUNT_OF_MONEY))
	{
		receiver->AddMoney(AMOUNT_OF_MONEY);
		DecreaseMoney(AMOUNT_OF_MONEY);
		return SUCCESS;
	}
	else
	{
		return FAILURE;
	}
}

bool Account::IsAvailableAmountOfMoney(const double& AMOUNT_OF_MONEY)
{
	if (AMOUNT_OF_MONEY < money)
	{
		return AVAILABLE;
	} 
	else
	{
		return NOT_AVAILABLE;
	}
}

void Account::AddMoney(const double& TRANSFERRED_MONEY)
{
	money += TRANSFERRED_MONEY;
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
