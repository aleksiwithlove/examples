////////////////////////////////////////////////////////////////////////////
// fl03.cpp
// M_Win окошко с переопределенным методом draw
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>

const char * name="text";

class M_Win:public Fl_Window{
 public:
    M_Win(int w, int h, const char *name="M_Win"): Fl_Window(w, h, name){
       show();
    }
    void draw(){
       Fl_Window::draw();
       fl_color(100, 100, 100);
       fl_point(100, 100);
       fl_line(0, 0, w(), h());       
       fl_rectf(100, 30, 20, 20);
       fl_color(FL_RED);
       fl_line_style(FL_SOLID, 3);
       fl_circle(100, 100, 10);
       fl_font(FL_COURIER,18);
       fl_draw(name, 50, 30); 
    }

};

int main(){
   M_Win win(300, 200, "TEST");
   return Fl::run();
}

// end of file fl03.cpp
////////////////////////////////////////////////////////////////////////////
