#pragma once
#include <iostream>
#include "degree.h"
using namespace std;


class Student {
private:

	/* Create the class Student  in the files student.h, which includes each of the following variables:
* Student ID, Firstname, Lastname, Email, Age, Array of days to compelete course, degreeprogram.
* set to private for setter and getters to modify and access */
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int CompletionDays[3];
	DegreeProgram degreeProgram;

public:

	// Set up constructor using all of the input parameters provided in the table
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int completionDays[3], DegreeProgram degreeProgram);
	~Student();

	// Set up an accessor (i.e., getter) for each instance variable from part D1
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getCompletionDays();
	DegreeProgram getDegreeProgram();

	// Set up a mutator (i.e., setter) for each instance variable from part D1
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setCompletionDays(int CompletionDays[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	// print() to print specific student data
	void print();
};