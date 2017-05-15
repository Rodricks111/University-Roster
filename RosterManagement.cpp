//
//  RosterManagement.cpp
//  RosterProject
//
//  Created by Rodricks Christian on 11/20/15.
//  Copyright © 2015 Rodricks Christian. All rights reserved.
//



#include "RosterManagement.hpp"
#include "Roster.hpp"
RosterManagement::RosterManagement(): Supervisor(false), MyRoster(NULL){}
RosterManagement:: RosterManagement(const bool super): Supervisor(super), MyRoster(NULL){}
RosterManagement::~RosterManagement()
{
    if(MyRoster!=NULL)
    {
        delete MyRoster;
        MyRoster =NULL;
    }
}
int RosterManagement::getCapacity(){return MyCapacity;}
void RosterManagement::choice(){
    int choi = NULL;
    if(Supervisor){
        cout<<"Enter your choice" <<endl;
        cout<<"1. Create a Roster"<<endl;
        cout<<"2. Delete a Roster"<<endl;
        cout<<"3. Display your Roster"<<endl;
        cout<<"4. Display all Roster"<<endl;
        cout<<"5. Select a Roster"<<endl;
        cout<<"6. Exit this program"<<endl;
        cin>>choi;
        
        switch(choi) {
            case 1:
                createRoster();
                break;
            case 2:
                //deleteRoster();
                break;
            case 3:
                //displayRoster();
                break;
            case 4:
                //displayRosterAll();
                break;
            case 5:
                //selectRoster();
                break;
            case 6:
                MyRoster -> setRanStudent();
                //MyRoster-> writeFile();
                return;
                break;
            default:
                cout<< choi<<": is not a valid option. Please try one more time.\n\n";
                break;
        }
        choice();
    }
    
    else{
        cout<<"Enter a choice"<<endl;
        cout<<"1. Select a Roster: " <<endl;
        cout<<"2. Exit " <<endl;
        cin>>choi;
        switch(choi){
                //selectRoster(cN);
                break;
            case 2:
                exit(1);
                break;
            default:
                cout<< choi<< ": is not a valid option. Try one  more time. /n /n";
        }
        
    }
}
void RosterManagement:: createRoster(){
    if(MySize == MyCapacity){
        growRoster();
    }
    cin>>MyRoster[MySize++];
    choice();
}
void RosterManagement::deleteRoster(){
    string input;
    cout<<"Enter couse code: "; cin>>input;
    for(int i=0; i<MySize; i++){
        if(input == MyRoster[i].getCourseCode()) {
            for(int j = i; j <= MySize - 2; j++)
                MyRoster[i] = MyRoster[i+1];
            --MySize;
            return;
        }
    }
    choice();
}

void RosterManagement::growRoster()
{
    int newCapacity = MyCapacity*2 +1;
    Roster* newRoster = new Roster[newCapacity];
    for(int i=0; i<MySize; ++i){
        newRoster[i]= MyRoster[i];
    }
    delete[] MyRoster;
    MyCapacity= newCapacity;
    MyRoster = newRoster;
}

void RosterManagement:: dispayRosterAll(){
    
}
void RosterManagement:: displayRoster(const int& courseNumber){
    
}
void RosterManagement::selectRoster(bool Supervisor)
{
    string C,lastname;
    char choice;
    Roster* foundRoster= NULL;
    cout<<"Enter course code: ";
    getline(cin, C);
    
    for(int i=0; i< MySize; ++i)
    {
        if(C == MyRoster[i].getCourseCode()){
            foundRoster= &MyRoster[i];
        }
    }
    if(foundRoster== NULL){
        cout<<"Roster not Found";
        return;
        
    }
    if(Supervisor){
        cout<<"Select one option";
        cout<<"A. Add new Student \n";
        cout<<"B. Remove a Student \n";
        cout<<"C. Edit a student \n'";
        cout<<"D. List all students \n";
        cin.get(choice);
    do{
        
        switch(choice){
            case 'A':
            case 'a':
                foundRoster-> addStudent();
                break;
            case 'B':
            case 'b':
                cout<<"Enter the student's last name: ";
                getline(cin,lastname);
                foundRoster->deleteStudent(foundRoster->findStudent());
                break;
            case 'C':
            case 'c':
                cout<<"Enter the student's last name: ";
                getline(cin,lastname);
                foundRoster->editStudent(foundRoster->findStudent());
                break;
                
            case 'D':
            case 'd':
                MyRoster->outputAllStudents();
                break;
            default:
                break;
        }
    }while(choice !='A' && choice !='a' &&
           choice !='B' && choice !='b' &&
           choice !='C' && choice !='c' &&
           choice !='D' && choice !='d');
}
else   {
    cout<<"Select one option";
    cout<<"A. Add new Student \n";
    cout<<"B. Remove a Student \n";
    cout<<"C. Edit a student \n'";
    cin.get(choice);
    do {
        
        switch(choice){
            case 'A':
            case 'a':
                foundRoster-> addStudent();
                break;
            case 'B':
            case 'b':
                cout<<"Enter the student's last name: ";
                getline(cin,lastname);
                foundRoster->deleteStudent(foundRoster->findStudent());
                break;
            case 'C':
            case 'c':
                cout<<"Enter the student's last name: ";
                getline(cin,lastname);
                foundRoster->editStudent(foundRoster->findStudent());
                break;
                
            default:
                break;
        }
    }while(choice !='A' && choice !='a' &&
           choice !='B' && choice !='b' &&
           choice !='C' && choice !='c' );
    
    }
}