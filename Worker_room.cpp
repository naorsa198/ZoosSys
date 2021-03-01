#include "Worker_room.h"

Worker_room::~Worker_room() {}

void Worker_room::add_student(Student* student)
{
    student->add_workerRoom(this);
}

void Worker_room::characterSplit(Room* leftSun,Room* rightSun){
    if(split==1)
        throw SplitBefore();
    leftSun->fatherRoom=this;
    rightSun->fatherRoom=this;
    this->rightRoom=rightSun;
    this->leftRoom=leftSun;
    vector<Student*>fv;
    fv=studentVector; // copy the father vector
    studentVector.clear(); // clean the father vector
    for (auto it = fv.begin(); it != fv.end(); ++it) {
        // now split the student
        leftSun->add_student(*it);
        rightSun->add_student(*it);
        this->add_student1(*it);
    }
    split=1;
    fv.clear();
}