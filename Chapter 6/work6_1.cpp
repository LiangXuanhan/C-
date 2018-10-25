#include <iostream>
#include <cctype>
using namespace std;
int main()
{
char ch;
while(cin.get(ch))
{
if (islower(ch))
	ch = toupper(ch);
else if (isupper(ch))
ch = tolower(ch);
else if (isdigit(ch))
	continue;
else if (strcmp(&ch, "@"))
	break;
cout << ch;
}
cin.ignore(1000);
cin.get();
return 0;

}