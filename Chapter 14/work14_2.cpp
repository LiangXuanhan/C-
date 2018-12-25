/*
 * work14_2.cpp
 *
 *  Created on: 2018年12月4日
 *      Author: Administrator
 */


/*
 * work14_1.h
 *
 *  Created on: 2018年12月4日
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

class Wine : private string, private PairArray
{
private:
	int year;
public:
	Wine(): string("N"){year = 3;}
	Wine(const char * l, int y, const int yr[], const int bot[]): string(l), PairArray(ArrayInt(yr,y), ArrayInt(bot, y))
	{
		year = y;
	}
	Wine(const char *l, int y): string(l), PairArray(ArrayInt(0,y), ArrayInt(0, y))
	{
    year = y;
	}
	~Wine(){}
	void GetBottles()
	{
		cout << "You can save " << year << " pieces of information.";
				for(int i =0; i < year; i++)
				{
					cout <<"No." << i << ": \n" << "Year:";
					cin>>PairArray::first()[i];
					while(cin.get()!= '\n')
						continue;
					cout << "Number of bottles: ";
					cin>>PairArray::second()[i];
								while(cin.get()!= '\n')
									continue;
				}
	}
	const string & label()
	{
		return (const string &)*this;
	}
	int sum()
	{
		int su = 0;
		for(int i = 0; i < year; i ++)
			{
			su += PairArray::second()[i];
			}
		return su;
	}
	void Show()
	{
		cout<< year <<" pieces information.\n";
		for(int i = 0; i < year ; i++)
				{
					cout << "No." << (i + 1) <<endl;
					cout << "Year: " << PairArray::first()[i] << endl;
					cout << "Bottle Number: " << PairArray::second()[i] << endl;
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






