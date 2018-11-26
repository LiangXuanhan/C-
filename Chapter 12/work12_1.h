#pragma once
#ifndef WORK12_1_H
#define WORK12_1_H
class Cow
{
private:
	char name[20];
	char *hobby;
	int len;
	double weight;
	static int cnt;
public:
	
	Cow();
	Cow(const char *nm, const char *ho, double wt);
	Cow(const Cow & c);
	~Cow();
	Cow & operator=(const Cow & c);
	void ShowCow() const;
	void ShowCnt() const;
};
#endif