#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "Member.h"
#include "MemberList.h"
#include "Groups.h"
#include "GroupsList.h"

using namespace std;

ostream &operator<<(ostream &oStream, MemberList &list)
{
	if (list.front == NULL)
	{
		cout << "This list is empty. Please enter something." << endl;
	}
	else
	{
		MemberNode *curr = list.front;
		while (curr->next != NULL)
		{
			oStream << curr->data << endl;
			curr = curr->next;
		}
		oStream << curr->data << endl;
	}
}

istream &operator>>(istream &iStream, MemberList &list)
{
	string line, first, last, email, instrument, shirt, genre, level, dues;
	char delim1 = '\t';
	bool duesBool;

	while (iStream != NULL)
	{
		//Obtains data of each object one at a time by lines
		getline(iStream, line);

		//Keep in mind the sections of each part of information is separated by the tab delimiter

		//Parses and sets the first section to the last name
		last = line.substr(0, line.find(delim1));
		//Removes the first section that was originally the last name including the tab delimiter
		line.erase(0, line.find(delim1) + 1);

		//Parses and sets the next section to the first name
		first = line.substr(0, line.find(delim1));
		//Removes the next section that was the first name including the tab delimiter
		line.erase(0, line.find(delim1) + 1);

		//Parses and sets the next section to the email address
		email = line.substr(0, line.find(delim1));
		//Removes the next section that was the email including the tab delimiter
		line.erase(0, line.find(delim1) + 1);

		//Parses and sets the next section to the instruments section
		instrument = line.substr(0, line.find(delim1));
		//Removes the next section that was the instruments section including the tab delimiter
		line.erase(0, line.find(delim1) + 1);

		//Parses and sets the next section to the shirt section
		shirt = line.substr(0, line.find(delim1));
		//Removes the next section that was the shirt section including the tab delimiter
		line.erase(0, line.find(delim1) + 1);

		//Parses and sets the next section to the genres section
		genre = line.substr(0, line.find(delim1));
		//Removes the next section that was the genres section including the tab delimiter
		line.erase(0, line.find(delim1) + 1);

		//Parses and sets the next section to the levels section
		level = line.substr(0, line.find(delim1));
		//Removes the next section that was the levels section including the tab delimiter
		line.erase(0, line.find(delim1) + 1);

		dues = line;

		//Below will generalize instruments to more basic sections
		if (instrument == "Vocal" || instrument == "Singer" || instrument == "Voice")
		{
			instrument = "Vocal";
		}
		if (instrument == "Piano" || instrument == "Keyboard")
		{
			instrument = "Piano";
		}
		if (instrument == "Guitar" || instrument == "Ukele" || instrument == "Uke" || 
			instrument == "Bass" || instrument == "Bass Guitar" || instrument == "Mandolin" || 
			instrument == "Banjo" || instrument == "Lute")
		{
			instrument = "Guitar";
		}
		if (instrument == "Cajon" || instrument == "Percussion" || instrument == "Drums" ||
			instrument == "Beatbox" || instrument == "Rhythm")
		{
			instrument = "Percussion";
		}
		if (instrument == "Violin" || instrument == "Viola" || instrument == "Cello" ||
			instrument == "Harp" || instrument == "Erhu" || instrument == "Guzheng")
		{
			instrument = "Strings";
		}
		if (instrument == "Trumpet" || instrument == "Trombone" || instrument == "Saxophone" ||
			instrument == "Flute" || instrument == "Clarinet" || instrument == "Oboe" ||
			instrument == "Bassoon" || instrument == "Mellophone" || instrument == "French Horn" ||
			instrument == "Euphonium" || instrument == "Tuba" || instrument == "Piccolo" ||
			instrument == "WoodwindBrass")
		{
			instrument = "WoodwindBrass";
		}

		//Below will generalize genres to more basic sections
		if (genre == "Any")
		{
			genre = "Any";
		}
		if (genre == "Pop")
		{
			genre = "Pop";
		}
		if (genre == "Rock" || genre == "Alternative" ||
			genre == "Metal" || genre == "Punk" || genre == "Punk Rock")
		{
			genre = "Rock";
		}
		if (genre == "Classical" || genre == "Opera")
		{
			genre = "Classical";
		}
		if (genre == "Jazz" || genre == "Funk" || genre == "Motown" || genre == "Blues" ||
			genre == "Soul")
		{
			genre = "Jazz";
		}
		if (genre == "Hip Hop" || genre == "R&B" || genre == "Ballad" || genre == "Rap")
		{
			genre = "Hip Hop";
		}
		if (genre == "Country" || genre == "Bluegrass")
		{
			genre = "Country";
		}

		//Sets the dues to the correct expression
		if (dues == "x")
		{
			duesBool = true;
		}
		else
		{
			duesBool = false;
		}

		//Parametrized constructor to create member object
		Member New(first, last, email, instrument, shirt, genre, level, duesBool, false);

		//Adds member to the list
		if (!first.empty())
		{
			list.addMember(New);
		}
	}
}

//Standard default constructor
MemberList::MemberList()
{
	front = NULL;
	back = NULL;
	size = 0;
}

//Standard copy constructor
MemberList::MemberList(const MemberList &other)
{
	front = new MemberNode(other.front->getData());
	MemberNode *temp1 = front;
	MemberNode *temp2 = other.front;
	while (temp2->next != NULL)
	{
		temp1 = temp1->next;
		temp2 = temp2->next;
		temp1 = new MemberNode(temp2->getData());
	}
	back = temp1;
	back->next = NULL;
}

//Destructor which calls clear() to clean the list
MemberList::~MemberList()
{
	clear();
}

//Assignment operator similar to the copy constructor
MemberList &MemberList::operator=(const MemberList &rhs)
{
	front = new MemberNode(rhs.front->getData());
	MemberNode *temp1 = front;
	MemberNode *temp2 = rhs.front;
	while (temp2->next != NULL)
	{
		temp1 = temp1->next;
		temp2 = temp2->next;
		temp1 = new MemberNode(temp2->getData());
	}
	back = temp1;
	back->next = NULL;
	return *this;
}

