#include "Header.h"


int main()
{
	linkedList list;
	char input;
	info tempRecord;
	bool successCheck = true;

	

	do 
	{
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
			case 'i':
				cout << "Enter a name for the record" << endl;
				cin >> tempRecord.name;
				cout << "\nEnter an age for the record" << endl;
				cin >> tempRecord.age;
				cout << "\nEnter whether the person on record holds a college degree (1=true|0=false)" << endl;
				cin >> tempRecord.degree;
				cout << endl;

				successCheck = list.insert(tempRecord);
				break;
			case 'r':
				break;
			case 'l':
				list.list();
				break;
			case 'f':
				break;
			case 'e':
				break;
			default:
				cout << "Invalid option, please enter a command from the list\n" << endl;

		}
		

	} while (input != 'e');

	cout << "Program closed successfully" << endl;

	return 0;
}
