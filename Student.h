#ifndef WORK5CPP_STUDENT_H
#define WORK5CPP_STUDENT_H
#include <string>
#include <iostream>
#include <vector>
#include "Room.h"
#include "Exception.h"
using namespace std;

class Room;

class Student
{
protected:
    std::string firstName;
    std::string lastName;
    int S_id;
    double average;
    int My_Room;
    vector<std::string> msg;
public:
    Student(std::string firstName,std::string lastName,int S_id,double average);
    virtual ~Student();
    virtual void add_lazyRoom(Room* rm)=0;
    virtual void add_workerRoom(Room* rm)=0;
    virtual void add_chargeRoom(Room* rm)=0;
    virtual void printStudent()const;
    virtual void setRoom(const int k);
    virtual int getID()const{return this->S_id;};
    virtual void IamWorking()const{false;};
    virtual void sendMsg(const vector<Student*>,const string sendMsg )const{throw StudentPermissions();};//
    virtual void addMsg(const string newMSG ); // int the cpp
    virtual int getMyRoom()const{return My_Room;}
    virtual void CryLazy()const{false;};
};

#endif //WORK5CPP_STUDENT_H