//Takes in a Member object and adds it to the list
void MemberList::addMember(const Member &Data)
{
	if (front == NULL)
	{
		MemberNode *temp = new MemberNode(Data, NULL);
		temp->next = NULL;
		back = temp;
		front = temp;
	}
	else
	{	
		MemberNode *temp = new MemberNode(Data, NULL);
		temp->next = NULL;
		back->next = temp;
		back = temp;
	}
}

//Requests the user to input the name of the member to remove from the list
void MemberList::removeMember()
{
	string firstname;
	string lastname;

	//Asks user for the name
	cout << "Please enter the last name of who you would like to delete: ";
	cin >> lastname;
	cout << "Please enter the first name of who you would like to delete: ";
	cin >> firstname;

	deleteMember(firstname, lastname);	
}

//Allows for the user to edit the information of a member
void MemberList::modifyMember()
{
	string firstname;
	string lastname;

	//Similar to the removeMember method, it requests the name of the member
	cout << "Please enter the last name of who you would like to modify: ";
	cin >> lastname;
	cout << "Please enter the first name of who you would like to modify: ";
	cin >> firstname;

	//Utilizes the same mechanic of finding the member in the list
	MemberNode *find = front;	
	while (find->next != NULL)
	{
		//Once found, a switch statement allows for editing of specific information
		if (find->data.getLast() == lastname && find->data.getFirst() == firstname)
		{
			int option3 = 0;
			cout << "1) First Name" << endl
				 << "2) Last Name" << endl
				 << "3) E-mail" << endl
				 << "4) Instrument" << endl
				 << "5) Shirt" << endl
				 << "6) Genre" << endl
				 << "7) Level" << endl
				 << "8) Dues" << endl
				 << "9) Is the member in a group?" << endl
				 << "10) Exit Member Modification" << endl;
			while (option3 != 10)
			{
				cout << "What would you like to modify?: ";
				cin >> option3;
				switch (option3)
				{
					case 1:
					{
						string first_name;
						cout << "Please enter the first name: ";
						cin >> first_name;
						find->data.setFirst(first_name);
						break;
					}
					case 2:
					{
						string last_name;
						cout << "Please enter the last name: ";
						cin >> last_name;
						find->data.setLast(last_name);
						break;
					}
					case 3:
					{
						string e_mail;
						cout << "Please enter the email: ";
						cin >> e_mail;
						find->data.setEmail(e_mail);
						break;
					}
					case 4:
					{
						string instru;
						cout << "Please enter the instrument: ";
						cin >> instru;
						if (instru == "Vocal" || instru == "Singer" || instru == "Voice")
						{
							instru = "Vocal";
						}
						if (instru == "Piano" || instru == "Keyboard")
						{
							instru = "Piano";
						}
						if (instru == "Guitar" || instru == "Ukele" || instru == "Uke" || 
							instru == "Bass" || instru == "Bass Guitar" || instru == "Mandolin" || 
							instru == "Banjo" || instru == "Lute")
						{
							instru = "Guitar";
						}
						if (instru == "Cajon" || instru == "Percussion" || instru == "Drums" ||
							instru == "Beatbox" || instru == "Rhythm")
						{
							instru = "Percussion";
						}
						if (instru == "Violin" || instru == "Viola" || instru == "Cello" ||
							instru == "Harp" || instru == "Erhu" || instru == "Guzheng")
						{
							instru = "Strings";
						}
						if (instru == "Trumpet" || instru == "Trombone" || instru == "Saxophone" ||
							instru == "Flute" || instru == "Clarinet" || instru == "Oboe" ||
							instru == "Bassoon" || instru == "Mellophone" || instru == "French Horn" ||
							instru == "Euphonium" || instru == "Tuba" || instru == "Piccolo")
						{
							instru = "WoodwindBrass";
						}
						find->data.setInstrument(instru);
						break;
					}
					case 5:
					{
						string shi;
						cout << "Please enter the shirt size: ";
						cin >> shi;
						find->data.setShirt(shi);
						break;
					}
					case 6:
					{
						string gen;
						cout << "Please enter the genre: ";
						cin >> gen;
						if (gen == "Any")
						{
							gen = "Any";
						}
						if (gen == "Pop")
						{
							gen = "Pop";
						}
						if (gen == "Rock" || gen == "Alternative" ||
							gen == "Metal" || gen == "Punk" || gen == "Punk Rock")
						{
							gen = "Rock";
						}
						if (gen == "Classical" || gen == "Opera")
						{
							gen = "Classical";
						}
						if (gen == "Jazz" || gen == "Funk" || gen == "Motown" || gen == "Blues" ||
							gen == "Soul")
						{
							gen = "Jazz";
						}
						if (gen == "Hip Hop" || gen == "R&B" || gen == "Ballad" || gen == "Rap")
						{
							gen = "Hip Hop";
						}
						if (gen == "Country" || gen == "Bluegrass")
						{
							gen = "Country";
						}
						find->data.setGenre(gen);
						break;
					}
					case 7:
					{
						string lev;
						cout << "Please enter the level: ";
						cin >> lev;
						find->data.setLevel(lev);
						break;
					}
					case 8:
					{
						string condition;
						if (find->data.getDues())
						{
							cout << "The member has already paid dues. Would you like to change that? (Y/N): ";
							cin >> condition;
							if (condition == "Yes" || condition == "Y" || condition == "yes" || condition == "y")
							{
								find->data.setDues(false);
							}
							else
							{
								cout << "Member's dues status has not changed." << endl;
							}
						}
						else
						{
							cout << "The member has not paid dues yet. Would you like to change that? (Y/N): ";
							cin >> condition;
							if (condition == "Yes" || condition == "Y" || condition == "yes" || condition == "y")
							{
								find->data.setGroup(true);
							}
							else
							{
								cout << "Member's dues status has not changed." << endl;
							}
						}
						break;
					}
					case 9:
					{
						string condition;
						if (find->data.getGroup())
						{
							cout << "The member is currently in a group. Would you like to change that? (Y/N): ";
							cin >> condition;
							if (condition == "Yes" || condition == "Y" || condition == "yes" || condition == "y")
							{
								find->data.setGroup(false);
							}
							else
							{
								cout << "Member's group status has not changed." << endl;
							}
						}
						else
						{
							cout << "The member is not currently in a group. Would you like to change that? (Y/N): ";
							cin >> condition;
							if (condition == "Yes" || condition == "Y" || condition == "yes" || condition == "y")
							{
								find->data.setGroup(true);
							}
							else
							{
								cout << "Member's group status has not changed." << endl;
							}
						}
						break;
					}
					default:
					{
						break;
					}
				}
			}
		}
		find = find->next;
	}
	//Program is implemented again to account for the last object of the list
	if (find->data.getLast() == lastname && find->data.getFirst() == firstname)
	{
		int option3 = 0;
		cout << "1) First Name" << endl
			 << "2) Last Name" << endl
			 << "3) E-mail" << endl
			 << "4) Instrument" << endl
			 << "5) Shirt" << endl
			 << "6) Genre" << endl
			 << "7) Level" << endl
			 << "8) Dues" << endl
			 << "9) Is the member in a group?" << endl
			 << "10) Exit Member Modification" << endl;
		while (option3 != 10)
		{
			cout << "What would you like to modify?: ";
			cin >> option3;
			switch (option3)
			{
				case 1:
				{
					string first_name;
					cout << "Please enter the first name: ";
					cin >> first_name;
					find->data.setFirst(first_name);
					break;
				}
				case 2:
				{
					string last_name;
					cout << "Please enter the last name: ";
					cin >> last_name;
					find->data.setLast(last_name);
					break;
				}
				case 3:
				{
					string e_mail;
					cout << "Please enter the email: ";
					cin >> e_mail;
					find->data.setEmail(e_mail);
					break;
				}
				case 4:
				{
					string instru;
					cout << "Please enter the instrument: ";
					cin >> instru;
					if (instru == "Vocal" || instru == "Singer" || instru == "Voice")
					{
						instru = "Vocal";
					}
					if (instru == "Piano" || instru == "Keyboard")
					{
						instru = "Piano";
					}
					if (instru == "Guitar" || instru == "Ukele" || instru == "Uke" || 
						instru == "Bass" || instru == "Bass Guitar" || instru == "Mandolin" || 
						instru == "Banjo" || instru == "Lute")
					{
						instru = "Guitar";
					}
					if (instru == "Cajon" || instru == "Percussion" || instru == "Drums" ||
						instru == "Beatbox" || instru == "Rhythm")
					{
						instru = "Percussion";
					}
					if (instru == "Violin" || instru == "Viola" || instru == "Cello" ||
						instru == "Harp" || instru == "Erhu" || instru == "Guzheng")
					{
						instru = "Strings";
					}
					if (instru == "Trumpet" || instru == "Trombone" || instru == "Saxophone" ||
						instru == "Flute" || instru == "Clarinet" || instru == "Oboe" ||
						instru == "Bassoon" || instru == "Mellophone" || instru == "French Horn" ||
						instru == "Euphonium" || instru == "Tuba" || instru == "Piccolo")
					{
						instru = "WoodwindBrass";
					}
					find->data.setInstrument(instru);
					break;
				}
				case 5:
				{
					string shi;
					cout << "Please enter the shirt size: ";
					cin >> shi;
					find->data.setShirt(shi);
					break;
				}
				case 6:
				{
					string gen;
					cout << "Please enter the genre: ";
					cin >> gen;
					if (gen == "Any")
					{
						gen = "Any";
					}
					if (gen == "Pop")
					{
						gen = "Pop";
					}
					if (gen == "Rock" || gen == "Alternative" ||
						gen == "Metal" || gen == "Punk" || gen == "Punk Rock")
					{
						gen = "Rock";
					}
					if (gen == "Classical" || gen == "Opera")
					{
						gen = "Classical";
					}
					if (gen == "Jazz" || gen == "Funk" || gen == "Motown" || gen == "Blues" ||
						gen == "Soul")
					{
						gen = "Jazz";
					}
					if (gen == "Hip Hop" || gen == "R&B" || gen == "Ballad" || gen == "Rap")
					{
						gen = "Hip Hop";
					}
					if (gen == "Country" || gen == "Bluegrass")
					{
						gen = "Country";
					}
					find->data.setGenre(gen);
					break;
				}
				case 7:
				{
					string lev;
					cout << "Please enter the level: ";
					cin >> lev;
					find->data.setLevel(lev);
					break;
				}
				case 8:
				{
					string condition;
					if (find->data.getDues())
					{
						cout << "The member has already paid dues. Would you like to change that? (Y/N): ";
						cin >> condition;
						if (condition == "Yes" || condition == "Y" || condition == "yes" || condition == "y")
						{
							find->data.setDues(false);
						}
						else
						{
							cout << "Member's dues status has not changed." << endl;
						}
					}
					else
					{
						cout << "The member has not paid dues yet. Would you like to change that? (Y/N): ";
						cin >> condition;
						if (condition == "Yes" || condition == "Y" || condition == "yes" || condition == "y")
						{
							find->data.setGroup(true);
						}
						else
						{
							cout << "Member's dues status has not changed." << endl;
						}
					}
					break;
				}
				case 9:
				{
					string condition;
					if (find->data.getGroup())
					{
						cout << "The member is currently in a group. Would you like to change that? (Y/N): ";
						cin >> condition;
						if (condition == "Yes" || condition == "Y" || condition == "yes" || condition == "y")
						{
							find->data.setGroup(false);
						}
						else
						{
							cout << "Member's group status has not changed." << endl;
						}
					}
					else
					{
						cout << "The member is not currently in a group. Would you like to change that? (Y/N): ";
						cin >> condition;
						if (condition == "Yes" || condition == "Y" || condition == "yes" || condition == "y")
						{
							find->data.setGroup(true);
						}
						else
						{
							cout << "Member's group status has not changed." << endl;
						}
					}
					break;
				}
				default:
				{
					break;
				}
			}
		}
	}
}

