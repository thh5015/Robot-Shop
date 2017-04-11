#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
using namespace std;

/////////////////////
//       PARTS     //
/////////////////////

class Parts
{
	public:
		void create_part();
        double get_cost();
        int get_weight();
	protected:
		string name;
		int part_num;
		double cost;
		double weight;
		string description;
};

void Parts::create_part()
{
	cout << "Please Enter a Name for this Part: ";
    getline(cin,name);
    getline(cin,name);
    cout << "Part Number: ";
    cin >> part_num;
    cout << "Please Enter a weight[kg]: ";
    cin >> weight;
    cout << "Please Enter a Cost: $";
    cin >> cost;
    cout << "Description: ";
    getline(cin,description);
    getline(cin,description);
}

double Parts::get_cost()
{
    return cost;
}

int Parts::get_weight()
{
    return weight;
}

class Head: public Parts
{
    public:
        void create_head(); 
        string to_string();
    protected: 
};

void Head::create_head()
{
	create_part();
}

string Head::to_string()
{
    stringstream to_string;
    to_string << "Part Name: " << name
              << "\nPart Number: #" << part_num
              << "\nPrice: $" << cost
              << "\nWeight: " << weight << "kg"
              << "\nDescription: " << description;
    return to_string.str();
}

class Torso: public Parts
{
    public:
		void create_torso();
        int get_compartments();
        string to_string();
    protected:
        int compartments;
};

void Torso::create_torso()
{
    create_part();
    cout << "Please enter the # of Battery Compartments: ";
    cin >> compartments;
}

int Torso::get_compartments()
{
    return compartments;
}

string Torso::to_string()
{
    stringstream to_string;
    to_string << "Part Name: " << name
              << "\nPart Number: #" << part_num
              << "\nPrice: $" << cost
              << "\nWeight: " << weight << " kg"
              << "\nDescription: " << description
              << "\nNumber of Compartments: " << compartments;
    return to_string.str();
}

class Battery: public Parts
{
    public:
        void create_battery();
        int get_energy_contained();
        string to_string();
    protected:
        int energy_contained;
};

void Battery::create_battery()
{
    create_part();
    cout << "Please enter the amount of energy it contains[Kilowatts/Hour]: ";
    cin >> energy_contained;
}

int Battery::get_energy_contained()
{
    return energy_contained;
}

string Battery::to_string()
{
    stringstream to_string;
    to_string << "Part Name: " << name
              << "\nPart Number: #" << part_num
              << "\nPrice: $" << cost
              << "\nWeight: " << weight << " kg"
              << "\nDescription: " << description
              << "\nEnergy Contained: " << energy_contained << " kW/h";
    return to_string.str();
}

class Arm: public Parts
{
    public:
        void create_arm();
        int get_energy_consumed();
        string to_string();
    protected:
        int energy_consumed;
};

int Arm::get_energy_consumed()
{
    return energy_consumed;
}

void Arm::create_arm()
{
    create_part();
    cout << "Please enter the amount of energy it consumes[Watts]: ";
    cin >> energy_consumed;
}

string Arm::to_string()
{
    stringstream to_string;
    to_string << "Part Name: " << name
              << "\nPart Number: #" << part_num
              << "\nPrice: $" << cost
              << "\nWeight: " << weight << "kg"
              << "\nDescription: " << description
              << "\nEnergy Consumed by Part: " << energy_consumed << " watts";
    return to_string.str();
}

class Locomotor: public Parts
{
    public:
        void create_locomotor();
        int get_energy_consumed();
        string to_string();
    protected: 
        int speed;
        int energy_consumed;
};

int Locomotor::get_energy_consumed()
{
    return energy_consumed;
}

void Locomotor::create_locomotor()
{
    create_part();
    cout << "Please enter the speed of the locomotor[MPH]: ";
    cin >> speed;
    cout << "Please enter the amount of energy it consumes[Watts]: ";
    cin >> energy_consumed;
}

string Locomotor::to_string()
{
    stringstream to_string;
    to_string << "Part Name: " << name
              << "\nPart Number: #" << part_num
              << "\nPrice: $" << cost
              << "\nWeight: " << weight << "kg"
              << "\nDescription: " << description
              << "\nSpeed: " << speed << " mph"
              << "\nEnergy Consumed by Part: " << energy_consumed << " watts";
    return to_string.str();
}

////////////////////
//      ROBOT     //
////////////////////
 
class Robot
{
    private:
        Head head;
        Torso torso;
        Arm left;
        Arm right;
        Locomotor locomotor;
        vector<Battery> batteries;

