/*
 * work13_3.h
 *
 *  Created on: 2018Äê11ÔÂ29ÈÕ
 *      Author: Administrator
 */

#ifndef WORK13_3_H_
#define WORK13_3_H_

#include <iostream>
#include <cstring>
class DMA{
private:
	char * label;
	int rating;
public:
	DMA(const char * l = "null", int r = 0);
	DMA(const DMA & d);
	virtual ~DMA();
	DMA & operator=(const DMA & d);
	virtual void Show() = 0;
	friend std::ostream & operator<<(std::ostream & os,
	                                     const DMA & rs);
};
//  Base Class Using DMA
class baseDMA : public DMA
{
private:
   int plus;

public:
    baseDMA(const char * l = "null", int r = 0, int p = 0);
    baseDMA(const baseDMA & rs);
     ~baseDMA();
    baseDMA & operator=(const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os,
                                     const baseDMA & rs);
    void Show();
};

// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA :public DMA
{
private:
    enum { COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char * c = "blank", const char * l = "null",
              int r = 0);
    lacksDMA(const char * c, const DMA & rs);
    friend std::ostream & operator<<(std::ostream & os,
                                     const lacksDMA & rs);
    void Show();
};

// derived class with DMA
class hasDMA :public DMA
{
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char * l = "null",
              int r = 0);
    hasDMA(const char * s, const DMA & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & rs);
    friend std::ostream & operator<<(std::ostream & os,
                                     const hasDMA & rs);
    void Show();
};




#endif /* WORK13_3_H_ */
