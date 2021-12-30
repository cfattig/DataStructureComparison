#pragma once
#include <iostream>
#include <string>

using namespace std;


struct info {
	string	name;
	int		age;
	bool	degree;
};


struct linkedListNode {
	info record;
	linkedListNode *prev;
	linkedListNode *next;
};

class linkedList {

public:
	//linkedList();
	//~linkedList();
	//info find(string name);
	//info find(int age);
	//info find(bool degree);
	//bool insert(info record);
	//bool remove(info record);
	//bool modify(info record);
	//bool isEmpty();
	//void print(info record);
	//void list();


private:
	linkedListNode *headptr;
	linkedListNode *tailptr;
};