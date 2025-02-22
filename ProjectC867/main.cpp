#include <iostream>
#include "roster.h"

using namespace std;


int main()
{
	cout << "C867-Scripting & Programming: Applications\n" <<
		"Language: C++\nStudent ID: 010600672\nName: Ruben Berrios\n" << endl;
	
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Ruben,Berrios,rberri5@wgu.edu,29, 30,30,30,SOFTWARE"
	};
	

	//creates a roster and call the parse and add function to add students from the student data table to the roster
	Roster classRoster;
	classRoster.parseAndAdd(studentData);

	classRoster.printAll();

	
	
	classRoster.printInvalidEmails();

	//prints average days for each individual student
	for (int i = 0 ; i < 5; i++ )
	{
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	} 

	//display students in certain degree program
	classRoster.printByDegreeProgram(SOFTWARE);


	//remove student A3 print all students then try to delete student A3 again
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");
	
	
	return 0;
}
