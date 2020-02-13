
#include <iostream>
#include <string>
#include <fstream>

#include "Member.h"
#include "MemberList.h"
#include "Groups.h"
#include "GroupsList.h"

using namespace std;

int main(void)
{
	MemberList MTC;
	GroupsList MTC_Groups;
	int option = 0;
	int option2 = 0;
	int option3 = 0;
	int option4 = 0;
	int option5 = 0;
	int option6 = 0;
	int option7 = 0;
	cout << "Welcome to the Musical Therapy Club Group Organizing Algorithm!" << endl;
	cout << "PLEASE READ BEFORE ENTERING DATA:" << endl
		 << "Use correct capitalization and spelling" << endl
		 << "or else the program will fail to recognize it." << endl;
	cout << endl;
	cout << "1) Import spreadsheet data from a spreadsheet '.txt' file" << endl
		 << "2) Add a new member" << endl
		 << "3) Remove a member" << endl
		 << "4) Modify a member" << endl
		 << "5) Show all members" << endl
		 << "6) Initiate algorithm" << endl
		 << "7) Export spreadsheet data onto a new '.txt' file" << endl
		 << "8) Switch to the Member View-mode Menu" << endl
		 << "9) Switch to Group List User Interface" << endl
		 << "10) Exit the User Interface" << endl;
	cout << endl;
	while (option != 10)
	{
		cout << "Please choose your option: ";
		cin >> option;
		cout << endl;
		switch (option)
		{
			case 1:
			{
				string iFile;
				ifstream iStream;
				cout << "What would you like to name your file?: ";
				cin >> iFile;
				iStream.open(iFile.c_str());
				iStream >> MTC;
				MTC.organizeList();
				cout << "Data has been imported from " << iFile << "!" << endl;
				cout << endl;
				break;
			}
			case 2:
			{	
				string first, last, email, instrument, shirt, genre, condition, level, condition2;
				bool group, dues;
				cout << "Please enter the first name of the member: ";
				cin >> first;
				cout << "Please enter the last name of the member: ";
				cin >> last;
				cout << "Please enter the email of the member: ";
				cin >> email;
				cout << "Please enter the instrument the member plays: ";
				cin >> instrument;
				//Below simplifies the instrument to more general sections
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
				cout << "Please enter the shirt size: ";
				cin >> shirt;
				cout << "Please enter the member's preferred genre: ";
				cin >> genre;
				//Below simplifies the genre into more general sections
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
				if (genre == "Jazz" || genre == "Funk" || genre == "Motown" || 
					genre == "Blues" || genre == "Soul")
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
				cout << "Has the member paid dues? (Yes/No): ";
				cin >> condition2;
				if (condition2 == "Yes" || condition2 == "yes" || condition2 == "Y" || condition2 == "y")
				{
					dues = true;
				}
				else
				{
					dues = false;
				}
				cout << "What is the skill level of the member? Please only enter one letter (N/B/I/A): ";
				cin >> level;
				cout << "Is the member currently in a group? (Yes/No): ";
				cin >> condition;
				if (condition == "Yes" || condition == "yes" || condition == "Y" || condition == "y")
				{
					group = true;
				}
				else
				{
					group = false;
				}

				Member New(first, last, email, instrument, shirt, genre, level, dues, group);

				MTC.addMember(New);
				MTC.organizeList();
				cout << "Member has been added!" << endl;
				cout << endl;
				break;
			}

			case 3:
			{
				MTC.removeMember();
				cout << "Member has been deleted!" << endl;
				cout << endl;
				break;
			}

			case 4:
			{
				MTC.modifyMember();
				MTC.organizeList();
				cout << endl;
				break;
			}

			case 5:
			{
				MTC.showAllMembers();
				cout << endl;
				break;
			}

			case 6:
			{
				MTC.groupSort(MTC_Groups);
				break;
			}
			case 7:
			{
				string oFile;
				ofstream oStream;
				cout << "What would you like to name your file?: ";
				cin >> oFile;
				oStream.open(oFile.c_str());
				oStream << MTC;
				cout << "Data has been exported to " << oFile << "!" << endl;
				cout << endl;
				break;
			}

			case 8:
			{
				while (option2 != 6)
				{
					cout << "Welcome to the Member View-mode Menu!" << endl
						 << "Here you have tools to view member statistics" << endl
						 << "1) View statistics on instruments" << endl
						 << "2) View statistics on genres" << endl
						 << "3) View statistics on level" << endl
						 << "4) View statistics on shirt sizes" << endl
						 << "5) View statistics on dues" << endl
						 << "6) Exit Member View-mode Menu" << endl;
					cout << "Please choose your option: ";
					cin >> option2;
					cout << endl;
					switch (option2)
					{
						case 1:
						{
							cout << "Statistics on instruments: " << endl
								 << "1) Show members that sing" << endl
								 << "2) Show memebers that play guitar" << endl
								 << "3) Show members that play piano" << endl
								 << "4) Show members that play percussion" << endl
								 << "5) Show members that play strings" << endl
								 << "6) Show members that play woodwind or brass" << endl
								 << "7) Show members that play other/unique instruments" << endl
								 << "8) Show the numbers" << endl
								 << "9) Exit Statistics on instruments" << endl;
							while (option3 != 9)
							{	
								cout << "Please choose your option: ";
								cin >> option3;
								cout << endl;
								switch (option3)
								{
									case 1:
									{
										MTC.showVocals();
										cout << endl;
										break;
									}
									case 2:
									{
										MTC.showGuitars();
										cout << endl;
										break;
									}
									case 3:
									{
										MTC.showPianos();
										cout << endl;
										break;
									}
									case 4:
									{
										MTC.showPercussion();
										cout << endl;
										break;
									}
									case 5:
									{
										MTC.showStrings();
										cout << endl;
										break;
									}
									case 6:
									{
										MTC.showWoodwindBrass();
										cout << endl;
										break;
									}
									case 7:
									{
										MTC.showEtcInstruments();
										cout << endl;
										break;
									}
									case 8:
									{
										cout << "Members that sing: " << MTC.sizeVocals() << endl
											 << "Members that play guitar: " << MTC.sizeGuitars() << endl
											 << "Members that play piano: " << MTC.sizePianos() << endl
											 << "Members that play percussion: " << MTC.sizePercussion() << endl
											 << "Members that play strings: " << MTC.sizeStrings() << endl
											 << "Members that play woodwind/brass: " << MTC.sizeWoodwindBrass() << endl
											 << "Members that play unique instruments: " << MTC.sizeEtcInstruments() << endl;
										 break;
									}
									case 9:
									{
										break;
									}
									default:
									{
										cout << "Statistics on instruments: " << endl
											 << "1) Show members that sing" << endl
											 << "2) Show memebers that play guitar" << endl
											 << "3) Show members that play piano" << endl
											 << "4) Show members that play percussion" << endl
											 << "5) Show members that play strings" << endl
											 << "6) Show members that play woodwind or brass" << endl
											 << "7) Show members that play other/unique instruments" << endl
											 << "8) Show the numbers" << endl
											 << "9) Exit Statistics on instruments" << endl;
										cout << "Please input a valid option" << endl;
										break;
									}
								}
							}
							break;
						}
						case 2:
						{
							cout << "Statistics on genre: " << endl
								 << "1) Show members that have no preferred genre" << endl
								 << "2) Show members that prefer Pop music" << endl
								 << "3) Show members that prefer Rock music" << endl
								 << "4) Show members that prefer Classical music" << endl
								 << "5) Show members that prefer Jazz music" << endl
								 << "6) Show members that prefer Hip Hop music" << endl
								 << "7) Show members that prefer Bluegrass/Country music" << endl
								 << "8) Show members that prefer other/unique genres" << endl
								 << "9) Show the numbers" << endl
								 << "10) Exit Statistics on genre" << endl;
							while (option4 != 10)
							{
								cout << "Please choose your option: ";
								cin >> option4;
								cout << endl;
								switch (option4)
								{
									case 1:
									{
										MTC.showAny();
										cout << endl;
										break;
									}
									case 2:
									{
										MTC.showPop();
										cout << endl;
										break;
									}
									case 3:
									{
										MTC.showRock();
										cout << endl;
										break;
									}
									case 4:
									{	
										MTC.showClassical();
										cout << endl;
										break;
									}
									case 5:
									{
										MTC.showJazz();
										cout << endl;
										break;
									}
									case 6:
									{
										MTC.showHipHop();
										cout << endl;
										break;
									}
									case 7:
									{
										MTC.showCountry();
										cout << endl;
										break;
									}
									case 8:
									{
										MTC.showEtcGenre();
										cout << endl;
										break;
									}
									case 9:
									{
										cout << "Members that prefer any genre: " << MTC.sizeAny() << endl
											 << "Members that prefer Pop: " << MTC.sizePop() << endl
											 << "Members that prefer Rock: " << MTC.sizeRock() << endl
											 << "Members that prefer Classical: " << MTC.sizeClassical() << endl
											 << "Members that prefer Jazz: " << MTC.sizeJazz() << endl
											 << "Members that prefer Hip Hop: " << MTC.sizeHipHop() << endl
											 << "Members that prefer Bluegrass/Country: " << MTC.sizeCountry() << endl
											 << "Members that prefer unique genres: " << MTC.sizeEtcGenre() << endl;	
										break;
									}
									case 10:
									{
										break;
									}
									default:
									{
										cout << "Statistics on genre: " << endl
											 << "1) Show members that have no preferred genre" << endl
											 << "2) Show members that prefer Pop music" << endl
											 << "3) Show members that prefer Rock music" << endl
											 << "4) Show members that prefer Classical music" << endl
											 << "5) Show members that prefer Jazz music" << endl
											 << "6) Show members that prefer Hip Hop music" << endl
											 << "7) Show members that prefer Bluegrass/Country music" << endl
											 << "8) Show members that prefer other/unique genres" << endl
											 << "9) Show the numbers" << endl
											 << "10) Exit Statistics on genre" << endl;
										cout << "Please input a valid option" << endl;
										break;
									}
								}
							}
							break;
						}
						case 3:
						{
							cout << "Statistics on levels" << endl
								 << "1) Show members that are beginner" << endl
								 << "2) Show members that are intermediate" << endl
								 << "3) Show members that are advanced" << endl
								 << "4) Show the numbers" << endl
								 << "5) Exit Statistics on level" << endl;
							while (option5 != 5)
							{
								cout << "Please choose your option: ";
								cin >> option5;
								cout << endl;
								switch (option5)
								{
									case 1:
									{
										MTC.showBegin();
										cout << endl;
										break;
									}
									case 2:
									{
										MTC.showInter();
										cout << endl;
										break;
									}
									case 3:
									{
										MTC.showAdvan();
										cout << endl;
										break;
									}
									case 4:
									{
										cout << "Members that are beginner: " << MTC.sizeBegin() << endl
											 << "Members that are intermediate: " << MTC.sizeInter() << endl
											 << "Members that are advanced: " << MTC.sizeAdvan() << endl;
										break;
									}
									case 5:
									{
										break;
									}
									default:
									{
										cout << "Statistics on levels" << endl
											 << "1) Show members that are beginner" << endl
											 << "2) Show members that are intermediate" << endl
											 << "3) Show members that are advanced" << endl
											 << "4) Show the numbers" << endl
											 << "5) Exit Statistics on level" << endl;
										cout << "Please input a valid option" << endl;
										break;
									}
								}
							}
							break;
						}
						case 4:
						{
							cout << "Statistics on shirt sizes of those who paid dues" << endl
								 << "1) Show members with XS shirt size" << endl
								 << "2) Show members with S shirt size" << endl
								 << "3) Show members with M shirt size" << endl
								 << "4) Show members with L shirt size" << endl
								 << "5) Show members with XL shirt size" << endl
								 << "6) Show members with XXL shirt size" << endl
								 << "7) Show the numbers" << endl
								 << "8) Exit Statistics on shirt sizes" << endl;
							while (option6 != 8)
							{
								cout << "Please choose your option: ";
								cin >> option6;
								cout << endl;
								switch (option6)
								{
									case 1:
									{
										MTC.showXS();
										cout << endl;
										break;
									}
									case 2:
									{
										MTC.showS();
										cout << endl;
										break;
									}
									case 3:
									{
										MTC.showM();
										cout << endl;
										break;
									}
									case 4:
									{
										MTC.showL();
										cout << endl;
										break;
									}
									case 5:
									{
										MTC.showXL();
										cout << endl;
										break;
									}
									case 6:
									{
										MTC.showXXL();
										cout << endl;
										break;
									}
									case 7:
									{
										cout << "Members with XS shirt size: " << MTC.sizeXS() << endl
											 << "Members with S shirt size: " << MTC.sizeS() << endl
											 << "Members with M shirt size: " << MTC.sizeM() << endl
											 << "Members with L shirt size: " << MTC. sizeL() << endl
											 << "Members with XL shirt size: " << MTC.sizeXL() << endl
											 << "Members with XXL shirt size: " << MTC.sizeXXL() << endl;
										break; 
									}
									case 8:
									{
										break;
									}
									default:
									{
										cout << "Statistics on shirt sizes of those who paid dues" << endl
											 << "1) Show members with XS shirt size" << endl
											 << "2) Show members with S shirt size" << endl
											 << "3) Show members with M shirt size" << endl
											 << "4) Show members with L shirt size" << endl
											 << "5) Show members with XL shirt size" << endl
											 << "6) Show members with XXL shirt size" << endl
											 << "7) Show the numbers" << endl
											 << "8) Exit Statistics on shirt sizes" << endl;
										cout << "Please input a valid option" << endl;
										break;
									}
								}
							}
 							break;

						}
						case 5:
						{
							cout << "Statistics on dues" << endl
								 << "1) Show members that have paid dues" << endl
								 << "2) Show the numbers" << endl
								 << "3) Exit Statistics on dues" << endl;
							while (option7 != 3)
							{
								cout << "Please choose your option: ";
								cin >> option7;
								cout << endl;
								switch (option7)
								{
									case 1:
									{
										MTC.showDues();
										cout << endl;
										break;
									}
									case 2:
									{
										cout << "Members that have paid dues: " << MTC.sizeDues() << endl;
										break;
									}
									case 3:
									{
										break;
									}
									default:
									{
										cout << "Statistics on dues" << endl
											 << "1) Show members that have paid dues" << endl
											 << "2) Show the numbers" << endl
											 << "3) Exit Statistics on dues" << endl;
										cout << "Please input a valid option" << endl;
										break;
									}
								}
							}
							break;
						}
						case 6:
						{
							cout << "1) Import spreadsheet data from a spreadsheet '.txt' file" << endl
								 << "2) Add a new member" << endl
								 << "3) Remove a member" << endl
								 << "4) Modify a member" << endl
								 << "5) Show all members" << endl
								 << "6) Initiate algorithm" << endl
								 << "7) Export spreadsheet data onto a new '.txt' file" << endl
								 << "8) Switch to the Member View-mode Menu" << endl
								 << "9) Switch to Group List User Interface" << endl
								 << "10) Exit the User Interface" << endl;
							cout << endl;
							break;
						}
						default:
						{
							cout << "Welcome to the Member View-mode Menu!" << endl
								 << "Here you have tools to view member statistics" << endl
								 << "1) View statistics on instruments" << endl
								 << "2) View statistics on genres" << endl
								 << "3) View statistics on level" << endl
								 << "4) View statistics on shirt sizes" << endl
								 << "5) View statistics on dues" << endl
								 << "6) Exit Member View-mode Menu" << endl;
							cout << "Please input a valid option" << endl;
							break;
						}
					}
				}
			}
			case 9:
			{
				break;
			}

			default:
			{
				cout << "1) Import spreadsheet data from a spreadsheet '.txt' file" << endl
					 << "2) Add a new member" << endl
					 << "3) Remove a member" << endl
					 << "4) Modify a member" << endl
					 << "5) Show all members" << endl
					 << "6) Initiate algorithm" << endl
					 << "7) Export spreadsheet data onto a new '.txt' file" << endl
					 << "8) Switch to the Member View-mode Menu" << endl
					 << "9) Switch to Group List User Interface" << endl
					 << "10) Exit the User Interface" << endl;
				cout << endl;
				break;
			}
		}
	}
	cout << "Exited Main Menu. Thank you for using the MTC User Interface" << endl;

}