//The method simply capitalizes the member's information throughout the list
void MemberList::organizeList()
{
	MemberNode *curr = front;
	while (curr != NULL)
	{
		curr->data.reorganize();
		curr = curr->next;
	}
}

//Removes all members from the list
void MemberList::clear()
{
	if (front !=NULL)
	{
		while (front->next != NULL)
		{
			MemberNode *temp = front;
			front = front->next;
			delete temp;
			temp = NULL;
		}
		front = NULL;
		back = NULL;
	}
}

//Checks to see if the list is empty
bool MemberList::empty()
{
	if (front == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Method deletes member through searching for the node, deleting it, and appending the list 
void MemberList::deleteMember(string First, string Last)
{
	//Created a find node to locate the specific node containing the name information
	MemberNode *find = front;
	while (find->next != NULL)
	{
		//Searches the list until there is a match
		if (find->data.getLast() == Last && find->data.getFirst() == First)
		{
			//Created  curr node to traverse to the back of the find node
			MemberNode *curr = front;
			while (curr->next != NULL)
			{
				//Accounts for if find is the first node of the list
				if (curr == find)
				{
					front = front->next;
					delete find;
					find = NULL;
					return;
				}
				//Finds the node before find and deletes find while appending the list
				if (curr->next == find)
				{
					curr->next = find->next;
					delete find;
					find = NULL;
					return;
				}
				curr = curr->next;
			}
		}
		find = find->next;
	}
	//Program is implemented again to account for the last object of the list
	if (find->data.getLast() == Last && find->data.getFirst() == First)
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			if (curr->next == find)
			{
				curr->next = find->next;
				delete find;
				find = NULL;
				return;
			}
			curr = curr->next;
		}
	}

	//Accounts for no ability to find the member in the list
	if (find != NULL)
	{
		cout << "Failed to delete name. Please check for spelling or if the member is not present in the list." << endl;
	}
}

