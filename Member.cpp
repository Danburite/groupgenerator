
#include <iostream>
#include <string>

#include "Member.h"

using namespace std;

Member::Member() 
{
	first.clear();
	last.clear();
	email.clear();
	instrument.clear();
	shirt.clear();
	genre.clear();
	level.clear();
	dues = false;
	group = false;

}

Member::Member(string First, string Last, string Email, string Instrument, string Shirt, string Genre, string Level, bool Dues, bool Group)
{
	first = First;
	last = Last;
	email = Email;
	instrument = Instrument;
	shirt = Shirt;
	genre = Genre;
	level = Level;
	dues = Dues;
	group = Group;
}

Member::~Member() {}

Member &Member::operator=(const Member &copy)
{
	first = copy.first;
	last = copy.last;
	email = copy.email;
	instrument = copy.instrument;
	shirt = copy.shirt;
	genre = copy.genre;
	level = copy.level;
	dues = copy.dues;
	group = copy.group;
}

bool Member::operator==(const Member &copy)
{
	if (first == copy.first && last == copy.last && email == copy.email &&
		instrument == copy.instrument && shirt == copy.shirt &&
		genre == copy.genre && level == copy.level && dues == copy.dues && group == copy.group)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string Member::getFirst()
{
	return first;
}

void Member::setFirst(string First)
{
	first = First;
}

string Member::getLast()
{
	return last;
}

void Member::setLast(string Last)
{
	last = Last;
}

string Member::getEmail()
{
	return email;
}

void Member::setEmail(string Email)
{
	email = Email;
}

string Member::getInstrument()
{
	return instrument;
}

void Member::setInstrument(string Instrument)
{
	instrument = Instrument;
}

string Member::getShirt()
{
	return shirt;
}

void Member::setShirt(string Shirt)
{
	shirt = Shirt;
}

string Member::getGenre() const
{
	return genre;
}

void Member::setGenre(string Genre)
{
	genre = Genre;
}

string Member::getLevel() const
{
	return level;
}

void Member::setLevel(string Level)
{
	level = Level;
}
bool Member::getDues()
{
	return dues;
}

void Member::setDues(bool Dues)
{
	dues = Dues;
}

bool Member::getGroup()
{
	return group;
}
void Member::setGroup(bool Group)
{
	group = Group;
}

ostream &operator<<(ostream & os, const Member &member)
{
	os << member.last << "\t" << member.first << "\t" << member.email << "\t" << member.instrument << "\t"
	   << member.shirt << "\t" << member.genre << "\t" << member.level << "\t";
	if (member.dues == true)
	{
		os << "x";
	}
	else
	{
		os << " ";
	}
	return os;
}

void Member::reorganize()
{
	capitalize(first);
	capitalize(last);
	capitalize(instrument);
	allCapitalize(shirt);
	capitalize(genre);
	capitalize(level);

}

void Member::capitalize(string &string)
{
	switch (string[0])
	{
		case 'a':
		{
			string[0] = 'A';
			break;
		}
		case 'b':
		{
			string[0] = 'B';
			break;
		}
		case 'c':
		{
			string[0] = 'C';
			break;
		}
		case 'd':
		{
			string[0] = 'D';
			break;
		}
		case 'e':
		{
			string[0] = 'E';
			break;
		}
		case 'f':
		{
			string[0] = 'F';
			break;
		}
		case 'g':
		{
			string[0] = 'G';
			break;
		}
		case 'h':
		{
			string[0] = 'H';
			break;
		}
		case 'i':
		{
			string[0] = 'I';
			break;
		}
		case 'j':
		{
			string[0] = 'J';
			break;
		}
		case 'k':
		{
			string[0] = 'K';
			break;
		}
		case 'l':
		{
			string[0] = 'L';
			break;
		}
		case 'm':
		{
			string[0] = 'M';
			break;
		}
		case 'n':
		{
			string[0] = 'N';
			break;
		}
		case 'o':
		{
			string[0] = 'O';
			break;
		}
		case 'p':
		{
			string[0] = 'P';
			break;
		}
		case 'q':
		{
			string[0] = 'Q';
			break;
		}
		case 'r':
		{
			string[0] = 'R';
			break;
		}
		case 's':
		{
			string[0] = 'S';
			break;
		}
		case 't':
		{
			string[0] = 'T';
			break;
		}
		case 'u':
		{
			string[0] = 'U';
			break;
		}
		case 'v':
		{
			string[0] = 'V';
			break;
		}
		case 'w':
		{
			string[0] = 'W';
			break;
		}
		case 'x':
		{
			string[0] = 'X';
			break;
		}
		case 'y':
		{
			string[0] = 'Y';
			break;
		}
		case 'z':
		{
			string[0] = 'Z';
			break;
		}
		default:
		{
			break;
		}
	}
}

//This function's purpose was made for the shirt member in order to account for multi-lettered strings like XXL
void Member::allCapitalize(string &string)
{
	for (int i=0; i<string.length(); i++)
	{
		switch (string[i])
		{
			case 'a':
			{
				string[i] = 'A';
				break;
			}
			case 'b':
			{
				string[i] = 'B';
				break;
			}
			case 'c':
			{
				string[i] = 'C';
				break;
			}
			case 'd':
			{
				string[i] = 'D';
				break;
			}
			case 'e':
			{
				string[i] = 'E';
				break;
			}
			case 'f':
			{
				string[i] = 'F';
				break;
			}
			case 'g':
			{
				string[i] = 'G';
				break;
			}
			case 'h':
			{
				string[i] = 'H';
				break;
			}
			case 'i':
			{
				string[i] = 'I';
				break;
			}
			case 'j':
			{
				string[i] = 'J';
				break;
			}
			case 'k':
			{
				string[i] = 'K';
				break;
			}
			case 'l':
			{
				string[i] = 'L';
				break;
			}
			case 'm':
			{
				string[i] = 'M';
				break;
			}
			case 'n':
			{
				string[i] = 'N';
				break;
			}
			case 'o':
			{
				string[i] = 'O';
				break;
			}
			case 'p':
			{
				string[i] = 'P';
				break;
			}
			case 'q':
			{
				string[i] = 'Q';
				break;
			}
			case 'r':
			{
				string[i] = 'R';
				break;
			}
			case 's':
			{
				string[i] = 'S';
				break;
			}
			case 't':
			{
				string[i] = 'T';
				break;
			}
			case 'u':
			{
				string[i] = 'U';
				break;
			}
			case 'v':
			{
				string[i] = 'V';
				break;
			}
			case 'w':
			{
				string[i] = 'W';
				break;
			}
			case 'x':
			{
				string[i] = 'X';
				break;
			}
			case 'y':
			{
				string[i] = 'Y';
				break;
			}
			case 'z':
			{
				string[i] = 'Z';
				break;
			}
			default:
			{
				break;
			}
		}
	}
}