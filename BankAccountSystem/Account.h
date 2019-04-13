#pragma once
#include <string>

enum ECurrency
{
	RUB,
	USD,
	EUR,
	GBP
};

class Account
{

public:

	Account();

	void PrintData() const;
	void PrintShortData() const;

	virtual std::string GetData() const;
	virtual std::string GetShortData() const;
	
	void AddMoney(const double& TRANSFERRED_MONEY);
	void Close();

	bool TransferMoney(Account* receiver, const double& AMOUNT_OF_MONEY);

	bool IsClosed() const;

	virtual ~Account() = 0;

protected:

	std::string number;

	double money;

	ECurrency currency;

	bool isClosed;

private:
	bool IsAvailableAmountOfMoney(const double& AMOUNT_OF_MONEY);
	void DecreaseMoney(const double& MONEY_DECREMENT);

};

