#include "Header.h"

linkedList::linkedList()
{
	headptr = nullptr;
	tailptr = nullptr;
}


linkedList::~linkedList() 
{
	linkedListNode *prev;
	linkedListNode *curr = headptr;
	
	//empty case
	if (headptr == nullptr)
		return;

	//not empty case
	while (curr != nullptr)
	{
		prev = curr;
		curr = curr->next;
		delete prev;
		return;
	}
}


void linkedList::list() 
{
	linkedListNode *tempptr = headptr;

	if (headptr == nullptr)
	{
		cout << "The linked list is empty\n" << endl;
		return;
	}

	while (tempptr != nullptr)
	{
		print(tempptr->record);
		tempptr = tempptr->next;
	}
	return;
}


void linkedList::print(info record) 
{
	cout << "Name: " << record.name << endl;
	cout << "Age: " << record.age << endl;
	cout << "College Degree: " << record.degree << endl << endl;
	return;
}


