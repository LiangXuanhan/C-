#pragma once
#ifndef WORK10_8_H
#define WORK10_8_H
#include<iostream>
typedef unsigned long listtype;
class List
{
private:
	enum {NUM = 100};
	listtype list[NUM];
	int top;
public:
List();
~List();
void listpush(listtype obj);
bool isempty()const;
bool isfull()const;
void listset(listtype obj, int location);
void show(int location)const;
};
#endif