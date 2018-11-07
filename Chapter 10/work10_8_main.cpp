#include<iostream>
#include "work10_8.h"
using namespace std;
int main()
{
	List use = List();
	use.isempty();
	use.isfull();
	use.listpush(60);
	use.show(0);
	use.listpush(70);
	use.show(1);
	use.listpush(80);
	use.show(2);
	use.listpush(90);
	use.show(3);
	use.listset(50,0);
	use.show(0);
	cin.get();
	return 0;
}