size_t MemberList::sizeAllMembers()
{
	int counter = 0;
	MemberNode *curr = front;
	while (curr->next != NULL)
	{
		counter++;
		curr = curr->next;
	}
	counter++;
	return counter;
}

size_t MemberList::sizeWithoutGroups()
{
	int counter = 0;
	MemberNode *curr = front;
	while (curr->next != NULL)
	{
		if (curr->data.getGroup() == false)
		{
			counter++;
		}
		curr = curr->next;
	}
	if (curr->data.getGroup() == false)
	{
		counter++;
	}
	return counter;
}

void MemberList::showAllMembers()
{
	if (front == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			cout << curr->data << endl;
			curr = curr->next;
		}
		cout << curr->data << endl;
	}
}

void MemberList::showWithoutGroups()
{
	if (front == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			if (curr->data.getGroup() == false)
			{
				cout << curr->data << endl;
			}
			curr = curr->next;
		}
		if (curr->data.getGroup() == false)
		{
			cout << curr->data << endl;
		}
	}
}

size_t MemberList::sizeVocals()
{
	int counter = 0;
	MemberNode *curr = front;
	while (curr->next != NULL)
	{
		if (curr->data.getInstrument() == "Vocal")
		{
			counter++;
		}
		curr = curr->next;
	}
	if (curr->data.getInstrument() == "Vocal")
	{
		counter++;
	}
	return counter;
}

size_t MemberList::sizePianos()
{
	int counter = 0;
	MemberNode *curr = front;
	while (curr->next != NULL)
	{
		if (curr->data.getInstrument() == "Piano")
		{
			counter++;
		}
		curr = curr->next;
	}
	if (curr->data.getInstrument() == "Piano")
	{
		counter++;
	}
	return counter;
}

size_t MemberList::sizeGuitars()
{
	int counter = 0;
	MemberNode *curr = front;
	while (curr->next != NULL)
	{
		if (curr->data.getInstrument() == "Guitar")
		{
			counter++;
		}
		curr = curr->next;
	}
	if (curr->data.getInstrument() == "Guitar")
	{
		counter++;
	}
	return counter;
}

size_t MemberList::sizePercussion()
{
	int counter = 0;
	MemberNode *curr = front;
	while (curr->next != NULL)
	{
		if (curr->data.getInstrument() == "Percussion")
		{
			counter++;
		}
		curr = curr->next;
	}
	if (curr->data.getInstrument() == "Percussion")
	{
		counter++;
	}
	return counter;
}

size_t MemberList::sizeStrings()
{
	int counter = 0;
	MemberNode *curr = front;
	while (curr->next != NULL)
	{
		if (curr->data.getInstrument() == "Strings")
		{
			counter++;
		}
		curr = curr->next;
	}
	if (curr->data.getInstrument() == "Strings")
	{
		counter++;
	}
	return counter;
}

size_t MemberList::sizeWoodwindBrass()
{
	int counter = 0;
	MemberNode *curr = front;
	while (curr->next != NULL)
	{
		if (curr->data.getInstrument() == "WoodwindBrass")
		{
			counter++;
		}
		curr = curr->next;
	}
	if (curr->data.getInstrument() == "WoodwindBrass")
	{
		counter++;
	}
	return counter;
}

size_t MemberList::sizeEtcInstruments()
{
	int counter = 0;
	MemberNode *curr = front;
	while (curr->next != NULL)
	{
		if (!(curr->data.getInstrument() == "Vocal" || curr->data.getInstrument() == "Piano" || 
			  curr->data.getInstrument() == "Guitar" || curr->data.getInstrument() == "Percussion" ||
			  curr->data.getInstrument() == "Strings" || curr->data.getInstrument() == "WoodwindBrass"))
		{
			counter++;
		}
		curr = curr->next;
	}
	if (!(curr->data.getInstrument() == "Vocal" || curr->data.getInstrument() == "Piano" || 
		  curr->data.getInstrument() == "Guitar" || curr->data.getInstrument() == "Percussion" ||
		  curr->data.getInstrument() == "Strings" || curr->data.getInstrument() == "WoodwindBrass"))
	{
		counter++;
	}
	return counter;
}

