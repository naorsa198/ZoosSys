#include "ZoomSys.h"

void delete_pointer_Student(Student* const ptr)
{
    delete ptr;
}

void delete_pointer_room(Room* const ptr)
{
    delete ptr;
}

ZoomSys::ZoomSys(string filename)
{
    roomKey=map<int,Room*>();
    Room* loby;
    loby=new Room();
    if(!loby) std::terminate();
    roomKey[-1]=loby;
    DeleteThisRoom(loby,roomKey);
    studentVector=vector<Student *>();  //all student vec of the program
    string line;
    ifstream inFile;
    inFile.open(filename.c_str());

    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {

            /* if the line end with \r */
            if (line[line.size() - 1] == '\r')
                line.erase(line.size() - 1);

            int i = 0;
            string studentVal[5];
            std::string firstname;
            std::string lastname;
            int id;
            double average;
            std::string type;
            istringstream s(line);

            while (s)
            {
                s >> studentVal[i];
                i++;
            }

            firstname = studentVal[0];
            lastname = studentVal[1];
            stringstream ID(studentVal[2]);
            ID >> id;
            stringstream avg(studentVal[3]);
            avg >> average;
            type = studentVal[4];

            Student* insertStudent;

            if (type == "W")
                insertStudent = new Worker_Student(firstname, lastname, id, average);

            if (type == "L")
                insertStudent = new Lazy_student(firstname, lastname, id, average);

            if (type == "R")
                insertStudent = new Charge_student(firstname, lastname, id, average);

            if (insertStudent == NULL) std::terminate();

            studentVector.push_back(insertStudent);  //add student tovec

        }
        inFile.close();
    }

    else
        cout << "Failed to reading from file" << endl;
}

// check if the student exist in the system
Student* studentExist(vector<Student*>&studentVector,int id)
{
    std::vector<Student*>::iterator  it;
    for( it=studentVector.begin(); it!=studentVector.end();++it) {
        if ((*it)->getID() == id)
            return (*it);
    }
    return NULL;
}

//check if room exist in the system
Room* roomExist(map<int,Room*>&roomKey,int id_room)
{
    map<int,Room*>::iterator it;
    for( it=roomKey.begin(); it!=roomKey.end();++it){
        if(it->first==id_room)
            return it->second;
    }
    return NULL;
}

// split by character / father =  the room you want to split
void CharacterSplit(map<int,Room*>&roomKey,Room* father,vector<Student*>&stv) {
    int left, right;
    Room *leftSun;
    Room *rightSun;
    Room* Rw;
    Room* Rl;
    Rw = new Worker_room();
    if(!Rw) std::terminate();
    roomKey[Room::getRoomNum() - 1] = Rw;
    left = (Room::getRoomNum() - 1);
    leftSun = roomExist(roomKey, left);

    Rl = new Lazy_room();
    if(!Rl) std::terminate();
    roomKey[Room::getRoomNum() - 1] = Rl;
    right = (Room::getRoomNum() - 1);
    rightSun = roomExist(roomKey, right);
    father->characterSplit(leftSun, rightSun);  // father give student to his suns
}

void SizeSplit(map<int,Room*>&roomKey,Room* father,vector<Student*>&vsm) {
    int left, right;
    Room *leftSun;
    Room *rightSun;
    Room* RR;
    RR = new Room();
    if(!RR) std::terminate();
    roomKey[Room::getRoomNum() - 1] = RR;
    left = (Room::getRoomNum() - 1);
    leftSun = roomExist(roomKey, left); //get the pointer
    Room* R2;
    R2 = new Room();
    if(!R2) std::terminate();
    roomKey[Room::getRoomNum() - 1] = R2;
    right = (Room::getRoomNum() - 1);
    rightSun = roomExist(roomKey, right);
    father->toSplitVector(leftSun, rightSun);
}

