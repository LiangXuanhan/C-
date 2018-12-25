/*
 * work16_7.cpp
 *
 *  Created on: 2018Äê12ÔÂ19ÈÕ
 *      Author: Administrator
 */

#include<iostream>
#include<vector>
#include<set>
#include<iterator>
#include<algorithm>
#include<ctime>
using namespace std;
vector<int> Lotto(int n, int m);
int main()
{
	srand(time(NULL));
	cout <<"Input number of numbers: ";
int n ;
cin>>n;
//n = 51;
cout << endl <<"Input number of jackpot numbers: ";
int m;
cin >>m;
//m = 6;
vector<int> winners = Lotto(n ,m);
ostream_iterator<int, char> out_iter(cout, " ");
copy(winners.begin(), winners.end(), out_iter);
	return 0;}
vector<int> Lotto(int n, int m)
		{
	set<int> s;
	while(s.size()!=m)
	{
		s.insert(rand()% (n + 1));
	}

	vector<int> temp(m);
	copy(s.begin(), s.end(), temp.begin());

	return temp;
		}
