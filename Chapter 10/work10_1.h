#pragma once
#ifndef WORK10_1_H
#define WORK10_1_H
#include<string>
using namespace std;
class Account
{
private:
	string name_;
	string acc_;
	double deposit_;
public:
	Account();
	Account(const string name, const string acc, double deposit);
	~Account();
	void show()const;
	void bankin(double number);
	void bankout(double number);

};
#endif