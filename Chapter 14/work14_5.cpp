/*
 * work14_5.cpp
 *
 *  Created on: 2018Äê12ÔÂ5ÈÕ
 *      Author: Administrator
 */
#include<iostream>
#include<string>
using namespace std;
class abstr_emp
{
private:
	string fname;
	string lname;
	string job;
protected:
	void Display() const {cout << "Name: " << fname <<" " << lname << endl;}
	virtual void Set(){cout<< "Set: "; cin>> fname >> lname >>job;}
public:

	abstr_emp(){fname = "John"; lname = "Doe"; job = "Programmer";}
	abstr_emp(const string & fn, const string & ln, const string & j){fname = fn; lname = ln; job = j;}
	virtual void ShowAll() const{}
	virtual void SetAll(){Set();}
	friend ostream & operator<<(ostream & os, const abstr_emp & e){ os << e.fname << " " << e.lname <<endl; return os;}
	virtual ~abstr_emp() = 0;
};
abstr_emp::~abstr_emp(){}
class employee : public abstr_emp
{
public:
	employee() : abstr_emp(){}
	employee(const string & fn, const string & ln, const string & j) : abstr_emp(fn, ln, j){}
	virtual void ShowAll() const{cout<<"Employee!" <<endl; abstr_emp::Display();}
	virtual void SetAll(){cout << "Employee Set!" << endl; abstr_emp::SetAll();}
};

class manager : virtual public abstr_emp
{
private:
	int inchargeof;
protected:
	int InChargeOf() const {return inchargeof;}
	int & InChargeOf(){return inchargeof;}
	virtual void Display() const {cout << "Number in charge of: " << inchargeof<<endl;}
	virtual void Set(){cout<< "Number in charge of:"; cin >> inchargeof;}
public:
	manager(): abstr_emp(){inchargeof = 0;}
	manager(const string & fn, const string & ln, const string & j, int ico = 0) : abstr_emp(fn, ln, j)
	{inchargeof = ico;}
	manager(const abstr_emp & e, int ico): abstr_emp(e){inchargeof = ico;}
	manager(const manager & m): abstr_emp(m){inchargeof = m.InChargeOf();}
	virtual void ShowAll() const { cout << "Manager!" << endl; abstr_emp::Display();Display();}
	virtual void SetAll(){cout << "Manager Set!"; abstr_emp::Set(); Set();}
};

class fink : virtual public abstr_emp
{
private:
	string reportsto;
protected:
	const string ReportsTo() const {return reportsto;}
	string ReportsTo() {return reportsto;}
	virtual void Display() const {cout << "To whom reports: " << reportsto<<endl;}
	virtual void Set(){cout<< "To whom reports: "; cin >> reportsto; cout << endl;}
public:
	fink(): abstr_emp(){reportsto = "Thor";}
	fink(const string & fn, const string & ln, const string & j, string rt = "Loki") : abstr_emp(fn, ln, j)
	{reportsto =rt;}
	fink(const abstr_emp & e, string rt): abstr_emp(e){reportsto =rt;}
	fink(const fink & m): abstr_emp(m){reportsto = m.ReportsTo();}
	virtual void ShowAll() const { cout << "Fink!" << endl; abstr_emp::Display();Display();}
	virtual void SetAll(){cout << "Fink Set!"; abstr_emp::Set(); Set();}
};

class highfink : public manager, public fink
{
protected:
	virtual void Display() const {}
	virtual void Set(){}
public:
	highfink(): abstr_emp(), manager(), fink(){}
	highfink(const string & fn, const string & ln, const string & j, string rt = "Loki", int ico = 0) : abstr_emp(fn, ln, j)
	, manager(fn, ln, j, ico), fink(fn, ln, j, rt){}
	highfink(const abstr_emp & e, int ico, string rt): abstr_emp(e), manager(e, ico), fink(e, rt){}
	highfink(const manager & m, string rt): abstr_emp(m), manager(m), fink(m, rt){}
	highfink(const fink & e, int ico): abstr_emp(e), manager(e, ico), fink(e){}
	highfink(const highfink & m): abstr_emp(m), manager(m), fink(m){}
	virtual void ShowAll() const { cout << "Highfink!" << endl; abstr_emp::Display();manager::Display(); fink::Display();}
	virtual void SetAll(){cout << "Highfink Set!"; abstr_emp::Set(); manager::Set(); fink::Set();}
};

int main ()
{
employee em("Trip", "Harris", "Thumper");
cout << em << endl;
em.ShowAll();
manager ma("Amorphia", "Spindragon", "Nuancer", 5);
cout<< ma << endl;
ma.ShowAll();
fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
cout << fi <<endl;
fi.ShowAll();
highfink hf(ma, "Curly Kew");
hf.ShowAll();
cout <<"Input a key for next phase:\n";
cin.get();
highfink hf2;
hf2.SetAll();
cout<<"Using abstr_emp * pointer:\n";
abstr_emp *tri[4] = {&em, &fi, &hf, &hf2};
for(int i = 0; i < 4; i++)
	tri[i]->ShowAll();
return 0;
}