int myPlace(vector<Student*>vs,Student* st)
{
   int index;
    std::vector<Student*>::iterator  it = std::find(vs.begin(),vs.end(),st);
    if(it!=vs.end())
        return index=std::distance(vs.begin(),it);

}

void ZoomSys::addStudent() {
    string firstname,lastname,type;
    double average;
    int id;
    cout<<"---Create Student---"<<"\n"<<"First name:"<<endl;
    cin>>firstname;
    cout<<"Last name:"<<endl;
    cin>>lastname;
    cout<<"ID:"<<endl;
    cin>>id;
    cout<<"avg:"<<endl;
    cin>>average;
    cout<<"Worker(W) or Lazy(L) or Responsible(R) Student?"<<endl;
    cin>>type;
    Student* st;
        st = studentExist(studentVector, id);
    try
    {
        /* Check if the ID is a positive integer */
        if(id<=0 || std::to_string(id).length() > 6)
            throw InvalidDetails();

        /* Check if the ID doesn't exist */
        if (st != NULL)
            throw InvalidDetails();

        /* Check if the average is a positive number between 0-100 */
        if (average > 100 || average < 0)
            throw InvalidDetails();

        /* Check if the type is not one of the letters R/L/W */
        if (type != "W" && type != "L" && type != "R")
            throw InvalidDetails();
    }

    catch (exception& e)
    {
        cout << e.what() << endl;
        return;
    }

    Student* insertStudent;

    if (type == "W")
        insertStudent = new Worker_Student(firstname, lastname, id, average);

    if (type == "L")
        insertStudent = new Lazy_student(firstname, lastname, id, average);

    if (type == "R")
        insertStudent = new Charge_student(firstname, lastname, id, average);

    if (insertStudent == NULL) std::terminate();
    studentVector.push_back(insertStudent);
}

void ZoomSys:: removeStudent() {
    cout << "---Remove Student---" << endl;
    int myRoom;
    int id_student;
    Room *rm;
    cout << "Enter the id:" << endl;
    cin >> id_student;
    Student *st;
    st = studentExist(studentVector, id_student);
    try {
        if (st == NULL)
            throw IDException();
        else {
            myRoom = st->getMyRoom();
            rm = roomExist(roomKey, myRoom);
        }
    }

    catch (exception &e) {
        cout << e.what() << endl;
        return;
    }
    if (rm->get_Key() != -1) {
        rm->RemoveStudent(st);
    }
    delete_pointer_Student(st);
    studentVector.erase(studentVector.begin() + myPlace(studentVector, st));

};

void ZoomSys:: assignStudent() {
    int id_student, id_room, myRoom;
    cout << "---Assign Student---\nEnter student id:" << endl;
    cin >> id_student;
    Student* st;
    st = studentExist(studentVector, id_student);
    try {
        /* Check if the id_student doesn't exist */
        if (st == NULL || id_student <= 0 )
            throw IDException();
    }
    catch (exception &e) {
        cout << e.what() << endl;
        return;
    }
    cout << "Enter room id:" << endl;
    cin >> id_room;
    try {
        /* Check if the ID is a positive integer */
        if ( id_room < -1)
            throw IDException();
    }
    catch (exception &e) {
        cout << e.what() << endl;
        return;
    }
    Room* rm;
    rm = roomExist(roomKey, id_room);
    try {
        /* Check if the id_room doesn't exist */
        if (rm == NULL && id_room != -1)
            throw IDException();
        else
            rm->add_general(st);
    }
    catch (exception &e) {
        cout << e.what() << endl;
        return;
    }
    // before change room dicrise from the list of his own room
    myRoom = st->getMyRoom();
    if (myRoom != -1) {
        rm = roomExist(roomKey, myRoom);
        rm->RemoveStudent(st);
    }
    st->setRoom(id_room);
}

void ZoomSys:: addRoom(){
    cout << "New room created" << endl;
    roomKey[Room::getRoomNum()-1]=new Room();
};

