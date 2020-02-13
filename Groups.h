#ifndef GROUPS_H
#define GROUPS_H

#include <iostream>
#include <string>

#include "Member.h"

using namespace std;

class Groups
{
	friend ostream &operator<<(ostream & os, const Groups &group);

	public:
		Groups();
		Groups(string Groupname, Member One, Member Two, Member Three, Member Four, Member Five);
		Groups(const Groups &other);
		~Groups();

		Groups &operator=(const Groups &rhs);
		bool empty();

		string getGroupName();
		void setGroupName(string Groupname);
		Member getOne() const;
		void setOne(Member One);
		Member getTwo() const;
		void setTwo(Member Two);
		Member getThree() const;
		void setThree(Member Three);
		Member getFour() const;
		void setFour(Member Four);
		Member getFive() const;
		void setFive(Member Five);
		
		void addMember(Member newMember);
		Member checkLast();
		void removeMember();

		string findDominantGenre() const;
		string findDominantLevel() const;

	private:
		string groupname;
		Member one;
		Member two;
		Member three;
		Member four;
		Member five;
};

#endif
