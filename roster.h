#pragma once
#include <string>
#include "student.h"
#include <string>
using namespace std;

class Roster {
public:

	const static int rows = 5; // Roster will have 5 rows for each student
	int lastrow = -1; // this is value of last row in roster
	Student* classRosterArray[rows]; // E1 Create an array of pointers, classRosterArray
	void parseData(string row); // Will be used to parse roster data
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram); //E3A sets the instance variables from part D1 and updates the roster
	void remove(string studentID); // E3B removes students from the roster by student ID
	void printAll(); // E3C prints a complete tab-separated list of student data
	void printAverageDaysInCourse(string studentID); // E3D prints a student’s average number of days in the three courses
	void printInvalidEmails(); // E3E verifies student email addresses and displays all invalid email addresses to the user
	void printByDegreeProgram(DegreeProgram degreeProgram); // E3F prints out student information for a degree program specified by an enumerated type
	~Roster(); // F5 Implement the destructor to release the memory that was allocated dynamically in Roster.
};