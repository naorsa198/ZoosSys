#include "Student.h"

using namespace std;

Student::Student(string firstName, string lastName,int S_id,double average)
{
    this->firstName=firstName;
    this->lastName=lastName;
    this->S_id=S_id;
    this->average=average;
    this->msg=vector<string>();
    this->My_Room=-1;
};

Student::~Student() {};

void Student::printStudent()const
{
    cout <<firstName<<" "<<lastName<<" "<<S_id<<" "<<average<<" "<<My_Room<<endl;
    if(msg.size() !=0) {
        cout << "---Messages---" << endl;
        for (auto i = msg.begin(); i != msg.end(); ++i)
            cout << *i << endl;
    }
};

void Student::setRoom(const int k){
    this->My_Room=k;
}

void Student::addMsg(const string newmsg) {
    msg.push_back(newmsg);
}