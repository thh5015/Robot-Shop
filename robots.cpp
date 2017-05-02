#include "parts.cpp"

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
        float cost;
        float price;
        float outstanding_balance;
        bool paid = false;
        bool obsolete = false;
        int weight;
        string description;
    public:
        Robot(){};
        Robot(Head head, Torso torso, Arm left, Arm right, Locomotor locomotor, vector<Battery> &batteries);
        bool get_paid();
        float get_price();
        string get_name();
        float get_outstanding_balance();
        void set_info();
        void set_obsolete();
        bool get_obsolete();
        void pay_amount(float amount);
        void ispaid();
        string to_string();
        void save(ostream& ost); 
        void load(istream& ist);
};

Robot::Robot(Head head, Torso torso, Arm left, Arm right, Locomotor locomotor, vector<Battery> &batteries)
{
    this->head = head;
    this->torso = torso;
    this->left = left;
    this->right = right;
    this->locomotor = locomotor;
    float cost = head.get_cost() + torso.get_cost() + left.get_cost() + right.get_cost() + locomotor.get_cost();
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

bool Robot::get_obsolete()
{
  return obsolete;
}

void Robot::set_info()
{
	stringstream temp;
	temp << "Production cost of robot: $" 
       << cost
       << "\nPrice of Robot[$]:";
	string name{fl_input("Please enter a name for the robot:",0)};
	string model_num{fl_input("Please enter a model number:",0)};
	string price{fl_input((temp.str()).c_str(),0)};
	string description{fl_input("Please enter a description for the model:",0)};
	this->name = name.c_str();
	this->model_num = atoi(model_num.c_str());
  this->price = atof(price.c_str());
  this->outstanding_balance = this->price;
  this->description = description.c_str();
}

void Robot::set_obsolete()
{
  obsolete = true;
}

void Robot::pay_amount(float amount)
{
  outstanding_balance = outstanding_balance - amount;
}

void Robot::ispaid()
{
  paid = true;
}

float Robot::get_price()
{
    return price;
}

float Robot::get_outstanding_balance()
{
  return outstanding_balance;
}

string Robot::get_name()
{
    return name;
}

bool Robot::get_paid()
{
  return paid;
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

void Robot::save(ostream& ost)
{
  ost << name << endl
      << model_num << endl
      << cost << endl
      << price << endl
      << outstanding_balance << endl
      << paid << endl
      << obsolete << endl
      << weight << endl
      << description << endl;
  head.save(ost);
  torso.save(ost);
  left.save(ost);
  right.save(ost);
  locomotor.save(ost);
  for(int i = 0; i < batteries.size(); i++)
  {
    batteries[i].save(ost);
  }
}

void Robot::load(istream& ist)
{
  string temp;
  getline(ist,temp);
  name = temp.c_str();
  getline(ist,temp);
  model_num = atoi(temp.c_str());
  getline(ist,temp);
  cost = atof(temp.c_str());
  getline(ist,temp);
  price = atof(temp.c_str());
  getline(ist,temp);
  outstanding_balance = atof(temp.c_str());
  getline(ist,temp);
  if(temp == "true")
  {
    paid = true;
  }
  if(temp == "false")
  {
    paid = false;
  }
  getline(ist,temp);
  if(temp == "true")
  {
    obsolete = true;
  }
  if(temp == "false")
  {
    obsolete = false;
  }
  getline(ist,temp);
  weight = atoi(temp.c_str());
  getline(ist,temp);
  description = temp.c_str();
  head.load(ist);
  torso.load(ist);
  left.load(ist);
  right.load(ist);
  locomotor.load(ist);
  for(int i = 0; i < torso.get_compartments(); i++)
  {
    Battery b;
    b.load(ist);
    batteries.push_back(b);
  }
}