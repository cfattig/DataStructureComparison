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
	cout << "First Name: " << record.firstName << endl;
	cout << "Last Name: " << record.lastName << endl;
	cout << "Age: " << record.age << endl;
	cout << "College Degree: " << record.degree << endl << endl;
	return;
}


bool linkedList::insert(info record)
{
	linkedListNode *prev = nullptr;
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
	if (record.firstName < headptr->record.firstName)
	{
		curr = new (nothrow) linkedListNode;
		if (curr == nullptr)
		{
			cout << "Memory allocation error. Terminating program." << endl;
			return false;
		}
		curr->next = headptr;
		curr->last = nullptr;
		curr->record = record;
		headptr->last = curr;
		headptr = curr;
		return true;
	}

	//middle case
	while (curr != nullptr && record.firstName >= curr->record.firstName)
	{
		prev = curr;
		curr = curr->next;
	}
	if (curr != nullptr)
	{
		prev->next = new (nothrow) linkedListNode;
		if (prev->next == nullptr)
		{
			cout << "Memory allocation error. Terminating program." << endl;
			return false;
		}
		prev->next->next = curr;
		prev->next->last = prev;
		prev->next->record = record;
		curr->last = prev->next;
		return true;
	}

	//end case
	if (curr == nullptr)
	{
		prev->next = new (nothrow) linkedListNode;
		if (prev->next == nullptr)
		{
			cout << "Memory allocation error. Terminating program." << endl;
			return false;
		}
		prev->next->next = curr;
		prev->next->last = prev;
		prev->next->record = record;
		tailptr = prev->next;
		return true;
	}
	return false;
}


bool linkedList::remove(info record) {
	linkedListNode *prev = nullptr;
	linkedListNode *curr = headptr;


	//empty case
	if (headptr == nullptr)
	{
		cout << "The linked list is empty, there is nothing to remove\n" << endl;
		return true;
	}

	//last node in list case
	if (headptr == tailptr && headptr->record == record)
	{
		delete headptr;
		headptr = nullptr;
		tailptr = nullptr;
		return true;
	}


	//front case
	if (headptr->record == record) 
	{
		headptr = headptr->next;
		delete curr;
		headptr->last = nullptr;
		return true;
	}

	//traverse
	while (curr != nullptr && !(curr->record == record))
	{
		prev = curr;
		curr = curr->next;
	}

	//end case
	if (curr != nullptr && curr == tailptr )
	{
		prev->next = nullptr;
		tailptr = prev;
		delete curr;
		return true;
	}
	
	//middle case
	if (curr != nullptr && curr->record == record)
	{
		prev->next = curr->next;
		curr->next->last = prev;
		delete curr;
		return true;
	}

	//not found
	if (curr == nullptr)
	{
		cout << "No record was found with the provided information\n" << endl;
		return true;
	}

	return false;
}