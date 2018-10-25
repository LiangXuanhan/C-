#include<iostream>
#include <cstring>
using namespace std;
int main()
{ char stack[100];
int cnt = 0;
	cout << "Iuput: \n";
do
{
cin >> stack;
cnt += 1;
}
while(strcmp(stack, "done"));
	cout << (cnt - 1);
	cin.get();
	cin.get();
	return 0;
}