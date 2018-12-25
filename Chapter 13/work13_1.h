/*
 * work13_1.h
 *
 *  Created on: 2018Äê11ÔÂ29ÈÕ
 *      Author: Administrator
 */

#ifndef WORK13_1_H_
#define WORK13_1_H_
class Cd{
private:
	char *performers;
	char *label;
	int selections;
	double playtime;
public:
	Cd(char * s1, char * s2, int n, double x);
	Cd(const Cd & d);
	Cd();
	virtual ~Cd();
	virtual void Report() const;
	Cd & operator=(const Cd & d);
};

class Classic : public Cd{
private:
	char  * names;
public:
	Classic(char * nms, char * s1, char * s2, int n, double x);
	Classic(char * nms, const Cd & d);
	Classic();
	virtual ~Classic();
	virtual void Report() const;
	virtual Classic & operator=(const Classic & d);
};



#endif /* WORK13_1_H_ */
