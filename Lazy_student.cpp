#include "Lazy_student.h"

Lazy_student::~Lazy_student(){
   msg.clear();
}

void Lazy_student::add_lazyRoom(Room* rm)
{
    this->My_Room=rm->get_Key();
     rm->add_general(this);
}