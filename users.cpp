#include "robots.cpp"

////////////////////
//	   Users      //
////////////////////

class User
{
    protected:
        string name;
        string username;
        string password;
        string phone_number;
        string email_address;
    public:
        string get_username();
        string get_password();
        string get_name();
};

string User::get_username()
{
    return username;
}

string User::get_password()
{
    return password;
}

string User::get_name()
{
    return name;
}

///////////////////////
//  Project Manager  //
///////////////////////

class Project_Manager: public User
{
    private:
        vector<Robot> robots;
        vector<Head> heads;
        vector<Torso> torsos;
        vector<Arm> arms;
        vector<Battery> batteries;
        vector<Locomotor> locomotors;
    public:
        void add_part(int part_type);
        void create_robot();  
        string list_robots();
        void set_obsolete(int index); 
        Robot get_robot(int index);    
        Project_Manager(){}
        Project_Manager(string username,string password);
        void save(ostream& ost);
        void load(istream& ist);
};

Project_Manager::Project_Manager(string username,string password)
{
    this->username = username;
    this->password = password;
}

void Project_Manager::set_obsolete(int index)
{
    robots[index].set_obsolete();
}

Robot Project_Manager::get_robot(int index)
{
    return robots[index];
}

void Project_Manager::add_part(int part_type)
{
    if(part_type == 1)
    {
        Head head;
        head.create_head();
        heads.push_back(head);
    }
    else if(part_type == 2)
    {
        Arm arm;
        arm.create_arm();
        arms.push_back(arm);

    }
    else if(part_type == 3)
    {
        Torso torso;
        torso.create_torso();
        torsos.push_back(torso);
    }
    else if(part_type == 4)
    {
        Locomotor locomotor;
        locomotor.create_locomotor();
        locomotors.push_back(locomotor);
    }
    else if(part_type == 5)
    {
        Battery battery;
        battery.create_battery();
        batteries.push_back(battery);
    }
}

void Project_Manager::create_robot()
{
    //Checking to see if there are enough parts to create robot
    if(heads.size() == 0)
        return;
    else if(arms.size() == 0)
        return;
    else if(torsos.size() == 0)
        return;
    else if(batteries.size() == 0)
        return;
    else if(locomotors.size() == 0)
        return;

    //Selecting the Head
    int index_head;
    stringstream to_string_head;
    for(int i = 0; i < heads.size(); i++)
    {
       
            to_string_head << "Head [#" << i << "]\n"
                            << heads[i].to_string()
                           << "\n\n";
        
    }
    to_string_head << "Select a Head [#]:";
    string head{fl_input((to_string_head.str()).c_str(),0)};
    index_head = atoi(head.c_str());

    //Selecting a Torso
    int index_torso;
    stringstream to_string_torso;
    for(int i = 0; i < torsos.size(); i++)
    {
        
            to_string_torso << "Torso [#" << i << "]\n"
                            << torsos[i].to_string()
        				    << "\n\n";
        
    }
    to_string_torso << "Select a Torso [#]: ";
    string torso{fl_input((to_string_torso.str()).c_str(),0)};
    index_torso = atoi(torso.c_str());

    //Selecting Batteries
    int index_batteries[3];
    vector<Battery> batteries_stored;
    stringstream to_string_battery;
    for(int i = 0; i < batteries.size(); i++)
    {
        
            to_string_battery << "Battery[#" << i << "]\n"
             			      << batteries[i].to_string()
             			      << "\n\n";
        
    }
    to_string_battery << "\nPlease Select a Battery for the compartment:";
    for(int i = 0; i < torsos[index_torso].get_compartments(); i++)
    {
    	string battery{fl_input((to_string_battery.str()).c_str(),0)};
    	index_batteries[i] = atoi(battery.c_str());
        batteries_stored.push_back(batteries[index_batteries[i]]);
    }

    //Selecting Right Arm
    int index_right_arm;
    stringstream to_string_rarm;
    for(int i = 0; i < arms.size(); i++)
    {
       
            to_string_rarm << "Arm[#" << i << "]\n"
                       << arms[i].to_string()
                       << "\n\n";
        
    }
    to_string_rarm << "\nSelect a Right Arm:";
    string rarm{fl_input((to_string_rarm.str()).c_str(),0)};
    index_right_arm = atoi(rarm.c_str());

    //Selecting Left Arm
    int index_left_arm;
    stringstream to_string_larm;
    for(int i = 0; i < arms.size(); i++)
    {
      
        to_string_larm << "Arm[#" << i << "]\n"
        			   << arms[i].to_string()
        	           << "\n\n";
        
    }
    to_string_larm << "\nSelect a Left Arm: ";
    string larm{fl_input((to_string_larm.str()).c_str(),0)};
    index_left_arm = atoi(larm.c_str());

    //Selecting  Locomotor
    int index_locomotor;
    stringstream to_string_locomotor;
    for(int i = 0; i < locomotors.size(); i++)
    {
        
        
        to_string_locomotor << "Locomotor[#" << i << "]\n"
             			    << locomotors[i].to_string()
            			    << "\n\n";
        
    }
    to_string_locomotor << "\nSelect a Locomotor:";
    string locomotor{fl_input((to_string_locomotor.str()).c_str(),0)};
    index_locomotor = atoi(locomotor.c_str());
   
    Robot robot(heads[index_head],torsos[index_torso],arms[index_left_arm],arms[index_right_arm],locomotors[index_locomotor],batteries_stored);
    robot.set_info();
    robots.push_back(robot);
}

