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
		string filename = "data.txt";
		Fl_Input* username;
		Fl_Input* password;
		Fl_Input* name;
		Fl_Input* phone_number;
		Fl_Input* email_address;
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
		static void return_startup(Fl_Widget* w, void* p);
		void real_return_startup();
		static void check_log(Fl_Widget* w, void* p);
		void real_check_log();
		static void createPM(Fl_Widget* w, void* p);
		void real_createPM();
		static void create_PM(Fl_Widget* w, void* p);
		void real_create_PM();
		static void createSAS(Fl_Widget* w, void* p);
		void real_createSAS();
		static void createCM(Fl_Widget* w, void* p);
		void real_createCM();
		static void exit(Fl_Widget* w, void* p);
		void real_exit();
		void startup();
		void pm_win();
		void save();
		void load();
};

gui::gui(int x, int y)
{
	this->x = x;
	this->y = y;
	load();
	startup();
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

void gui::return_startup(Fl_Widget* w, void* p)
{
	((gui*)p)->real_return_startup();
}

void gui::real_return_startup()
{
	save();
	win->hide();
	startup();
}

void gui::exit(Fl_Widget* w, void* p)
{
	((gui*)p)->real_exit();
}

void gui::real_exit()
{
	std::exit(0);
}

void gui::check_log(Fl_Widget* w, void* p)
{
	((gui*)p)->real_check_log();
}

void gui::real_check_log()
{
	bool user_check = true;

	//Check Project Manager Log in
    if(username->value() == pm.get_username())
    {
        if(password->value() == pm.get_password())
        {
        	user_check = false;
            pm_win();
        }
        else
        {
        	fl_message("Password is incorrect!");
        	user_check = false;
        }
    }

    //Check Customer login
    /*for(int i = 0; i < cms.size(); i++)
    {
        if(username == cms[i].get_username())
        {
            if(password == cms[i].get_password())
            {
                clean();
                interface_customer(i);
            }
            else
            {
                clean();
                cout << "Password is incorrect!\n\n";
                login();
            }
        }
    }

    //Check Sales_Associate
    for(int i = 0; i < sas.size(); i++)
    {
        if(username == sas[i].get_username())
        {
            if(password == sas[i].get_password())
            {
                clean();
                interface_sa(i);
            }
            else
            {
                clean();
                cout << "Password is incorrect!\n\n";
                login();
            }
        }
    }*/
    if(user_check == true)
    {
    	fl_message("Username is incorrect!");
    }
}

void gui::createPM(Fl_Widget* w, void* p)
{
	((gui*)p)->real_createPM();
}

void gui::real_createPM()
{
	win->hide();
	win = new Fl_Window(x,y,"Please Enter the Information Below?");
	win->begin();
	username = new Fl_Input(x/3,y/9,175,25,"Username: ");
	password = new Fl_Input(x/3,y/5,175,25,"Password: ");
	name = new Fl_Input(x/3,y/3.4,175,25,"Full Name: ");
	phone_number = new Fl_Input(x/3,y/2.58,175,25,"Phone Number: ");
	email_address = new Fl_Input(x/3,y/2.05,175,25,"Email: ");
	Fl_Button* submit = new Fl_Button(x/2,y/1.7,75,25,"Submit");
	submit->callback(create_PM,this);
	win->show();
}

void gui::create_PM(Fl_Widget* w, void* p)
{
	((gui*)p)->real_create_PM();
}

void gui::real_create_PM()
{
	Project_Manager x(username->value(),password->value());
	pm = x;
	pm_win();
}

void gui::createSAS(Fl_Widget* w, void* p)
{
	((gui*)p)->real_createSAS();
}

void gui::real_createSAS()
{
	
}

void gui::createCM(Fl_Widget* w, void* p)
{
	((gui*)p)->real_createCM();
}

void gui::real_createCM()
{
	win->hide();
	win = new Fl_Window(x,y,"Please Enter the Information Below?");
	win->begin();
	username = new Fl_Input(x/3,y/9,175,25,"Username: ");
	password = new Fl_Input(x/3,y/5,175,25,"Password: ");
	name = new Fl_Input(x/3,y/3.4,175,25,"Full Name: ");
	phone_number = new Fl_Input(x/3,y/2.58,175,25,"Phone Number: ");
	email_address = new Fl_Input(x/3,y/2.05,175,25,"Email: ");
	Fl_Button* submit = new Fl_Button(x/2,y/1.7,75,25,"Submit");
	submit->callback(create_CM,this);
	win->show();
}

void gui::create_CM(Fl_Widget* w, void* p)
{
	
}

void gui::real_create_CM()
{

}

void gui::pm_win()
{
	win->hide();
	win = new Fl_Window(x,y,"Project Manager Screen");
	win->begin();
	Fl_Button* head = new Fl_Button(x/3.5,y/9,125,25,"Add Head");
	Fl_Button* arm = new Fl_Button(x/3.5,y/5,125,25,"Add Arm");
	Fl_Button* torso = new Fl_Button(x/3.5,y/3.4,125,25,"Add Torso");
	Fl_Button* battery = new Fl_Button(x/3.5,y/2.58,125,25,"Add Battery");
	Fl_Button* locomotor = new Fl_Button(x/3.5,y/2.05,125,25,"Add Locomotor");
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
	log_off->callback(return_startup,this);
	win->end();
	win->show();
}

void gui::startup()
{
	win->begin();
	win = new Fl_Window(x,y,"Welcome to Robot Shop!");
	username = new Fl_Input(x/3,y/9,175,25,"Username: ");
	password = new Fl_Input(x/3,y/5,175,25,"Password: ");
	Fl_Button* submit = new Fl_Button(x/2.1,y/3.4,75,25,"Submit");
	Fl_Button* create_pm = new Fl_Button(x/4,y/2.05,175,25,"Create Project Manager");
	Fl_Button* create_sas = new Fl_Button(x/4,y/1.71,175,25,"Create Customer");
	Fl_Button* create_cm = new Fl_Button(x/4,y/1.47,175,25,"Create Sales Associate");
	Fl_Button* Exit = new Fl_Button(x/4,y/1.2,175,25,"Exit");
	submit->callback(check_log,this);
	create_pm->callback(createPM,this);
	create_sas->callback(createSAS,this);
	create_cm->callback(createCM,this);
	Exit->callback(exit);
	win->end();
	win->show();
}

void gui::save()
{
	ofstream ost{filename};
	pm.save(ost);
	ost.close();
}

void gui::load()
{
	ifstream ist{filename};
	ist.clear();
	ist.seekg(0,ios::beg);
	pm.load(ist);
	ist.close();
}

int main()
{
	gui test(300,400);
	return Fl::run();
}
