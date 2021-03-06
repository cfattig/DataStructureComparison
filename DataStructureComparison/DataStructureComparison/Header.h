#pragma once
#include <iostream>
#include <string>

using namespace std;

struct info 
{
	string	firstName;
	string	lastName;
	int		age;
	bool	degree;
};


struct linkedListNode 
{
	info record;
	linkedListNode *last;
	linkedListNode *next;
};

class linkedList 
{

public:
	linkedList();
	~linkedList();
	//info find(string firstName);
	//info find(string lastName);
	//info find(int age);
	//info find(bool degree);
	bool insert(info record);
	bool remove(info record);
	//bool modify(info record);
	//bool isEmpty();
	void print(info record);
	//bool sort();
	//bool scramble();
	void list();


private:
	linkedListNode *headptr;
	linkedListNode *tailptr;
};

info fillRecord();
bool operator==(info left, info right);