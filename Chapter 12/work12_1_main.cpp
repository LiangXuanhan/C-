#include<iostream>
#include"work12_1.h"
using namespace std;
int main(){
	char buffer[512];
	Cow *buftest = new (buffer) Cow;
	Cow test;
	test.ShowCow();
	test.ShowCnt();
	Cow test2("MAX", "Eat", 233);
	test2.ShowCow();
	test2.ShowCnt();
	*buftest = test2;
	buftest->ShowCow();
	buftest->ShowCnt();
	buftest->~Cow();
	Cow test3(test2);
	test3.ShowCow();
	test3.ShowCnt();
	Cow test4;
	test4 = test2;
	test4.ShowCow();
	test4.ShowCnt();
	test4 = test3;
	test4.ShowCow();
	test4.ShowCnt();
	test2.~Cow();
	test3.ShowCnt();
	return 0;
}