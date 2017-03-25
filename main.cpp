#include <iostream>
#include <string.h>
using namespace std;

class System
{
	private:

	public: 
		void login();
};

void System::login()
{
	int input;
	string log_page = R"(
	**************************
	*	   LIST OF USERS	 *
	*						 *
	*	0) Log off			 *
	*	1) Project Manager	 *
	*	2) Customer			 *
	*	3) Sales Associate   *
	*	4) Boss				 *
	**************************
	Input User: )";
	cout << log_page;
	cin >> input;
	if(input == 0)
	{
		exit(0);
	}
	else if(input == 1)
	{

	}
	else if(input == 2)
	{

	}
	else if(input == 3)
	{

	}
	else if(input == 4)
	{

	}
	else
	{
		cout << "Error: No User Located!";
	}
}

int main()
{
	System win();
	win.login();
	return 0;
}