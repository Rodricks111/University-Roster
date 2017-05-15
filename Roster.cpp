//
//  Roster.cpp
//  HomeWork5
//
//  Created by Rodricks Christian on 11/12/15.
//  Copyright (c) 2015 Rodricks Christian. All rights reserved.
//
#include <iostream>
#include "Roster.hpp"
#include <string>

using namespace std;

//Constructors


Roster::Roster () {
    cout << "Please enter the course name: ";
    getline(cin, courseName);
    cout << "Please enter the course number: ";
    getline(cin, courseCode);
    cout << "Please enter the instructor's name: ";
    getline(cin, instructor);
    cout << "# of credits granted for completion of the course: ";
    cin >> numOfCredits;
    while (numOfCredits < 1 || numOfCredits > 4) {
        cout << "Please enter a valid number of credits";
        cin>>numOfCredits;
    }
    cout<<"Enter Number of Student allowed in this course: ";
    cin>>Students_Cap;
    
    studentList=new Student*[Students_Cap];
    
    
	studentsEnrolled = 0;
}

const Student& Roster::operator[](int index) {
    if(index >= 0 || index < studentsEnrolled)
        return *studentList[index];
    exit(1);
}

Roster::Roster (string course, string courseNumber, string professor, int credits, int Capacity)
: courseName(course), courseCode(courseNumber), instructor(professor), numOfCredits(credits) {
    if (numOfCredits < 0) {
        numOfCredits = 3;
    }
    Students_Cap=Capacity;
     studentList=new Student*[Students_Cap];
    studentsEnrolled = 0;
    
}


Roster::Roster(const Roster& rhs){

    courseName= rhs.courseName;
    courseCode= rhs.courseCode;
    instructor=rhs.instructor;
    numOfCredits=rhs.numOfCredits;
    studentsEnrolled=rhs.studentsEnrolled;
    Students_Cap=rhs.Students_Cap;
    
    studentList = new Student*[rhs.Students_Cap];
    for(int i=0; i<studentsEnrolled; i++)
    {
        studentList[i]= new Student(*rhs.studentList[i]);
    }
    
}
Roster& Roster::operator = (const Roster& rhs){
    
    if(this != &rhs) {
        courseName= rhs.courseName;
        courseCode= rhs.courseCode;
        instructor=rhs.instructor;
        numOfCredits=rhs.numOfCredits;
        studentsEnrolled=rhs.studentsEnrolled;
        Students_Cap=rhs.Students_Cap;
    
        studentList = new Student*[rhs.Students_Cap];
        for(int i=0; i<studentsEnrolled; i++)
        {
            studentList[i]= new Student(*rhs.studentList[i]);
        }
    }
    return *this;
}

Roster::~Roster(){
    if (studentList!= NULL) {
        for(int i = 0; i < studentsEnrolled; i++) {
            delete studentList[i];
        }
        delete[] studentList;
        studentList=NULL;
    }
}


//Mutators
void Roster:: grow(){
    Students_Cap=Students_Cap*2+1;
    Student** temp= new Student*[Students_Cap];
    
    for(int i =0; i<Students_Cap; i++)
    {
        temp[i]=studentList[i];
    }
    delete[] studentList;
    studentList=temp;
    
}

void Roster::addStudent () {
    if (studentsEnrolled == Students_Cap) {
        cout<<"Roaster size is full. Would you like to double the size.\n";
        char y;
        cin >>y;
        if(y=='y'||y=='Y')
        {
            grow();
            cout<<"Roaster size has been increased....\n";
        }
        else
            cout<<"Roaster is full. It cannot acept more Student for this class, so sorry :( ";
        return;
        
    }
    Student* aStudent = new Student();
	cin >> *aStudent;
    studentList[studentsEnrolled] = aStudent;
    ++studentsEnrolled;
}

void Roster::addStudent (Student* aStudent) {
    if (studentsEnrolled == Students_Cap) {
        cout<<"Roaster size is full. Would you like to double the size.\n";
        char y;
        cin >>y;
        if(y=='y'||y=='Y')
        {
        grow();
        cout<<"Roaster size has been increased....\n";
        }
        else
            cout<<"Roaster is full. It cannot acept more Student for this class, so sorry :( ";
        return;
    }
    studentList[studentsEnrolled] = aStudent;
    ++studentsEnrolled;
}

void Roster::addStudent (Student* newStudents[], int numOfStudents) {
    if (studentsEnrolled == Students_Cap) {
        cout<<"Roaster size is full. Would you like to double the size.\n";
        char y;
        cin >>y;
        if(y=='y'||y=='Y')
        {
            grow();
            cout<<"Roaster size has been increased....\n";
        }
        else
            cout<<"Roaster is full. It cannot acept more Student for this class, so sorry :( ";
        return;
    }
    
    for (int count = 0; count < numOfStudents; ++count, ++studentsEnrolled) {
        studentList[studentsEnrolled] = newStudents[count];
        
    if (count < numOfStudents) {
        cout << "The roster for " << courseName << " was only able to " <<
        "accomodate " << count << " student(s)\n";
    }
}
}

