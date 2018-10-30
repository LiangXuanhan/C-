// recur.cpp -- using recursion
#include <iostream>
void countdown(int n);

int main()
{
	int input;
	std::cin >> input;
    countdown(input);           // call the recursive function
    std::cin.get();
	std::cin.get();
    return 0;
}

void countdown(int n)
{
    using namespace std;
    cout << "Counting down ... " << n << "n at " << &n << endl;
    if (n > 0)
        countdown(n-1);     // function calls itself
    cout << n << ": Kaboom! " << "n at " << &n <<endl;
}
