#include <iostream>
#include <string>
#include <sstream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <Fl/Fl_Text_Display.H>
#include <Fl/Fl_Input.H>
#include <Fl/Fl_Button.H>
using namespace std;

class gui
{
	private:
		int x;
		int y;
		int input;
		Fl_Window* win;
	public:
		gui(int x, int y);
		static void add_head(Fl_Widget* w, void* p, void* i);
		void real_add_head();
		void pm_win();
};

gui::gui(int x, int y)
{
	this->x = x;
	this->y = y;
	pm_win();
}

void gui::add_head(Fl_Widget* w, void* p, void* i)
{
	((gui*)p)->real_add_head();
}

void gui::real_add_head()
{
	//pm.add_part(1);
}

void gui::pm_win()
{
	win->begin();
	win = new Fl_Window(x,y,"Project Manager Screen");
	Fl_Button* head = new Fl_Button(x/3.5,y/9,125,25,"Add Head");
	head->callback(add_head,this,1);
	Fl_Button* arm = new Fl_Button(x/3.5,y/5,125,25,"Add Arm");
	Fl_Button* torso = new Fl_Button(x/3.5,y/3.4,125,25,"Add Torso");
	Fl_Button* battery = new Fl_Button(x/3.5,y/2.58,125,25,"Add Locomotor");
	Fl_Button* locomotor = new Fl_Button(x/3.5,y/2.05,125,25,"Add Battery");
	Fl_Button* create = new Fl_Button(x/3.5,y/1.71,125,25,"Create Robot");
	Fl_Button* view = new Fl_Button(x/3.5,y/1.47,125,25,"View Robots");
	Fl_Button* log_off = new Fl_Button(x/3.5,y/1.2,125,25,"Log off");
	win->end();
	win->show();
}

int main()
{
	gui test(300,400);
	return Fl::run();
}
