/*
 * work13_1_main.cpp
 *
 *  Created on: 2018��11��29��
 *      Author: Administrator
 */
#include<iostream>
#include"work13_1.h"
using namespace std;
void Bravo(const Cd & disk);
int main ()
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata", "Alfred Brebdel", "Philips", 2, 57.17);
	Cd *pcd = &c1;
	cout << "Using object directly: \n";
	c1.Report();
	c2.Report();
	cout <<"Using type cd * pointer to objects: \n";
	pcd ->Report();
	pcd = &c2;
	pcd ->Report();
	cout << "Calling a function with a Cd reference argument: \n";
	Bravo(c1);
	Bravo(c2);
	cout << "Testing assignment: ";
	Classic copy;
	copy = c2;
	copy.Report();
	cin.get();
	return 0;
}
void Bravo(const Cd & disk)
{
disk.Report();
}


