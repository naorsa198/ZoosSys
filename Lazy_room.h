#ifndef WORK5CPP_LAZY_ROOM_H
#define WORK5CPP_LAZY_ROOM_H
#include "Room.h"

class Lazy_room : public Room{
public:
    Lazy_room():Room(){};
    virtual ~Lazy_room();
    virtual void add_student( Student*);
    virtual void characterSplit(Room* left,Room*right);
};


#endif //WORK5CPP_LAZY_ROOM_H