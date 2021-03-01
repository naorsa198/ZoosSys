#include "Room.h"

int Room::roomNum=-1;
Room::Room(){
    id_Room=getRoomNum();
    split=0;
    leftRoom= NULL;
    rightRoom= NULL;
    fatherRoom= NULL;
    studentVector= vector<Student*>();
    raiseRoomNum();
}
Room::~Room() {
    this->studentVector.clear();
}
void Room::add_student(Student* student)
{
    student->add_chargeRoom(this);
}

void Room::add_student1(Student* student)
{
    student->add_chargeRoom(this);
}


int Room::get_Key() {
    return this->id_Room;
}

void Room::add_general(Student* sp){
    studentVector.push_back(sp);
}

void Room::printRoom()const {
    cout<<"room id:"<<this->id_Room<<", "<<"students:"<<this->studentVector.size()<<"\n";
}

void Room::work()const {
  //  std::vector<Student*>::iterator  it;
      for (auto it = studentVector.begin(); it != studentVector.end(); ++it) {
          (*it)->IamWorking();
      }
}

void deleteIterator(vector<Student*>studentVector,int key)
{
    for (auto it = studentVector.begin(); it != studentVector.end(); it++) {
        (*it)->CryLazy();
        (*it)->setRoom(key);
    }
}

void DeleteThisRoom(Room* rm,map<int,Room*>&roomKey){
    if(rm==NULL)
        return;
    DeleteThisRoom(rm->leftRoom,roomKey);
    DeleteThisRoom(rm->rightRoom,roomKey);
    //send all the student to father vector

    // change the room to each student
    if (rm->fatherRoom == NULL) //if no father every one is -1
        deleteIterator(rm->studentVector,-1);
    else{
        rm->fatherRoom->studentVector.insert(
                rm->fatherRoom->studentVector.end(),rm->studentVector.begin(),
                rm->studentVector.end());
        if(rm->fatherRoom->rightRoom==rm)
            rm->fatherRoom->rightRoom=NULL;
        else rm->fatherRoom->leftRoom=NULL;
        deleteIterator(rm->studentVector,rm->fatherRoom->id_Room);
    }
    rm->studentVector.clear();

    map<int,Room*>::iterator iter=roomKey.find(rm->id_Room);
    if(iter!=roomKey.end())
        roomKey.erase(iter);
    delete rm;
}

int myPlace(vector<Student*>vs,const Student* st)
{
    int index;
    std::vector<Student*>::iterator  it = std::find(vs.begin(),vs.end(),st);
    if(it!=vs.end())
        return index=std::distance(vs.begin(),it);
}

void Room::sendMsgToSt(const Student* st,const string msg)
{
    st->sendMsg(studentVector,msg);
}

void Room::RemoveStudent(const Student* st)
{
    studentVector.erase(studentVector.begin() +
                                  myPlace(studentVector, st));
}

void Room::toSplitVector(Room* leftSun,Room* rightSun){
if(split==1)
    throw SplitBefore();

    int size = studentVector.size();
int left,right;
this->rightRoom=rightSun;
this->leftRoom=leftSun;
leftSun->fatherRoom=this;
rightSun->fatherRoom=this;
std::vector<Student*>::iterator  middleItr(studentVector.begin()+size/2);
for(auto it =studentVector.begin(); it!=studentVector.end();++it){
    if(std::distance(it,middleItr)>0)
    { leftSun->studentVector.push_back(*it); (*it)->setRoom(left);}
    else
    { rightSun->studentVector.push_back(*it);(*it)->setRoom(right);}
}
    studentVector.clear();
    split=1;
    }

    // room split him self by character
void Room::characterSplit(Room* leftSun,Room* rightSun){
    if(split==1)
        throw SplitBefore();
    // update suns to father and father to suns
    leftSun->fatherRoom=this;
    rightSun->fatherRoom=this;
    this->rightRoom=rightSun;
    this->leftRoom=leftSun;
    vector<Student*>fv;
    fv=studentVector; // copy the father vector
    studentVector.clear(); // clean the father vector
    for (auto it = fv.begin(); it != fv.end(); ++it) {
        // now split the student
        leftSun->add_student(*it);
        rightSun->add_student(*it);
        this->add_student(*it);
    }
    split=1;
    fv.clear();
}