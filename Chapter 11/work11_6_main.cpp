#include<iostream>
#include "work11_6.h"
using namespace std;
int main()
{
	double pds = 0;
	Stonewt arr[6] = {Stonewt(1.1),
	Stonewt(2.2),
	Stonewt(3.3)
	}; 
	for (int i = 3; i < 6; i++)
	{

	cout << "input pounds:";
	cin >> pds;
	arr[i].rtnew(pds);
	}
	int min, max, cnt;
	cnt = 0;
	Stonewt test = Stonewt(10000);
	Stonewt test2 = Stonewt(0);
	for (int i = 0; i < 6; i++)
	{
	
	if (arr[i].show_lbs() > 11)
	{
	cnt++;
	}
	if(test > arr[i])
	{
	min = i;
	test.rtnew(arr[i].show_lbs());
	}
	if(test2 < arr[i])
	{
	max = i;
	test2.rtnew(arr[i].show_lbs());
	}
	}
	cout << "Min is"<< min <<endl;
	cout << "Max is"<< max <<endl;
	cout << "Cnt is"<< cnt <<endl;
	cin.get();
	return 0;
}