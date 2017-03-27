#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>
using namespace std;

////////////////////
//	    Parts	  //
////////////////////

class Head
{
	protected:
		string part_name;
		int part_num;
		int weight;
		double cost;
		string description;
	public:
		Head(string part_name, int part_num, int weight, double cost, string description);
		string to_string();
};

Head::Head(string part_name, int part_num, int weight, double cost, string description)
{
	this->part_name = part_name;
	this->part_num = part_num;
	this->weight = weight;
	this->cost = cost;
	this->description = description;
}

string Head::to_string()
{
	stringstream to_string;
	to_string << "Part Number: #" << part_num << "\nWeight: " << weight << " kg\nCost: $" << cost << "\nDescription: " << description << "\n\n";
	return to_string.str();
}

class Arm
{
	protected:
		string part_name;
		int part_num;
		int weight;
		double cost;
		int power_usage;
		string description;
	public:
		Arm(string part_name, int part_num, int weight, double cost, int power_usage, string description);
};

Arm::Arm(string part_name, int part_num, int weight, double cost, int power_usage, string description)
{
	this->part_name = part_name;
	this->part_num = part_num;
	this->weight = weight;
	this->cost = cost;
	this->power_usage = power_usage;
	this->description = description;
}

class Battery
{
	protected:
		string part_name;
		int part_num;
		int power_stored;
		int weight;
		double cost;
		string description;
	public:
		Battery(string part_name, int part_num, int power_stored, int weight, double cost, string description);
		int get_power_stored();
};

Battery::Battery(string part_name, int part_num, int power_stored, int weight, double cost, string description)
{
	this->part_name = part_name;
	this->part_num = part_num;
	this->power_stored = power_stored;
	this->weight = weight;
	this->cost = cost;
	this->description = description;
}

int Battery::get_power_stored()
{
	return power_stored;
}

class Torso
{
	protected:
		string part_name;
		int part_num;
		int weight;
		double cost;
		vector<Battery> batteries;
		int battery_count;
		string description;
	public:
		Torso(string part_name, int part_num, int weight, double cost, string description);
		void add_battery(Battery battery);
		int get_total_power();
		double get_total_cost();
		int get_total_weight();	
};

Torso::Torso(string part_name, int part_num, int weight, double cost, string description)
{
	this->part_name = part_name;
	this->part_num = part_num;
	this->weight = weight;
	this->cost = cost;
	this->description = description;
	battery_count = 0;
}

void Torso::add_battery(Battery battery)
{
	if(battery_count <= 3)
	{
		batteries.push_back(battery);
		battery_count++;
	}
	else
	{
		cout << "Max Battery Count Reached!";
	}
}

int Torso::get_total_power()
{
	int total_power = 0;
	for(int i = 0; i < batteries.size(); i++)
	{
		total_power = total_power + batteries[i].get_power_stored();

	}
	return total_power;
}

class Locomotor
{
	protected:
		string part_name;
		int part_num;
		int weight;
		double cost;
		int power_consumed;
		int max_speed;
		string description;
	public:
		Locomotor(string part_name, int part_num, int weight, double cost, int power_consumed, int max_speed, string description);
};

Locomotor::Locomotor(string part_name, int part_num, int weight, double cost, int power_consumed, int max_speed, string description)
{
	this->part_name = part_name;
	this->part_num = part_num;
	this->weight = weight;
	this->cost = cost;
	this->power_consumed = power_consumed;
	this->max_speed = max_speed;
	this->description = description;
}

/////////////////////
//		Robot	   //
/////////////////////

class Robot//: public Head, public Arm, public Torso, public Locomotor
{
	protected:
		vector<Robot> list_of_robots;
		vector<Head> list_of_heads;
		vector<Arm> list_of_arms;
		vector<Torso> list_of_torsos;
		vector<Locomotor> list_of_locomotors;
		vector<Battery> list_of_batteries;
		int model_number;
		string model_name;
		double model_price;
	public:
		//Robot(Head head, Torso torso, Arm left, Arm Right,Locomotor locomotor,string model_name);
		void add_head();
		void add_arm();
		void add_torso();
		void add_locomotor();
		void add_battery();
		void create_robot();
		double get_model_price();
		void test_interface();
		void clean();
};

