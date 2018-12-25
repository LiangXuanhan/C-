/*
 * work16_4.cpp
 *
 *  Created on: 2018Äê12ÔÂ19ÈÕ
 *      Author: Administrator
 */
#include<iostream>
#include<array>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
template<class T>
int reduce(T arr[], int n);
int main()
{
	int arr[10] = {1,2,3,99,99,5,6,2,1,3};
	int num = reduce(arr, 10);
	cout <<endl<< num;
return 0;
}
template<class T>
int reduce(T arr[], int n)
{//{vector<long> temp;
//for(int i = 0; i < n; i++)
//{temp.push_back(arr[i]);
//	}
//array<double, 10> ts;
sort(arr, arr+n);
auto it = unique(arr, arr +n);
int cnt = 0;
T * po;
for(po = arr; po!= it; po++)
	cnt++;
ostream_iterator<T, char> out_iter(cout, " ");
copy(arr, arr+cnt, out_iter);
return cnt;
}