void MemberList::showVocals()
{
	if (front == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			if (curr->data.getInstrument() == "Vocal")
			{
				cout << curr->data << endl;
			}
			curr = curr->next;
		}
		if (curr->data.getInstrument() == "Vocal")
		{
			cout << curr->data << endl;
		}
	}
}

void MemberList::showPianos()
{
	if (front == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			if (curr->data.getInstrument() == "Piano")
			{
				cout << curr->data << endl;
			}
			curr = curr->next;
		}
		if (curr->data.getInstrument() == "Piano")
		{
			cout << curr->data << endl;
		}
	}
}

void MemberList::showGuitars()
{
	if (front == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			if (curr->data.getInstrument() == "Guitar")
			{
				cout << curr->data << endl;
			}
			curr = curr->next;
		}
		if (curr->data.getInstrument() == "Guitar")
		{
			cout << curr->data << endl;
		}
	}
}

void MemberList::showPercussion()
{
	if (front == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			if (curr->data.getInstrument() == "Percussion")
			{
				cout << curr->data << endl;
			}
			curr = curr->next;
		}
		if (curr->data.getInstrument() == "Percussion")
		{
			cout << curr->data << endl;
		}
	}
}

void MemberList::showStrings()
{
	if (front == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			if (curr->data.getInstrument() == "Strings")
			{
				cout << curr->data << endl;
			}
			curr = curr->next;
		}
		if (curr->data.getInstrument() == "Strings")
		{
			cout << curr->data << endl;
		}
	}
}

void MemberList::showWoodwindBrass()
{
	if (front == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			if (curr->data.getInstrument() == "WoodwindBrass")
			{
				cout << curr->data << endl;
			}
			curr = curr->next;
		}
		if (curr->data.getInstrument() == "WoodwindBrass")
		{
			cout << curr->data << endl;
		}
	}
}

void MemberList::showEtcInstruments()
{
	if (front == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			if (!(curr->data.getInstrument() == "Vocal" || curr->data.getInstrument() == "Piano" || 
				  curr->data.getInstrument() == "Guitar" || curr->data.getInstrument() == "Percussion" ||
				  curr->data.getInstrument() == "Strings" || curr->data.getInstrument() == "WoodwindBrass"))
			{
				cout << curr->data << endl;
			}
			curr = curr->next;
		}
		if (!(curr->data.getInstrument() == "Vocal" || curr->data.getInstrument() == "Piano" || 
			  curr->data.getInstrument() == "Guitar" || curr->data.getInstrument() == "Percussion" ||
			  curr->data.getInstrument() == "Strings" || curr->data.getInstrument() == "WoodwindBrass"))
		{
			cout << curr->data << endl;
		}
	}
}

size_t MemberList::sizeAny()
{
	int counter = 0;
	MemberNode *curr = front;
	while (curr->next != NULL)
	{
		if (curr->data.getGenre() == "Any")
		{
			counter++;
		}
		curr = curr->next;
	}
	if (curr->data.getInstrument() == "Any")
	{
		counter++;
	}
	return counter;
}

size_t MemberList::sizePop()
{
	int counter = 0;
	MemberNode *curr = front;
	while (curr->next != NULL)
	{
		if (curr->data.getGenre() == "Pop")
		{
			counter++;
		}
		curr = curr->next;
	}
	if (curr->data.getInstrument() == "Pop")
	{
		counter++;
	}
	return counter;
}

size_t MemberList::sizeRock()
{
	int counter = 0;
	MemberNode *curr = front;
	while (curr->next != NULL)
	{
		if (curr->data.getGenre() == "Rock")
		{
			counter++;
		}
		curr = curr->next;
	}
	if (curr->data.getInstrument() == "Rock")
	{
		counter++;
	}
	return counter;
}

size_t MemberList::sizeClassical()
{
	int counter = 0;
	MemberNode *curr = front;
	while (curr->next != NULL)
	{
		if (curr->data.getGenre() == "Classical")
		{
			counter++;
		}
		curr = curr->next;
	}
	if (curr->data.getInstrument() == "Classical")
	{
		counter++;
	}
	return counter;
}

size_t MemberList::sizeJazz()
{
	int counter = 0;
	MemberNode *curr = front;
	while (curr->next != NULL)
	{
		if (curr->data.getGenre() == "Jazz")
		{
			counter++;
		}
		curr = curr->next;
	}
	if (curr->data.getInstrument() == "Jazz")
	{
		counter++;
	}
	return counter;
}

size_t MemberList::sizeHipHop()
{
	int counter = 0;
	MemberNode *curr = front;
	while (curr->next != NULL)
	{
		if (curr->data.getGenre() == "Hip Hop")
		{
			counter++;
		}
		curr = curr->next;
	}
	if (curr->data.getInstrument() == "Hip Hop")
	{
		counter++;
	}
	return counter;
}

size_t MemberList::sizeCountry()
{
	int counter = 0;
	MemberNode *curr = front;
	while (curr->next != NULL)
	{
		if (curr->data.getGenre() == "Country")
		{
			counter++;
		}
		curr = curr->next;
	}
	if (curr->data.getInstrument() == "Country")
	{
		counter++;
	}
	return counter;
}

size_t MemberList::sizeEtcGenre()
{
	int counter = 0;
	MemberNode *curr = front;
	while (curr->next != NULL)
	{
		if (!(curr->data.getGenre() == "Any" || curr->data.getGenre() == "Pop" || curr->data.getGenre() == "Rock" ||
			  curr->data.getGenre() == "Classical" || curr->data.getGenre() == "Jazz" || curr->data.getGenre() == "Hip Hop" ||
			  curr->data.getGenre() == "Country"))
		{
			counter++;
		}
		curr = curr->next;
	}
	if (!(curr->data.getGenre() == "Any" || curr->data.getGenre() == "Pop" || curr->data.getGenre() == "Rock" ||
		  curr->data.getGenre() == "Classical" || curr->data.getGenre() == "Jazz" || curr->data.getGenre() == "Hip Hop" ||
		  curr->data.getGenre() == "Country"))
	{
		counter++;
	}
	return counter;
}

