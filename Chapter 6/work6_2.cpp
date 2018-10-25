#include<iostream>
using namespace std;
double calculate(double x, double y, double (*func)(double z, double w))
{
return func(x, y);
}
double add_w(double x, double y)
{
return x + y;
}
double minus_w(double x, double y)
{
if(x*x > y*y)
	return x - y;
else 
	return y - x;
}
int main()
{ double ipt1, ipt2, result[3];
double (*pf[3]) (double, double) = {add_w, minus_w,add_w};
cout << "Input three pair of numbers.\n";
for(int i = 0; i < 3; i++)
{
cin >> ipt1 >>ipt2;
result[i] = calculate(ipt1, ipt2, pf[i]);

}
cout <<"Result is: " << result[0] <<endl << result[1] << endl << result[2] <<endl;
	cin.ignore(1);	
	cin.get();
return 0;
}