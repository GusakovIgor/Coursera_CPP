#include <iostream>
#include <string>

using namespace std;


struct Specialization
{
	string value;

	explicit Specialization (const string& init_value)
	{
		value = init_value;
	}
};

struct Course
{
	string value;

	explicit Course (const string& init_value)
	{
		value = init_value;
	}
};

struct Week
{
	string value;

	explicit Week (const string& init_value)
	{
		value = init_value;
	}
};


struct LectureTitle
{
	string specialization;
	string course;
	string week;

	LectureTitle (
					const Specialization& init_specialization, 
	 				const Course& init_course, 
	 				const Week& init_week
	 			 )
	{
		specialization = init_specialization.value;
		course = init_course.value;
		week = init_week.value;
	}
};




/*
int main ()
{
	// Should work:

	LectureTitle title
	(
    	Specialization("C++"),
    	Course("White belt"),
    	Week("4th")
	);


	// Shouldn't work:

	LectureTitle title ("C++", "White belt", "4th");

	LectureTitle title (string("C++"), string("White belt"), string("4th"));

	LectureTitle title = {"C++", "White belt", "4th"};

	LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};

	LectureTitle title
	(
	    Course("White belt"),
	    Specialization("C++"),
	    Week("4th")
	);

	LectureTitle title
	(
	    Specialization("C++"),
	    Week("4th"),
	    Course("White belt")
	);

	return 0;
}
*/