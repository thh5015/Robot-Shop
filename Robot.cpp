#include <iostream>
#include <string>
using namespace std;

class RobotPart
{
    private:
        string namee;
        int model_number;
        double cost;
	    double weight;
        string description;
        static string image_filename;
        static int type;
    public:
	   void makepart();
};

void RobotPart::makepart(){
    cout << "Please Enter a Name for the Part: ";
    cin >> namee;
    cout << "Model Number: ";
    cin >> model_number;
    cout << "Description: ";
    cin >> description;
    cout << "Please Enter a weight(In Pounds): ";
    cin >> weight;
    cout << "Please Enter a Cost: ";
    cin >> cost;

}

class head: public RobotPart{
    private:
        double power;  
    public:
        void set_power();  
};

void head::set_power(){
    cout << "Please Enter Power in Watts: ";
    cin >> power;
};

class torso: public RobotPart{
    private:
        int battery_compartments;
        int max_arms;
    public:
	void set_battery_arms();
};

void torso::set_battery_arms(){
	cout << "Please Enter Battery Compartments (Up To 3): ";
	cin >> battery_compartments;
	cout << "Please Enter Max Arms: ";
	cin >> max_arms;
}

class battery: public RobotPart{
    private:
        double max_power; 
    public:
	void set_power(); 
};

void battery::set_power(){
	cout << "Please Enter power contained: ";
	cin >> max_power;

}

class locomotor: public RobotPart{
    private:
        double max_power; // In mph
    public:
	void set_max_speed();
};

void locomotor::set_max_speed(){
	cout << "Please Enter Max Speed (in MPH): ";
	cin >> max_power;
}

class arm: public RobotPart{
    private:
	double max_power;
    public:
	void set_power_consumed();
};
void arm::set_power_consumed(){
	cout << "Please set the power consumed: ";
	cin >> max_power;

}

int main()
{
    int i;
while (i != 6){
    cout << "\n What Part Would You Like to Create? \n 1) Head \n 2) Torso \n 3) Battery \n 4) Locomotor \n 5) Arm \n 6) Exit \n\n ";
    cin >> i;
    cout << "\n\n";
if (i == 1){
    head newrobotpart;
    newrobotpart.makepart();
    newrobotpart.set_power();
};
if (i == 2){
    torso newrobotpart;
    newrobotpart.makepart();
    newrobotpart.set_battery_arms();
};
if (i == 3){
    battery newrobotpart;
    newrobotpart.makepart();
    newrobotpart.set_power();
};
if (i == 4){
    locomotor newrobotpart;
    newrobotpart.makepart();
    newrobotpart.set_max_speed();
};
if (i == 5){
    arm newrobotpart;
    newrobotpart.makepart();
    newrobotpart.set_power_consumed();    
};
}
}




