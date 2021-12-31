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


bool linkedList::insert(info record)
{
	linkedListNode *prev;
	linkedListNode *curr = headptr;

	//empty case
	if (headptr == nullptr)
	{
		headptr = new (nothrow) linkedListNode;
		if (headptr == nullptr)
		{
			cout << "Memory allocation error. Terminating program." << endl;
			return false;
		}

		tailptr = headptr;
		headptr->record = record;
		headptr->next = nullptr;
		headptr->last = nullptr;

		return true;
	}

	//front case
	if (headptr->next == nullptr)
	{
		headptr->next = new (nothrow) linkedListNode;
		if (headptr->next == nullptr)
		{
			cout << "Memory allocation error. Terminating program." << endl;
			return false;
		}

		tailptr = headptr->next;
		tailptr->next = nullptr;
		tailptr->last = headptr;
		tailptr->record = record;
		return true;
	}
	//middle case
	//end case

	return false;
}