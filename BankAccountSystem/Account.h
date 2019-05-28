#pragma once
#include <string>

class Account
{

public:

	Account(const double& MONEY);

	virtual ~Account() = 0;

	void PrintData() const;
	void PrintShortData() const;

	virtual std::string GetData() const;
	virtual std::string GetShortData() const;
	
	void AddMoney(const double& TRANSFERRED_MONEY);
	void Close();

	bool TransferMoney(Account* receiver, const double& AMOUNT_OF_MONEY);

	bool IsClosed() const;

	double GetMoney() const;

	int GetNumberOfOperations() const;

protected:

	std::string number;

	double money;

	bool isClosed;

private:

	int numberOfOperations;

	bool IsAvailableAmountOfMoney(const double& AMOUNT_OF_MONEY);
	void DecreaseMoney(const double& MONEY_DECREMENT);

};

