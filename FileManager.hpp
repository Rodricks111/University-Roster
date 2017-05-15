//
//  FileManager.hpp
//  Homework6
//
//  Created by Rodricks Christian on 11/30/15.
//  Copyright © 2015 Rodricks Christian. All rights reserved.
//

#ifndef FileManager_hpp
#define FileManager_hpp
#include <iostream>
#include <fstream>
#include "Roster.hpp"
#include "RosterManagement.hpp"
using namespace std;

enum super{ None=-1, User=0, Admin=1};
class FileManager{
public:
    //Constructors
    FileManager();
    FileManager(const string& user, const string& password, const int&super);
    ~FileManager();
    
    void writeDatabase();
    void writeRoster(const Roster currentRoster[]);
    void readRoster(RosterManagement currentManager);
    void parseRosterLine(string line, Roster& newRoster);
    void parseStudentLine(string line, Student& newStudent);
    
    // mutators
    
    void setUsername(const string user);
    void setPassword(const string pass);
    void setSupervisor(const int super);
    void start();
    void login();
    void options();
    
    //accessors
    const string getUsername();
    const string getPassword();
    const int getSupervisor();
    const bool DatabaseAccess();
    //operator overload
    friend ostream& operator<< (ostream& output, const RosterManagement& currentRoster);
    friend istream& operator>> (istream& input, RosterManagement& currentFile);
    ostream& setRoster(const Roster& currentRoster);
    istream& getRoster();
    
    private :
    
    string UserName;
    string password;
    int Supervisor;

};

#endif /* FileManager_hpp */
