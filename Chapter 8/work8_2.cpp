#include<iostream>
#include<string>
using namespace std;
struct CandyBar{
    string name;
	double weight;
	int Kal;
};
void Input(CandyBar &, char *, double, int);
	void Show(const CandyBar &);
int main(){
	CandyBar ori;
	CandyBar & ref = ori;
	Input(ref, "Mill Munch", 2.85, 350);
	Show(ref);
	
	cin.get();
return 0;
}
void Input(CandyBar & cb, char * fn, double we, int kal)
{
	cb.name = fn;
	cb.weight = we;
	cb.Kal = kal;
}
	void Show(const CandyBar & cb)
	{
	cout << "Name: " << cb.name << endl;
	cout << "Weight: " << cb.weight <<endl;
	cout << "KAL: " << cb.Kal << endl;
	}