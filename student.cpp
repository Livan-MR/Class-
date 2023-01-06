#include <iostream>
#include <string>
#include "student.h"
using namespace std;

// D2C All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.
// D2D  constructor using all of the input parameters provided in the table
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int CompletionDays[3], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < 3; ++i) {
		this->CompletionDays[i] = CompletionDays[i];
	}
	this->degreeProgram = degreeProgram;
}


Student::~Student() {}

// D2A an accessor (i.e., getter) for each instance variable from part D1
string Student::getStudentID() {
	return studentID;
}
string Student::getFirstName() {
	return firstName;
}
string Student::getLastName() {
	return lastName;
}
string Student::getEmailAddress() {
	return emailAddress;
}
int Student::getAge() {
	return age;
}
int* Student::getCompletionDays() {
	return CompletionDays;
}
DegreeProgram Student::getDegreeProgram() {
	return degreeProgram;
}



// D2B a mutator (i.e., setter) for each instance variable from part D1
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setCompletionDays(int CompletionDays[]) {
	for (int i = 0; i < 3; ++i) {
		this->CompletionDays[i] = CompletionDays[i];
	}
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}


// D2Eprint() to print specific student data
void Student::print() {
	cout << studentID << "\t";
	cout << firstName << "\t   "; // added three spaces here for better formatting
	cout << lastName << "\t";
	cout << age << "\t";
	cout << "{" << CompletionDays[0] << ", " << CompletionDays[1] << ", " << CompletionDays[2] << "}" << "\t";
	cout << degreeprogram[this->getDegreeProgram()] << endl;
}