#include "users.cpp"
using namespace std;



class gui
{
	private:
		Project_Manager pm;
        vector<Sales_Associate> sas; 
        int sa_session;                 
        vector<Customer> cms;	
        int cm_session;

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
		static void viewBOS(Fl_Widget* w, void* p);
		void real_viewBOS();
		static void viewALL(Fl_Widget* w, void* p);
		void real_viewALL();
		static void orderRobot(Fl_Widget* w, void* p);
		void real_orderRobot();
		static void viewOrder(Fl_Widget* w, void* p);
		void real_viewOrder();
		static void createPM(Fl_Widget* w, void* p);
		void real_createPM();
		static void create_PM(Fl_Widget* w, void* p);
		void real_create_PM();
		static void createSAS(Fl_Widget* w, void* p);
		void real_createSAS();
		static void create_SAS(Fl_Widget* w, void* p);
		void real_create_SAS();
		static void createCM(Fl_Widget* w, void* p);
		void real_createCM();
		static void create_CM(Fl_Widget* w, void* p);
		void real_create_CM();
		static void exit(Fl_Widget* w, void* p);
		void real_exit();
		void startup();
		void pm_win();
		void cm_win();
		void sas_win();
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

void gui::viewBOS(Fl_Widget* w, void* p)
{
	((gui*)p)->real_viewBOS();
}

void gui::real_viewBOS()
{
	string to_string = sas[sa_session].bill_of_sales();
	fl_message(to_string.c_str());
}

void gui::viewALL(Fl_Widget* w, void* p)
{
	((gui*)p)->real_viewALL();
}

void gui::real_viewALL()
{
	stringstream to_string;
	to_string << "List of All Orders:\n\n";
	for(int i = 0; i < cms.size(); i++)
	{
		to_string << "Name of Customer: " << cms[i].get_name() 
		          << "\n" << cms[i].view_orders();
	}
	fl_message((to_string.str()).c_str());
}

void gui::orderRobot(Fl_Widget* w, void* p)
{
	((gui*)p)->real_orderRobot();
}

void gui::real_orderRobot()
{
	stringstream to_string;
	to_string << pm.list_robots() << "Which Robot Would You Like To Purchase? ";
	string index_robot{fl_input((to_string.str()).c_str(),0)};
	cms[cm_session].purchase_robot(pm.get_robot(atoi(index_robot.c_str())));
	sas[cms[cm_session].get_currentsa()].place_order(pm.get_robot(atoi(index_robot.c_str())),cms[cm_session].get_name());
}

void gui::viewOrder(Fl_Widget* w, void* p)
{
	((gui*)p)->real_viewOrder();
}

void gui::real_viewOrder()
{
	stringstream to_string;
	to_string << "List of All Orders:\n\n" << cms[cm_session].view_orders();
	fl_message((to_string.str()).c_str());
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
    for(int i = 0; i < cms.size(); i++)
    {
        if(username->value() == cms[i].get_username())
        {
            if(password->value() == cms[i].get_password())
            {
            	user_check = false;
            	cm_session = i;
                cm_win();
            }
            else
            {
                fl_message("Password is incorrect!");
        		user_check = false;
            }
        }
    }

    //Check Sales_Associate
    for(int i = 0; i < sas.size(); i++)
    {
        if(username->value() == sas[i].get_username())
        {
            if(password->value() == sas[i].get_password())
            {
               user_check = false;
               sa_session = i;
               sas_win();
            }
            else
            {
                fl_message("Password is incorrect!");
                user_check = false;
            }
        }
    }
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
	win = new Fl_Window(x,y,"Creating Project Manager");
	win->begin();
	username = new Fl_Input(x/3,y/9,175,25,"Username: ");
	password = new Fl_Input(x/3,y/5,175,25,"Password: ");
	name = new Fl_Input(x/3,y/3.4,175,25,"Full Name: ");
	phone_number = new Fl_Input(x/3,y/2.58,175,25,"Phone #: ");
	email_address = new Fl_Input(x/3,y/2.05,175,25,"Email: ");
	Fl_Button* submit = new Fl_Button(x/2,y/1.7,75,25,"Submit");
	Fl_Button* back = new Fl_Button(x/2,y/1.5,75,25,"Return");
	back->callback(return_startup,this);
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
	win->hide();
	win = new Fl_Window(x,y,"Creating Customer");
	win->begin();
	username = new Fl_Input(x/3,y/9,175,25,"Username: ");
	password = new Fl_Input(x/3,y/5,175,25,"Password: ");
	name = new Fl_Input(x/3,y/3.4,175,25,"Full Name: ");
	phone_number = new Fl_Input(x/3,y/2.58,175,25,"Phone #: ");
	email_address = new Fl_Input(x/3,y/2.05,175,25,"Email: ");
	Fl_Button* submit = new Fl_Button(x/2,y/1.7,75,25,"Submit");
	Fl_Button* back = new Fl_Button(x/2,y/1.5,75,25,"Return");
	submit->callback(create_SAS,this);
	back->callback(return_startup,this);
	win->show();
}

void gui::create_SAS(Fl_Widget* w, void* p)
{
	((gui*)p)->real_create_SAS();
}

void gui::real_create_SAS()
{
	Sales_Associate x(name->value(),username->value(),password->value());
	sas.push_back(x);
	sa_session = sas.size()-1;
	sas_win();
}

void gui::createCM(Fl_Widget* w, void* p)
{
	((gui*)p)->real_createCM();
}

void gui::real_createCM()
{
	win->hide();
	win = new Fl_Window(x,y,"Creating Customer");
	win->begin();
	username = new Fl_Input(x/3,y/9,175,25,"Username: ");
	password = new Fl_Input(x/3,y/5,175,25,"Password: ");
	name = new Fl_Input(x/3,y/3.4,175,25,"Full Name: ");
	phone_number = new Fl_Input(x/3,y/2.58,175,25,"Phone #: ");
	email_address = new Fl_Input(x/3,y/2.05,175,25,"Email: ");
	Fl_Button* submit = new Fl_Button(x/2,y/1.7,75,25,"Submit");
	Fl_Button* back = new Fl_Button(x/2,y/1.5,75,25,"Return");
	submit->callback(create_CM,this);
	back->callback(return_startup,this);
	win->show();
}

void gui::create_CM(Fl_Widget* w, void* p)
{
	((gui*)p)->real_create_CM();
}

void gui::real_create_CM()
{
	stringstream to_string;
	to_string << "List of Sales Associate:\n\n";
    for(int i = 0; i < sas.size(); i++)
    {
        to_string << "Sales Associate [#" << i << "]\n" 
                  << "Name: " << sas[i].get_name() << "\n";
    }
    to_string << "Who would you like as your Sales Associate: ";
	string sa_index{fl_input((to_string.str()).c_str(),0)};
	Customer x(name->value(),username->value(),password->value(),atoi(sa_index.c_str()));
	cms.push_back(x);
	cm_session = cms.size()-1;
	cm_win();
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

void gui::sas_win()
{
	win->hide();
	win = new Fl_Window(x,y,"Sales Associate Screen");
	win->begin();
	Fl_Button* view_bill = new Fl_Button(x/3.5,y/5,150,25,"View Sales Report");
	Fl_Button* view_all_orders = new Fl_Button(x/3.5,y/3.4,150,25,"View All Orders");
	Fl_Button* manage_orders = new Fl_Button(x/3.5,y/2.58,150,25,"Manage Orders");
	Fl_Button* log_off = new Fl_Button(x/3.5,y/1.71,150,25,"Log off");
	view_bill->callback(viewBOS,this);
	view_all_orders->callback(viewALL,this);
	log_off->callback(return_startup,this);
	win->end();
	win->show();
}

void gui::cm_win()
{
	win->hide();
	win = new Fl_Window(x,y,"Customer Window");
	win->begin();
	Fl_Button* order_robot = new Fl_Button(x/3.5,y/5,150,25,"Order a Robot");
	Fl_Button* view_orders = new Fl_Button(x/3.5,y/3.4,150,25,"View Orders");
	Fl_Button* view_bill = new Fl_Button(x/3.5,y/2.58,150,25,"View Bill(Invoice)");
	Fl_Button* log_off = new Fl_Button(x/3.5,y/1.71,150,25,"Log off");
	order_robot->callback(orderRobot,this);
	view_orders->callback(viewOrder,this);
	//view_bill->callback(viewBill,this);
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
	Fl_Button* create_sas = new Fl_Button(x/4,y/1.71,175,25,"Create Sales Associate");
	Fl_Button* create_cm = new Fl_Button(x/4,y/1.47,175,25,"Create Customer");
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
