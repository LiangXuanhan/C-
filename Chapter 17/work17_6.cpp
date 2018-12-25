/*
 * work14_5.cpp
 *
 *  Created on: 2018Äê12ÔÂ5ÈÕ
 *      Author: Administrator
 */
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
#define maxlen 10
class abstr_emp
{
private:
	int kind;
	string fname;
	string lname;
	string job;

protected:
	void Display() const {cout << "Name: " << fname <<" " << lname << endl << "Job: " << job <<endl;}
	virtual void Set(){cout<< "Set: "; cin>> fname >> lname >>job;}
public:

	abstr_emp(int k = 0): kind(k){fname = "John"; lname = "Doe"; job = "Programmer";}
	abstr_emp(const string & fn, const string & ln, const string & j, int k = 0){fname = fn; lname = ln; job = j;kind = k;}
	virtual void ShowAll() const{}
	virtual ofstream & SaveAll(ofstream & fout){fout << kind << endl << fname << endl << lname << endl << job << endl;return fout;}
	virtual void SetAll(){Set();}
	friend ostream & operator<<(ostream & os, const abstr_emp & e){ os << e.fname << " " << e.lname <<endl; return os;}
	virtual ~abstr_emp() = 0;
};
abstr_emp::~abstr_emp(){}
class employee : public abstr_emp
{
public:
	employee(int k = 1) : abstr_emp(k){}
	employee(const string & fn, const string & ln, const string & j, int k = 1) : abstr_emp(fn, ln, j, k){}
	virtual void ShowAll() const{cout<<"Employee!" <<endl; abstr_emp::Display();}
	virtual ofstream & SaveAll(ofstream & fout){return abstr_emp::SaveAll(fout);}
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
	manager(int k = 2): abstr_emp(k){inchargeof = 0;}
	manager(const string & fn, const string & ln, const string & j, int ico = 0, int k = 2) : abstr_emp(fn, ln, j, k)
	{inchargeof = ico;}
	manager(const abstr_emp & e, int ico): abstr_emp(e){inchargeof = ico;}
	manager(const manager & m): abstr_emp(m){inchargeof = m.InChargeOf();}
	int Echom(){return inchargeof;}
	virtual ofstream & SaveAll(ofstream & fout){abstr_emp::SaveAll(fout) << inchargeof<< endl; return fout;}
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
	fink(int k = 3): abstr_emp(k){reportsto = "Thor";}
	fink(const string & fn, const string & ln, const string & j, string rt = "Loki", int k = 3) : abstr_emp(fn, ln, j, k)
	{reportsto =rt;}
	fink(const abstr_emp & e, string rt): abstr_emp(e){reportsto =rt;}
	fink(const fink & m): abstr_emp(m){reportsto = m.ReportsTo();}
	string Echof(){return reportsto;}
	virtual ofstream & SaveAll(ofstream & fout){abstr_emp::SaveAll(fout) << reportsto <<endl; return fout;}
	virtual void ShowAll() const { cout << "Fink!" << endl; abstr_emp::Display();Display();}
	virtual void SetAll(){cout << "Fink Set!"; abstr_emp::Set(); Set();}
};

class highfink : public manager, public fink
{
protected:
	virtual void Display() const {}
	virtual void Set(){}
public:
	highfink(int k = 4): abstr_emp(k), manager(k), fink(k){}
	highfink(const string & fn, const string & ln, const string & j, string rt = "Loki", int ico = 0, int k = 4) : abstr_emp(fn, ln, j, k)
	, manager(fn, ln, j, ico, k), fink(fn, ln, j, rt, k){}
	highfink(const abstr_emp & e, int ico, string rt): abstr_emp(e), manager(e, ico), fink(e, rt){}
	highfink(const manager & m, string rt): abstr_emp(m), manager(m), fink(m, rt){}
	highfink(const fink & e, int ico): abstr_emp(e), manager(e, ico), fink(e){}
	highfink(const highfink & m): abstr_emp(m), manager(m), fink(m){}
	virtual void ShowAll() const { cout << "Highfink!" << endl; abstr_emp::Display();manager::Display(); fink::Display();}
	virtual ofstream & SaveAll(ofstream & fout){abstr_emp::SaveAll(fout) << Echom() << endl<< Echof() << endl; return fout;}
	virtual void SetAll(){cout << "Highfink Set!"; abstr_emp::Set(); manager::Set(); fink::Set();}
};

