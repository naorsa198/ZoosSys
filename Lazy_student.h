#ifndef WORK5CPP_LAZY_STUDENT_H
#define WORK5CPP_LAZY_STUDENT_H
#include "Student.h"
using namespace std;

class Lazy_student : public Student
{
public:
    Lazy_student(std::string firstName,std::string lastName,int S_id,double average):
    Student(firstName,lastName,S_id,average){};
    virtual ~Lazy_student();
    virtual void add_lazyRoom(Room* rm);
    virtual void add_workerRoom(Room* rm){};
    virtual void add_chargeRoom(Room* rm){};
    virtual void CryLazy()const{ cout<<firstName<<" "<<lastName<<" is crying"<<endl;};
};

#endif //WORK5CPP_LAZY_STUDENT_H