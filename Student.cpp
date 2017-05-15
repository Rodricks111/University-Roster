//
//  Student.cpp
//  HW 6
//
//  Created by Rodricks Christian on 11/17/15.
//  Copyright © 2015 Rodricks Christian. All rights reserved.
//
#include <iostream>
#include "Student.hpp"


using namespace std;

const double Student::MIN_GPA = 0.0;
const double Student::MAX_GPA = 4.0;

//Constructors

Student::Student() {
    firstName = "";
    lastName = "";
    gpa = MIN_GPA;
    credits = 0;
	ID = -1;
}

Student::Student(std::string last, std::string first, double gradeAvg, int creds, Date birthday, Date matriculationDate)
: lastName(last), firstName(first), gpa(gradeAvg), credits(creds), dob(birthday), matriculation(matriculationDate){
    if (credits < 0) { credits = 0; }
    if (gpa < MIN_GPA || gpa > MAX_GPA) { gpa = 0; }
    setStanding();
}

//Mutators

int Student::getID ( ) const { return ID; }

void Student::setCredits(int creds) {
    if (creds < 0) {
        cout << "Negative number of credits entered. The default value of 0 will be used.\n";
        credits = 0;
    }
    else {
        credits = creds;
    }
    setStanding();
}

void Student::setDob(const Date &birthday) {
    dob = birthday;
}

void Student::setFirstName(std::string first) {
    firstName = first;
}

void Student::setGpa(double gradeAvg) {
    if (gradeAvg < MIN_GPA || gradeAvg > MAX_GPA) {
        cout << "Invalid GPA entered, the default value of 0 will be used.\n";
        gpa = 0;
    } else {
        gpa = gradeAvg;
    }
}

void Student::setLastName(std::string last) {
    lastName = last;
}

void Student::setMatric( const Date &matric) {
    matriculation = matric;
}

//Accessors

int Student::getCredits() const {
    return credits;
}

std::string Student::getFirstName() const {
    return firstName;
}

const Date& Student::getDob() const {
    return dob;
}

std::string Student::getFullName () const {
    return firstName + " " + lastName;
}

void Student::setID(int id) {
	ID = id;
}

double Student::getGpa() const {
    return gpa;
}

std::string Student::getLastName() const {
    return lastName;
    
}

const Date& Student::getMatric() const {
    return matriculation;
}

std::string Student::getStanding() const {
    return standing;
}

//Other Functions

istream& operator>>(istream& input, Student& myStudent) {
    
    cout << "First name: ";
    input >> myStudent.firstName;
    cout << "Last name: ";
    input >> myStudent.lastName;
    cout << "Credits Earned: ";
    input >> myStudent.credits;
    cout << "Current GPA: ";
    input >> myStudent.gpa;
    cout << "Date of Birth:\n";
    input >> myStudent.dob;
    cout << "Matriculation Date:\n";
    input>> myStudent.matriculation;
	return input;
}

ostream& operator<<(ostream& output, const Student& myStudent) {
    output << "First Name: " << myStudent.firstName << "\n";
    output << "Last Name: " << myStudent.lastName << "\n";
    output << "Gpa: " << myStudent.gpa << "\n";
    output << "Credits Earned: " << myStudent.credits << "\n";
    output << "Current Standing: " << myStudent.standing << "\n";
    output << "Date of Birth: " << myStudent.dob << "\n";
    output << "Matriculation Date: " << myStudent.matriculation << "\n";
    output << "\n";
	return output;
}

void Student::setStanding() {
    if (credits > 105) {
        standing = "Graduate";
    } else if (credits > 90) {
        standing = "Lower Senior";
    } else if (credits > 75) {
        standing = "Upper Junior";
    } else if (credits > 60) {
        standing = "Lower Junior";
    } else if (credits > 45) {
        standing = "Upper Sophmore";
    } else if (credits > 30) {
        standing = "Lower Sophomore";
    } else if (credits > 15) {
        standing = "Upper Freshman";
    } else {
        standing = "Lower Freshman";
    }
}


bool Student::operator == (const Student& changeOp) const {
    return (lastName == changeOp.lastName &&
            firstName == changeOp.firstName &&
            ID == changeOp.ID);
    
}
bool Student::operator >= (const Student& changeOp) const {
    return !operator<(changeOp);
}
bool Student::operator <= (const Student& changeOp) const {
    return operator<(changeOp) || operator==(changeOp);
}
bool Student::operator != (const Student& changeOp) const {
    return !operator==(changeOp);
}
bool Student::operator < (const Student& changeOp) const {
    return (lastName < changeOp.lastName &&
            firstName < changeOp.firstName &&
            ID < changeOp.ID);
}
bool Student::operator >(const Student& changeOp) const {
    return !operator<(changeOp) && !operator == (changeOp);
}
