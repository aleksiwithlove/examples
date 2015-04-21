#include<iostream>
#include<cmath>
#include<string>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>
#include <cmath>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include "string.h"

using namespace std;

void s(double x1, double y1, double x2, double y2, double x3, double y3, int N){

	if (N==1) 
	{
		fl_polygon((int)x1,(int)y1, (int)x2, (int)y2, (int)x3, (int)y3);
	
		return;
		
	}
if(N>1)
{
	s(x1, y1, (x1 + x3) / 2, (y1 + y3) / 2, (x1 + x2) / 2, (y1 + y2) / 2, N - 1);
	s(x3, y3, (x1 + x3) / 2, (y1 + y3) / 2, (x3 + x2) / 2, (y3 + y2) / 2, N - 1);
	s(x2, y2, (x2 + x3) / 2, (y2 + y3) / 2, (x1 + x2) / 2, (y1 + y2) / 2, N - 1);
 return;
}
} 

class M_Win:public Fl_Window{
 public:
 
	int N;
	
	Fl_Input *inp;
	Fl_Button *bt;
	
    M_Win(int w, int h): Fl_Window(w, h)
	{
		resizable(this);
		N = 5;
		inp = new Fl_Input(40,40,60,60, "What?");
		bt = new Fl_Button(40, 100, 30, 30, "OK");
		inp->value("5");
		show();
    } 

    void draw()
	{
		Fl_Window::draw();
		fl_color(250, 18, 50);
		s(0,h(),w()/2,0,w(),h(),N);
		
	}
};

void my_callback(Fl_Widget* winp, void*p)
{
	M_Win * win=(M_Win *)p;
	
		
	win->N = atoi(win->inp->value());

	win -> redraw();
}

int main(){
	
	M_Win win(400, 800);
	win.bt ->callback(my_callback,&win);
	return Fl::run();
}
