////////////////////////////////////////////////////////////////////////////
// fl05.cpp
// Обработка события нажатие кнопки
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/fl_draw.H>

class M_Win:public Fl_Window{
 public:
    int x, y, dx;
    M_Win(int w, int h, const char *name="M_Win"): Fl_Window(w, h, name){
       show();
       x=y=0;
       dx=10;
    }
    void draw(){
       Fl_Window::draw();
       fl_color(100, 100, 100);
       fl_rectf(x,y, 20, 20);
    }
    int handle(int event){
	if (event==FL_KEYDOWN){ // FL_KEYUP
            switch (Fl::event_key()){
                case FL_Up:    y-=dx; redraw(); return 1;
		case FL_Down:  y+=dx; redraw(); return 1;
		case FL_Right: x+=dx; redraw(); return 1;
		case FL_Left:  x-=dx; redraw(); return 1;

                default : Fl_Window::handle(event);
            }
        }
        return Fl_Window::handle(event);
    }
};

int main(){
   M_Win win(300, 200, "TEST");
   return Fl::run();
}

// end of file fl03.cpp
////////////////////////////////////////////////////////////////////////////
