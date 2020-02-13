
#include <iostream>
#include <string>

#include "Member.h"
#include "Groups.h"

using namespace std;

Groups::Groups() {}

Groups::Groups(string Groupname, Member One, Member Two, Member Three, Member Four, Member Five)
{
	groupname = Groupname;
	one = One;
	two = Two;
	three = Three;
	four = Four;
	five = Five;
}

Groups::Groups(const Groups &other)
{
	groupname = other.groupname;
	one = other.one;
	two = other.two;
	three = other.three;
	four = other.four;
	five = other.five;

}

Groups::~Groups() {}

Groups &Groups::operator=(const Groups &rhs)
{
	groupname = rhs.groupname;
	one = rhs.one;
	two = rhs.two;
	three = rhs.three;
	four = rhs.four;
	five = rhs.five;
}

bool Groups::empty()
{
	Member nullMember;
	if (one == nullMember && two == nullMember && three == nullMember &&
		four == nullMember && five == nullMember)
	{
		return true;
	}
	else
	{
		return false;
	}

}

string Groups::getGroupName()
{
	return groupname;
}

void Groups::setGroupName(string Groupname)
{
	groupname = Groupname;
}

Member Groups::getOne() const
{
	return one;
}

void Groups::setOne(Member One)
{
	one = One;
}

Member Groups::getTwo() const
{
	return two;
}

void Groups::setTwo(Member Two)
{
	two = Two;
}

Member Groups::getThree() const
{
	return three;
}

void Groups::setThree(Member Three)
{
	three = Three;
}

Member Groups::getFour() const
{
	return four;
}

void Groups::setFour(Member Four)
{
	four = Four;
}

Member Groups::getFive() const
{
	return five;
}

void Groups::setFive(Member Five)
{
	five = Five;
}

void Groups::addMember(Member newMember)
{
	Member nullMember;

	if (one == nullMember)
	{
		one = newMember;
	}
	else if (two == nullMember)
	{
		two = newMember;
	}
	else if (three == nullMember)
	{
		three = newMember;
	}
	else if (four == nullMember)
	{
		four = newMember;
	}
	else if (five == nullMember)
	{
		five = newMember;
	}
}

Member Groups::checkLast()
{
	Member nullMember;

	if (!(five == nullMember))
	{
		return five;
	}
	else if (!(four == nullMember))
	{
		return four;
	}
	else if (!(three == nullMember))
	{
		return three;
	}
	else if (!(two == nullMember))
	{
		return two;
	}
	else if (!(one == nullMember))
	{
		return one;
	}
}

void Groups::removeMember()
{
	Member nullMember;

	if (!(five == nullMember))
	{
		five = nullMember;
	}
	else if (!(four == nullMember))
	{
		four = nullMember;
	}
	else if (!(three == nullMember))
	{
		three = nullMember;
	}
	else if (!(two == nullMember))
	{
		two = nullMember;
	}
	else if (!(one == nullMember))
	{
		one = nullMember;
	}
}

string Groups::findDominantGenre() const
{
	int pointStrengthOne = 0, pointStrengthTwo = 0, pointStrengthThree = 0, pointStrengthFour = 0, pointStrengthFive = 0;
	int maxPoint = 0;

	//Below assigns a point system to each member's genre to take a number count on which is greater
	string dominantGenre = one.getGenre();
	if (two.getGenre() == dominantGenre)
	{
		pointStrengthOne++;		
	}
	if (three.getGenre() == dominantGenre)
	{
		pointStrengthOne++;		
	}
	if (four.getGenre() == dominantGenre)
	{
		pointStrengthOne++;		
	}
	if (five.getGenre() == dominantGenre)
	{
		pointStrengthOne++;		
	}
	dominantGenre = two.getGenre();
	if (one.getGenre() == dominantGenre)
	{
		pointStrengthTwo++;		
	}
	if (three.getGenre() == dominantGenre)
	{
		pointStrengthTwo++;		
	}
	if (four.getGenre() == dominantGenre)
	{
		pointStrengthTwo++;		
	}
	if (five.getGenre() == dominantGenre)
	{
		pointStrengthTwo++;		
	}
	dominantGenre = three.getGenre();
	if (one.getGenre() == dominantGenre)
	{
		pointStrengthThree++;		
	}
	if (two.getGenre() == dominantGenre)
	{
		pointStrengthThree++;		
	}
	if (four.getGenre() == dominantGenre)
	{
		pointStrengthThree++;		
	}
	if (five.getGenre() == dominantGenre)
	{
		pointStrengthThree++;		
	}
	dominantGenre = four.getGenre();
	if (one.getGenre() == dominantGenre)
	{
		pointStrengthFour++;		
	}
	if (two.getGenre() == dominantGenre)
	{
		pointStrengthFour++;		
	}
	if (three.getGenre() == dominantGenre)
	{
		pointStrengthFour++;		
	}
	if (five.getGenre() == dominantGenre)
	{
		pointStrengthFour++;		
	}
	dominantGenre = five.getGenre();
	if (one.getGenre() == dominantGenre)
	{
		pointStrengthFive++;		
	}
	if (two.getGenre() == dominantGenre)
	{
		pointStrengthFive++;		
	}
	if (three.getGenre() == dominantGenre)
	{
		pointStrengthFive++;		
	}
	if (four.getGenre() == dominantGenre)
	{
		pointStrengthFive++;		
	}

	//Below places the points into an array and uses a for loop to find the maximum value in the array
	int arrayFind[] = {pointStrengthOne, pointStrengthTwo, pointStrengthThree, pointStrengthFour, pointStrengthFive};
	for (int i=0; i<5; i++)
	{
		if (maxPoint < arrayFind[i])
		{
			maxPoint = arrayFind[i];
		}
	}

	//After finding the maximum value, the below statements check to ensure the points align 
	if (maxPoint == pointStrengthOne)
	{
		return one.getGenre();
	}
	if (maxPoint == pointStrengthTwo)
	{
		return two.getGenre();
	}
	if (maxPoint == pointStrengthThree)
	{
		return three.getGenre();
	}
	if (maxPoint == pointStrengthFour)
	{
		return four.getGenre();
	}
	if (maxPoint == pointStrengthFive)
	{
		return five.getGenre();
	}
}

