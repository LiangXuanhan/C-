/*
 * work18_1.cpp
 *
 *  Created on: 2018Äê12ÔÂ25ÈÕ
 *      Author: Administrator
 */

#include<iostream>
#include<vector>
#include<initializer_list>
using namespace std;
template<typename T>
T average_list(initializer_list<T> il){
	vector<T> temp(il);
	T r = 0;
	for( T x: temp)
	{r+=x;}
	r = r / temp.size();
	return r;
}
int main(){
	auto q = average_list({15.4, 10.7, 8.0});
	cout << q << endl;

	cout << average_list({20, 30, 19, 17, 45, 30}) << endl;
	auto ad = average_list<double>({'A', 70, 65.33});
	cout << ad << endl;
	return 0;
}


