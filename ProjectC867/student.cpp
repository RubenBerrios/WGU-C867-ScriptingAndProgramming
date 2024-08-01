#include <iostream>
#include "student.h"


using namespace std;

 Student::Student()
{
	 this->studentID = "";
	 this->firstName = "";
	 this->lastName = "";
	 this->emailAddress = "";
	 this->age = 0;

	 for (int i = 0; i < daysInCourseArraySize; i++)
	 {
		 this->numberOfDaysToComplete[i] = 0;
	 }

	 this->theDegreeProgram = DegreeProgram::SOFTWARE;
}
 
 Student::Student(string studentIDInfo, string firstNameInfo, string lastNameInfo, string emailAddressInfo, int ageInfo, int numberOfDaysToCompleteInfo[], DegreeProgram degreeProgamInfo) 
 {
	 this->studentID = studentIDInfo;
	 this->firstName = firstNameInfo;
	 this->lastName = lastNameInfo;
	 this->emailAddress = emailAddressInfo;
	 this->age = ageInfo;

	 for (int i = 0; i < daysInCourseArraySize; i++)
	 {
		 this->numberOfDaysToComplete[i] = numberOfDaysToCompleteInfo[i];
	 }

	 this->theDegreeProgram = degreeProgamInfo;

 }


 // getter functions to access the information stored in this student
 string Student::getStudentID()
 {
     return studentID;
 }
 string Student::getFirstName()
 {
     return firstName;
 }
 string Student::getLastName()
 {
     return lastName;
 }
 string Student::getEmailAddress()
 {
     return emailAddress;
 }
 int Student::getAge()
 {
     return age;
 }
 int* Student::getNumberOfDaysToComplete()
 {
     return numberOfDaysToComplete;
 }
 DegreeProgram Student::getDegreeProgram()
 {
     return theDegreeProgram;
 }

 // setter functions to set data for student id, first name, last name, email, age, number of days to complete and program enrolled in
 void Student::setStudentID(string studentIDInfo)
 {
     this->studentID = studentIDInfo;
 }
 void Student::setFirstName(string firstNameInfo)
 {
     this->firstName = firstNameInfo;

 }
 void Student::setLastName(string lastNameInfo)
 {
     this->lastName = lastNameInfo;
 }
 void Student::setEmailAddress(string EmailAddressInfo)
 {
     this->emailAddress = EmailAddressInfo;

 }
 void Student::setAge(int AgeInfo)
 {
     this->age = AgeInfo;
 }
 void Student::setNumberOfDaysToComplete(int NumberOfDaysToCompleteInfo[])
 {
     //loop through to copy the contents of one array to the other
     for (int i = 0; i < daysInCourseArraySize; i++)
     {
         this->numberOfDaysToComplete[i] = NumberOfDaysToCompleteInfo[i];
     }
 }
 void Student::setDegreeProgram(DegreeProgram degreeProgramInfo)
 {
     this->theDegreeProgram = degreeProgramInfo;
 }

 
 //printing function to print out all the info from this specific student
 void Student::print()
 {
     cout << getStudentID() << "\t" << getFirstName() << "\t" << getLastName() << "\t" << getEmailAddress() << "\t" << getAge() <<
         "\t{" << getNumberOfDaysToComplete()[0] << "," << getNumberOfDaysToComplete()[1] << "," << getNumberOfDaysToComplete()[2] << "}\t" << DegreeProgramString[getDegreeProgram()] << endl;
 }

 //destructor to release memory space
 Student::~Student()
 {
	
 }
