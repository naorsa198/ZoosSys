#ifndef WORK5CPP_WORKER_ROOM_H
#define WORK5CPP_WORKER_ROOM_H
#include "Room.h"

class Worker_room : public Room{
public:
        Worker_room():Room(){};
        virtual ~Worker_room();
        virtual void add_student( Student*);
        virtual void characterSplit(Room* left,Room*right);
};

#endif //WORK5CPP_WORKER_ROOM_H