#include<iostream>
#include<vector>
#include<array>
using namespace std;
int main()
{
	cout << "Input time for 40 meters running.\n";
	vector<double> time[3];
	array<double, 3> Time;
	cin >> Time[0] >> Time [1] >> Time[2];
	int a = sizeof(Time) / 8;
	double sum = 0;
	for (int i = 0; i < a; i++)
	{
	sum = sum + Time[i];
	}
	double avg = sum / a;
	cout << "Times: "<< a <<endl;
	cout << "Average: "<< avg <<endl;
	cin.get();
	cin.get();
}