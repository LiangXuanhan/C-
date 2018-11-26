// stonewt.h -- definition for the Stonewt class!
#pragma once
#ifndef WORK11_6_H
#define WORK11_6_H
class Stonewt
{
private:
    enum {Lbs_per_stn = 14};      // pounds per stone
    int stone;                    // whole stones
    double pds_left;              // fractional pounds
    double pounds;                // entire weight in pounds
public:
    Stonewt(double lbs);          // constructor for double pounds
    Stonewt(int stn, double lbs); // constructor for stone, lbs
    Stonewt();                    // default constructor
    ~Stonewt();
    double show_lbs() const;        // show weight in pounds format
    void show_stn() const;        // show weight in stone format
	bool operator>(const Stonewt & sw) const;
	bool operator>=(const Stonewt & sw) const;
	bool operator<(const Stonewt & sw) const;
	bool operator<=(const Stonewt & sw) const;
	bool operator=(const Stonewt & sw) const;
	bool operator!=(const Stonewt & sw) const;
	void rtnew(double db);
};
#endif
