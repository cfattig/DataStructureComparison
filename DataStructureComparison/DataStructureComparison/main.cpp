#include "Header.h"


int main()
{
	linkedList list;
	char input;
	info tempRecord;
	bool successCheck = true;

	

	do 
	{
		//A simple menu of commands for the user to manipulate data
		cout << "list of commands:" << endl;
		cout << "i - insert" << endl;
		cout << "r - remove" << endl;
		cout << "l - list all records" << endl;
		cout << "f - find" << endl;
		cout << "e - exit program\n" << endl;
		cout << "Enter a command"<< endl;

		cin >> input;
		system("cls");

		switch (input)
		{
			//insert data into data structure
			case 'i':
				tempRecord = fillRecord();
				successCheck = list.insert(tempRecord);
				break;

			//remove data from data structure
			case 'r':
				break;

			//list out all records
			case 'l':
				list.list();
				break;

			//find a record from data structure
			case 'f':
				break;

			//frees up allocated memory and ends the program
			case 'e':
				break;

			default:
				cout << "Invalid option, please enter a command from the list\n" << endl;

		}
		if (!successCheck)
			{
				cout << "An error was encountered and the program will now be safely terminated" << endl;
				input = 'e';
			}

	} while (input != 'e');

	cout << "Program closed successfully" << endl;

	return 0;
}


info fillRecord() {
	info temp;
	
	cout << "Enter the person's first name for the record" << endl;
	cin >> temp.firstName;
	cout << "\nEnter the person's last name for the record" << endl;
	cin >> temp.lastName;
	cout << "\nEnter an age for the record" << endl;
	cin >> temp.age;
	cout << "\nEnter whether the person on record holds a college degree (1=true|0=false)" << endl;
	cin >> temp.degree;
	cout << endl;

	return temp;
}


//overloads == operator so as to be able to compare info stuctures
bool operator==(info left, info right)
{
	if(left.age == right.age && left.degree == right.degree && left.firstName == right.firstName && left.lastName == right.lastName)
		return true;

	return false;
}