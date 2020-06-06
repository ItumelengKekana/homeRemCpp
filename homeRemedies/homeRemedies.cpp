// homeRemedies.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <ctime>


using namespace std;

char str[26];
time_t result = time(NULL);

class User
{
	private:
		string name, remedy;

	public: 
		User();
		void setValues(string);
		void setRem(string);
		string getName() { return name; };
		string getRem() { return remedy; };
};

User::User()
{
	name = " ";
	remedy = " ";
}

void User::setValues(string nm)
{
	name = nm;
}

void User::setRem(string rm)
{
	remedy = rm;
}

void login(User& usr)
{	
	string nm;

	cout << "Enter your username: ";
	cin >> nm;

	usr.setValues(nm);
}

int menu(User usr)
{
	int num;

	cout << "Welcome " << usr.getName() << endl;
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

string search(int num, User& usr)
{
	string name, remedy;

	switch (num)
	{
	case 1:
		name = "Cold.txt";
		remedy = "Common cold remedy";
		break;
	case 2:
		name = "headache.txt";
		remedy = "Headache remedy";
		break;
	case 3:
		name = "back.txt";
		remedy = "Sore back remedy";
		break;
	case 4:
		name = "throat.txt";
		remedy = "Sore throat remedy";
		break;
	case 5:
		cout << "Goodbye!" << endl;
		break;
	default:
		cout << "Please enter a valid option";
		break;
	}

	usr.setRem(remedy);
	return name;
}

void getProd(string fname)
{
	ifstream inFile(fname.c_str());
	string line, product;

	if (!inFile)
	{
		cout << "File could not open. Please check if it exists";
	}
	else
	{
		while (getline(inFile, line))
		{
			product = line;
			cout << product;
			cout << '\n';
		}

		
	}
}

void logHistory(User usr)
{
	string fname = "log.txt";
	ofstream outFile;
	ctime_s(str, sizeof str, &result);

	outFile.open(fname.c_str(), ios_base::app);

	if (outFile.fail())
	{
		cout << "The session was not logged";
	}
	else
	{
		outFile << usr.getName() << " Searched for " << usr.getRem() << " on " << str << endl;
		outFile.close();
		cout << "\n\nSession logged!" << endl;
	}
}

void display(User usr)
{
	int option;
	string file;

	login(usr);

	do {
		option = menu(usr);
		file = search(option, usr);
		getProd(file);
		logHistory(usr);
	} while (option != 5);
}


int main()
{
	User person;
	
	display(person);

	system("Pause");
	return 0;

}

