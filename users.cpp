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
        to_string << robots[i].to_string()
       			  << "\n\n";
    }
    return to_string.str();
}