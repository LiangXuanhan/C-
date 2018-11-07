#include<iostream>
using namespace std;
template <typename T>
T maxn(T arr[], int n);
int main(){
	int intarr[6] = {6, 2, 8, 4, 5, 1};
	double dbarr[4] = {6.6, 2.2, 8.8, 4.4};
	cout << "NEW!\n";
	cout << "MAX INT: " << maxn(intarr, 6) << endl;
	cout << "MAX DOUBLE: " << maxn(dbarr, 4) << endl;
	cin.get();
	return 0;
}
template <typename T>
T maxn(T arr[], int n)
{
	T temp = arr[0];
	for(int i = 1; i < n;i ++)
	{
	temp = arr[i] < temp ? temp : arr[i];
	}
	return temp;
}