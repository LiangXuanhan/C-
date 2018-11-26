#include <iostream>
#include <string>
#include "work12_1.h"
using namespace std;
int Cow::cnt = 0;
Cow::Cow(){
strcpy(name, "\0");
len = 0;
hobby = new char[len + 1];
strcpy(hobby, "\0");
weight = 0;
cnt ++;
}

Cow::Cow(const char * nm, const char * ho, double wt){
	len = strlen(ho);
	hobby = new char[len + 1];
	strcpy(name, nm);
	strcpy(hobby, ho);
	weight = wt;
	cnt++;
}

Cow::Cow(const Cow & c){
	cnt++;
	len = c.len;
	strcpy(name, c.name);
	hobby = new char[len + 1];
	strcpy(hobby, c.hobby);
	weight = c.weight;
}

Cow::~Cow(){
	delete [] hobby;
	--cnt;
	cout <<"Destroy!" << endl;	
}

Cow & Cow::operator=(const Cow & c)
{
	if(this == & c)
		return *this;
	delete [] hobby;
	len = c.len;
	hobby = new char[len + 1];
	strcpy(name, c.name);
	strcpy(hobby, c.hobby);
	weight = c.weight;
	return *this;
}

void Cow::ShowCow() const{
	cout << "Name: " << name << endl;
	cout << "Hobby: " << hobby << endl;
	cout << "Weight: " << weight << endl;
}

void Cow::ShowCnt() const{
	cout << "Number: " << cnt <<endl;
}