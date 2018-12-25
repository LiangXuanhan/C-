/*
 * work18_2.cpp
 *
 *  Created on: 2018Äê12ÔÂ25ÈÕ
 *      Author: Administrator
 */

#include<iostream>
#include<string>
#include<utility>
#include<initializer_list>
using namespace std;

long double sum_value1()
{
return 0;
}
template<typename T>
long double sum_value1(const T t)
{
return t;
}
template<typename T, typename... Args>
long double sum_value1(const T t, const Args...args)
{
	long double sum = 0;
	sum=t + sum_value1(args...);
	return sum;
}

 int main()
 {
	 long double a = sum_value1(1.1, 2.2, 3.3, 4.4);
	 cout << a;

	 return 0;
 }


