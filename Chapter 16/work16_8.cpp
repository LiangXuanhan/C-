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
using namespace std;

int main()
{
	vector<pair<string,string>> Mat;
	vector<pair<string,string>> Pat;
	string fn, ln;
	cout << "Mat inserts name: " ;
	cin>> fn >>ln;
	while(fn!="q")
	{Mat.push_back(pair<string,string>(fn, ln));
	cout<< "Mat inserts name: ";
	cin>> fn >>ln;
	}
//	Mat.push_back(pair<string,string>("a", "s"));
//	Mat.push_back(pair<string,string>("d", "f"));
//	Mat.push_back(pair<string,string>("y", "u"));
//	Mat.push_back(pair<string,string>("i", "o"));
	sort(Mat.begin(), Mat.end());

//copy(Mat.begin(), Mat.end(), out);
for(auto pt : Mat)
{cout << get<0>(pt) << " " << get<1>(pt) << endl;}
cout << "Pat inserts name: " ;
	cin>> fn >>ln;
	while(fn!="q")
	{Pat.push_back(pair<string,string>(fn, ln));
	cout<< "Pat inserts name: ";
	cin>> fn >>ln;
	}
//	Mat.push_back(pair<string,string>("a", "s"));
//	Mat.push_back(pair<string,string>("d", "f"));
//	Mat.push_back(pair<string,string>("y", "u"));
//	Mat.push_back(pair<string,string>("i", "o"));
	sort(Pat.begin(), Pat.end());
	for(auto pt : Pat)
	{cout << get<0>(pt) << " " << get<1>(pt) << endl;}
		vector<pair<string,string>> temp;
		for(auto x : Mat)
		{temp.push_back(x);}
		for(auto x : Pat)
		{ temp.push_back(x);}
		sort(temp.begin(), temp.end());
		temp.erase(unique(temp.begin(),temp.end()), temp.end());
		cout <<"temp:" << endl;
		for(auto pt : temp)
			{cout << get<0>(pt) << " " << get<1>(pt) << endl;}
	return 0;
	}

