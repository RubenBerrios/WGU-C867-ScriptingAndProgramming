#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

Roster::Roster()
{

}

Roster::~Roster()
{
	//release the memory in the class roster array by deleting the students in it, automatically gets called at end of program
	for (int i = 0; i < 5; i++)
	{
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}

void Roster::parseAndAdd(const string studentData[])
{
	//sent the data table into this function and going to loop through and add each student individually
	//find commas to seperate into seperate var
	string studID = "";
	string FName = "";
	string LName = "";
	string EmailAdd = "";
	int age = 0;
	int DaysInCourse1;
	int DaysInCourse2;
	int DaysInCourse3;


	DegreeProgram dprogram;
	

	for (int i = 0; i < 5; i++)
	{
		size_t rhs = studentData[i].find(",");
		studID = studentData[i].substr(0, rhs);

		size_t lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		FName = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		LName = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		EmailAdd = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		age = stoi(studentData[i].substr(lhs, rhs - lhs));//stoi - convert string to int

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		DaysInCourse1 = stoi(studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		DaysInCourse2 = stoi(studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		DaysInCourse3 = stoi(studentData[i].substr(lhs, rhs - lhs));

		

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string strDegreeprogram = studentData[i].substr(lhs, rhs - lhs);


		//check to see what degree program was chosen by comparing string extracted. add function does not take string for degreeprogram
		if (strDegreeprogram == DegreeProgramString[0])
		{
			dprogram = DegreeProgram::SECURITY;
		}
		else if (strDegreeprogram == DegreeProgramString[1])
		{
			dprogram = DegreeProgram::NETWORK;
		}
		else if (strDegreeprogram == DegreeProgramString[2])
		{
			dprogram = DegreeProgram::SOFTWARE;
		}

		
		//once the data is parse for the individual student call the add method from here and pass it the information gathered
		add(studID, FName, LName, EmailAdd, age, DaysInCourse1, DaysInCourse2, DaysInCourse3, dprogram);

	}
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	//new student class asks for array of the 3 courses so convert the 3 vars to 1 array
	int courses[3] = { daysInCourse1, daysInCourse2,daysInCourse3 };

	//loop through class roster array checking if it is still null, if it is null add the student into that spot
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i] == nullptr)
		{
			//if spot in class roster array is empty create a new student with the info
			classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, courses, degreeprogram);
			break;//leave the loop otherwise will copy to the next slot 
		}
	}
	
}

void Roster::remove(string studentID)
{
	//will be used to check if student id matches with on in the class roster array
	bool studentFound = false;

	//print message stating removing student
	cout << "Removing " << studentID << ":" << endl;
	
	//loop through the roster class array looking to see if the student id matches
	for (int i = 0; i < 5; i++)
	{
		//first make sure that the slot in class array is populated and not a nullptr, if not nullptr then check the studentID otherwise skip trying to check if studentID matches
		if (classRosterArray[i] != nullptr)
		{
			if (classRosterArray[i]->getStudentID() == studentID)
			{
				//if student is found stop looking for the rest of the loop, turn the bool of studentfound to true, delete the student and set that spot in the class array to null 
				studentFound = true;
				delete classRosterArray[i];
				classRosterArray[i] = nullptr;
				break;
			}
		}	
	}


	
	//if student was not found print student not found message
	if (!studentFound)
	{
		cout << "The student with the ID: " << studentID << " was not found." << endl;
		
	}
	
}

void Roster::printAll()
{
	//loop through all of class roster and call the print function for each student
	cout << "\nDisplaying all students:" << endl;

	for (int i = 0; i < 5; i++)
	{
		//check if the slot is populated by checking if it is set to nullptr, if nullptr don't try to display
		if (classRosterArray[i] != nullptr)
		{
			classRosterArray[i]->print();
		}
		
	}
	 
}

void Roster::printAverageDaysInCourse(string studentID)
{
	
	//look for the specific student in the class roster array
	for (int i = 0, avg = 0; i < 5; i++, avg = 0)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			//if the student id matches what was passed, find the average days
			//cout << classRosterArray[i]->getNumberOfDaysToComplete()[0] << endl;

			for (int j = 0; j < 3; j++)
			{
				avg += classRosterArray[i]->getNumberOfDaysToComplete()[j];
			}

			avg /= 3;
			cout <<"Student ID: "<< studentID << ", average days in course is: " << avg << endl ;
		}
	}
}

void Roster::printInvalidEmails()
{
	cout << "\nDisplaying Invalid emails:" << endl;

	//loop through class roster and check if email is invalid by making sure it has an @ and . and no spaces
	for (int i = 0; i < 5; i++)
	{
		//if find invalid
		if((classRosterArray[i]->getEmailAddress().find('@') == string::npos) || (classRosterArray[i]->getEmailAddress().find('.') == string::npos) || 
			(classRosterArray[i]->getEmailAddress().find(' ') != string::npos))
		{
			//print the email address that are invalid
			cout << classRosterArray[i]->getEmailAddress() << " - is invalid." << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	cout << "\nShowing students in degree program: " << DegreeProgramString[degreeProgram] << endl;
	
	//loop through class roster array to find students in specific degree program and print the info
	for (int i = 0; i < 5; i++)
	{
		
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram)
		{
			cout << classRosterArray[i]->getStudentID() << "\t" << classRosterArray[i]->getFirstName() << "\t"<< classRosterArray[i]->getLastName() << classRosterArray[i]->getAge() <<
				"\t{" << classRosterArray[i]->getNumberOfDaysToComplete()[0] << "," << classRosterArray[i]->getNumberOfDaysToComplete()[1] << "," << classRosterArray[i]->getNumberOfDaysToComplete()[2] << "}\t" << DegreeProgramString[classRosterArray[i]->getDegreeProgram()] << endl;
		}
	}	
}

