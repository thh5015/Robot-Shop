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
        int weight;
        string description;
    public:
        Robot(Head head, Torso torso, Arm left, Arm right, Locomotor locomotor, vector<Battery> &batteries);
        float get_price();
        string get_name();
        void set_info();
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

void Robot::set_info()
{
	stringstream temp;
	temp << "Production cost of robot: $" << cost
         << "\nPrice of Robot[$]:";
	string name{fl_input("Please enter a name for the robot:",0)};
	string model_num{fl_input("Please enter a model number:",0)};
	string cost{fl_input((temp.str()).c_str(),0)};
	string description{fl_input("Please enter a description for the model:",0)};
	this->name = name.c_str();
	this->model_num = atoi(model_num.c_str());
    this->cost = atof(cost.c_str());
    this->description = description.c_str();
}

float Robot::get_price()
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

void Robot::save(ostream& ost)
{
  ost << name << endl
      << model_num << endl
      << cost << endl
      << price << endl
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
  weight = atoi(temp.c_str());
  getline(ist,temp);
  description = temp.c_str();
  head.load(ist);
  torso.load(ist);
  right.load(ist);
  locomotor.load(ist);
  for(int i = 0; i < torso.get_compartments(); i++)
  {
    batteries[i].load(ist);
  }
}