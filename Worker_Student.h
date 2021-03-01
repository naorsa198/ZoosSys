#ifndef WORK5CPP_WORKER_STUDENT_H
#define WORK5CPP_WORKER_STUDENT_H
#include "Student.h"
using namespace std;

class Worker_Student : public Student
{
public:
    Worker_Student(std::string firstName,std::string lastName,int S_id,double average):
    Student(firstName,lastName,S_id,average){};
    virtual ~Worker_Student();
    virtual void add_workerRoom(Room* rm);
    virtual void add_chargeRoom(Room* rm){};
    virtual void add_lazyRoom(Room* rm){};

    virtual void IamWorking()const;
};
#endif //WORK5CPP_WORKER_STUDENT_H