/*
 * work17_1.cpp
 *
 *  Created on: 2018��12��22��
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
	fout.open(argv[1], ios_base::out|ios_base:: app);
	if(fin.is_open()&& fout.is_open())
	{
		cout <<fout.tellp() << endl << fin.tellg();
	char temp;
//
	temp = fin.get();
	while(!fin.eof())
	{
	cout << temp;
	temp = fin.get();
	}
	cout << endl <<fout.tellp() << endl << fin.tellg();

	cout <<endl << "Input:";
	char tempc;
	while(!cin.eof())
	{tempc = cin.get();
	fout << tempc;
	}
	}
	else
	{cout << "File hasn't been opened.";
	exit(1);}
}


