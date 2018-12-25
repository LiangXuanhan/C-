/*
 * work14_1.h
 *
 *  Created on: 2018Äê12ÔÂ4ÈÕ
 *      Author: Administrator
 */


#include<iostream>
#include <array>
#include <string>
#include <valarray>
#include"pairs.h"
using namespace std;
typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine
{
private:
	string NAME;
	PairArray VA;
	int year;
public:
	Wine(){VA = PairArray(ArrayInt(1), ArrayInt(1)); NAME = "NA"; year = 3;}
	Wine(const char * l, int y, const int yr[], const int bot[])
	{
		NAME = l;
		year = y;
		VA = Pair<valarray<int>, valarray<int>>(valarray<int>(y), valarray<int>(y));
for(int i = 0; i < y; i++)
{
	VA.first()[i] = yr[i];
	VA.second()[i] = bot[i];
}
	}
	Wine(const char *l, int y)
	{

		NAME = l;
		year = y;
		VA = Pair<valarray<int>, valarray<int>>(ArrayInt(y), ArrayInt(y));
		for(int i = 0; i < y; i++)
		{
			VA.first()[i] = 0;
			VA.second()[i] = 0;
		}
	}
	~Wine(){}
	void GetBottles()
	{
		cout << "You can save " << year << " pieces of information.";
		for(int i =0; i < year; i++)
		{
			cout <<"No." << i << ": \n" << "Year:";
			cin>>VA.first()[i];
			while(cin.get()!= '\n')
				continue;
			cout << "Number of bottles: ";
			cin>>VA.second()[i];
						while(cin.get()!= '\n')
							continue;
		}
	}
	string & label()
	{
		return NAME;
	}
	int sum()
	{
		int su = 0;
		for(int i = 0; i < year; i ++)
		{
		su += VA.second()[i];
		}
		return su;
	}
	void Show()
	{
		cout<< year <<" pieces information.\n";
		for(int i = 0; i < year ; i++)
		{
			cout << "No." << (i + 1) <<endl;
			cout << "Year: " << VA.first()[i] << endl;
			cout << "Bottle Number: " << VA.second()[i] << endl;
		}

	}
};


int main()
{
	int yr[3] = {1980, 1985, 1990};
	int bot[3] = {4,5,6};
	int y = 3;
	Wine test("OK", y, yr, bot);
	cout << test.label();
	cout << endl << test.sum() << endl;
	test.Show();
			test.GetBottles();
			cout << test.label();
				cout << endl << test.sum();
				test. Show();
return 0;
}




