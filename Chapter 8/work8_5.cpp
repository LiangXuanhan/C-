#include<iostream>
using namespace std;
template <typename T>
T max5(T arr[]);
int main(){
	int intarr[5] = {6, 2, 8, 4, 5};
	double dbarr[5] = {6.6, 2.2, 8.8, 4.4, 5.5};
	cout << "MAX INT: " << max5(intarr) << endl;
	cout << "MAX DOUBLE: " << max5(dbarr) << endl;
	cin.get();
	return 0;
}
template <typename T>
T max5(T arr[])
{
	T temp = arr[0];
	for(int i = 1; i < 5;i ++)
	{
	temp = arr[i] < temp ? temp : arr[i];
	}
	return temp;
}