#ifndef MEMBERLIST_H
#define MEMBERLIST_H

#include <iostream>
#include <string>
#include <fstream>

#include "Member.h"
#include "Groups.h"
#include "GroupsList.h"

using namespace std;

class MemberList;

class MemberNode
{
	friend class MemberList;
	friend ostream &operator<<(ostream &oStream, MemberList &list);
	friend istream &operator>>(istream &iStream, MemberList &list);

	public:
		MemberNode() : next(NULL) {}
		MemberNode(const Member Data, MemberNode *Next=NULL) : data(Data), next(Next) {}
		MemberNode(const MemberNode &other) : data(other.data), next(other.next) {}
		~MemberNode() {}
		Member getData()
		{
			return data;
		}
		MemberNode getNext()
		{
			return *next;
		}

	private:
		MemberNode *next;
		Member data;
};

class MemberList
{
	friend ostream &operator<<(ostream &oStream, MemberList &list);
	friend istream &operator>>(istream &iStream, MemberList &list);

	public:
		MemberList();
		MemberList(const MemberList &other);
		~MemberList();

		MemberList &operator=(const MemberList &rhs);

		void addMember(const Member &Data);
		void removeMember();
		void modifyMember();
		void organizeList();
		void clear();
		bool empty();
		void deleteMember(string First, string Last);

		size_t sizeAllMembers();
		size_t sizeWithoutGroups();
		void showAllMembers();
		void showWithoutGroups();

		size_t sizeVocals();
		size_t sizePianos();
		size_t sizeGuitars();
		size_t sizePercussion();
		size_t sizeStrings();
		size_t sizeWoodwindBrass();
		size_t sizeEtcInstruments();
		void showVocals();
		void showPianos();
		void showGuitars();
		void showPercussion();
		void showStrings();
		void showWoodwindBrass();
		void showEtcInstruments();

		size_t sizeAny();
		size_t sizePop();
		size_t sizeRock();
		size_t sizeClassical();
		size_t sizeJazz();
		size_t sizeHipHop();
		size_t sizeCountry();
		size_t sizeEtcGenre();
		void showAny();
		void showPop();
		void showRock();
		void showClassical();
		void showJazz();
		void showHipHop();
		void showCountry();
		void showEtcGenre();

		size_t sizeXS();
		size_t sizeS();
		size_t sizeM();
		size_t sizeL();
		size_t sizeXL();
		size_t sizeXXL();
		void showXS();
		void showS();
		void showM();
		void showL();
		void showXL();
		void showXXL();

		size_t sizeBegin();
		size_t sizeInter();
		size_t sizeAdvan();
		void showBegin();
		void showInter();
		void showAdvan();

		size_t sizeDues();
		void showDues();

		void groupSort(GroupsList &groupslist);

	private:
		MemberNode *front;
		MemberNode *back;
		size_t size;

		//Below are helper functions used to support the code of the groupSort() algorithm
		bool groupCheck(const Groups &group);
};

#endif