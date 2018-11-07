#include<iostream>
#include<string>
#include"work10_1.h"
using namespace std;
int main()
{
	Account ACC[2] = {
	Account(),
	Account("lxh", "12345", 233.33)
	};
	ACC[0].show();
	ACC[0].bankin(10000);
	ACC[0].show();
	ACC[0].bankout(5000);
	ACC[0].show();
	ACC[0].bankout(6000);
	ACC[0].show();
	ACC[1].show();
	ACC[1].bankin(2100);
	ACC[1].show();
	ACC[1].bankin(-10);
	cin.get();
	return 0;
}