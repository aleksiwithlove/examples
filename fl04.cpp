////////////////////////////////////////////////////////////////////////////
// fl04.cpp
// работа с таймером 
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>

class M_Win:public Fl_Window{
 public:
    M_Win(int w, int h, const char *name="M_Win"):Fl_Window(w, h, name){
       xx=0;
       show();
    }
    int xx;
    void draw(){
       Fl_Window::draw();
       fl_color(0, 0, 0);
       fl_rectf(xx, 50, 20, 20);
    }
};

void callback(void* winp) {
   M_Win * win=(M_Win *)winp;
   win->xx++;
   win->redraw();
   Fl::repeat_timeout(0.2,callback, win);
}

int main(){
   M_Win win(300, 200, "TEST");
   Fl::add_timeout(1.0, callback, &win); //создаем таймер
   return Fl::run();
}

// end of file fl04.cpp
////////////////////////////////////////////////////////////////////////////