string Groups::findDominantLevel() const
{
	int pointStrengthOne = 0, pointStrengthTwo = 0, pointStrengthThree = 0, pointStrengthFour = 0, pointStrengthFive = 0;
	int maxPoint = 0;


	//Below assigns a point system to each member's genre to take a number count on which is greater
	string dominantLevel = one.getLevel();
	if (two.getLevel() == dominantLevel)
	{
		pointStrengthOne++;		
	}
	if (three.getLevel() == dominantLevel)
	{
		pointStrengthOne++;		
	}
	if (four.getLevel() == dominantLevel)
	{
		pointStrengthOne++;		
	}
	if (five.getLevel() == dominantLevel)
	{
		pointStrengthOne++;		
	}
	dominantLevel = two.getLevel();
	if (one.getLevel() == dominantLevel)
	{
		pointStrengthTwo++;		
	}
	if (three.getLevel() == dominantLevel)
	{
		pointStrengthTwo++;		
	}
	if (four.getLevel() == dominantLevel)
	{
		pointStrengthTwo++;		
	}
	if (five.getLevel() == dominantLevel)
	{
		pointStrengthTwo++;		
	}
	dominantLevel = three.getLevel();
	if (one.getLevel() == dominantLevel)
	{
		pointStrengthThree++;		
	}
	if (two.getLevel() == dominantLevel)
	{
		pointStrengthThree++;		
	}
	if (four.getLevel() == dominantLevel)
	{
		pointStrengthThree++;		
	}
	if (five.getLevel() == dominantLevel)
	{
		pointStrengthThree++;		
	}
	dominantLevel = four.getLevel();
	if (one.getLevel() == dominantLevel)
	{
		pointStrengthFour++;		
	}
	if (two.getLevel() == dominantLevel)
	{
		pointStrengthFour++;		
	}
	if (three.getLevel() == dominantLevel)
	{
		pointStrengthFour++;		
	}
	if (five.getLevel() == dominantLevel)
	{
		pointStrengthFour++;		
	}
	dominantLevel = five.getLevel();
	if (one.getLevel() == dominantLevel)
	{
		pointStrengthFive++;		
	}
	if (two.getLevel() == dominantLevel)
	{
		pointStrengthFive++;		
	}
	if (three.getLevel() == dominantLevel)
	{
		pointStrengthFive++;		
	}
	if (four.getLevel() == dominantLevel)
	{
		pointStrengthFive++;		
	}

	//Below places the points into an array and uses a for loop to find the maximum value in the array
	int arrayFind[] = {pointStrengthOne, pointStrengthTwo, pointStrengthThree, pointStrengthFour, pointStrengthFive};
	for (int i=0; i<5; i++)
	{
		if (maxPoint < arrayFind[i])
		{
			maxPoint = arrayFind[i];
		}
	}

	//After finding the maximum value, the below statements check to ensure the points align 
	if (maxPoint == pointStrengthOne)
	{
		return one.getLevel();
	}
	if (maxPoint == pointStrengthTwo)
	{
		return two.getLevel();
	}
	if (maxPoint == pointStrengthThree)
	{
		return three.getLevel();
	}
	if (maxPoint == pointStrengthFour)
	{
		return four.getLevel();
	}
	if (maxPoint == pointStrengthFive)
	{
		return five.getLevel();
	}
}

ostream &operator<<(ostream & os, const Groups &group)
{
	os << group.groupname << endl
	   << group.one << endl
	   << group.two << endl
	   << group.three << endl
	   << group.four << endl
	   << group.five << endl
	   << endl;
	return os;
}