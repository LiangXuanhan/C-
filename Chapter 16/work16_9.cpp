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
#include <utility>
#include<list>
using namespace std;

int main()
{
	srand(time(0));
	vector <int> vi0(0);
	list<int> li(0);
	for(int i = 0; i < 1000000; i++)
	{
		vi0.push_back(rand());

	}
vector<int> vi(vi0);
li.insert(li.begin(), vi0.begin(), vi0.end());
//
//	ostream_iterator<int> out(cout, " ");
//	copy(vi0.begin(), vi0.end(), out);
//cout << endl;
//copy(li.begin(), li.end(), out);
//cout << endl;
//li.erase(li.begin(), li.end());
//cout << endl << "erase";
//copy(li.begin(), li.end(), out);
//copy(vi.begin(), vi.end(), out);
//cout <<endl <<"end";
clock_t start, end;
start = clock();
sort(vi.begin(), vi.end());
end = clock();
cout << "Time to sort vi: " << double (end-start) / CLOCKS_PER_SEC << endl;
start = clock();
li.sort();
end = clock();
cout << "Time to sort li: " << double (end-start) / CLOCKS_PER_SEC << endl;
li.erase(li.begin(), li.end());
//	ostream_iterator<int> out(cout, " ");

li.insert(li.begin(), vi0.begin(), vi0.end());
vi.clear();
start = clock();
vi.insert(vi.begin(),li.begin(),li.end());
li.clear();
sort(vi.begin(), vi.end());
li.insert(li.begin(), vi.begin(), vi.end());
end = clock();
cout << "Time to sort li using plan B: " << double (end-start) / CLOCKS_PER_SEC << endl;
	return 0;
	}

