// strtype4.cpp -- line input
#include <iostream>
#include <string>               // make string class available
#include <cstring>              // C-style string library
int main()
{
    using namespace std;
    char charr3[20]; 
    string str;

    cout << "Length of string in charr before input: " 
         << strlen(charr3) << endl;
    cout << "Length of string in str before input: "
         << str.size() << endl;
//	cout << charr3 <<endl;
    cout << "Enter a line of text:\n";
    cin.getline(charr3, 20);     // indicate maximum length
    cout << "You entered: " << charr3 << endl;
    cout << "Enter another line of text:\n";
    getline(cin, str);          // cin now an argument; no length specifier
    cout << "You entered: " << str << endl;
    cout << "Length of string in charr after input: " 
         << strlen(charr3) << endl;
    cout << "Length of string in str after input: "
         << str.size() << endl;
     cin.get();

    return 0; 
}
