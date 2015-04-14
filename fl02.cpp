////////////////////////////////////////////////////////////////////////////
// fl02.cpp
// Окошко с кнопкой и обработчиком событий
//
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <stdlib.h>

void fbt(Fl_Widget *w, void *) {
   if (w->color()!=FL_RED) {
      w->color(FL_RED); 
      return ;	
   }
   if (w->color()!=FL_GREEN) {
      w->color(FL_GREEN);
      return ;
   }
}

int main(){
   Fl_Window win(300, 200, "TEST");      // создаем окно
   Fl_Button bt(10, 10, 80, 30, "&bt");  // добавляем кнопку
   bt.callback(fbt,0);                   // подключаем обработчик события нажатия на кнопку
   win.show();                           // отображаем окно
   return Fl::run();                     // запускаем обработчик событий
}
// end of file fl02.cpp
////////////////////////////////////////////////////////////////////////////
