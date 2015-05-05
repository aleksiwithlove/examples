#include<iostream>
#include<cmath>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>
#include <cmath>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include "string.h"
#include "stdlib.h"
#include <cstring>
#include <sstream>
#include <string>
#define dt 0.01
using namespace std;
double alfa = 0.1;
double omega = 1;
double length=200;
double E =0;

const char* ToString(double val)
{
	stringstream stream;
	stream << val;
	
	return stream.str().c_str();
	
}
class M_Win:public Fl_Window{
 public:
 
	//input alfa, omega	
	Fl_Input *inp1;
	Fl_Input *inp2;
	Fl_Input *inp3;
	Fl_Input *inp4;
	Fl_Button *bt;
	Fl_Button *b;
    M_Win(int w, int h): Fl_Window(w, h)
	{
		resizable(this);
	
		inp1 = new Fl_Input(40,40,60,60); //alfa
		inp2 = new Fl_Input(140,40,60,60);//omega
		inp3 = new Fl_Input(240,40,60,60);//length
		inp4 = new Fl_Input(340,40,60,60);//length
		bt = new Fl_Button(40, 100, 60, 60, "START");
		b = new Fl_Button(120, 100, 60, 60, "STOP");
		inp1->value(ToString(alfa));
		inp2->value(ToString(omega));
		inp3->value(ToString(length));
		inp4->value(ToString(E));
		
		show();
    } 
 };

class M_Win1:public Fl_Window{
 public:

    M_Win1(int w, int h): Fl_Window(w, h)
	{
		
		show();
    } 

    void draw()
	{
		Fl_Window::draw();
		fl_color(250, 18, 50);
		fl_line(w()/2, h()/2, w()/2 + length*sin(alfa), h()/2 + length*(cos(alfa)));
		
	}
};


M_Win* u1;
M_Win1* u2;




double ToDbl(const char* val)
{
	string str(val);
	stringstream stream(str);
	double z;
	stream >> z;
	return z;

}
int a = 0;
void callback_t(void*p)
{
	alfa+=omega*dt;
	omega += -sin(alfa)*dt;
	u2->redraw();
	u1->redraw();
	if (a%2 !=0)
	{
	Fl::repeat_timeout(0.01,callback_t, u2);
	}
	E=omega*omega/2 +10*(1-cos(alfa));
	
	u1->inp1->value(ToString(alfa));
	u1->inp2->value(ToString(omega));
	u1->inp4->value(ToString(E));

}

void callback(Fl_Widget* winp, void*p)
{
	a+=1;
	alfa = ToDbl(u1->inp1->value());
	omega = ToDbl(u1->inp2->value());
	length = ToDbl(u1->inp3->value()); 
	Fl::add_timeout(1.0, callback_t, &u2);
}


void callbackSTP(Fl_Widget* winp,void*p)
{
	a+=1;
}


int main(){
	u1 = new M_Win(400,800);
	u2 = new M_Win1(400,800);
	u1->bt->callback(callback, 0);
	u1->b->callback(callbackSTP,0);
	return Fl::run();
	
}
