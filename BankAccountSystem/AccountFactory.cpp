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

	std::cout << "����� ������������: ";
	Input(termMoney);

	std::cout << "���� ������������ (� �����): ";
	Input(term);

	std::cout << "������ �� ������� (� ���������): ";
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

	std::cout << "���� �������� (� �����): ";
	Input(term);

	std::cout << "������� �� ������: ";
	Input(interestRate);

	std::cout << "�����: ";
	Input(money);

	return new DepositAccount(money, interestRate, term, termMoney);
}

Account* AccountFactory::MakeCheckingAccount()
{
	double money = 0.0;

	std::cout << "����� �� �����: ";
	Input(money);

	return new CheckingAccount(money);
}