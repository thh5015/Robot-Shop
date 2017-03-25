#include <iostream>
#include <string.h>
#include <vector>
#include "robot.cpp"
using namespace std;

///////////////////////////////
//			System		     //
///////////////////////////////
class System
{
	private:
		//vector<Product_Manager> pm;
		//vector<Sales_Associate> sa;
		//vector<Customer> customer;
		//vector<Boss> boss;
		//Product_Manager curr_pm;
		//Customer curr_customer;
		//Sales_Associate curr_sa;
		//Boss curr_boss; 
	public: 
		void clean();
		void startup();
		void login();
		void signup();
		void pm_screen();
		void sa_screen();
		void customer_screen();
		void boss_screen();
};

void System::clean()
{
	for(int i = 0; i < 250; i++)
	{
		cout << "\n";
	}
}

void System::pm_screen()
{
	int input;
	string pm_page = R"(
    **************************
    *   LIST OF FUNCTIONS    *
    *                        *
    *   0) Log off           *
    *   1) Create Robot      *
    *   2) Delete Robot      *
    **************************
    Input User: )";
	cout << pm_page;
	cin >> input;
	if(input == 0)
	{
		exit(0);
	}
	else if(input == 1)
	{
		clean();
	}
	else if(input == 2)
	{
		clean();
	}
	else
	{
		cout << "Error: Not a Function!";
	}
}

void System::customer_screen()
{
	int input;
	string customer_page = R"(
    ****************************
    *   LIST OF FUNCTIONS      *
    *                          *
    *   0) Log off             *
    *   1) Browse Catalog      *
    *   2) View Orders/        *
    *      Outstanding Balance *
    ****************************
    Input User: )";
	cout << customer_page;
	cin >> input;
	if(input == 0)
	{
		exit(0);
	}
	else if(input == 1)
	{
		clean();
	}
	else if(input == 2)
	{
		clean();
	}
	else
	{
		cout << "Error: Not a Function!";
	}
}

void System::sa_screen()
{
	int input;
	string sa_page = R"(
    ****************************
    *   LIST OF FUNCTIONS      *
    *                          *
    *   0) Log off             *
    *   1) Order Robot         *
    *   2) View Bill of Sales  *
    *   3) View Sales Report   *
    *   4) Lobby for Raise     *
    ****************************
    Input User: )";
	cout << sa_page;
	cin >> input;
	if(input == 0)
	{
		exit(0);
	}
	else if(input == 1)
	{
		clean();
	}
	else if(input == 2)
	{
		clean();
	}
	else if(input == 3)
	{
		clean();
	}
	else if(input == 4)
	{
		clean();
	}
	else
	{
		cout << "Error: Not a Function!";
	}
}

void System::boss_screen()
{
	int input;
	string boss_page = R"(
    ****************************
    *   LIST OF FUNCTIONS      *
    *                          *
    *   0) Log off             *
    *   1) View Profit Margin  *
    *   2) List of Orders Sold *
    *   3) View All Sales      *
    *   4) Raise Requests      *
    ****************************
    Input User: )";
	cout << boss_page;
	cin >> input;
	if(input == 0)
	{
		exit(0);
	}
	else if(input == 1)
	{
		clean();
	}
	else if(input == 2)
	{
		clean();
	}
	else if(input == 3)
	{
		clean();
	}
	else if(input == 4)
	{
		clean();
	}
	else
	{
		cout << "Error: Not a Function!";
	}
}

void System::signup()
{
	int input;
	string signup_page = R"(
    **************************
    *      LIST OF USERS     *
    *                        *
    *   0) Go Back           *
    *   1) Project Manager   *
    *   2) Customer          *
    *   3) Sales Associate   *
    *   4) Boss              *
    **************************
    Input User: )";
	cout << signup_page;
	cin >> input;
	if(input == 0)
	{
		clean();
		startup();
	}
	else if(input == 1)
	{
		clean();
		//create_pm();
		pm_screen();
	}
	else if(input == 2)
	{
		clean();
		//create_customer();
		customer_screen();
	}
	else if(input == 3)
	{
		clean();
		//create_sa();
		sa_screen();
	}
	else if(input == 4)
	{
		clean();
		//create_boss();
		boss_screen();
	}
	else
	{
		cout << "Error: No User of this Type Found!";
	}
}

void System::login()
{
	int user;
	string name;
	string password;
	cout << R"(
    #1             #2         #3          #4 
[ Customer, Project Manager, Boss, Sales Associate ]

Choose the user # that you wish to login as: )";
	cin >> user;
	cout << "Username: ";
	cin >> name;
	cout << "Password: ";
	cin >> password;
	//check_login(user);
}

void System::startup()
{
	int input;
	string startup_page = R"(
    **************************
    *         WELCOME!       *
    *                        *
    *   0) Exit              *
    *   1) Login             *
    *   2) Signup            *
    **************************
    Input User: )";
	cout << startup_page;
	cin >> input;
	if(input == 0)
	{
		exit(0);
	}
	else if(input == 1)
	{
		clean();
		login();
	}
	else if(input == 2)
	{
		clean();
		signup();
	}
	else
	{
		cout << "Error: Command Not Found!";
	}
}

////////////////////
//		Main      //
////////////////////

int main()
{
	System win;
	win.startup();
	return 0;
}