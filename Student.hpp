//
//  Student.h
//  HomeWork5
//
//  Created by Rodricks Christian on 11/12/15.
//  Copyright (c) 2015 Rodricks Christian. All rights reserved.
//

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include "Date.hpp"

class Student {
public:
    //Constructors
    
    Student();
    
    Student(std::string last, std::string first, double gradeAvg, int creds, Date birthday, Date matriculationDate);
    
    //Accessors
   
    
    int getCredits() const;
    
    const Date& getDob() const;
    
    
    std::string getFirstName() const;
    
    double getGpa() const;
    
    std::string getLastName() const;
    
    const Date& getMatric() const;
    
    std::string getStanding() const;
    
    std::string getFullName() const;
    
	void setID(int id);
    
	//Mutators
    int getID() const;
    
    void setCredits(int creds);
    
    void setDob(const Date &birthday);
    
    void setFirstName(std::string first);
    
    void setGpa(double gradeAvg);
    
    void setLastName(std::string last);
    
    void setMatric(const Date &matric);
    
    bool operator == (const Student& changeOP) const;
    bool operator >= (const Student& changeOP) const;
    bool operator <= (const Student& changeOP) const;
    bool operator != (const Student& changeOP) const;
    bool operator < (const Student& changeOP) const;
    bool operator >(const Student& changeOP) const;
 
	friend std::istream& operator>>(std::istream& input, Student& myStudent);
	friend std::ostream& operator<<(std::ostream& input, const Student& myStudent);

private:
    //Mutators
    
    void setStanding();
    int ID;
    
    //variables
    static const double MAX_GPA;
    static const double MIN_GPA;
    
    std::string lastName;
    std::string firstName;
    double gpa;
    int credits;
    std::string standing;
    Date dob;
    Date matriculation;
};


#endif //STUDENT_HPP
