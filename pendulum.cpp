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
#define dt 0,01
using namespace std;
double alfa;
double omega;
double length;
double t = 0;
double xx;
double yy;

class M_Win:public Fl_Window{
 public:
 
	//input alfa, omega	
	Fl_Input *inp1;
	Fl_Input *inp2;
	Fl_Input *inp3;
	Fl_Button *bt;
	
    M_Win(int w, int h): Fl_Window(w, h)
	{
		resizable(this);
	
		inp1 = new Fl_Input(40,40,60,60); //alfa
		inp2 = new Fl_Input(140,40,60,60);//omega
		inp3 = new Fl_Input(240,40,60,60);//length
		
		bt = new Fl_Button(40, 100, 30, 30, "START");
		show();
    } 
 };

class M_Win1:public Fl_Window{
 public:

    M_Win1(int w, int h): Fl_Window(w, h)
	{
		xx = w/2;
		yy = (h/2) - length;
		show();
    } 

    void draw()
	{
		Fl_Window::draw();
		fl_color(250, 18, 50);
		fl_line_style(0, 5); 
		fl_line(w()/2, h()/2, xx,yy);
		
	}
};
M_Win* u1;
M_Win1* u2;
const char* ToString(int val)
{
	stringstream stream;
	stream << val;
	
	return stream.str().c_str();
	
}

int ToInt(const char* val)
{
	string str(val);
	stringstream stream(str);
	int z;
	stream >> z;
	return z;

}
void callback0(Fl_Widget* winp, void*p)
{
	M_Win * win=(M_Win *)winp;
	alfa = ToInt(win->inp1->value());
	omega = ToInt(win->inp2->value());
	length = ToInt(win->inp3->value()); 
	t+=dt;
	alfa+=omega*t; 
	xx+=length*sin(alfa);
	yy+=length*(1-cos(alfa));
	Fl::repeat_timeout(0.01,callback0, win);

}
void callback1(Fl_Widget* winp, void*p)
{
	M_Win1 * win=(M_Win1 *)winp;
	u2->redraw();
	Fl::repeat_timeout(0.01,callback1, win);
	
}

int main(){
	u1 = new M_Win(400,800);
	u2 = new M_Win1(400,800);
	
	Fl::add_idle(callback0, &u1);   
	Fl::add_idle(callback1, &u2);   

	u1->bt ->callback(callback0,&u1);
	
	return Fl::run();
	
}
