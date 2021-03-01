#ifndef WORK5CPP_ZOOMSYS_H
#define WORK5CPP_ZOOMSYS_H
#include "Worker_Student.h"
#include "Lazy_student.h"
#include "Charge_student.h"
#include "Student.h"
#include <fstream>
#include <sstream>
#include "Room.h"
#include "Worker_room.h"
#include "Lazy_room.h"
#include "Exception.h"
using namespace std;

class ZoomSys {
    string filename;
    vector<Student*>studentVector;
    std::map<int,Room*>roomKey;
public:
    ZoomSys(const string filename);
    ~ZoomSys();
    void addStudent();
    void removeStudent();
    void assignStudent();
    void addRoom();
    void splitRoom();
    void removeRoom();
    void work();
    void sendMessage();
    void printRooms();
    void printStudents();
    void printStudentDetails();
};

#endif //WORK5CPP_ZOOMSYS_H