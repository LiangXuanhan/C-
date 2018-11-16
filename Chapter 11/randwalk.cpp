// randwalk.cpp -- using the Vector class!
// compile with the vect.cpp file
#include <iostream>
#include <fstream>
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype
#include "vect.h"
int main()
{
	
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));     // seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
	ofstream f1("example.txt");
	if(!f1.is_open())
		{   cout << "Wrong File!\n";
			return 1;}
    cout << "Enter target distance (q to quit): ";
	int first = 0;
    while (cin >>target)
    {
		if(first == 0)
		{
		f1 << "Target Distance: " << target <<", ";
		first++;
		}
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
		f1 << "Step Size: " << dstep << endl;
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
			f1 << steps << " (x, y) = (" << result.xval() << ", " << result.yval() << ")" << endl;
            steps++;
			
        }
        cout << "After " << steps << " steps, the subject "
            "has the following location:\n";
		f1 << "After " << steps << " steps, the subject "
            "has the following location:\n";
        cout << result << endl;
		f1 << result << endl;
        result.polar_mode();
        cout << " or\n" << result << endl;
        cout << "Average outward distance per step = "
            << result.magval()/steps << endl;
		f1 << " or\n" << result << endl;
        f1 << "Average outward distance per step = "
            << result.magval()/steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
		first = 0;
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
/* keep window open
    cin.clear();
    while (cin.get() != '\n')
        continue;
    cin.get();
*/
    return 0; 
}
