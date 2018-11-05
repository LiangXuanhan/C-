#include<iostream>
#include "golf.h"
using namespace std;
int main()
{
	golf test;
	golf & ref = test;
	setgolf(ref, "lxh", 10);
	showgolf(ref);
	setgolf(ref);
	showgolf(ref);
	handicap(ref, 12);
	showgolf(ref);
	cin.get();
	cin.get();
return 0;
}