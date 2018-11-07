//#include<iostream>
#include "work10_8.h"
using namespace std;
List::List()
{
top = 0;
}

List::~List()
{
cout << "Bye!!" << endl;
}

void List::listpush (listtype obj)
{
if(top > NUM)
cout << "List is full. No obj is pushed in." << endl;
else
list[top++] = obj;
}

bool List::isempty()const
{
	if(top == 0)
		{
			cout << "Empty!" << endl;
		return true;
	}
	else
	{
	cout << "Not empty!" << endl;
	return false;
	}
}

bool List::isfull()const
{
	if(top == NUM)
		{
			cout << "Full!" << endl;
		return true;
	}
	else
	{
	cout << "Not full!" << endl;
	return false;
	}
}

void List::listset(listtype obj, int location)
{
	if(location >= 0 && location <= top)
	list[location] = obj;
	else
		cout << "Wrong location!" << endl;
}

void List::show(int location)const
{
	if(location >= 0 && location <= top)
	cout << list[location] << endl;
	else
		cout << "Wrong location!" << endl;
}