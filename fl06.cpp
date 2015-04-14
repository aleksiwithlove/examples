////////////////////////////////////////////////////////////////////////////
// fl06.cpp
// тяжелые вычисления

#include <cmath>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>

class M_Win:public Fl_Window{
 public:
    M_Win(int w, int h, const char *name="M_Win"):Fl_Window(w, h, name){
       phi=0.0;
       resizable(this);
       show();
    }
    double phi;
    void draw(){
       Fl_Window::draw();
       fl_color(0, 0, 0);
       fl_line_style(0, 5); 
       fl_line(w()/2, h()/2, w()/2+int(100*cos(phi)), h()/2-int(100*sin(phi)));
    }
};

void callback(void* winp) {
   M_Win * win=(M_Win *)winp;
   // часть необходимых вычислений
   win->phi+=0.001;
   win->redraw();
}

int main(){
   M_Win win(300, 200, "TEST");
   Fl::add_idle(callback, &win);   // запускать в промежутке между обработкой событий
   //Fl::remove_idle(callback, &win);
   return Fl::run();
}

// end of file fl04.cpp
////////////////////////////////////////////////////////////////////////////
