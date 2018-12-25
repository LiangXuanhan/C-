/*
 * work17_1.cpp
 *
 *  Created on: 2018Äê12ÔÂ22ÈÕ
 *      Author: Administrator
 */

#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<iterator>
#include<algorithm>
#include<ctime>
#include <utility>
using namespace std;
#define MAX_t 1000
#define strglen 20
int main(int argc, char *argv[])
{
	ifstream fin1;
	ifstream fin2;
	ofstream fout;
fin1.open("Mat.txt", ios_base:: in);
fin2.open("Pat.txt", ios_base::in);
fout.open("matnpat.dat", ios_base::out | ios_base::app);
if (fin1.is_open() && fin2.is_open() && fout.is_open())
{
vector<pair<string, string>> Pat;
vector<pair<string, string>> Mat;
pair<string,string> temp;
cout << "Mat: " <<endl;
while(!fin1.eof())
{
fin1 >>get<0>(temp) >>get<1>(temp);
cout << get<0>(temp) << " "<< get<1> (temp) << endl;
Mat.push_back(pair<string,string>(temp));
}
cout << "Pat: " << endl;
while(!fin2.eof())
{
fin2 >>get<0>(temp) >>get<1>(temp);
cout << get<0>(temp) << " "<< get<1> (temp) <<endl;
Pat.push_back(pair<string,string>(temp));
}
vector<pair<string, string>> Comb;
for(auto x : Mat)
{Comb.push_back(x);}
for(auto x : Pat)
{Comb.push_back(x);}
cout<< "After combination:" << endl;
for(auto x: Comb )
{cout << get<0>(x) << " " << get<1>(x) << endl;}
sort(Comb.begin(), Comb.end());
Comb.erase(unique(Comb.begin(), Comb.end()), Comb.end());
cout<< "After unique: "<< endl;
for(auto x: Comb )
{cout << get<0>(x) << " " << get<1>(x) << endl;
fout << get<0>(x) << " " << get<1>(x) << endl;}
fout.close();


}
else
{
	cout << "Fail to link files.";
	exit(1);
}
}


