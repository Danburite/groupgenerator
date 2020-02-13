#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>

using namespace std;

class Member
{
	//Prints out member information structured like an excel spreadsheet
	friend ostream &operator<<(ostream & os, const Member &member);

	friend class Groups;

	public:
		//Default constructor and destructor
		Member();
		Member(string First, string Last, string Email, string Instrument, string Shirt, string Genre, string Level, bool Dues, bool Group);
		~Member();

		//Assignment operator
		Member &operator=(const Member &copy);
		bool operator==(const Member &copy);

		//Get and Set operations for private members
		string getFirst();
		void setFirst(string First);
		string getLast();
		void setLast(string Last);
		string getEmail();
		void setEmail(string Email);
		string getInstrument();
		void setInstrument(string Instrument);
		string getShirt();
		void setShirt(string Shirt);
		string getGenre() const;
		void setGenre(string Genre);
		string getLevel() const;
		void setLevel(string Level);
		bool getDues();
		void setDues(bool Dues);
		bool getGroup();
		void setGroup(bool Group);

		//Uses capitalize function to capitalize appropriate mebers in entire object
		void reorganize();

	private:
		string first;
		string last;
		string email;
		string instrument;
		string shirt;
		string genre;
		string level;
		bool dues;
		bool group;

		//Re-usable function for capitalizing
		void capitalize(string &string);
		//Function dedicated to capitalize all letters in a string
		void allCapitalize(string &string);
};

#endif