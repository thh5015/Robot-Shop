#include <iostream>
#include <string>
#include <sstream>
#include <vector>
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
//  Project Manager  //
///////////////////////

class Project_Manager
{
    private:
        string username;
        string password;
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
};

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
    cout << batteries_stored.size();
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
//     POS SYSTEM    //
///////////////////////

class POS_System
{
    private:
        //vector<Project_Manager> pms;                   Private variables will be 
        //vector<Sales_Associates> sms;                  in final model!
        //vector<Customers> cms;
        //Boss boss;
        Project_Manager pm;
    public:
        void interface();
        void clean();
};

void POS_System::clean()
{
    for(int i = 0; i < 100 ; i++)
    {
        cout << "\n";
    }
}

void POS_System::interface()
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
    *    7) View Robot     *
    *    8) Exit           *
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
            exit(0);
        }
        else
        {
            clean();
            cout << "NOT AN INPUT!";
        }
    }
}

//////////////////
//     MAIN     //
//////////////////

int main()
{
    POS_System test;
    test.interface();
	return 0;
}