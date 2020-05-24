// homeRemedies.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <ctime>

using namespace std;

class User
{
	protected:
		string name, email, password;
		string products[4];

	public: 
		User();
		void setValues(string, string, string);
		string getName() { return name; };
		string getPass() { return password; };
		string getEmail() { return email; };
		void login();
		void getProd(string, int);
		void logHistory(int);
		string search(int);
		int menu();
		void display();

};

User::User()
{
	name = " ";
	email = " ";
	password = " ";
}

void User::setValues(string nm, string em, string pass)
{
	nm = name;
	em = email;
	pass = password;
}

void User::login()
{	
	User usr;
	string nm, em, pass;

	cout << "Enter your username: ";
	cin >> nm;
	cout << "Enter your email: ";
	cin >> em;
	cout << "Enter your password: ";
	cin >> pass;

	usr.setValues(nm, em, pass);

	cout << "Welcome" << usr.getName() << endl;
}

void User::getProd(string fname, int val)
{
	ifstream inFile(fname.c_str());
	string line;

	if (!inFile)
	{
		cout << "File could not open. Please check if it exists";
	}
	else
	{
		while (getline(inFile, line))
		{
			for (int x = 0; x < 4; x++)
			{
				products[val] = line;
			}
		}

		for (int x = 0; x < 4; x++)
		{
			cout << products[val];
		}
	}
}

string User::search(int num)
{
	string name;

	switch (num)
	{
	case 1: 
		name = "Cold.txt";
		break;
	case 2: 
		name = "headache.txt";
		break;
	case 3:
		name = "back.txt";
		break;
	case 4:
		name = "throat.txt";
		break;
	case 5: 
		break;
	default:
		cout << "Please enter a valid option";
		break;
	}

	return name;
}

int User::menu()
{
	int num;
	User usr;


	cout << "\nHome Remedy Menu: " << endl
		<< "====================================" << endl
		<< "What ails you at this moment?\n" << endl
		<< "1. Common Cold" << endl
		<< "2. Headache" << endl
		<< "3. Sore back" << endl
		<< "4. Sore Throat" << endl
		<< "5. Exit............" << endl << endl;
	cin >> num;

	return num;
}

void User::logHistory(int op)
{
	User usr;
	string fname = "log.txt";
	ofstream outFile;

	/*time_t tt;
	struct tm * ti;
	time(&tt);
	ti = localtime(&tt);*/

	outFile.open(fname.c_str());

	if (outFile.fail())
	{
		cout << "The session was not successfully logged!";
	}
	else
	{
		outFile << usr.getName() << " Searched for " << usr.search(op) << " on " << /*asctime(ti)*/ endl;
		outFile.close();
		cout << "Session logged!" << endl;
	}
}

void User::display()
{
	User usr;
	int option;
	string file;

	usr.login();
	option = usr.menu();
	file = usr.search(option);
	usr.getProd(file, option);
	usr.logHistory(option);

}


int main()
{
	User person;
	
	person.display();

	system("Pause");
	return 0;

}

