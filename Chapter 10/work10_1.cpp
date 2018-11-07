#include<iostream>
#include<string>
#include "work10_1.h"
Account::Account()
{
	name_ = "noname";
	acc_ = "00000";
	deposit_ = 0.0;
}

Account::Account(const string name, const string acc, double deposit)
{
	name_ = name;
	acc_ = acc;
	deposit_ = deposit;
}

Account::~Account()
{
cout << "See you!" << endl;
}

void Account::show() const
{
	cout << "Name: " << name_ <<endl;
	cout << "Account: " << acc_ << endl;
	cout << "Deposit: " << deposit_ << endl;
}

void Account::bankin( double number)
{
if(number > 0)
	deposit_ += number;
else
	cout << "You have to input more than zero!" << endl;
}

void Account::bankout(double number)
{
if(number > 0)
{if(number > deposit_)
cout << "The money in bank is not enough!" << endl;
else
	deposit_ -= number;
}
else
	cout << "You have to take more than zero!" << endl;
}