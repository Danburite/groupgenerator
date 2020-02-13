File Name: Musician Group Generator
Author: Sherman Lee
Purpose: Queue-based data structure to organize members based on instrument for querying.

Version 1.0, October 20, 2018:	 
		Overall Structure:
			I set up the data structure as a queue for the database with the
			intent to allow for better traversal.

		Criteria:
			Requires information for last name, first name, email, 
			instrument, shirt size, genre preference, level of skill,
			dues paid, and whether they are currently in a group, respectively
			inline .txt file for each individual general member separated by 
			tabs. 

			Information originated from Google Sheets under
			the musicalunr@gmail.com drive under Fall 2018 Member List.
			By selecting the cells, copying and pasting the data into a .txt
			file, the information will fit the criteria for the requirements.

		Queries:
			The available queries in this database are:
				-Instruments
					-List of vocalists
					-List of guitarists
					-List of pianists
					-List of percussionists
					-List of string players
					-List of woodwind and brass players
					-List of unique instrument players
					-Numbers of each instrument
			 	-Genre
			 		-List of genre with no preference
			 		-List of pop genre
			 		-List of rock genre
			 		-List of classical genre
			 		-List of jazz genre
			 		-List of hip hop genre
			 		-List of bluegrass and country genre
			 		-List of unique genres
			 		-Numbers of each genre
			 	-Level of skill
			 		-List of beginner level members
			 		-List of intermediate level members
			 		-List of advanced level members
			 		-Number of each level of skill
			 	-Shirt size
			 		-List of XS shirt size
			 		-List of S shirt size
			 		-List of M shirt size
			 		-List of L shirt size
			 		-List of XL shirt size
			 		-List of XXL shirt size
			 		-Number of each shirt size
			 	-Dues paid
			 		-List of members who have paid dues
			 		-Number of members who have paid dues

		Additional Features:
			Group Generation Algorithm:
				Program is intended to generate optimal groups of 5 that considers
				instrument, level of skill, and genre preference as factors
				with the intent that these groups would be permanent; however,
				without considering the human social factor in the program, it
				was not able to achieve optimality. Instead, the program was a better
				fit for small activities that divided the members into temporary
				groups.

				Because the three factors involved compounded more complexity to
				the algorithm, the functionality of the algorithm had many failings.
				In the future I will plan on revising the algorithm that 
				automatically organizes the groups because it failed a majority of
				the time. 

		In Review:
			Utilizing a queue-based data structure was not optimal for
			a database. I will continue to research more methods to
			improve on it. Possibly use a hashtable.

			All information was intended to be a master datasheet to 
			query information whenever needed; however the information was
			rarely needed. 

			The major use of the program was intended for 
			activities involving group making in order to reduce time in
			manually assigning over 200 members to groups of 6.

		Future Revisions:
			The Group .cpp and .h files were intended to have another database
			on current groups but because of the nature of how fluid groups are
			in the club setting, it was rendered useless, so I am planning to
			remove this feature.

			I intend on removing queries that are not necessary for the group 
			making activity and will most likely set the criteria to only 
			involve: last name, first name, and instrument,	respectively.
			The group generation algorithm will be simplified to only consider
			instruments. Overall organization of code was somewhat messy.
