#pragma once
#include <iostream>
#include "Degree.h"
#include "student.h"


using namespace std;

class Roster {

public:

	//an array of pointers and set them to null thus not point to any memory location
	Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
	
	Roster();//setter for blank roster
	~Roster();//destructor 

	//function for processing the data table of students provided, function will parse and populate the class roster array
	void parseAndAdd(const string studentData[]);


	//this is to add individual student with prefilled information
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID); //removes students from the roster by student Id, if id does not exist print error message
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails(); //Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
	void printByDegreeProgram(DegreeProgram degreeProgram);

	

private:

	



};