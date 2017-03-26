#include <iostream>
#include <string.h>
#include <vector>
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
};

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
		Arm(int part_num, int weight, double cost, int power_usage, string description);

};

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
};

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

/////////////////////
//		Robot	   //
/////////////////////

class Robot: public Head, public Arm, public Torso, public Locomotor
{
	protected:
		vector<Head> list_of_heads;
		vector<Arm> list_of_arms;
		vector<Torso> list_of_torsos;
		vector<Locomotor> list_of_locomotors;
		vector<Battery> list_of_batteries;
		Head head;
		Arm left;
		Arm right;
		Torso torso;
		Locomotor locomotor;
		int model_number;
		string model_name;
		double model_price;
	public:
		Robot();
		Robot(Head head, Torso torso, Arm left, Arm Right,Locomotor locomotor,string model_name);
		void define_parts();
		double get_model_price();
};

void Robot::define_parts()
{

}

int main()
{
	Robot test;
	test.define_parts();
	return 0;
}