//
//  main.cpp
//  RosterProject
//
//  Created by Rodricks Christian on 11/20/15.
//  Copyright © 2015 Rodricks Christian. All rights reserved.
//

#include <iostream>
#include "FileManager.hpp"
#include "RosterManagement.hpp"

int main(int argc, const char * argv[]) {
    
    FileManager data;
    data.start();
    
    RosterManagement user(data.getSupervisor());
    data.DatabaseAccess();
    
    cout<<"Welcome" <<data.getUsername()<<endl;
    user.choice();
    return 0;
}
