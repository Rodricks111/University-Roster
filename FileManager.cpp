//
//  FileManager.cpp
//  Homework6
//
//  Created by Rodricks Christian on 11/30/15.
//  Copyright © 2015 Rodricks Christian. All rights reserved.
//

#include "FileManager.hpp"
#include <iostream>
#include<fstream>
#include "RosterManagement.hpp"
#include "Roster.hpp"
using namespace std;

FileManager:: FileManager(): UserName(" "), password(" "), Supervisor(-1)
{
    Supervisor = DatabaseAccess();
}
FileManager:: ~FileManager()
{
    
}
//mutators
void FileManager::setUsername(const string user) {UserName = user;}
void FileManager::setPassword(const string pass) { password= pass;}
void FileManager::setSupervisor(const int super) { password=super;}
void FileManager::start()
{
    int choice;
    cout<<"Select an option"<<endl;
    cout<<"1. log in"<<endl;
    cout<<"2. sign up"<<endl;
    cin>>choice;
    
    switch(choice){
        case 1:
            login();
            break;
        case 2:
            cin >> *this;
            DatabaseAccess();
            break;
        default:
            cout<<choice<< ": is not a valid option. Please try again.\n\n";
            start();
            break;
    }
}

void FileManager::login()
{
    cout<<"Username";
    cin>>UserName;
    DatabaseAccess();
}

void FileManager::writeDatabase()
{
    ofstream outputFile("Database.txt",ofstream::app);
    if(outputFile.is_open()){
        outputFile<<UserName<<" "<<password<<" "<<Supervisor<<"\n";
    }
    else{cout<<"Error: file did not open!\n";}
    outputFile.close();
}
void FileManager::writeRoster(const Roster currentRoster[])
{
    ofstream outputFile("Roster.txt");
    if(outputFile.is_open()){
        for(int i=0; i<currentRoster->getStudentCap(); i++)
        outputFile<<currentRoster[i].getCourseName()<<" | "<<
        currentRoster[i].getCourseCode()<<" | "<<
        currentRoster[i].getNumOfCredits()<< " | "<<
        currentRoster[i].getInstructorName()<<"\n";
        for(int i=0; i<currentRoster[i].getSize(); ++i)
        {
            outputFile<<currentRoster[i].getStudent[i]<<endl;
        }
        outputFile<<"end_roster|\n";
    }
  else{cout<<"Error: file did not open!\n";}
    outputFile.close();
}

void FileManager::readRoster(RosterManagement myManagement){
    ifstream inputFile("Roster.txt");
    string rosterLine, studentLine;
    if(inputFile.is_open()){
        while(getline(cin,rosterLine)){
            Roster tempRoster;
            parseRosterLine(rosterLine, tempRoster);
            while(getline(cin,studentLine)){
                if(studentLine=="end_roster|") {break;}
                Student aStudent;
                parseStudentLine(studentLine, aStudent);
                tempRoster.addStudent(&aStudent);
            }
        }
    }
}

void FileManager::parseRosterLine(string aRosterLine, Roster& aRoster){
    string courseName, courseCode, InstructorName;
    int crds;
    unsigned long int posOfLine1, posOfLine2;
    
    posOfLine1=aRosterLine.find('|');
    courseName=aRosterLine.substr(0, posOfLine1-2);
    
    posOfLine2=aRosterLine.find('|', posOfLine1+1);
    courseCode=aRosterLine.substr(posOfLine1 +2 , posOfLine2-posOfLine1-3);
    
    posOfLine1=posOfLine2;
    posOfLine2=aRosterLine.find('|', posOfLine1+1);
    crds=stoi(aRosterLine.substr(posOfLine1 +2 , posOfLine2-posOfLine1-3));
    
    posOfLine1=posOfLine2;
    InstructorName=aRosterLine.substr(posOfLine1+2, aRosterLine.length()-posOfLine1-2);
}

