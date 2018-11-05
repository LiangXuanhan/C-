#include "golf.h"
#include <string>
using namespace std;
void setgolf(golf & g, const char * name, int hc)
{
	strcpy(g.fullname, name);
	g.handicap = hc;
}

int setgolf(golf & g)
{
	
cout << "Input fullname: ";
cin >> g.fullname;
cout << "Input handicap: ";
cin >> g.handicap;
return 0;
}

void handicap(golf & g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf & g)
{
	cout << "Name: " << g.fullname << endl;
	cout << "Handicap: " << g.handicap << endl;
}