#pragma once
#include <iostream>
#include "degree.h"

using namespace std;

class Student
{
public:
    const  static int daysInCourseArraySize = 3;//max amount of classes each person will have

    Student(); //setter for blank student

    //setter-constructor for using all of the input parameters that are given on the table
    Student(string studentIDInfo, string firstNameInfo, string lastNameInfo, string emailAddressInfo, int ageInfo, int numberOfDaysToCompleteInfo[], DegreeProgram degreeProgamInfo);

    //all getters and setter functions are public so they can access the private information
    //getter functions
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getNumberOfDaysToComplete();
    DegreeProgram getDegreeProgram();

    //setter functions
    void setStudentID(string studentIDInfo);
    void setFirstName(string firstNameInfo);
    void setLastName(string lastNameInfo);
    void setEmailAddress(string EmailAddressInfo);
    void setAge(int AgeInfo);
    void setNumberOfDaysToComplete(int NumberOfDaysToCompleteInfo[]);
    void setDegreeProgram(DegreeProgram degreeProgramInfo);


    //print function will print out the information from the individual student
    void print();

    //deconstructor of the student to release memory
    ~Student();



private:
    //these vars will hold private student information
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int numberOfDaysToComplete[daysInCourseArraySize];
    DegreeProgram theDegreeProgram;

};