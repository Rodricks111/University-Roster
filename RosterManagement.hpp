//
//  RosterManagement.hpp
//  RosterProject
//
//  Created by Rodricks Christian on 11/20/15.
//  Copyright © 2015 Rodricks Christian. All rights reserved.
//

#ifndef RosterManagement_hpp
#define RosterManagement_hpp

#include <stdio.h>

#include <stdio.h>
#include <iostream>
#include  <string>
#include "Roster.hpp"
#include "Student.hpp"

using namespace std;

class RosterManagement{
public:
    
    RosterManagement();
    RosterManagement(const bool Supervisor);
    ~RosterManagement();
    
    //Mutators
    void createRoster();
    void growRoster();
    void selectRoster(bool Supervisor);
    void choice(); //Options
    
    //Accessors
    int getCapacity();
    void dispayRosterAll();
    void displayRoster(const int& courseNumber);
    void deleteRoster();
    
    
    //Dynamic variables
    Roster* MyRoster;
    int MyCapacity;
    int MySize;
    //variables
    bool Supervisor;
    
    
};

#endif /* RosterManagement_hpp */
