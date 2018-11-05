#include<iostream>
#include "work9_4.h"
namespace SALES
{
void setSales(Sales & s, const double ar[], int n)
{
	double mintmp, maxtmp, sum;
	mintmp = ar[0];
	maxtmp = ar[0];
	sum = 0;
	for(int i =0; i < n; i++)
	{
		s.sales[i] = ar[i];
		sum += ar[i];
		mintmp = mintmp < ar[i] ? mintmp : ar[i];
		maxtmp = maxtmp > ar[i] ? maxtmp : ar[i];
	}
	s.average = sum / n;
	s.max = maxtmp;
	s.min = mintmp;
}

void setSales(Sales & s)
{
using namespace std;
double mintmp, maxtmp, sum;

	sum = 0;
int n = 0;
cout << "Input q to t=quit" << endl;
cout << "Input sales: " << endl;
if(cin != "q" && n < 4)
{
	cin >> s.sales[n];
	mintmp = s.sales[0];
    maxtmp = s.sales[0];
	sum += s.sales[n];
		mintmp = mintmp < s.sales[n] ? mintmp : s.sales[n];
		maxtmp = maxtmp > s.sales[n] ? maxtmp : s.sales[n];
		n++;
	cout << "Input sales: " << endl;
}
while(cin != "q" && n < 4)
{
	cin >> s.sales[n];
	sum += s.sales[n];
		mintmp = mintmp < s.sales[n] ? mintmp : s.sales[n];
		maxtmp = maxtmp > s.sales[n] ? maxtmp : s.sales[n];
		n++;
	cout << "Input sales: " << endl;
}
s.average = sum / n;
	s.max = maxtmp;
	s.min = mintmp;

}
void showSales(const Sales & s)
{
	using namespace std;
	cout <<"Sales: ";
	for (int i = 0; i < (sizeof(s.sales)/8);i++)
	{
		cout << s.sales[i] << " "; 
	}
	cout << endl << "Average: "<< s.average << endl;
	cout << "MAX: " << s.max << endl;
	cout << "MIN: " << s.min << endl;
}
}