void Robot::clean()
{
	for(int i; i < 200; i++)
	{
		cout << "\n";
	}
}

void Robot::add_head()
{
	string part_name;
	cout << "Name of Part: ";
	getline(cin,part_name);
	getline(cin,part_name);
	int part_num = list_of_heads.size();
	int weight;
	cout << "Weight of Part [kg/Integer]: ";
	cin >> weight;
	double cost;
	cout << "Price of Part: $";
	cin >> cost;
	string description;
	cout << "Description of Part: ";
	getline(cin,description);
	getline(cin,description);
	Head head(part_name, part_num, weight, cost, description);
	list_of_heads.push_back(head);
	clean();
	test_interface();
}

void Robot::add_arm()
{
	string part_name;
	cout << "Name of Part: ";
	cin >> part_name;
	int part_num = list_of_arms.size();
	int weight;
	cout << "Weight of Part [kg/Integer]: ";
	cin >> weight;
	double cost;
	cout << "Price of part: $";
	cin >> cost;
	int power_usage;
	cout << "Power Consumed by Part [Watts/Integer]: ";
	cin >> power_usage;
	string description;
	cout << "Description of Part: ";
	cin >> description;
	Arm arm(part_name, part_num, weight, cost, power_usage, description);
	list_of_arms.push_back(arm);
	clean();
	test_interface();
}

void Robot::add_torso()
{
	string part_name;
	cout << "Name of Part: ";
	cin >> part_name;
	int part_num = list_of_torsos.size();
	int weight;
	cout << "Weight of Part [kg/Integer]: ";
	cin >> weight;
	double cost;
	cout << "Price of part: $";
	cin >> cost;
	string description;
	cout << "Description of Part: ";
	cin >> description;
	Torso torso(part_name, part_num, weight, cost, description);
	list_of_torsos.push_back(torso);
	clean();
	test_interface();
}

void Robot::add_locomotor()
{
	string part_name;
	cout << "Name of Part: ";
	cin >> part_name;
	int part_num = list_of_locomotors.size();
	int weight;
	cout << "Weight of Part [kg/Integer]: ";
	cin >> weight;
	double cost;
	cout << "Price of part: $";
	cin >> cost;
	int power_consumed;
	cout << "Power Consumed by Part [Watts/Integer]: ";
	cin >> power_consumed;
	int max_speed;
	cout << "Max Speed [MPH/Integer]: ";
	cin >> max_speed;
	string description;
	cout << "Description of Part: ";
	cin >> description;
	Locomotor locomotor(part_name, part_num, weight, cost, power_consumed, max_speed, description);
	list_of_locomotors.push_back(locomotor);
	clean();
	test_interface();
}

void Robot::add_battery()
{
	string part_name;
	cout << "Name of Part: ";
	cin >> part_name;
	int part_num = list_of_batteries.size();
	int power_stored;
	cout << "Amount of Stored Power [killowatt hours/Integer]: ";
	cin >> power_stored;
	int weight;
	cout << "Weight of Part [kg/Integer]: ";
	cin >> weight;
	double cost;
	cout << "Price of part: $";
	cin >> cost;
	string description;
	cout << "Description of Part: ";
	cin >> description;
	Battery battery(part_name, part_num, power_stored, weight, cost, description);
	list_of_batteries.push_back(battery);
	clean();
	test_interface();
}

void Robot::create_robot()
{
	int input_head;
	for(int i = 0; i < list_of_heads.size(); i++)
	{
		cout << list_of_heads[i].to_string();
	}
	cout << "\nSelect a Head [Part #]: ";
	cin >> input_head;
}

void Robot::test_interface()
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
    ************************
    Command: )";
	cout << interface;
	cin >> input;
	if(input == 1)
	{
		clean();
		add_head();
	}
	else if(input == 2)
	{
		clean();
		add_arm();
	}
	else if(input == 3)
	{
		clean();
		add_torso();
	}
	else if(input == 4)
	{
		clean();
		add_locomotor();
	}
	else if(input == 5)
	{
		clean();
		add_battery();
	}
	else if(input == 6)
	{
		clean();
		create_robot();
	}
	else
	{
		exit(0);
	}
}

int main()
{
	Robot test;
    test.test_interface();
	return 0;
}