/*
 * work14_3.cpp
 *
 *  Created on: 2018Äê12ÔÂ4ÈÕ
 *      Author: Administrator
 */

#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
using namespace std;
 class Person
 {
 private:
	 string fn;
	 string ln;
 public:

	 Person(){fn = "John"; ln = "Doe";}
	 Person(const char * fs, const char * ss){fn = fs; ln = ss;}
	 Person(const Person & p){fn = p.fn, ln = p.ln;}
	 void Display(){cout << "Name: " << fn << " "<< ln << endl;}
	 void Show(){Display();}
	 ~Person(){}
 };

 class Gunslinger : virtual public Person
 {
 private:
	 double time;
	 int scar;
 public:
	 Gunslinger(): Person(){time = 1000.0; scar = 0;}
	 Gunslinger(const char *fn, const char * ln, double t, int s)
	 : Person(fn, ln){time = t; scar = s;}
	 void Display(){cout << "Time: " << time << " Scar: " << scar << endl;}
	 void Show(){Person::Display(); Display();}
	 double Draw(){return time;}
	 ~Gunslinger(){}
 };
 class Card
 		 {
 public:
 			 int type;
 			 int num;
 		 };
 class PokerPlayer : virtual public Person
 {
 private:
	 Card dw;
 public:
	 PokerPlayer(): Person(){}
	 PokerPlayer(const char *fn, const char * ln) : Person(fn, ln){}
	 void Show(){Person::Show();}
	 Card & Draw(){srand((unsigned)time(NULL)); dw.num = (rand() % (12))+ 1; dw.type = (rand() % (4)) + 1; return dw;}
	 ~PokerPlayer(){}
 };

 class BadDude : public Gunslinger, public PokerPlayer
 {
 private:
 public:
	 BadDude(): Person(), Gunslinger(){}
	 BadDude(const char *fn, const char * ln, double t, int s) : Person(fn, ln), Gunslinger(fn, ln, t, s){}
	double Gdraw(){return Gunslinger::Draw();}
	Card & Cdraw(){return PokerPlayer::Draw();}
	void Show(){Person::Display(); Gunslinger::Display();}
	 ~BadDude(){}
 };

 int main()
 {
	 Person start;
	 start.Show();
	 Person first("xh", "L");
	 first.Show();
	 Person second(first);
	 second.Show();
	 Gunslinger third;
	 third.Show();
	 Gunslinger fourth("xh", "L", 88, 8);
	 fourth.Show();
	 cout << fourth.Draw() << endl;
	 PokerPlayer fifth;
	 fifth.Show();
	 Card c1 = fifth.Draw();
	 cout << c1.num <<endl << c1.type << endl;
	 PokerPlayer sixth("xh", "L");
	 sixth.Show();
	 c1 = sixth.Draw();
		 cout << c1.num <<endl << c1.type << endl;
		 BadDude seventh;
		 seventh.Show();
		 cout << seventh.Gdraw() << endl;
		 c1 = seventh.Cdraw();
		 cout << c1.num <<endl << c1.type << endl;
	 return 0;
 }


