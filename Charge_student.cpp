#include "Charge_student.h"

Charge_student::~Charge_student(){
    msg.clear();
}

void Charge_student::add_chargeRoom(Room* rm) {
    this->My_Room=rm->get_Key();
    rm->add_general(this);
}

void Charge_student::sendMsg(const vector<Student*> vs,const string sendMsg)const {
    string fullMSG=firstName+" "+lastName+":"+sendMsg;
    for(auto i=(vs).begin();i!=(vs).end();++i)
        (*i)->addMsg(fullMSG);
}