void ZoomSys:: splitRoom() {
    int id_room;
    int t;
    cout << "---Split Room---" << "\n" << "Room id:" << endl;
    cin >> id_room;
    Room *father;
    father = roomExist(roomKey, id_room);
    if(father != NULL)
        t = father->getSplit();
    try {
        if (father == NULL)
            throw IDException();
        if (t == 1)
            throw SplitBefore();
    }
    catch (exception &e) {
        cout << e.what() << endl;
        return;
    }

    cout << "1.Character split" << endl;
    cout << "2.Size split" << endl;
    string menuOption;
    cin >> menuOption;
    int invalid=0;
    try {
        if (menuOption !="1" && menuOption !="2") {
            cin.clear();
            invalid=1;
            throw InvalidDetails();
        }
    }
    catch (exception &e) {
        cout << e.what() << endl;
        return;
    }
    int flag;
    if(menuOption=="1")
        flag=1;
    else flag=2;
    try {
        if (invalid != 1) {
            switch (flag) {
                case 1:
                    CharacterSplit(roomKey, father,studentVector);
                    break;
                case 2:
                    SizeSplit(roomKey, father,studentVector);
                    break;
            }
        }
    }
    catch (exception &e) {

        cout << e.what() << endl;
        return;
    }
};

void ZoomSys:: removeRoom()
{
    Room *rm;
    int id_room;
    cout<<"---Remove Room---"<<endl;
    cout <<"Enter room id:"<< endl;
    cin >> id_room;
    rm = roomExist(roomKey, id_room);
    try
    {
        if (rm == NULL)
            throw IDException();
    }

    catch (exception& e)
    {
        cout << e.what() << endl;
        return;
    }
   DeleteThisRoom(rm,roomKey);
}

void ZoomSys:: work()
{
    Room *rm;
    int id_room;
    cout << "Enter the room you want to work:" << endl;
    cin >> id_room;
    rm = roomExist(roomKey, id_room);
    try
    {
        if (rm == NULL)
            throw IDException();
        else
            rm->work();
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
        return;
    }
}
void ZoomSys:: sendMessage() {
    Student *st;
    string msg,type;
    int id;
    cout << "Enter the id:" << endl;
    cin >> id;
    st = studentExist(studentVector, id);
/*    type = st->addMsg();*/
    try {
        if (st == NULL)
            throw IDException();
    }
    catch (exception &e) {
        cout << e.what() << endl;
        return;
    }

    cout << "Enter the message:" << endl;
    cin >> msg;
    try {
        int room_id = st->getMyRoom();
        roomExist(roomKey, room_id)->sendMsgToSt(st, msg);
    }
    catch (exception &e) {
        cout<<e.what()<<endl;
        return;
    }
};

void ZoomSys:: printRooms()
{
    for(auto i=roomKey.begin(); i!=roomKey.end();++i) {
        if(i->first==-1)continue;
        i->second->printRoom();
    }
};

void ZoomSys:: printStudents()
{
    std::vector<Student*>::iterator  it;
    if (!studentVector.empty())
    {
        cout << "First name, Last Name, ID, Avg, Room ID" << endl;
    for( it=studentVector.begin(); it!=studentVector.end();++it)
        (*it)->printStudent();
    }
};

void ZoomSys:: printStudentDetails() {
    int id_student;
    cout << "Enter student id:" << endl;
    cin >> id_student;
    Student *st;
    st = studentExist(studentVector, id_student);
    try {
        if (st == NULL)
            throw IDException();
        else
            st->printStudent();
    }
    catch (exception &e) {
        cout << e.what() << endl;
        return;
    }
};

ZoomSys::~ZoomSys(){
    std::vector<Student*>::iterator  it;
    for( it=studentVector.begin(); it!=studentVector.end();++it)
         delete_pointer_Student(*it);
    studentVector.clear();
    std::map<int,Room*>::iterator itm;
    for(itm=roomKey.begin(); itm!=roomKey.end();++itm)
            delete_pointer_room(itm->second);
    roomKey.clear();
}

