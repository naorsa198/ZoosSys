#include "Worker_Student.h"

Worker_Student::~Worker_Student(){
    msg.clear();
}


void Worker_Student::add_workerRoom(Room* rm){
    this->My_Room=rm->get_Key();
    rm->add_general(this);
}

void Worker_Student::IamWorking()const {
    cout<<firstName<<" "<<lastName<<" "<<"is working"<<endl;
}