void MemberList::showAny()
{
	if (front == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			if (curr->data.getGenre() == "Any")
			{
				cout << curr->data << endl;
			}
			curr = curr->next;
		}
		if (curr->data.getGenre() == "Any")
		{
			cout << curr->data << endl;
		}
	}
}
void MemberList::showPop()
{
	if (front == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			if (curr->data.getGenre() == "Pop")
			{
				cout << curr->data << endl;
			}
			curr = curr->next;
		}
		if (curr->data.getGenre() == "Pop")
		{
			cout << curr->data << endl;
		}
	}
}

void MemberList::showRock()
{
	if (front == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			if (curr->data.getGenre() == "Rock")
			{
				cout << curr->data << endl;
			}
			curr = curr->next;
		}
		if (curr->data.getGenre() == "Rock")
		{
			cout << curr->data << endl;
		}
	}
}

void MemberList::showClassical()
{
	if (front == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			if (curr->data.getGenre() == "Classical")
			{
				cout << curr->data << endl;
			}
			curr = curr->next;
		}
		if (curr->data.getGenre() == "Classical")
		{
			cout << curr->data << endl;
		}
	}
}

void MemberList::showJazz()
{
	if (front == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			if (curr->data.getGenre() == "Jazz")
			{
				cout << curr->data << endl;
			}
			curr = curr->next;
		}
		if (curr->data.getGenre() == "Jazz")
		{
			cout << curr->data << endl;
		}
	}
}

void MemberList::showHipHop()
{
	if (front == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			if (curr->data.getGenre() == "Hip Hop")
			{
				cout << curr->data << endl;
			}
			curr = curr->next;
		}
		if (curr->data.getGenre() == "Hip Hop")
		{
			cout << curr->data << endl;
		}
	}
}

void MemberList::showCountry()
{
	if (front == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			if (curr->data.getGenre() == "Country")
			{
				cout << curr->data << endl;
			}
			curr = curr->next;
		}
		if (curr->data.getGenre() == "Country")
		{
			cout << curr->data << endl;
		}
	}
}

void MemberList::showEtcGenre()
{
	if (front == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			if (!(curr->data.getGenre() == "Any" || curr->data.getGenre() == "Pop" || curr->data.getGenre() == "Rock" ||
		 		curr->data.getGenre() == "Classical" || curr->data.getGenre() == "Jazz" || curr->data.getGenre() == "Hip Hop" ||
				curr->data.getGenre() == "Country"))
			{
				cout << curr->data << endl;
			}
			curr = curr->next;
		}
		if (!(curr->data.getGenre() == "Any" || curr->data.getGenre() == "Pop" || curr->data.getGenre() == "Rock" ||
			  curr->data.getGenre() == "Classical" || curr->data.getGenre() == "Jazz" || curr->data.getGenre() == "Hip Hop" ||
			  curr->data.getGenre() == "Country"))
		{
			cout << curr->data << endl;
		}
	}
}

size_t MemberList::sizeXS()
{
	int counter = 0;
	MemberNode *curr = front;
	while (curr->next != NULL)
	{
		if (curr->data.getShirt() == "XS" && curr->data.getDues() == true)
		{
			counter++;
		}
		curr = curr->next;
	}
	if (curr->data.getShirt() == "XS" && curr->data.getDues() == true)
	{
		counter++;
	}
	return counter;
}

size_t MemberList::sizeS()
{
	int counter = 0;
	MemberNode *curr = front;
	while (curr->next != NULL)
	{
		if (curr->data.getShirt() == "S" && curr->data.getDues() == true)
		{
			counter++;
		}
		curr = curr->next;
	}
	if (curr->data.getShirt() == "S" && curr->data.getDues() == true)
	{
		counter++;
	}
	return counter;
}

size_t MemberList::sizeM()
{
	int counter = 0;
	MemberNode *curr = front;
	while (curr->next != NULL)
	{
		if (curr->data.getShirt() == "M" && curr->data.getDues() == true)
		{
			counter++;
		}
		curr = curr->next;
	}
	if (curr->data.getShirt() == "M" && curr->data.getDues() == true)
	{
		counter++;
	}
	return counter;
}

size_t MemberList::sizeL()
{
	int counter = 0;
	MemberNode *curr = front;
	while (curr->next != NULL)
	{
		if (curr->data.getShirt() == "L" && curr->data.getDues() == true)
		{
			counter++;
		}
		curr = curr->next;
	}
	if (curr->data.getShirt() == "L" && curr->data.getDues() == true)
	{
		counter++;
	}
	return counter;
}

size_t MemberList::sizeXL()
{
	int counter = 0;
	MemberNode *curr = front;
	while (curr->next != NULL)
	{
		if (curr->data.getShirt() == "XL" && curr->data.getDues() == true)
		{
			counter++;
		}
		curr = curr->next;
	}
	if (curr->data.getShirt() == "XL" && curr->data.getDues() == true)
	{
		counter++;
	}
	return counter;
}

size_t MemberList::sizeXXL()
{
	int counter = 0;
	MemberNode *curr = front;
	while (curr->next != NULL)
	{
		if (curr->data.getShirt() == "XXL" && curr->data.getDues() == true)
		{
			counter++;
		}
		curr = curr->next;
	}
	if (curr->data.getShirt() == "XXL" && curr->data.getDues() == true)
	{
		counter++;
	}
	return counter;
}

void MemberList::showXS()
{
	if (front == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			if (curr->data.getShirt() == "XS" && curr->data.getDues() == true)
			{
				cout << curr->data << endl;
			}
			curr = curr->next;
		}
		if (curr->data.getShirt() == "XS" && curr->data.getDues() == true)
		{
			cout << curr->data << endl;
		}
	}
}

