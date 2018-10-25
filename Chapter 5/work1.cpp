#include<iostream>
using namespace std;
int main()
{ int min, max, sum;
	cout <<"Input a small integer: ";
	cin >> min;
	cout << endl << "Input a big integer: ";
	cin >> max;
	sum = 0;
	for(int i = min; i <=max; ++i)
		sum += i;
	cout << endl << "The sum is: " << sum << endl;

	cin.get();
	cin.get();
	return 0;
}