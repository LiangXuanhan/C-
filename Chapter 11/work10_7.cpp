#include<iostream>
#include "work10_7.h"

using namespace std;
namespace COMPLEX{

Complex::Complex()
{
	real = 0;
	imag = 0;
}
Complex::Complex(double x, double y)
{
real = x;
imag = y;
}
Complex::~Complex()
{
cout << "Disapear!\n";
}

Complex Complex::operator+(const Complex & c) const
{
	Complex sum;
	sum.real = real + c.real;
	sum.imag = imag + c.imag;
	return sum;
}

Complex Complex::operator-(const Complex & c) const
{
Complex result;
result.real = real - c.real;
result.imag = imag - c.imag;
return result;
}

Complex Complex::operator*(const Complex & c) const
{
Complex result;
result.real = real * c.real - imag * c.imag;
result.imag = real * c.imag + imag * c.real;
return result;
}

Complex Complex::operator*(const double x) const
{
Complex result;
result.real = real * x;
result.imag = imag * x;
return result;
}

Complex Complex::operator~() const
{
Complex result;
result.real = real;
result.imag = -imag;
return result;
}

std::ostream & operator<<(std::ostream & os, const Complex & c)
{
	os << "("<< c.real << ", " << c.imag << ")";
return os;
}

std::istream & operator>>(std::istream & is, Complex & c)
{
	is >> c.real >>c.imag;
	return is;
}
}