////////////////////////////////////////////////////////////////////////////
// fl01.cpp
// Простейшее приложение с использованием FLTK
#include <FL/Fl.H>                          // базовые части fltk приложения
#include <FL/Fl_Window.H>                   // класс с простейшим окошком

int main(){
	for (int i = 0; i<3;i++)
	{
		Fl_Window* lal = new Fl_Window(i*100, i*150,300, 200, "Hello, fltk");
		lal->show();   
		
	}
Fl::run();
    return 0;                
}

