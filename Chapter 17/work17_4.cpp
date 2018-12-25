/*
 * work17_1.cpp
 *
 *  Created on: 2018Äê12ÔÂ22ÈÕ
 *      Author: Administrator
 */

#include<iostream>
#include<fstream>
using namespace std;
#define MAX_t 1000
int main(int argc, char *argv[])
{
	ifstream fin1;
	ifstream fin2;
	ofstream fout;
fin1.open("harry.txt", ios_base:: in);
fin2.open("tobuy.txt", ios_base::in);
fout.open("combine.txt", ios_base::out | ios_base::app);
if (fin1.is_open() && fin2.is_open() && fout.is_open())
{char ipt1[MAX_t], ipt2[MAX_t];
while(!fin1.eof()  && !fin2.eof())
	{fin1.getline(ipt1, MAX_t, '\n');
	fin2.getline(ipt2, MAX_t, '\n');
fout << ipt1 << " " << ipt2 <<endl;}
if(fin1.eof())
{
	while(!fin2.eof())
	{
		fin2.getline(ipt2, MAX_t, '\n');
		fout << ipt2 << endl;
	}
}
else
{
	while(!fin1.eof())
		{
			fin1.getline(ipt1, MAX_t, '\n');
			fout << ipt1 << endl;
		}
}
}
else
{
	cout << "Fail to link files.";
	exit(1);
}
}


