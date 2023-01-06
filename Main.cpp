#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main() {
	// F1 Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
	cout << "Scripting and Programming - Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: #001520260" << endl;
	cout << "Livan Martinez" << endl;
	cout << endl;

	const string studentData[] = {
		  "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		  "A5,Livan,Martinez,lmartin7@wgu.edu,23,10,15,20,SOFTWARE"
	};

	// F2 Create an instance of the Roster class called classRoster.
	Roster classRoster;
	const int row = 5;

	// F3 Parse data then add each student to classRoster.
	for (int i = 0; i < row; i++) {
		classRoster.parseData(studentData[i]);
	}

	// F4 Convert pseudo code printAll()
	cout << "Student List " << endl;
	classRoster.printAll();
	cout << endl;

	// Calls for printInvalidEmails class in roster
	cout << "Invalid Emails: " << endl;
	classRoster.printInvalidEmails();
	cout << endl;

	// Calls for printAverageDaysInCourse class in roster
	cout << "Average Days In Course: " << endl;
	for (int i = 0; i < row; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	cout << endl;

	// Calls for printByDegreeProgram class in roster
	cout << "Students in software degree program: " << endl;
	classRoster.printByDegreeProgram((DegreeProgram)2);
	cout << endl;

	// Calls for remove class in roster
	cout << "Removing student A3: " << endl;
	classRoster.remove("A3");
	cout << endl;

	// Calls for updated printAll() class in roster after removing A3
	cout << "Student List: " << endl;
	classRoster.printAll();
	cout << endl;

	// Calls for remove class but this time will print else function since A3 was removed
	cout << "Removing student A3: " << endl;
	classRoster.remove("A3");
	cout << endl;

	system("pause");
	return 0;
}