string Project_Manager::list_robots()
{
	stringstream to_string;
	to_string << "List of Robots: \n\n";
    for(int i = 0; i < robots.size(); i++)
    {
        if(robots[i].get_obsolete() != true)
        {
        to_string << "Robot [#" << i << "]\n" 
                  << robots[i].to_string()
       			  << "\n\n";
        }
    }
    return to_string.str();
}

void Project_Manager::save(ostream& ost)
{
    ost << username << endl
        << password << endl
        << robots.size() << endl
        << heads.size() << endl
        << torsos.size() << endl
        << arms.size() << endl
        << batteries.size() << endl
        << locomotors.size() << endl;
    for(int i = 0; i < robots.size(); i++)
    {
        robots[i].save(ost);
    }
    for(int i = 0; i < heads.size(); i++)
    {
        heads[i].save(ost);
    }
    for(int i = 0; i < torsos.size(); i++)
    {
        torsos[i].save(ost);
    }
    for(int i = 0; i < arms.size(); i++)
    {
        arms[i].save(ost);
    }
    for(int i = 0; i < batteries.size(); i++)
    {
        batteries[i].save(ost);
    }
    for(int i = 0; i < locomotors.size(); i++)
    {
        locomotors[i].save(ost);
    }
}

void Project_Manager::load(istream& ist)
{
    int size[6];
    string temp;
    getline(ist,temp);
    username = temp.c_str();
    getline(ist,temp);
    password = temp.c_str();
    for(int i = 0; i < 6; i++)
    {
        getline(ist,temp);
        size[i] = atoi(temp.c_str());
    }
    for(int i = 0; i < size[0]; i++)
    {
        Robot r;
        r.load(ist);
        robots.push_back(r);
    }
    for(int i = 0; i < size[1]; i++)
    {
        Head h;
        h.load(ist);
        heads.push_back(h);
    }
    for(int i = 0; i < size[2]; i++)
    {
        Torso t;
        t.load(ist);
        torsos.push_back(t);
    }
    for(int i = 0; i < size[3]; i++)
    {
        Arm a;
        a.load(ist);
        arms.push_back(a);
    }
    for(int i = 0; i < size[4]; i++)
    {
        Battery b;
        b.load(ist);
        batteries.push_back(b);
    }
    for(int i = 0; i < size[5]; i++)
    { 
        Locomotor l;
        l.load(ist);
        locomotors.push_back(l);
    } 
}

///////////////////////
//  Sales Associate  //
///////////////////////

class Sales_Associate: public User
{
    private:
        vector<Robot> sales;
        vector<string> names;
        vector<int> year;
        vector<int> month;
        vector<int> day;
    public:
        void place_order(Robot robot, string name);
        string bill_of_sales();
        Sales_Associate(string name,string username, string password);
        Sales_Associate() {};
        void save(ostream& ost);
        void load(istream& ist);

};

Sales_Associate::Sales_Associate(string name, string username, string password)
{
    this->name = name;
    this->username = username;
    this->password = password;
}

void Sales_Associate::place_order(Robot robot,string name)
{
    time_t t = time(0);
    struct tm* now = localtime(&t);
    year.push_back(now->tm_year+1900);
    month.push_back(now->tm_mon+1);
    day.push_back(now->tm_mday);
    names.push_back(name);
    sales.push_back(robot);
}

string Sales_Associate::bill_of_sales()
{
    stringstream bill_of_sales;
    bill_of_sales << "Bill of Sales:\n\n";
    for(int i = 0; i < sales.size(); i++)
    {
        bill_of_sales << "Order #: " << i+1
                      << "\nDate of Sale: " << month[i] << "/" << day[i] << "/" << year[i]
                      << "\nCustomers Name: " << names[i]
                      << "\nRobot Ordered: " << sales[i].get_price() << "\n\n";
    }
    return bill_of_sales.str();
}

void Sales_Associate::save(ostream& ost)
{
    ost << username << endl
        << password << endl
        << name << endl
        << sales.size() << endl
        << names.size() << endl
        << year.size() << endl
        << month.size() << endl
        << day.size() << endl;
    for(int i = 0; i < sales.size(); i++)
    {
        sales[i].save(ost);
    }
    for(int i = 0; i < names.size(); i++)
    {
        ost << names[i];
    }
    for(int i = 0; i < year.size(); i++)
    {
        ost << year[i];
    }
    for(int i = 0; i < month.size(); i++)
    {
        ost << month[i];
    }
    for(int i = 0; i < day.size(); i++)
    {
        ost << day[i];
    }
}

