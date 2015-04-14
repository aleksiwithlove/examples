#include<iostream>
#include<cmath>
#include<string>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>
#include <cmath>


using namespace std;

void s(double x1, double y1, double x2, double y2, double x3, double y3, int N){

	s(x1, y1, (x1 + x3) / 2, (y1 + y3) / 2, (x1 + x2) / 2, (y1 + y2) / 2, N - 1);
	s(x3, y3, (x1 + x3) / 2, (y1 + y3) / 2, (x3 + x2) / 2, (y3 + y2) / 2, N - 1);
	s(x2, y2, (x2 + x3) / 2, (y2 + y3) / 2, (x1 + x2) / 2, (y1 + y2) / 2, N - 1);
 return ;
} 

class M_Win:public Fl_Window{
 public:
    M_Win(int w, int h): Fl_Window(w, h){
       show();
    }

    void draw()
	{
		Fl_Window::draw();
		fl_color(100, 100, 100);
        //fl_line(0, 0, w(), h());  
		s(0,h(),w()/2,0,w(),h(),5);
	}
};


int main(){
	
	M_Win win(400, 800);
   return Fl::run();
}
