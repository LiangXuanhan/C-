/*
 * work17_1.cpp
 *
 *  Created on: 2018��12��22��
 *      Author: Administrator
 */

#include<iostream>
using namespace std;
#define MAX_t 1000
int main()
{
	cout << "Input a sentence: ";
	int cnt = 0;
	char temp;
	while(cin.peek()!='$')
		{cnt++;

		if(cnt== MAX_t)
		{cout <<endl <<"Too long!";}
		cin.get();}
	cout<< cnt <<" characters in this sentence." << endl;
	cin >>temp;
	cout <<temp;
	return 0;
}


