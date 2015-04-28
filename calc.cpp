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
#include "stdlib.h"
#include <cstring>
#include <sstream>
#include <string>
using namespace std;


class M_Win:public Fl_Window{
 public:
 
	
	
	Fl_Input *inp1;
	Fl_Input *inp2;
	Fl_Input *inp3;
	
	Fl_Button *bt;
	
    M_Win(int w, int h): Fl_Window(w, h)
	{
		resizable(this);
	
		inp1 = new Fl_Input(40,40,60,60);
		inp2 = new Fl_Input(140,40,60,60);
		inp3 = new Fl_Input(240,40,60,60);

		bt = new Fl_Button(40, 100, 30, 30, "+");
		show();
    } 

    void draw()
	{
		Fl_Window::draw();
		fl_color(250, 18, 50);
		
		
	}
};
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

void my_callback(Fl_Widget* winp, void*p)
{
	M_Win * win=(M_Win *)p;
	int x  = ToInt(win->inp1->value());
	int y = ToInt(win->inp2->value());
	//int z = x+y;
	
	
   	win->inp3->value(ToString(x+y));
	
}

int main(){
	
	M_Win win(400, 800);
	win.bt ->callback(my_callback,&win);
	return Fl::run();
}
