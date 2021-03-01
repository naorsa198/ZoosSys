#ifndef WORK5CPP_CHARGE_STUDENT_H
#define WORK5CPP_CHARGE_STUDENT_H
#include "Student.h"

class Charge_student : public Student {

public:
    Charge_student(std::string firstName, std::string lastName, int S_id, double average) :
            Student(firstName, lastName, S_id, average) {};

    virtual ~Charge_student();
    virtual void add_chargeRoom(Room* rm);
    virtual void add_lazyRoom(Room* rm){};
    virtual void add_workerRoom(Room* rm){};
    virtual void sendMsg(const vector<Student *>vs, const string sendMsg) const;
};

#endif //WORK5CPP_CHARGE_STUDENT_H