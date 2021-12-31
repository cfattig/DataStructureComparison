#include "Header.h"


int main()
{
	linkedList list;
	char input;

	

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
