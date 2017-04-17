#include "users.cpp"
using namespace std;



class gui
{
	private:
		Project_Manager pm;
        //vector<Sales_Associate> sas;                  
        //vector<Customer> cms;	

		int x;
		int y;
		int input;
		Fl_Window* win;
	public:
		gui(int x, int y);
		static void add_head(Fl_Widget* w, void* p);
		void real_add_head();
		static void add_arm(Fl_Widget* w, void* p);
		void real_add_arm();
		static void add_torso(Fl_Widget* w, void* p);
		void real_add_torso();
		static void add_battery(Fl_Widget* w, void* p);
		void real_add_battery();
		static void add_locomotor(Fl_Widget* w, void* p);
		void real_add_locomotor();
		static void create_robot(Fl_Widget* w, void* p);
		void real_create_robot();
		static void view_robots(Fl_Widget* w, void* p);
		void real_view_robots();
		static void exit(Fl_Widget* w, void* p);
		void pm_win();
};

gui::gui(int x, int y)
{
	this->x = x;
	this->y = y;
	pm_win();
}

void gui::add_head(Fl_Widget* w, void* p)
{
	((gui*)p)->real_add_head();
}

void gui::real_add_head()
{
	win->hide();
	pm.add_part(1);
	pm_win();
}

void gui::add_arm(Fl_Widget* w, void* p)
{
	((gui*)p)->real_add_arm();
}

void gui::real_add_arm()
{
	win->hide();
	pm.add_part(2);
	pm_win();
}

void gui::add_torso(Fl_Widget* w, void* p)
{
	((gui*)p)->real_add_torso();
}

void gui::real_add_torso()
{
	win->hide();
	pm.add_part(3);
	pm_win();
}

void gui::add_locomotor(Fl_Widget* w, void* p)
{
	((gui*)p)->real_add_locomotor();
}

void gui::real_add_locomotor()
{
	win->hide();
	pm.add_part(4);
	pm_win();
}

void gui::add_battery(Fl_Widget* w, void* p)
{
	((gui*)p)->real_add_battery();
}

void gui::real_add_battery()
{
	win->hide();
	pm.add_part(5);
	pm_win();
}

void gui::create_robot(Fl_Widget* w, void* p)
{
	((gui*)p)->real_create_robot();
}

void gui::real_create_robot()
{
	win->hide();
	pm.create_robot();
	pm_win();
}

void gui::view_robots(Fl_Widget* w, void* p)
{
	((gui*)p)->real_view_robots();
}

void gui::real_view_robots()
{
	win->hide();
	string view = pm.list_robots();
	fl_message(view.c_str());
	pm_win();
}

void gui::exit(Fl_Widget* w, void* p)
{
	std::exit(0);
}

void gui::pm_win()
{
	win->begin();
	win = new Fl_Window(x,y,"Project Manager Screen");
	Fl_Button* head = new Fl_Button(x/3.5,y/9,125,25,"Add Head");
	Fl_Button* arm = new Fl_Button(x/3.5,y/5,125,25,"Add Arm");
	Fl_Button* torso = new Fl_Button(x/3.5,y/3.4,125,25,"Add Torso");
	Fl_Button* battery = new Fl_Button(x/3.5,y/2.58,125,25,"Add Locomotor");
	Fl_Button* locomotor = new Fl_Button(x/3.5,y/2.05,125,25,"Add Battery");
	Fl_Button* create = new Fl_Button(x/3.5,y/1.71,125,25,"Create Robot");
	Fl_Button* view = new Fl_Button(x/3.5,y/1.47,125,25,"View Robots");
	Fl_Button* log_off = new Fl_Button(x/3.5,y/1.2,125,25,"Log off");
	head->callback(add_head,this);
	arm->callback(add_arm,this);
	torso->callback(add_torso,this);
	battery->callback(add_battery,this);
	locomotor->callback(add_locomotor,this);
	create->callback(create_robot,this);
	view->callback(view_robots,this);
	log_off->callback(exit,this);
	win->end();
	win->show();
}

int main()
{
	gui test(300,400);
	return Fl::run();
}