        string name;
        int model_num;
        double cost;
        double price;
        int weight;
        string description;
    public:
        Robot(Head head, Torso torso, Arm left, Arm right, Locomotor locomotor, vector<Battery> &batteries);
        double get_price();
        string get_name();
        void set_info();
        string to_string();
};

Robot::Robot(Head head, Torso torso, Arm left, Arm right, Locomotor locomotor, vector<Battery> &batteries)
{
    this->head = head;
    this->torso = torso;
    this->left = left;
    this->right = right;
    this->locomotor = locomotor;
    int cost = head.get_cost() + torso.get_cost() + left.get_cost() + right.get_cost() + locomotor.get_cost();
    int weight = head.get_weight() + torso.get_weight() + left.get_weight() + right.get_weight() + locomotor.get_weight();
    for(int i = 0; i < batteries.size(); i++)
    {
        this->batteries.push_back(batteries[i]);
        cost = cost + batteries[i].get_cost();
        weight = weight + batteries[i].get_weight();
    }
    this->weight = weight;
    this->cost = cost;
}

void Robot::set_info()
{
    cout << "Model Name: ";
    getline(cin,name);
    getline(cin,name);
    cout << "Model Number: ";
    cin >> model_num;
    cout << "Cost of Robot: $" << cost
         << "\nPrice of Robot: $";
    cin >> price;
    cout << "Please Enter a description for the product: ";
    getline(cin,description);
    getline(cin,description);
}

double Robot::get_price()
{
    return price;
}

string Robot::get_name()
{
    return name;
}

string Robot::to_string()
{
    stringstream to_string;
    to_string << "Model Name: " << name
              << "\nModel Number: #" << model_num
              << "\nPrice: $" << price
              << "\nWeight: " << weight << "kg"
              << "\nDescription: " << description;
    return to_string.str();
}

///////////////////////
//        User       //
///////////////////////

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
        void list_robots(); 
        Robot get_robot(int index);    
        Project_Manager(){}
        Project_Manager(string username,string password);
};

Project_Manager::Project_Manager(string username,string password)
{
    this->username = username;
    this->password = password;
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
    for(int i = 0; i < heads.size(); i++)
    {
        cout << "Head [#" << i << "]\n";
        cout << heads[i].to_string();
        cout << "\n\n";
    }
    cout << "\nSelect a head: ";
    cin >> index_head;
    for(int i = 0; i < 100 ; i++)
    {
        cout << "\n";
    }

    //Selecting a Torso
    int index_torso;
    for(int i = 0; i < torsos.size(); i++)
    {
        cout << "Torso [#" << i << "]\n";
        cout << torsos[i].to_string();
        cout << "\n\n";
    }
    cout << "\nSelect a Torso: ";
    cin >> index_torso;
    for(int i = 0; i < 100 ; i++)
    {
        cout << "\n";
    }

    //Selecting Batteries
    int index_batteries[3];
    vector<Battery> batteries_stored;
    for(int i = 0; i < batteries.size(); i++)
    {
        cout << "Battery[#" << i << "]\n"
             << batteries[i].to_string()
             << "\n\n";
    }
    for(int i = 0; i < torsos[index_torso].get_compartments(); i++)
    {
        cout << "\nBattery "<< i+1 << ": ";
        cin >> index_batteries[i];
        batteries_stored.push_back(batteries[index_batteries[i]]);
    }
    for(int i = 0; i < 100 ; i++)
    {
        cout << "\n";
    }

    //Selecting Right Arm
    int index_right_arm;
    for(int i = 0; i < arms.size(); i++)
    {
        cout << "Arm[#" << i << "]\n"
             << arms[i].to_string()
             << "\n\n";
    }
    cout << "\nSelect a Right Arm: ";
    cin >> index_right_arm;
    for(int i = 0; i < 100 ; i++)
    {
        cout << "\n";
    }

    //Selecting Left Arm
    int index_left_arm;
    for(int i = 0; i < arms.size(); i++)
    {
        cout << "Arm[#" << i << "]\n"
        << arms[i].to_string()
        << "\n\n";
    }
    cout << "\nSelect a Left Arm: ";
    cin >> index_left_arm;
    for(int i = 0; i < 100 ; i++)
    {
        cout << "\n";
    }

    //Selecting  Locomotor
    int index_locomotor;
    for(int i = 0; i < locomotors.size(); i++)
    {
        cout << "Locomotor[#" << i << "]\n"
             << locomotors[i].to_string()
             << "\n\n";
    }
    cout << "\nSelect a Locomotor: ";
    cin >> index_locomotor;
    for(int i = 0; i < 100 ; i++)
    {
        cout << "\n";
    }

    Robot robot(heads[index_head],torsos[index_torso],arms[index_left_arm],arms[index_right_arm],locomotors[index_locomotor],batteries_stored);
    robot.set_info();
    robots.push_back(robot);
}

