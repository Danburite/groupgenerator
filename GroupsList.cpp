
#include <iostream>
#include <string>
#include <fstream>

#include "Member.h"
#include "Groups.h"
#include "GroupsList.h"

using namespace std;

GroupsList::GroupsList() {}

GroupsList::GroupsList(const GroupsList &other)
{
	front = new GroupsNode(other.front->getData());
	GroupsNode *temp1 = front;
	GroupsNode *temp2 = other.front;
	while (temp2->next != NULL)
	{
		temp1 = temp1->next;
		temp2 = temp2->next;
		temp1 = new GroupsNode(temp2->getData());
	}
	back = temp1;
	back->next = NULL;
}

GroupsList::~GroupsList() {}

GroupsList &GroupsList::operator=(const GroupsList &rhs)
{
	front = new GroupsNode(rhs.front->getData());
	GroupsNode *temp1 = front;
	GroupsNode *temp2 = rhs.front;
	while (temp2->next != NULL)
	{
		temp1 = temp1->next;
		temp2 = temp2->next;
		temp1 = new GroupsNode(temp2->getData());
	}
	back = temp1;
	back->next = NULL;
}

void GroupsList::addGroup(const Groups &Data)
{
	if (front == NULL)
	{
		GroupsNode *temp = new GroupsNode(Data, NULL);
		temp->next = NULL;
		back = temp;
		front = temp;
	}
	else
	{	
		GroupsNode *temp = new GroupsNode(Data, NULL);
		temp->next = NULL;
		back->next = temp;
		back = temp;
	}
}

void GroupsList::removeGroup()
{
	GroupsNode *curr = front;
	while(curr->next != back)
	{
		curr = curr->next;
	}
	delete back;
	back = NULL;
	back = curr->next;
}

size_t GroupsList::sizeAllGroups()
{
	int counter = 0;
	GroupsNode *curr = front;
	while (curr->next != NULL)
	{
		counter++;
		curr = curr->next;
	}
	counter++;
	return counter;
}

void GroupsList::showAllGroups()
{
	GroupsNode *curr = front;
	while (curr->next != NULL)
	{
		cout << curr->data << endl;
		curr = curr->next;
	}
	cout << curr->getData() << endl;
}

ostream &operator<<(ostream &oStream, GroupsList &list)
{
	if (list.front == NULL)
	{
		cout << "This list is empty. Please enter something." << endl;
	}
	else
	{
		GroupsNode *curr = list.front;
		while (curr->next != NULL)
		{
			oStream << curr->data << endl;
			curr = curr->next;
		}
		oStream << curr->data << endl;
	}
}