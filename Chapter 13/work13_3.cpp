/*
 * work13_3.cpp
 *
 *  Created on: 2018Äê11ÔÂ29ÈÕ
 *      Author: Administrator
 */
#include "work13_3.h"
#include<iostream>
#include <cstring>
using namespace std;

// baseDMA methods
DMA::DMA(const char * l, int r)
{
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

DMA::DMA(const DMA & d)
{
    label = new char[std::strlen(d.label) + 1];
    std::strcpy(label, d.label);
    rating = d.rating;
}

DMA::~DMA()
{
    delete [] label;
    cout << "DMA Destroyed!" << endl;
}

DMA & DMA::operator=(const DMA & d)
{
    if (this == &d)
        return *this;
    delete [] label;
    label = new char[std::strlen(d.label) + 1];
    std::strcpy(label, d.label);
    rating = d.rating;
    return *this;
}
std::ostream & operator<<(std::ostream & os, const DMA & rs)
{
    os << "Label: " << rs.label << std::endl;
    os << "Rating: " << rs.rating << std::endl;
    return os;
}

baseDMA::baseDMA(const char * l , int r , int p) : DMA(l, r)
{
	plus = p;

}

baseDMA::baseDMA(const baseDMA & rs): DMA(rs){
	plus = rs.plus;
}
baseDMA::~baseDMA(){
	cout << "baseDMA destroyed!" << endl;
}


std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
    os << (DMA &) rs;
    os << "Plus: " << rs.plus << std::endl;
    return os;
}
void baseDMA::Show(){
	cout << plus;
}
// lacksDMA methods
lacksDMA::lacksDMA(const char * c, const char * l, int r)
    : DMA(l, r)
{
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const DMA & rs)
    : DMA(rs)
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}
void lacksDMA::Show(){
	cout << color;
}
std::ostream & operator<<(std::ostream & os, const lacksDMA & ls)
{
    os << (const DMA &) ls;
    os << "Color: " << ls.color << std::endl;
    return os;
}

// hasDMA methods
hasDMA::hasDMA(const char * s, const char * l, int r)
         : DMA(l, r)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const DMA & rs)
         : DMA(rs)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs)
         : DMA(hs)  // invoke base class copy constructor
{
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if (this == &hs)
        return *this;
    DMA::operator=(hs);  // copy base portion
    delete [] style;         // prepare for new style
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}

std::ostream & operator<<(std::ostream & os, const hasDMA & hs)
{
    os << (const DMA &) hs;
    os << "Style: " << hs.style << std::endl;
    return os;
}
void hasDMA::Show(){
	cout << style;
}