void MemberList::showS()
{
	if (front == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			if (curr->data.getShirt() == "S" && curr->data.getDues() == true)
			{
				cout << curr->data << endl;
			}
			curr = curr->next;
		}
		if (curr->data.getShirt() == "S" && curr->data.getDues() == true)
		{
			cout << curr->data << endl;
		}
	}
}

void MemberList::showM()
{
	if (front == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			if (curr->data.getShirt() == "M" && curr->data.getDues() == true)
			{
				cout << curr->data << endl;
			}
			curr = curr->next;
		}
		if (curr->data.getShirt() == "M" && curr->data.getDues() == true)
		{
			cout << curr->data << endl;
		}
	}
}

void MemberList::showL()
{
	if (front == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			if (curr->data.getShirt() == "L" && curr->data.getDues() == true)
			{
				cout << curr->data << endl;
			}
			curr = curr->next;
		}
		if (curr->data.getShirt() == "L" && curr->data.getDues() == true)
		{
			cout << curr->data << endl;
		}
	}
}

void MemberList::showXL()
{
	if (front == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			if (curr->data.getShirt() == "XL" && curr->data.getDues() == true)
			{
				cout << curr->data << endl;
			}
			curr = curr->next;
		}
		if (curr->data.getShirt() == "XL" && curr->data.getDues() == true)
		{
			cout << curr->data << endl;
		}
	}
}

void MemberList::showXXL()
{
	if (front == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			if (curr->data.getShirt() == "XXL" && curr->data.getDues() == true)
			{
				cout << curr->data << endl;
			}
			curr = curr->next;
		}
		if (curr->data.getShirt() == "XXL" && curr->data.getDues() == true)
		{
			cout << curr->data << endl;
		}
	}
}

size_t MemberList::sizeBegin()
{
	int counter = 0;
	MemberNode *curr = front;
	while (curr->next != NULL)
	{
		if (curr->data.getLevel() == "B" || curr->data.getLevel() == "N")
		{
			counter++;
		}
		curr = curr->next;
	}
	if (curr->data.getLevel() == "B" || curr->data.getLevel() == "N")
	{
		counter++;
	}
	return counter;
}

size_t MemberList::sizeInter()
{
	int counter = 0;
	MemberNode *curr = front;
	while (curr->next != NULL)
	{
		if (curr->data.getLevel() == "I")
		{
			counter++;
		}
		curr = curr->next;
	}
	if (curr->data.getLevel() == "I")
	{
		counter++;
	}
	return counter;
}

size_t MemberList::sizeAdvan()
{
	int counter = 0;
	MemberNode *curr = front;
	while (curr->next != NULL)
	{
		if (curr->data.getLevel() == "A")
		{
			counter++;
		}
		curr = curr->next;
	}
	if (curr->data.getLevel() == "A")
	{
		counter++;
	}
	return counter;
}

void MemberList::showBegin()
{
	if (front == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			if (curr->data.getLevel() == "B" || curr->data.getLevel() == "N")
			{
				cout << curr->data << endl;
			}
			curr = curr->next;
		}
		if (curr->data.getLevel() == "B" || curr->data.getLevel() == "N")
		{
			cout << curr->data << endl;
		}
	}
}

void MemberList::showInter()
{
	if (front == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			if (curr->data.getLevel() == "I")
			{
				cout << curr->data << endl;
			}
			curr = curr->next;
		}
		if (curr->data.getLevel() == "I")
		{
			cout << curr->data << endl;
		}
	}
}

void MemberList::showAdvan()
{
	if (front == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			if (curr->data.getLevel() == "A")
			{
				cout << curr->data << endl;
			}
			curr = curr->next;
		}
		if (curr->data.getLevel() == "A")
		{
			cout << curr->data << endl;
		}
	}
}

size_t MemberList::sizeDues()
{
	int counter = 0;
	MemberNode *curr = front;
	while (curr->next != NULL)
	{
		if (curr->data.getDues() == true)
		{
			counter++;
		}
		curr = curr->next;
	}
	if (curr->data.getDues() == true)
	{
		counter++;
	}
	return counter;
}

void MemberList::showDues()
{
	if (front == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		MemberNode *curr = front;
		while (curr->next != NULL)
		{
			if (curr->data.getDues() == true)
			{
				cout << curr->data << endl;
			}
			curr = curr->next;
		}
		if (curr->data.getDues() == true)
		{
			cout << curr->data << endl;
		}
	}
}

void MemberList::groupSort(GroupsList &groupslist)
{
	//Makes a temporary group that is to be tested by the groupCheck method
	//If it passes, it is inserted into the grouplist parameter and the members are removed from MemberList
	//If it fails, the group is disbanded and the cycle continues
	Groups tempGroup;

	//nullGroup is made to re-initialize the object to default
	Groups nullGroup;

	//The use of random number generation will be used to assist the organization of groups
	//Since there is no deterministic method of organizing musicians, random is the only method I could find
	srand((unsigned)time(NULL));

	//Ensures the entire list can output groups until the list is empty
	while (!empty())
	{
		cout << "System Reset" << endl;

		if (sizeAllMembers() < 5)
		{
			break;
		}
		
		tempGroup = nullGroup;

		//Created a curr node to be put into a group
		MemberNode *curr = front;

		//Iterates over each five members
		for (int i=0; i<5; i++)
		{

			if (sizeAllMembers() < 5)
			{
				break;
			}

			curr = front;

			//Randomly assigns a location to the curr node
			int randomPosition = rand() % (sizeAllMembers() + 1);

			//Traverses to the location for curr node
			for (int j=0; j<randomPosition; j++)
			{
				curr = curr->next;
			}

			//Ensures that admins are not included in the group
			if (curr->data.getInstrument() == "Admin")
			{
					curr = curr->next;
			}

			//Changes the member's group data to true
			curr->data.setGroup(true);

			//Adds the member to the temporary group
			tempGroup.addMember(curr->data);

			//Removes from the MembersList in order to avoid the random assignment from choosing the same member
			deleteMember(curr->data.getFirst(), curr->data.getLast());
		}

		cout << tempGroup;

		//Uses the groupCheck method to verify if the group is balanced
		if (groupCheck(tempGroup))
		{
			cout << "Group Check: PASSED" << endl;
			//If it follows through, the group is added to the GroupsList and kept off of the MembersList
			groupslist.addGroup(tempGroup);

			cout << "Group is ADDED" << endl;
		}
		else
		{
			cout << "Group Check: FAILED" << endl;
			//If the groupCheck fails, a temporary member object is made to return the members back to the MemberList
			Member tempMember;

			//Makes a nullMember to reset
			Member nullMember;

			for (int i=0; i<5; i++)
			{
				//Resets every iteration
				tempMember = nullMember;

				if (tempGroup.empty())
				{
					break;
				}

				//Takes out the last member of the group and places it into the temporary member object
				tempMember = tempGroup.checkLast();
				tempGroup.removeMember();

				//Readjust to the member's information on groups since it failed the groupCheck
				tempMember.setGroup(false);

				//Returns the temporary member back to the MemberList
				addMember(tempMember);
			}

			cout << "Group is REMOVED" << endl;
		}

	}

} 