void Roster::addStudentCap(int Students_Capacity)
{
    Students_Cap=Students_Capacity;
}


void Roster::deleteStudent (int index) {
    for (int i = index; i < Students_Cap - 1; ++i) {
        studentList[i] = studentList[i + 1];
    }
   *studentList[studentsEnrolled - 1] = Student();
    --studentsEnrolled;
}

int  Roster::getStudentCap()
{
    return Students_Cap;
}


string Roster::getCourseName () const {
    return courseName;
}

string Roster::getCourseCode () const {
    return courseCode;
}

string Roster::getInstructorName () const {
    return instructor;
}

int Roster::getNumOfCredits () const {
    return numOfCredits;
}


ostream& operator<<(ostream& output, const Roster& currentRoster)
{
    output << "==============================\n";
    output<< "Course: " << currentRoster.courseName << "\n";
    output << "Course Code: " << currentRoster.courseCode << "\n";
    output << "Instructor: " << currentRoster.instructor << "\n";
    output << "Students Currently Enrolled: " << currentRoster.studentsEnrolled << "\n";
    output << "==============================\n";
    for (int i = 0; i < currentRoster.studentsEnrolled; ++i){
        output << *currentRoster.studentList[i];
    }
    output << "------------------------------\n";
    return output;
}


/*void Roster::findStudent () {
    cout << "Please enter the student's last name: ";
    string lastName;
    cin >> lastName;
    findStudentHelper(lastName);
}*/


/*
void Roster::findStudentHelper (std::string lastName) {
    int *foundStudents = new int[studentsEnrolled];
    int numFound = 0;
    for (int i = 0; i < studentsEnrolled; ++i) {
        if (lowerConvert(studentList[i].getLastName()) == lowerConvert(lastName)) {
            cout << numFound + 1 << ". " + studentList[i].getFullName() + "\n";
            foundStudents[numFound] = i;
            numFound++;
        }
    }
    
    //If no students are found, return to the caller.
    if (numFound == 0) {
        cout << "No students were found.\n";
        return;
    }
    
    int selectedStudent = foundStudents[0];
    
    //If more than one student with the same last name is found, Ask for the correct one
    if (numFound > 1) {
        cout << "Please choose a student: ";
        int studentChosen;
        cin >> studentChosen;
        while (studentChosen < 1 | studentChosen > numFound) {
            cout << "Please enter a valid number: ";
            cin >> studentChosen;
        }
        selectedStudent = foundStudents[studentChosen - 1];
        
    }
    cout << studentList[selectedStudent].getFullName() << "\n";
    
    //Display the list of options avaiable.
    const int numOfOptions = 3;
    const string options[numOfOptions] = {"Delete", "Display Info", "Continue"};
    for (int i = 0; i < numOfOptions; ++i) {
        cout << i + 1 << ") " << options[i] << "\n";
    }
    cout << "Please choose an option: ";
    char optionChosen;
    cin >> optionChosen;
    while (optionChosen < '1' || optionChosen > static_cast<char>('0' + numOfOptions)) {
        cout << "Please enter a valid number: ";
        cin >> optionChosen;
    }
    switch (optionChosen) {
        case '1':
            deleteStudent(selectedStudent);
            break;
        case '2':
            studentList[selectedStudent].displayInfo();
            break;
        case '3':
        default:
            break;
    }
    
}*/


//Accessors

/*void Roster::displayRoster () const {
    cout << "==============================\n";
    cout << "Course: " << courseName << "\n";
    cout << "Course Code: " << courseCode << "\n";
    cout << "Instructor: " << instructor << "\n";
    cout << "Credits: " << numOfCredits << "\n";
    cout << "Students Currently Enrolled: " << studentsEnrolled << "\n";
    cout << "==============================\n";
    for (int i = 0; i < studentsEnrolled; ++i) {
        cout << studentList[i].getFirstName() + " " + studentList[i].getLastName() << "\n";
    }
    cout << "------------------------------\n";
}*/



//Driver
/*
 void Roster:: driver()
 {
 setCourseName("Object Oriented Programming C++");
 setCourseName("CSC 211");
 setCredit(3);
 SetInstructorName("Dr. Alayev");
 setStudent(0);
 setStudent(1);
 selectionSort(student, MAX_CAPACITY);
 count<<*this;
 }
 //Other Functions
 
 const string Roster::lowerConvert (string data) {
 for (int i = 0; i < data.length(); ++i) {
 data[i] = static_cast<char>(tolower(data[i]));
 }*/
//return data;
//}

