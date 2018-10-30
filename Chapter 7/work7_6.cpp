#include<iostream>
#include<cctype>
const int ARSIZE = 5;
using namespace std;
double *Fill_array(double *, int);
void Show_array(const double *,int);
double *Reverse_array(double *, int);
int main()
{
	double arraystore[ARSIZE];
	double *newarrs;
	newarrs = Fill_array(arraystore, ARSIZE);
	Show_array(newarrs, ARSIZE);
	newarrs = Reverse_array(newarrs, ARSIZE);
	Show_array(newarrs, ARSIZE);
	cin.ignore(ARSIZE);
	cin.get();
	return 0;
}
double *Fill_array(double *arr, int n)
{
	double tmp;
	for(int i = 0; i < n; i++)
	{
	if(cin >> tmp)
		arr[i] = tmp;
	else
		{cout << "Not number. Input over.\n";
	break;}
	}
	return &arr[0];
}
void Show_array(const double *arr,int n)
{
for (int i = 0;i < n; i++)
{
cout << *(arr + i) << endl;
}
}
double *Reverse_array(double *arr, int n)
{
for(int i = 0; i <(n - i) ;i++)
{
double tmp;
tmp = arr[i];
arr[i] = arr[n - i - 1];
arr[n - i - 1] = tmp;
}
return arr;
}