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
	ifstream fin;
	ofstream fout;
	fin.open(argv[1], ios_base::in);
	fout.open(argv[2], ios_base::out|ios_base:: app);
	if(fin.is_open()&& fout.is_open())
	{
		cout <<fout.tellp() << endl << fin.tellg();
	char temp;
//
	temp = fin.get();
	while(!fin.eof())
	{
	cout << temp;
	fout << temp;
	temp = fin.get();
	}
	cout << endl <<fout.tellp() << endl << fin.tellg();
	}
	else
	{cout << "File hasn't been opened.";
	exit(1);}
}


