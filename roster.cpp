#include "roster.h"
#include "student.h"
#include <string>
#include <iostream>
using std::string;
using std::cout;


// Will be using C++ Parsing Technique 4 from course tips section as reference
// E2A Parse each set of data identified in the “studentData Table.”
void Roster::parseData(std::string studentData) {
	int rhs = studentData.find(",");
	string studentID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int course1 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int course2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int course3 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	DegreeProgram degreeprogram;
	if (studentData.at(lhs) == 'N') {
		degreeprogram = NETWORK;
	}
	else if ((studentData.at(lhs) == 'S') && (studentData.at(lhs + 1) == 'E')) {
		degreeprogram = SECURITY;
	}
	else if ((studentData.at(lhs) == 'S') && (studentData.at(lhs + 1) == 'O')) {
		degreeprogram = SOFTWARE;
	}

	add(studentID, firstName, lastName, emailAddress, age, course1, course2, course3, degreeprogram);
}

// E3A sets the instance variables from part D1 and updates the roster.
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int CompletionDays[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++lastrow] = new Student(studentID, firstName, lastName, emailAddress, age, CompletionDays, degreeProgram);
}

// E3B removes students from the roster by student ID
void Roster::remove(string studentID) {
	bool success = false;
	for (int i = 0; i <= lastrow; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			success = true;
			if (i < rows - 1) {
				Student* sub = classRosterArray[i];
				classRosterArray[i] = classRosterArray[rows - 1];
				classRosterArray[rows - 1] = sub;
			}
			Roster::lastrow--;
		}
	}
	if (success) {
		cout << "Removing: " << studentID << std::endl;
	}
	else {
		cout << "Student ID: " << studentID << " not found." << std::endl; //If the student ID does not exist, the function prints an error message indicating that the student was not found
	}
}

// E3C loop through all the students in classRosterArray and call the print() function for each student.
void Roster::printAll() {
	for (int i = 0; i <= Roster::lastrow; i++) {
		classRosterArray[i]->print();
	}
	cout << std::endl;
}

// E3D prints a student’s average number of days in the three courses.
void Roster::printAverageDaysInCourse(std::string studentID) {
	for (int i = 0; i <= Roster::lastrow; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) { // The student is identified by the studentID parameter.
			cout << studentID << ": ";
			cout << (classRosterArray[i]->getCompletionDays()[0] + classRosterArray[i]->getCompletionDays()[1] + classRosterArray[i]->getCompletionDays()[2]) / 3 << std::endl;
		}
	}
}

// E3E verifies student email addresses and displays all invalid email addresses to the user.
void Roster::printInvalidEmails()
{
	bool check = false;
	for (int i = 0; i <= lastrow; i++) {
		string valid = (classRosterArray[i]->getEmailAddress());
		if (valid.find('@') == string::npos || valid.find('.') == string::npos || valid.find(' ') != string::npos) { // A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
			check = true;
			cout << classRosterArray[i]->getStudentID() << ": " << classRosterArray[i]->getEmailAddress() << std::endl;
		}
	}
}

// E3F prints out student information for a degree program specified by an enumerated type.
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i < rows; ++i) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}

// F5 Implement the destructor to release the memory that was allocated dynamically in Roster.
Roster::~Roster() {
	for (int i = 0; i < rows; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}