void FileManager::parseStudentLine(string aStudentLine, Student& aStudent){
    string s1, s2;
    int credits, id;
    double gpa;
    Date dob, mat;
    int month, day, year;
    unsigned long int posOfLine1, posOfLine2;
    
    posOfLine1=aStudentLine.find('|');
    s1=aStudentLine.substr(0,posOfLine1-1);
    
    posOfLine2=aStudentLine.find('|', posOfLine1+1);
    id=stoi(aStudentLine.substr(posOfLine1+1,posOfLine2-posOfLine1-1));
    
    posOfLine1=aStudentLine.find('|', posOfLine2+1);
    posOfLine2=aStudentLine.find('|',posOfLine1+1);
    
    credits=stoi(aStudentLine.substr(posOfLine1+1, posOfLine2-posOfLine1-1));
    posOfLine1=posOfLine2;
    
    posOfLine2=aStudentLine.find('|',posOfLine1+1);
    gpa=stod(aStudentLine.substr(posOfLine1+1,posOfLine2-posOfLine1-1));
    
    posOfLine1=posOfLine2;
    posOfLine2=aStudentLine.find('/',posOfLine1+1);
    month=stoi(aStudentLine.substr(posOfLine1+1, posOfLine2-posOfLine1-1));
    
    posOfLine1=posOfLine2;
    posOfLine2=aStudentLine.find('/',posOfLine1+1);
    day=stoi(aStudentLine.substr(posOfLine1+1, posOfLine2-posOfLine1-1));

    posOfLine1=posOfLine2;
    posOfLine2=aStudentLine.find('|',posOfLine1+1);
    year=stoi(aStudentLine.substr(posOfLine1+1, posOfLine2-posOfLine1-1));
    dob = Date(month, day, year);
    
    posOfLine1=posOfLine2;
    posOfLine2=aStudentLine.find('/',posOfLine1+1);
    month=stoi(aStudentLine.substr(posOfLine1+1, posOfLine2-posOfLine1-1));
    
    posOfLine1= posOfLine2;
    posOfLine2=aStudentLine.find('/',posOfLine1+1);
    day=stoi(aStudentLine.substr(posOfLine1+1, posOfLine2-posOfLine1-1));
    
    posOfLine1=posOfLine2;
    year=stoi(aStudentLine.substr(posOfLine1+1, aStudentLine.length()-posOfLine1-1));
    
    mat= Date(month, day, year);
    
    aStudent.setFirstName(s1);
    aStudent.setLastName(s2);
    aStudent.setID(id);
    aStudent.setCredits(credits);
    aStudent.setGpa(gpa);
    aStudent.setMatric(mat);
    aStudent.setDob(dob);
}

const string FileManager::getUsername(){
    return UserName;
}
const string FileManager::getPassword(){
    return password;
}
const int FileManager::getSupervisor(){
    return Supervisor;
}
const bool FileManager::DatabaseAccess(){
    string line;
    ifstream inputFile("Database.txt");
    string _UserName, _PassWord;
    int _Supervisor;
    bool search=false;
    if(inputFile.is_open()){
        while(getline(inputFile,line)){
            stringstream iss(line);
            iss>>_UserName>>_PassWord>>_Supervisor;
            
            if(UserName==_UserName && password==_PassWord){
                cout<<"Wel come \n\n";
                Supervisor=_Supervisor;
                search= true;
                return Supervisor;
            }
        }
        if(!search){
            cout<<"Invalid userID or Password! \n\n";
            start();
        }
    }
    else{
        cout<<"Error while opening the file. \n";}
    return -1;
    }

//Operation overloading

ostream& operator << (ostream& output, const FileManager& currentRoster)
{
    if(currentRoster.user==" " )
    {
        output<<"Error: No user found."<<endl;
        return output;
    }
    output<<currentRoster.UserName<<" "<<currentRoster.password<<" "
    <<currentRoster.Supervisor<<endl;
    return output;
}

istream& operator >>(istream& input, FileManager& currentRoster){
    cout<<" *Sign UP*"<<endl;
    cout<<" Username: "; input>> currentRoster.UserName;
    cout<< "Password: "; input>> currentRoster.password;
    currentRoster.Supervisor=User;
    currentRoster.writeDatabase();
    return input;
}