void Project_Manager::list_robots()
{
    cout << "List of Robots: \n\n";
    for(int i = 0; i < robots.size(); i++)
    {
        cout << robots[i].to_string()
        << "\n\n";
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

///////////////////////
//     Customers     //
///////////////////////

class Customer: public User
{
    private:
        vector<Robot> orders;
        double outstanding_balance;
        int sa_index;
    public:
        void purchase_robot(Robot robot);
        void change_sa(int sa_index);
        void pay_amount(double amount);
        string view_orders();
        int get_currentsa();
        double get_outstanding_balance();
        Customer(string name,string username,string password,int current_sa);
};

Customer::Customer(string name, string username,string password, int sa_index)
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

void Customer::pay_amount(double amount)
{
    outstanding_balance = outstanding_balance - amount;
}

void Customer::change_sa(int sa_index)
{
    this->sa_index = sa_index;
}

string Customer::view_orders()
{
    stringstream to_string;
    to_string << "List of Orders:\n\n";
    for(int i = 0; i < orders.size(); i++)
    {
        to_string << "Order #: " << i+1
                  << "\nModel Name: " << orders[i].get_name()
                  << "\nPrice of Robot: " << orders[i].get_price() << "\n\n";
    }
    return to_string.str();
}

double Customer::get_outstanding_balance()
{
    return outstanding_balance;
}

int Customer::get_currentsa()
{
    return sa_index;
}

///////////////////////
//     POS SYSTEM    //
///////////////////////

class POS_System
{
    private:
        Project_Manager pm;
        vector<Sales_Associate> sas;                  
        vector<Customer> cms;
        //Boss boss;
    public:
        void interface_pm();
        void interface_customer(int session);
        void interface_sa(int session);
        void startup_screen();
        void login();
        void clean();
};

void POS_System::clean()
{
    for(int i = 0; i < 100 ; i++)
    {
        cout << "\n";
    }
}

void POS_System::interface_pm()
{
    int input;
    string interface = R"(
    ************************
    *    1) Add Head       *
    *    2) Add Arm        *
    *    3) Add Torso      *
    *    4) Add Locomotor  *
    *    5) Add Battery    *
    *    6) Create Robot   *
    *    7) View Robots    *
    *    8) Log off        *
    ************************
    Command: )";

    while(input != 8)
    {
        cout << interface;
        cin >> input;
        if(input == 1)
        {
            clean();
            pm.add_part(1);
            clean();
        }
        else if(input == 2)
        {
            clean();
            pm.add_part(2);
            clean();
        }
        else if(input == 3)
        {
            clean();
            pm.add_part(3);
            clean();
        }
        else if(input == 4)
        {
            clean();
            pm.add_part(4);
            clean();
        }   
        else if(input == 5)
        {
            clean();
            pm.add_part(5);
            clean();
        }
        else if(input == 6)
        {
            clean();
            pm.create_robot();
            clean();
        }
        else if(input == 7)
        {
            clean();
            pm.list_robots();
        }
        else if(input == 8)
        {
            clean();
            startup_screen();
        }
        else
        {
            clean();
            cout << "NOT AN INPUT!";
        }
    }
}

void POS_System::interface_customer(int session)
{
    string bs;
    int input;
    int index;
    string interface = R"(
    **********************************
    *    1) Order a Robot            *
    *    2) View Purchase History    *
    *    3) View Outstanding Balance *
    *    4) Pick the Sales Associate *
    *       you wish to speak too    *
    *    5) Make a Payment           *
    *    6) Log off                  *
    **********************************
    Command: )";
    while(input != 5)
    {
        cout << interface;
        cin >> input;
        if(input == 1)
        {
            clean();
            pm.list_robots();
            cout << "Please select a robot to purchase: ";
            cin >> index;
            cms[session].purchase_robot(pm.get_robot(index));
            sas[cms[session].get_currentsa()].place_order(pm.get_robot(index),cms[session].get_name());
            clean();
        }
        else if(input == 2)
        {
            clean();
            cms[session].view_orders();
            cout << "Type a random character and then click enter to continue!";
            cin >> bs;
            clean();
        }
        else if(input == 3)
        {
            clean();
            cout << "Your outstanding balance is: $" << cms[session].get_outstanding_balance();
            cout << "\n\nType a random character and then click enter to continue!";
            cin >> bs;
            clean();
        }
        else if(input == 4)
        {
            clean();
            cout << "List of Sales Associate:\n\n";
            for(int i = 0; i < sas.size(); i++)
            {
                cout << "Sales Associate [#" << i << "]\n" 
                     << "Name: " << sas[session].get_name() << "\n";
            }
            cout << "Who would you like as your Sales Associate: ";
            cin >> index;
            cms[session].change_sa(index);
            clean();
        }
        else if(input == 5)
        {
            double payment;
            clean();
            cout << "Your outstanding balance is: $" << cms[session].get_outstanding_balance()
                 << "\nEnter payment amount: $";
            cin >> payment;
            cms[session].pay_amount(payment);
            clean();
        }
        else if (input == 6)
        {
            clean();
            startup_screen();
        }
        else
        {
            clean();
            cout << "NOT AN INPUT!";
        }
    }
}