void Sales_Associate::load(istream& ist)
{
    int size[5];
    string temp;
    getline(ist,temp);
    username = temp.c_str();
    getline(ist,temp);
    password = temp.c_str();
    getline(ist,temp);
    name = temp.c_str();
    for(int i = 0; i < 6; i++)
    {
        getline(ist,temp);
        size[i] = atoi(temp.c_str());
    }
    for(int i = 0; i < size[0]; i++)
    {
        Robot r;
        r.load(ist);
        sales.push_back(r);
    }
    for(int i = 0; i < size[1]; i++)
    {
        getline(ist,temp);
        names.push_back(temp.c_str());
    }
    for(int i = 0; i < size[2]; i++)
    {
        getline(ist,temp);
        year.push_back(atoi(temp.c_str()));
    }
    for(int i = 0; i < size[3]; i++)
    {
        getline(ist,temp);
        month.push_back(atoi(temp.c_str()));
    }
    for(int i = 0; i < size[4]; i++)
    {
        getline(ist,temp);
        day.push_back(atoi(temp.c_str()));
    }
}

//////////////////
//  Customer    //
//////////////////

class Customer: public User
{
    private:
        vector<Robot> orders;
        float outstanding_balance;
        int sa_index;
    public:
        void purchase_robot(Robot robot);
        void change_sa(int sa_index);
        void pay_amount(int order_index,float amount);
        string view_orders();
        string bill_invoice();
        int get_currentsa();
        float get_outstanding_balance();
        Customer(string name,string username,string password,int current_sa);
        Customer() {};
        void save(ostream& ost);
        void load(istream& ist);
};

Customer::Customer(string name, string username, string password, int sa_index)
{
    this->name = name;
    this->username = username;
    this->password = password;
    this->sa_index = sa_index;
    outstanding_balance = 0;
}

void Customer::purchase_robot(Robot robot)
{
    orders.push_back(robot);
    outstanding_balance = outstanding_balance + robot.get_price();
}

void Customer::pay_amount(int order_index,float amount)
{
    orders[order_index].pay_amount(amount);
    if(orders[order_index].get_outstanding_balance() <= 0)
    {
        orders[order_index].ispaid();
    }
    outstanding_balance = outstanding_balance - amount;
}

void Customer::change_sa(int sa_index)
{
    this->sa_index = sa_index;
}

string Customer::view_orders()
{
    stringstream to_string;
    for(int i = 0; i < orders.size(); i++)
    {
        to_string << "Order #: " << i+1
                  << "\nModel Name: " << orders[i].get_name()
                  << "\nPrice of Robot: $" << orders[i].get_price() 
                  << "\nOutstanding Balance on Robot: $" << orders[i].get_outstanding_balance()
                  << "\n\n";
    }
    return to_string.str();
}

string Customer::bill_invoice()
{
    stringstream paid;
    stringstream not_paid;
    paid << "Paid Off Robots:\n\n";
    not_paid << "Not Paid Off Robots\n\n";
    for(int i = 0; i < orders.size(); i++)
    {
        if(orders[i].get_paid() == true)
        {
            paid << "Order #: " << i+1
                 << "\nModel Name: " << orders[i].get_name()
                 << "\nPrice of Robot: $" << orders[i].get_price() << "\n\n";
        }
        else
        {
            not_paid << "Order #: " << i+1
                     << "\nModel Name: " << orders[i].get_name()
                     << "\nPrice of Robot: $" << orders[i].get_price() 
                     << "\nAmount Still Owed: $" << orders[i].get_outstanding_balance()
                     << "\n\n";
        }
    }
    paid << not_paid.str() << "Outstanding Balance: $" << outstanding_balance;
    return paid.str();
}

float Customer::get_outstanding_balance()
{
    return outstanding_balance;
}

int Customer::get_currentsa()
{
    return sa_index;
}

void Customer::save(ostream& ost)
{
    ost << username << endl
        << password << endl
        << name << endl
        << outstanding_balance << endl
        << sa_index << endl
        << orders.size() << endl;
        for(int i = 0; i < orders.size(); i++)
        {
            orders[i].save(ost);
        }
}

void Customer::load(istream& ist)
{
    string temp;
    int size;
    getline(ist,temp);
    username = temp.c_str();
    getline(ist,temp);
    password = temp.c_str();
    getline(ist,temp);
    name = temp.c_str();
    getline(ist,temp);
    outstanding_balance = atoi(temp.c_str());
    getline(ist,temp);
    sa_index = atoi(temp.c_str());
    getline(ist,temp);
    size = atoi(temp.c_str());
    for(int i = 0; i < size; i++)
    {
        Robot r;
        r.load(ist);
        orders.push_back(r);
    }
}