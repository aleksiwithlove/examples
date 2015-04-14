////////////////////////////////////////////////////////////////////////////
// fl03.cpp
// M_Win окошко с переопределенным методом draw
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>

const char * name="Hey, baby!";

class M_Win:public Fl_Window{
 public:
    M_Win(int w, int h, const char *name="M_Win"): Fl_Window(w, h, name){
       show();
    }
    void draw(){
      Fl_Window::draw();
       fl_color(150, 300, 0);
       fl_point(100, 100);
       fl_line(-50, 0, w()-50, h());       
	   fl_line(50, 0, w()+50, 680); 
       fl_rectf(100, 30, 20, 20);
       fl_color(FL_BLUE);
       fl_line_style(FL_DOT , 3);
       fl_circle(340, 500, 80);
	   fl_circle(210, 600, 80);
       fl_font(FL_ITALIC,50);

       fl_draw(name, 150, 100); 
	fl_polygon(50, 50, 180, 150, 300, 200, 80,100); 

    }

};

int main(){
   M_Win win(400, 800, "TEST");
   return Fl::run();
}

// end of file fl03.cpp
////////////////////////////////////////////////////////////////////////////
