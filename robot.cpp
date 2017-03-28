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
	to_string << "#" << part_num << " " << part_name << "\nWeight: " << weight << " kg\nCost: $" << cost << "\nDescription: " << description << "\n\n";
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
		string to_string();
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

string Arm::to_string()
{
	stringstream to_string;
	to_string << "#" << part_num << " " << part_name << "\nWeight: " << weight << " kg\nPower Consumed by Part[watts]: " << power_usage << "\nCost: $" << cost << "\nDescription: " << description << "\n\n";
	return to_string.str();
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
		int get_weight();
		string to_string();
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

int Battery::get_weight()
{
	return weight;
}

string Battery::to_string()
{
	stringstream to_string;
	to_string << "#" << part_num << " " << part_name << "\nWeight: " << weight << " kg\nPower Avaliable: " << power_stored << "\nCost: $" << cost << "\nDescription: " << description << "\n\n";
	return to_string.str();
}

class Torso
{
	protected:
		string part_name;
		int part_num;
		int weight;
		int battery_num;
		int count;
		double cost;
		vector<Battery> batteries;
		string description;
	public:
		Torso(string part_name, int part_num, int weight, int battery_num, double cost, string description);
		void add_battery(Battery battery);
		int get_total_power();
		double get_total_cost();
		int get_total_weight();	
		string to_string();
};

Torso::Torso(string part_name, int part_num, int weight, int battery_num, double cost, string description)
{
	this->part_name = part_name;
	this->part_num = part_num;
	this->weight = weight;
	this->battery_num = battery_num;
	this->cost = cost;
	this->description = description;
	count = 0;
}

void Torso::add_battery(Battery battery)
{
	if(count <= battery_num)
	{
		batteries.push_back(battery);
		count++;
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

int Torso::get_total_weight()
{
	int total_weight;
	for(int i = 0; i < batteries.size(); i++)
	{
		total_weight = total_weight + batteries[i].get_weight();
	}
	total_weight = total_weight + weight;
	return total_weight;
}

string Torso::to_string()
{
	stringstream to_string;
	to_string << "#" << part_num << " " << part_name << "\nWeight: " << weight << " kg\n# of Battery Compartments: " << battery_num << "\nCost: $" << cost << "\nDescription: " << description << "\n\n";
	return to_string.str();
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
		string to_string();
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

string Locomotor::to_string()
{
	stringstream to_string;
	to_string << "#" << part_num << " " << part_name << "\nWeight: " << weight << " kg\nPower Consumed by Part[watts]: " << power_consumed << "\nMax Speed: " << max_speed << " mph" <<"\nCost: $" << cost << "\nDescription: " << description << "\n\n";
	return to_string.str();
}

/////////////////////
//		Robot	   //
/////////////////////

class Robot: public Head, public Arm, public Torso, public Locomotor
{
	protected:
		int model_number;
		string model_name;
		double model_price;
		Head head;
		Torso torso;
		Arm arm_left;
		Arm arm_right;
		Locomotor locomotor;
	public:
		Robot(Head head, Torso torso, Arm left, Arm Right,Locomotor locomotor,string model_name);
		double get_model_price();
		void test_interface();
		void clean();
};

Robot::Robot(Head head, Torso torso, Arm left, Arm Right,Locomotor locomotor,string model_name)
{
	this->head = head;
	this->torso = torso;
	this->arm_left = left;
	this->arm_right = right;
	this->locomotor = locomotor;
	this->model_name = model_name;
}

/////////////////////
//		System	   //
/////////////////////

class System
{
	private:
		vector<Robot> list_of_robots;
		vector<Head> list_of_heads;
		vector<Arm> list_of_arms;
		vector<Torso> list_of_torsos;
		vector<Locomotor> list_of_locomotors;
		vector<Battery> list_of_batteries;
	public:
		void add_head();
		void add_arm();
		void add_torso();
		void add_locomotor();
		void add_battery();
		void create_robot();
		void test_interface();
		void clean();
};

void System::test_interface()
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

void System::create_robot()
{
	int input_head;
	if(list_of_heads.size() == 0)
	{
		clean();
		cout << "NO HEADS AVALIABLE!\n";
		test_interface();
	}
	else
	{
		for(int i = 0; i < list_of_heads.size(); i++)
		{
			cout << list_of_heads[i].to_string();
		}
	}
	cout << "\nSelect a Head [Part #]: ";
	cin >> input_head;
	clean();

	int input_torso;
	if(list_of_torsos.size() == 0)
	{
		clean();
		cout << "NO TORSOS AVALIABLE!\n";
		test_interface();
	}
	else
	{
		for(int i = 0; i < list_of_torsos.size(); i++)
		{
			cout << list_of_torsos[i].to_string();
		}
	}
	cout << "\nSelect a Torso [Part#]";
	cin >> input_torso;
	clean();

	int input_batteries[3];
	int size = sizeof(input_batteries)/4;
	if(list_of_batteries.size() == 0)
	{
		clean();
		cout << "NO BATTERIES AVALIABLE!\n";
		test_interface();
	}
	else
	{
		for(int i = 0; i < size; i++)
		{
			for(int x = 0; x < list_of_batteries.size(); x++)
			{
				cout << list_of_batteries[x].to_string();
			}
			cout << "\nSelect Battery [#" << (i+1) << "]: ";
			cin >> input_batteries[i];
		}
	}

	int input_left_arm;
	if(list_of_arms.size() == 0)
	{
		clean();
		cout << "NO ARMS AVALIABLE";
		test_interface();
	}
	else
	{
		for(int i = 0; i < list_of_arms.size(); i++)
		{
			cout << list_of_arms[i].to_string();
		}
	}
	cout << "\nSelect a Left Arm [Part #]: ";
	cin >> input_left_arm;
	clean();

	int input_right_arm;
	if(list_of_arms.size() == 0)
	{
		clean();
		cout << "NO ARMS AVALIABLE";
		test_interface();
	}
	else
	{
		for(int i = 0; i < list_of_arms.size(); i++)
		{
			cout << list_of_arms[i].to_string();
		}
	}
	cout << "\nSelect a Right Arm [Part #]: ";
	cin >> input_right_arm;
	clean();

	int input_locomotor;
	if(list_of_locomotors.size() == 0)
	{
		clean();
		cout << "NO LOCOMOTORS AVALIABLE!";
		test_interface();
	}
	else
	{
		for(int i = 0; i < list_of_locomotors.size(); i++)
		{
			cout << list_of_locomotors[i].to_string();
		}
	}
	cout << "\nSelect a Locomotor: ";
	cin >> input_locomotor;
	clean();

	string model_name;
	cout << "Model Name: ";
	getline(cin,model_name);
	getline(cin,model_name);

	//Robot(list_of_heads[input_head], list_of_torsos[input_torso], list_of_arms[input_left_arm], list_of_arms[input_right_arm], list_of_locomotors[input_locomotor],model_name)
	
	clean();
	test_interface();
}

void System::clean()
{
	for(int i; i < 200; i++)
	{
		cout << "\n";
	}
}

void System::add_head()
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
	cout << "";
	clean();
	test_interface();
}

void System::add_arm()
{
	string part_name;
	cout << "Name of Part: ";
	getline(cin,part_name);
	getline(cin,part_name);
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
	getline(cin,description);
	getline(cin,description);
	Arm arm(part_name, part_num, weight, cost, power_usage, description);
	list_of_arms.push_back(arm);
	clean();
	test_interface();
}

void System::add_torso()
{
	string part_name;
	cout << "Name of Part: ";
	getline(cin,part_name);
	getline(cin,part_name);
	int part_num = list_of_torsos.size();
	int weight;
	cout << "Weight of Part [kg/Integer]: ";
	cin >> weight;
	int battery_num;
	cout << "Number of Battery Compartments: ";
	cin >> battery_num;
	double cost;
	cout << "Price of part: $";
	cin >> cost;
	string description;
	cout << "Description of Part: ";
	getline(cin,description);
	getline(cin,description);
	Torso torso(part_name, part_num, weight, battery_num, cost, description);
	list_of_torsos.push_back(torso);
	clean();
	test_interface();
}

void System::add_locomotor()
{
	string part_name;
	cout << "Name of Part: ";
	getline(cin,part_name);
	getline(cin,part_name);
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
	getline(cin,description);
	getline(cin,description);
	Locomotor locomotor(part_name, part_num, weight, cost, power_consumed, max_speed, description);
	list_of_locomotors.push_back(locomotor);
	clean();
	test_interface();
}

void System::add_battery()
{
	string part_name;
	cout << "Name of Part: ";
	getline(cin,part_name);
	getline(cin,part_name);
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
	getline(cin,description);
	getline(cin,description);
	Battery battery(part_name, part_num, power_stored, weight, cost, description);
	list_of_batteries.push_back(battery);
	clean();
	test_interface();
}

int main()
{
	System test;
    test.test_interface();
	return 0;
}