/*
 * work13_1.cpp
 *
 *  Created on: 2018Äê11ÔÂ29ÈÕ
 *      Author: Administrator
 */

#include<iostream>
#include<cstring>
#include"work13_1.h"
using namespace std;

Cd::Cd(char * s1, char * s2, int n, double x)
{
	int len = strlen(s1);
	performers = new char[len + 1];
strcpy(performers, s1);
len = strlen(s2);
label = new char[len + 1];
strcpy(label, s2);
selections = n;
playtime = x;
}

Cd::Cd(const Cd & d)
{
	int len = strlen(d.performers);
		performers = new char[len + 1];
	strcpy(performers, d.performers);
	len = strlen(d.label);
	label = new char[len + 1];
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

void Cd::Report() const
	{
		cout <<  "Performers: " << performers << endl;
		cout << "Label: " << label << endl;
		cout << "Selections: " << selections << endl;
		cout << "Playtime: " << playtime << endl;
	}

	Cd & Cd::operator=(const Cd & d)
	{
		if (this ==&d)
			return *this;
		delete [] performers;
		delete [] label;
		int len = strlen(d.performers);
				performers = new char[len + 1];
			strcpy(performers, d.performers);
			len = strlen(d.label);
			label = new char[len + 1];
			strcpy(label, d.label);
			selections = d.selections;
			playtime = d.playtime;
		return *this;
	}
	Cd::Cd(){
		performers = new char[1];
		strcpy(performers, "\0");
		label = new char[1];
		strcpy(label, "\0");
		selections = 0;
	playtime = 0;
	}
	Cd::~Cd()
	{
		delete [] label;
		delete [] performers;
	cout << "Cd destroyed!";
	}

	Classic::Classic(char * nms, char * s1, char * s2, int n, double x): Cd(s1, s2, n, x)
	{
		int len = strlen(nms);
		names = new char[len + 1];
		strcpy(names, nms);
	}
	Classic::Classic(char * nms, const Cd & d) : Cd(d)
		{
			int len = strlen(nms);
					names = new char[len + 1];
					strcpy(names, nms);
		}

	Classic::Classic(){
		names = new char[1];
		strcpy(names, "\0");
	}
		Classic::~Classic()
		{
			delete [] names;
			cout << "Classic destroyed!" << endl;
		}
		void Classic::Report() const
		{
			Cd::Report();
			cout << "Names: " << names << endl;
		}
		Classic & Classic::operator=(const Classic & d)
		{
			if (this == &d)
				return *this;
			Cd::operator=(d);
			delete [] names;
			int len = strlen(d.names);
			names = new char [len + 1];
			strcpy(names, d.names);
			return *this;
		}
