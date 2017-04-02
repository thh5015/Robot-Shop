#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Parts
{
	public:
		enum Type{head,torso,battery,arm,locomotor};
		void create_part();
	protected:
		string name;
		int part_num;
		Type type;
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
    cout << "Description: ";
    getline(cin,description);
    getline(cin,description);
    cout << "Please Enter a weight[Kg]: ";
    cin >> weight;
    cout << "Please Enter a Cost: $";
    cin >> cost;
}

class Head: public Parts
{
    public:
        void create_head(); 
    protected: 
};

void Head::create_head()
{
	type = head;
	create_part();
}

class Torso: public Parts
{
    private:
        int compartments;
    public:
		void create_torso();
};

void Torso::create_torso()
{

}




int main()
{

	return 0;
}