void POS_System::interface_sa(int session)
{
    int input;
    string bs;
    string interface = R"(
    **********************************
    *    1) View Bill of Sales       *
    *    2) Lobby for raise //NA     *
    *    3) Log off                  *
    **********************************
    Command: )";
    while(input != 3)
    {
        cout << interface;
        cin >> input;
        if(input == 1)
        {
            clean();
            cout << sas[session].bill_of_sales()
                 << "\nType any character in and then click enter to continue!";
            cin >> bs;
        }
        else if(input == 2)
        {
            clean();
        }
        else if(input == 3)
        {
            clean();
            startup_screen();
        }
        else
        {
            clean();
            cout << "NOT AN INPUT!";
        }
    }
}

void POS_System::login()
{
    string username;
    string password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    //Check Project Manager Log in
    if(username == pm.get_username())
    {
        if(password == pm.get_password())
            {
                clean();
                interface_pm();
            }
            else
            {
                clean();
                cout << "Password is incorrect!\n\n";
                login();
            }
    }
    //Check Customer login
    for(int i = 0; i < cms.size(); i++)
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
    }
}

void POS_System::startup_screen()
{
    //load();
    int input;
    string name;
    string username;
    string password;
    string interface = R"(
    ********************************
    *    1) Login                  *
    *    2) Create Project Manager *
    *    3) Create Customer        *
    *    4) Create Sales_Associate *
    *    5) Exit                   *
    ********************************
    Command: )";
    cout << interface;
    cin >> input;
    while(input != 5)
    {
        if(input == 1)
        {   
            clean();
            login();
        }
        else if(input == 2)
        {
            if(pm.get_username() == "")
            {
                clean();
                cout << "Please Enter a Username: ";
                cin >> username;
                cout << "Please Enter a Password: ";
                cin >> password;
                Project_Manager temp(username,password);
                pm = temp;
                clean(); 
                interface_pm();
            }
            else
            {
                clean();
                cout << "Can only have 1 project manager!";
                clean();
                startup_screen();
            }
        }
        else if(input == 3)
        {
            clean();
            int sa_index;
            cout << "Please Enter a Username: ";
            cin >> username;
            cout << "Please Enter a Password: ";
            cin >> password;
            cout << "Please Enter your FULL name: ";
            getline(cin,name);
            getline(cin,name);
            if(sas.size() == 0)
            {
                clean();
                cout << "Can't create customer until a Sales Associate is made!";
                startup_screen(); 
            }
            else
            {
                cout << "\nList of Sales Associates:\n\n";
                for(int i = 0; i < sas.size(); i++)
                {
                    cout <<"Sales Associate [#" << i << "]\nName:" << sas[i].get_name() << "\n\n";
                }
                cout << "Please Select the Employee # of the Sales Associate that you wish to assist you: ";
                cin >> sa_index;
                Customer temp(name,username,password,sa_index);
                cms.push_back(temp);
                interface_customer(cms.size()-1);
            }
        }
        else if(input == 4)
        {
            clean();
            cout << "Please Enter a Username: ";
            cin >> username;
            cout << "Please Enter a Password: ";
            cin >> password;
            cout << "Please Enter your FULL name: ";
            getline(cin,name);
            getline(cin,name);
            if(pm.get_username() == "")
            {
                clean();
                cout << "No Project Manager in System!";
                startup_screen();
            } 
            else
            {
                Sales_Associate temp(name,username,password);
                sas.push_back(temp);
                interface_sa(sas.size()-1);
            }
        }
        else if(input == 5)
        {
            //save();
            exit(0);
        }
        else
        {
           clean();
           cout << "NOT AN INPUT!";
        }
    }
}

void save(POS_System test)
{
    
}

POS_System load()
{
    POS_System data;
    string filename = "data.txt";
    ofstream infile;
    infile.open(filename.c_str(),ios::in);
    infile.read()
    return data;
}

//////////////////
//     MAIN     //
//////////////////

int main()
{
    POS_System test;
    test = load();
    test.startup_screen();
    save(test);
	return 0;
}