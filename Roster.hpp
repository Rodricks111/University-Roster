//
//  Roster.h
//  HomeWork5
//
//  Created by Rodricks Christian on 11/12/15.
//  Copyright (c) 2015 Rodricks Christian. All rights reserved.
//

#ifndef HomeWork5_Roster_h
#define HomeWork5_Roster_h

#include <string>
#include <iostream>
#include "Student.hpp"

//#define MAX_CAPACITY 10
using namespace std;


class Roster {
public:
    static const std::string lowerConvert (std::string data);
    
    
    //Constructors
    
    Roster ();
    ~Roster();
    Roster(const Roster& rhs);
    Roster& operator = (const Roster& rhs);
    const Student& operator[](int index);
    
    Roster (std::string course, std::string courseNumber, std::string professor, int credits, int Capacity);
    
    //Accessor Functions
    
    string getCourseName () const;
    
    int getStudentCap();
    
    std::string getCourseCode ()const;
    
    std::string getInstructorName () const;
   
    int getNumOfCredits () const;
    
    int getSize();
    
    //Mutator Functions
    
    void addStudent ();
    
    void addStudentCap(int Student_Capacity);
    
    void addStudent (Student* aStudent);
    
    void addStudent (Student* newStudents[], int numOfStudents);
    
    void editStudent(int index);
    
    void outputAllStudents();
    
    void setRanStudent();
    void setSize();
    
    
    int findStudent ();
    void deleteStudent (int index);
    
    //Other Functions
    
    friend std::ostream& operator<<(std::ostream& output, const Roster& current);
    
    friend std::istream& operator>>(std::istream& input, Roster& current);
    
private:
    
    //Mutator Functions
    
    
    void  grow();
    //void findStudentHelper (std::string last);
    
    string courseName;
    string courseCode;
    string instructor;
    int numOfCredits;
    Student** studentList;
    int studentsEnrolled;
    int Students_Cap;
    
    
    //Selectionsort with template
    template< class T>
    void selectionSort(T a[], int size)
    {
        int indexofSmallest=0;
        for(int i=0; i<size-1; i++)
        {
            indexofSmallest=i;
            for(int j=i+1; j<size; j++)
            {
                if(a[j] <a[indexofSmallest])
                {
                    indexofSmallest=j;
                }
            }
            if(i!=indexofSmallest)
            {
                swapValues(a[i],a[indexofSmallest]);
            }
        }
    }
    template< class T>
    void swapValues(T& a, T& b)
    {
        T temp =1;
        a=b;
        b=temp;
    }
};


#endif //ROSTER_HPP