//This function will be used as a check whether the generated group will pass based on the following guidelines:
//		1) It is suggested that each group has at least two instrumentalists
//		2) It is suggested that 3 out of 5 of the group members share a genre preference
//		3) It is suggested that 3 out of 5 of the group members share the same amount of experience
bool MemberList::groupCheck(const Groups &group)
{
	int pointThreshold = 20;
	int pointInstrumentalist = 5;
	int pointGenre = 3;
	string genreCheck = group.findDominantGenre();
	int pointLevel = 1;
	string levelCheck = group.findDominantLevel();

	int pointCheck = 0;

	//Below checks to see who in the group is an instrumentalist and adds five points to the group pointCheck
	if (group.getOne().getInstrument() == "Guitar" || group.getOne().getInstrument() == "Piano" || 
		group.getOne().getInstrument() == "Strings" || group.getOne().getInstrument() == "WoodwindBrass")
	{
		pointCheck = pointCheck + pointInstrumentalist;
	}
	if (group.getTwo().getInstrument() == "Guitar" || group.getTwo().getInstrument() == "Piano" || 
		group.getTwo().getInstrument() == "Strings" || group.getTwo().getInstrument() == "WoodwindBrass")
	{
		pointCheck = pointCheck + pointInstrumentalist;
	}
	if (group.getThree().getInstrument() == "Guitar" || group.getThree().getInstrument() == "Piano" || 
		group.getThree().getInstrument() == "Strings" || group.getThree().getInstrument() == "WoodwindBrass")
	{
		pointCheck = pointCheck + pointInstrumentalist;
	}
	if (group.getFour().getInstrument() == "Guitar" || group.getFour().getInstrument() == "Piano" || 
		group.getFour().getInstrument() == "Strings" || group.getFour().getInstrument() == "WoodwindBrass")
	{
		pointCheck = pointCheck + pointInstrumentalist;
	}
	if (group.getFive().getInstrument() == "Guitar" || group.getFive().getInstrument() == "Piano" || 
		group.getFive().getInstrument() == "Strings" || group.getFive().getInstrument() == "WoodwindBrass")
	{
		pointCheck = pointCheck + pointInstrumentalist;
	}

	//Below checks to see who in the group shares the same genre and adds it to the group pointCheck
	if (group.getOne().getGenre() == genreCheck)
	{
		pointCheck = pointCheck + pointGenre;
	}
	if (group.getTwo().getGenre() == genreCheck)
	{
		pointCheck = pointCheck + pointGenre;
	}
	if (group.getThree().getGenre() == genreCheck)
	{
		pointCheck = pointCheck + pointGenre;
	}
	if (group.getFour().getGenre() == genreCheck)
	{
		pointCheck = pointCheck + pointGenre;
	}
	if (group.getFive().getGenre() == genreCheck)
	{
		pointCheck = pointCheck + pointGenre;
	}

	//Below checks to see who in the group shares the same level and adds it to the group pointCheck
	if (group.getOne().getLevel() == levelCheck)
	{
		pointCheck = pointCheck + pointLevel;
	}
	if (group.getTwo().getLevel() == levelCheck)
	{
		pointCheck = pointCheck + pointLevel;
	}
	if (group.getThree().getLevel() == levelCheck)
	{
		pointCheck = pointCheck + pointLevel;
	}
	if (group.getFour().getLevel() == levelCheck)
	{
		pointCheck = pointCheck + pointLevel;
	}
	if (group.getFive().getLevel() == levelCheck)
	{
		pointCheck = pointCheck + pointLevel;
	}

	//Below checks to see if all the group members are instrumentalist and sets the pointCheck to 0
	if ((group.getOne().getInstrument() == "Guitar" || group.getOne().getInstrument() == "Piano" || 
		group.getOne().getInstrument() == "Strings" || group.getOne().getInstrument() == "WoodwindBrass") &&
		(group.getTwo().getInstrument() == "Guitar" || group.getTwo().getInstrument() == "Piano" || 
		group.getTwo().getInstrument() == "Strings" || group.getTwo().getInstrument() == "WoodwindBrass") &&
		(group.getThree().getInstrument() == "Guitar" || group.getThree().getInstrument() == "Piano" || 
		group.getThree().getInstrument() == "Strings" || group.getThree().getInstrument() == "WoodwindBrass") &&
		(group.getFour().getInstrument() == "Guitar" || group.getFour().getInstrument() == "Piano" || 
		group.getFour().getInstrument() == "Strings" || group.getFour().getInstrument() == "WoodwindBrass") &&
		(group.getFive().getInstrument() == "Guitar" || group.getFive().getInstrument() == "Piano" || 
		group.getFive().getInstrument() == "Strings" || group.getFive().getInstrument() == "WoodwindBrass"))
	{
		pointCheck = 0;
	}

	//Below finally returns true if it passed the point check program or false if it falls short of points
	if (pointCheck < pointThreshold)
	{
		return false;
	}
	else
	{
		return true;
	}
}