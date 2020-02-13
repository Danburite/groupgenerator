#ifndef GROUPSLIST_H
#define GROUPSLIST_H

#include <iostream>
#include <string>

#include "Member.h"
#include "Groups.h"

using namespace std;

class GroupsList;

class GroupsNode
{
	friend class GroupsList;
	friend ostream &operator<<(ostream &oStream, GroupsList &list);

	public:
		GroupsNode() : next(NULL) {}
		GroupsNode(const Groups Data, GroupsNode *Next=NULL) : data(Data), next(Next) {}
		GroupsNode(const GroupsNode &other) : data(other.data), next(other.next) {}
		~GroupsNode() {}
		Groups &getData()
		{
			return data;
		}
		GroupsNode *getNext()
		{
			return next;
		}

	private:
		GroupsNode *next;
		Groups data;
};

class GroupsList
{
	friend ostream &operator<<(ostream &oStream, GroupsList &list);

	public:
		GroupsList();
		GroupsList(const GroupsList &other);
		~GroupsList();

		GroupsList &operator=(const GroupsList &rhs);

		void addGroup(const Groups &Data);
		void removeGroup();

		size_t sizeAllGroups();
		void showAllGroups();

	private:
		GroupsNode *front;
		GroupsNode *back;
		size_t size;
};

#endif