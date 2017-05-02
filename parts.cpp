#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Menu_Bar.H>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include <fstream>
using namespace std;

/////////////////////
//       Parts     //
/////////////////////

class Parts
{
	public:
		void create_part();
    float get_cost();
    int get_weight();
	protected:
		string name;
		int part_num;
		float cost;
		int weight;
		string description;
};

void Parts::create_part()
{
  string name{fl_input("Please Enter a Name for this Part:",0)};
  string part_num{fl_input("Please Enter a Part #:",0)};
  string cost{fl_input("Please enter a Cost[$]: ",0)};
  string weight{fl_input("Please Enter a weight[kg]:",0)};
  string description{fl_input("Please Enter a description:",0)};
  this->name = name.c_str();
  this->part_num = atoi(part_num.c_str());
  this->cost = atof(cost.c_str());
  this->weight = atoi(weight.c_str());
  this->description = description.c_str();
}

float Parts::get_cost()
{
    return cost;
}

int Parts::get_weight()
{
    return weight;
}

//////////////////
//     Head     //
//////////////////

class Head: public Parts
{
    public:
        void create_head();
        void save(ostream& ost); 
        void load(istream& ist);
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

void Head::save(ostream& ost)
{
  ost << name << endl
      << part_num << endl
      << cost << endl
      << weight << endl
      << description << endl;
}

void Head::load(istream& ist)
{
  string temp;
  getline(ist,temp);
  name = temp.c_str();
  getline(ist,temp);
  part_num = atoi(temp.c_str());
  getline(ist,temp);
  cost = atof(temp.c_str());
  getline(ist,temp);
  weight = atoi(temp.c_str());
  getline(ist,temp);
  description = temp.c_str();
}

////////////////////
//      Torso     //
////////////////////

class Torso: public Parts
{
    public:
        void create_torso();
        int get_compartments();
        string to_string();
        void save(ostream& ost); 
        void load(istream& ist);
    protected:
        int compartments;
};

void Torso::create_torso()
{
    create_part();
    string compartments{fl_input("Please Enter the # of Battery Compartment:",0)};
    this->compartments = atoi(compartments.c_str());
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

void Torso::save(ostream& ost)
{
  ost << name << endl
      << part_num << endl
      << cost << endl
      << weight << endl
      << description << endl
      << compartments << endl;
}

void Torso::load(istream& ist)
{
  string temp;
  getline(ist,temp);
  name = temp.c_str();
  getline(ist,temp);
  part_num = atoi(temp.c_str());
  getline(ist,temp);
  cost = atof(temp.c_str());
  getline(ist,temp);
  weight = atoi(temp.c_str());
  getline(ist,temp);
  description = temp.c_str();
  getline(ist,temp);
  compartments = atoi(temp.c_str());
}

///////////////////
//    Battery    //
///////////////////

class Battery: public Parts
{
    public:
        void create_battery();
        int get_energy_contained();
        string to_string();
        void save(ostream& ost); 
        void load(istream& ist);
    protected:
        int energy_contained;
};

void Battery::create_battery()
{
    create_part();
    string energy_contained{fl_input("Please enter the amount of energy it contains[Kilowatts/Hour]:",0)};
    this->energy_contained = atoi(energy_contained.c_str());
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

void Battery::save(ostream& ost)
{
  ost << name << endl
      << part_num << endl
      << cost << endl
      << weight << endl
      << description << endl
      << energy_contained << endl;
}

void Battery::load(istream& ist)
{
  string temp;
  getline(ist,temp);
  name = temp.c_str();
  getline(ist,temp);
  part_num = atoi(temp.c_str());
  getline(ist,temp);
  cost = atof(temp.c_str());
  getline(ist,temp);
  weight = atoi(temp.c_str());
  getline(ist,temp);
  description = temp.c_str();
  getline(ist,temp);
  energy_contained = atoi(temp.c_str());
}

//////////////////////
//        Arm       //
//////////////////////

class Arm: public Parts
{
    public:
        void create_arm();
        int get_energy_consumed();
        string to_string();
        void save(ostream& ost); 
        void load(istream& ist);
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
    string energy_consumed{fl_input("Please enter the amount of energy it consumes[Watts]:",0)};
    this->energy_consumed = atoi(energy_consumed.c_str());
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

void Arm::save(ostream& ost)
{
  ost << name << endl
      << part_num << endl
      << cost << endl
      << weight << endl
      << description << endl
      << energy_consumed << endl;
}

void Arm::load(istream& ist)
{
  string temp;
  getline(ist,temp);
  name = temp.c_str();
  getline(ist,temp);
  part_num = atoi(temp.c_str());
  getline(ist,temp);
  cost = atof(temp.c_str());
  getline(ist,temp);
  weight = atoi(temp.c_str());
  getline(ist,temp);
  description = temp.c_str();
  getline(ist,temp);
  energy_consumed = atoi(temp.c_str());
}

/////////////////////////
//       Locomotor     //
/////////////////////////

class Locomotor: public Parts
{
    public:
        void create_locomotor();
        int get_energy_consumed();
        string to_string();
        void save(ostream& ost); 
        void load(istream& ist);
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
    string speed{fl_input("Please enter the speed of the locomotor[MPH]:",0)};
    this->speed = atoi(speed.c_str());
    string energy_consumed{fl_input("Please enter the amount of energy it consumes[Watts]:",0)};
    this->energy_consumed = atoi(energy_consumed.c_str());
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

void Locomotor::save(ostream& ost)
{
  ost << name << endl
      << part_num << endl
      << cost << endl
      << weight << endl
      << description << endl
      << speed << endl
      << energy_consumed << endl;
}

void Locomotor::load(istream& ist)
{
  string temp;
  getline(ist,temp);
  name = temp.c_str();
  getline(ist,temp);
  part_num = atoi(temp.c_str());
  getline(ist,temp);
  cost = atof(temp.c_str());
  getline(ist,temp);
  weight = atoi(temp.c_str());
  getline(ist,temp);
  description = temp.c_str();
  getline(ist,temp);
  speed = atoi(temp.c_str());
  getline(ist,temp);
  energy_consumed = atoi(temp.c_str());
}