/*
 * work18_2.cpp
 *
 *  Created on: 2018Äê12ÔÂ25ÈÕ
 *      Author: Administrator
 */

#include<iostream>
#include<string>
#include<utility>
using namespace std;
class Cpmv
{
public:
	struct Info
	{
		string qcode;
		string zcode;
	};
private:
 Info * pi;
public:
Cpmv(){pi = new Info;}
Cpmv(string q, string z){pi = new Info; pi->qcode = q; pi->zcode = z;}
Cpmv(const Cpmv & cp){pi = new Info; pi->qcode = cp.pi->qcode; pi->zcode = cp.pi->zcode;}
Cpmv(Cpmv && mv){cout<< "Move con!" <<endl;pi = mv.pi;mv.pi = nullptr;}
~Cpmv(){delete pi;}
Cpmv & operator=(const Cpmv & cp){}
Cpmv & operator=(Cpmv && mv){
	cout << "Move ass!" <<endl;
	if (this==&mv)
		return *this;
	pi = mv.pi;
	mv.pi = nullptr;
	return *this;
}
Cpmv operator+(const Cpmv & obj) const{Cpmv temp(*this);
temp.pi->qcode += obj.pi->qcode;
temp.pi->zcode += obj.pi->zcode;
return temp; }
void Display() const{cout << pi->qcode << endl << pi->zcode <<endl;}

};
 int main()
 {
	 Cpmv test("a", "b");
	 Cpmv test2("c", "d");
	 Cpmv test3;
	 Cpmv test4(test + test2);
	 test3 = test + test2;
	 test3.Display();

	 return 0;
 }


