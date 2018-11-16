#pragma once
#ifndef WORK10_7_H
#define WORK10_7_H
namespace COMPLEX
{
class Complex
{
private:
	double real;
	double imag;
public:
	Complex();
	Complex(double x, double y);
	~Complex();
	double get_real(){return real;} 
	double get_imag(){return imag;} 
	Complex operator+(const Complex & c) const;
	Complex operator-(const Complex & c) const;
	Complex operator*(const Complex & c) const;
	Complex operator*(const double x) const;
	Complex operator~() const;
	friend std::ostream & operator<<(std::ostream & os, const Complex & c);
	friend std::istream & operator>>(std::istream & is, Complex & c);
};
}
#endif