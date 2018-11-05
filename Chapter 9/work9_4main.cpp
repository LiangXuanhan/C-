#include<iostream>
#include "work9_4.h"
using namespace SALES;
int main()
{
	Sales A, B;
	Sales & refa = A; 
	Sales & refb = B;
	double ar[QUARTERS] = {1,2,3,4};
	setSales(refa, ar, QUARTERS);
	showSales(refa);
	setSales(refb);
	showSales(refb);
	std::cin.ignore(4);
	std::cin.get();
return 0;
}
