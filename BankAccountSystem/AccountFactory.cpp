#include "AccountFactory.h"
#include "CreditAccount.h"
#include "DepositAccount.h"
#include "CheckingAccount.h"
#include <iostream>

Account* AccountFactory::MakeCreditAccount()
{
	double money = 0.0;
	double termMoney = 0.0;
	float interestRate = 0.f;
	short int term = 0;

	std::cout << "Сумма кредитования: ";
	Input(termMoney);

	std::cout << "Срок кредитования (в годах): ";
	Input(term);

	std::cout << "Ставка по кредиту (в процентах): ";
	Input(interestRate);
	
	return new CreditAccount(money, interestRate, term, termMoney);
}

template<typename T>
void AccountFactory::Input(T& destination)
{
	std::cin >> destination;
}

Account* AccountFactory::MakeDepositAccount()
{
	double money = 0.0;
	double termMoney = 0.0;
	float interestRate = 0.f;
	short int term = 0;

	std::cout << "Срок депозита (в годах): ";
	Input(term);

	std::cout << "Процент по вкладу: ";
	Input(interestRate);

	std::cout << "Взнос: ";
	Input(money);

	return new DepositAccount(money, interestRate, term, termMoney);
}

Account* AccountFactory::MakeCheckingAccount()
{
	double money = 0.0;

	std::cout << "Сумма на счёте: ";
	Input(money);

	return new CheckingAccount(money);
}