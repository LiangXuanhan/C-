// stock20.h -- augmented version!
#ifndef WORK13_3_H
#define WORK13_3_H
#include<iostream>
#include <string>

class Stock
{
private:
    char * company;
	int len;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
    Stock();        // default constructor
    Stock(char * co, long n = 0, double pr = 0.0);
    ~Stock();       // do-nothing destructor
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show()const;
	friend ostream & operator<<(ostream & os, const Stock & s);
    const Stock & topval(const Stock & s) const;
};

#endif