int main ()
{ abstr_emp * arr[10];
	ofstream fout ("data.txt", ios_base:: out | ios_base:: app);
	ifstream fin("data.txt", ios_base:: in);
	int kd, ico, len;
	string fn, ln, job, rt, rt2;

	for(int k = 0; k < maxlen; k++)
	{


	fin >>kd;
	if(fin.eof())
	{break;}
	switch(kd)
	{
	case 1:
				fin >>fn >>ln >> job;
		arr[k] = new employee(fn, ln, job, 1);
		len = k;
		break;
	case 2:
		fin >>fn >> ln >> job >> ico;
		arr[k] = new manager(fn, ln, job, ico, 2);
		len = k;
		break;
	case 3:
		fin >> fn >>ln >> job>> rt;

		arr[k] = new fink(fn, ln, job, rt, 3);
		len = k;
		break;
	case 4:
		fin >> fn >> ln >> job >> ico >>rt;

		arr[k] = new highfink(fn, ln, job, rt, ico, 4);
		len = k;
		break;

	}
	}
//employee em("Trip", "Harris", "Thumper");
//cout << em << endl;
//em.ShowAll();
//arr[0] = &em;
//manager ma("Amorphia", "Spindragon", "Nuancer", 5);
//cout<< ma << endl;
//ma.ShowAll();
//arr[1] = &ma;
//fink fi("Matt", "Oggs", "Oiler", "Juno Barr", 3);
//cout << fi <<endl;
//fi.ShowAll();
//arr[2] = &fi;
//highfink hf("Harry", "Potter","Farmer", "Curly Kew", 10, 4);
//hf.ShowAll();
//arr[3] = &hf;
	len = len + 1;
for(int i = 0; i < len; i++)
{
arr[i]->ShowAll();
}
while(len < maxlen)
{
cout << endl << "Will you in put new data? Type:" <<endl ;
cout << "1 Employee" << endl << "2 Manager" << endl << "3 Fink" << endl << "4 Highfink" << endl
		<< "5 Quit" << endl;
int choose;
cin >>choose;
switch(choose)
{
case 1:
	cout<< "First name: ";
	cin  >> fn;
	cout << endl << "Last name: ";
	cin >> ln;
	cout << endl<< "Job:";
			cin >> job;
			arr[++len] = new employee(fn, ln, job, choose);
			arr[len]->SaveAll(fout);
	break;
case 2:
	cout<< "First name: ";
		cin  >> fn;
		cout << endl << "Last name: ";
		cin >> ln;
		cout << endl<< "Job:";
				cin >> job;
				cout <<endl << "Number of people in charge of: ";
				cin >> ico;
				arr[++len] = new manager(fn, ln, job, ico, choose);
				arr[len]->SaveAll(fout);
	break;
case 3:
	cout<< "First name: ";
			cin  >> fn;
			cout << endl << "Last name: ";
			cin >> ln;
			cout << endl<< "Job:";
					cin >> job;
					cout <<endl << "To whom report to: ";
					cin >> rt;
					arr[++len] = new fink(fn, ln, job, rt, choose);
					arr[len]->SaveAll(fout);
	break;
case 4:
	cout<< "First name: ";
			cin  >> fn;
			cout << endl << "Last name: ";
			cin >> ln;
			cout << endl<< "Job:";
					cin >> job;
					cout <<endl << "Number of people in charge of: ";
					cin >> ico;
					cout <<endl << "To whom report to: ";
										cin >> rt;
					arr[++len] = new highfink(fn, ln, job, rt, ico, choose);
					arr[len]->SaveAll(fout);
					break;
case 5:
	cout << "Quit." << endl;
	for(int i = 0; i < (len+ 1); i++)
	{
	arr[i]->ShowAll();
	}
	fout.close();
	exit(1);
	break;
}
}
cout << "Array is full;" << endl;
for(int i = 0; i < (len+ 1); i++)
	{
	arr[i]->ShowAll();
	}
//cout <<"Input a key for next phase:\n";
//cin.get();
//highfink hf2;
//hf2.SetAll();
//cout<<"Using abstr_emp * pointer:\n";
//abstr_emp *tri[4] = {&em, &fi, &hf, &hf2};
//for(int i = 0; i < 4; i++)
//	tri[i]->ShowAll();
return 0;
}
