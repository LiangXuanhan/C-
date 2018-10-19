#include <iostream>
#include <string>
using namespace std;
char * GetStr();
int main ()
{
	
	char temp[100];
    cout << "What is your first name?\n";
	char * fnp = GetStr();
	cout << "What is your last name?\n";
	char * lnp = GetStr();
	cout << "What letter grade do you deserve?\n";
	char grade;
	cin >> grade;
	int a;
	a = (int) grade + 1;
	grade = (char) a;
	
	cout << "What is your age?\n";
	cin >> a;

	cout << "Name: "<< fnp << " " << lnp << "."<< endl << "Grade: " << grade <<".\nAge: " << a << endl;
	cin.get();
	cin.get();
	return 0;
}
char * GetStr()
{
    char temp[100];
    cin.get(temp,100);
	char * strp = new char[strlen(temp) + 1];
	strcpy(strp, temp);
	cin.ignore(100, '\n');
	return strp;
}