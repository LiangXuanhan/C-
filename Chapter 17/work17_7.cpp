/*
 * work14_5.cpp
 *
 *  Created on: 2018Äê12ÔÂ5ÈÕ
 *      Author: Administrator
 */
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
void Showstr(const string &s){cout << s << endl;}
class Store
{
public:
	ofstream& o;
	Store(ofstream & ofs): o(ofs){}
	ofstream & operator()(const string &s)
	{int len = s.length();
	o.write((char *) len, sizeof len);
	o.write(s.data(), len);
	return o;
	}
};
vector<string> & Getstrs(ifstream & i, vector<string> & vi)
{
	int len;
	i.read((char *) &len, sizeof len);
	char tempc[len + 1];
	i.read(tempc, len);
	string temps(tempc);
	vi.push_back(temps);
	return vi;
}

int main(){
	vector<string> vostr;
	string temp;
	//acquire strings
	cout << "Enter strings (empty line to quit):\n";
	while(getline(cin,temp) && temp[0]!= '\0')
		vostr.push_back(temp);
	cout << "Here is your input. \n";
	for_each (vostr.begin(), vostr.end(), Showstr);
	// store in a file
	ofstream fout("string.dat", ios_base:: out | ios_base:: binary);
			for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();

	//recover file contents
	vector<string> vistr;
	ifstream fin("string.dat", ios_base:: in | ios_base:: binary);
	if(!fin.is_open())
	{}
	Getstrs(fin, vistr);
	cout<< "\nHere are the strings read from the file:\n";
	for_each(vistr.begin(), vistr.end(), Showstr);


	return 0;

}
