#ifndef WORK5CPP_ROOM_H
#define WORK5CPP_ROOM_H
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "exception"
#include "Student.h"
using namespace std;

class Student;

class Room {
private:
    static int roomNum;
protected:
    vector<Student*>studentVector;
    int id_Room;
    int split;
public:
    Room* leftRoom;
    Room* rightRoom;
    Room* fatherRoom;
    Room();
    virtual ~Room();
    virtual void add_student(Student* st);  // isomorphisem depends on room type
    virtual void add_student1(Student* st); // add only Responsibly student - because after char split the room because responsibly
    virtual int get_Key();
    virtual void add_general(Student* st);
    virtual void printRoom()const;
    virtual void work()const; // in the cpp
    virtual void RemoveStudent(const Student* st);
    virtual void characterSplit(Room* left,Room*right);
    virtual void toSplitVector(Room* left,Room* right);
    virtual void sendMsgToSt(const Student* st ,const string msg );
    static int getRoomNum() {return roomNum;}
    static void raiseRoomNum() {roomNum++;}
    int getSplit(){return split;}

    friend void DeleteThisRoom(Room* rm,map<int,Room*>&roomKey);
};

#endif //WORK5CPP_ROOM_H