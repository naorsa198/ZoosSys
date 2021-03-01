prog: Charge_student.o Lazy_room.o Lazy_student.o main.o Room.o Student.o Worker_room.o Worker_Student.o ZoomSys.o
	g++ Charge_student.o Lazy_room.o Lazy_student.o main.o Room.o Student.o Worker_room.o Worker_Student.o ZoomSys.o -o output
 
Charge_student.o: Charge_student.cpp Charge_student.h Student.h Room.h Exception.h
	g++ -c Charge_student.cpp

Lazy_room.o: Lazy_room.cpp Lazy_room.h Room.h Student.h Exception.h
	g++ -c Lazy_room.cpp
	
Lazy_student.o: Lazy_student.cpp Lazy_student.h Student.h Room.h Exception.h
	g++ -c Lazy_student.cpp
	
main.o: main.cpp ZoomSys.h Worker_Student.h Student.h Room.h Exception.h Lazy_student.h Charge_student.h Worker_room.h Lazy_room.h
	g++ -c main.cpp
		
Room.o: Room.cpp Room.h Student.h Exception.h
	g++ -c Room.cpp
	
Student.o: Student.cpp Student.h Room.h Exception.h
	g++ -c Student.cpp
	
Worker_room.o: Worker_room.cpp Worker_room.h Room.h Student.h Exception.h
	g++ -c Worker_room.cpp
	
Worker_Student.o: Worker_Student.cpp Worker_Student.h Student.h Room.h Exception.h
	g++ -c Worker_Student.cpp
	
ZoomSys.o: ZoomSys.cpp ZoomSys.h Worker_Student.h Student.h Room.h Exception.h Lazy_student.h Charge_student.h Worker_room.h Lazy_room.h
	g++ -c ZoomSys.cpp
	
clean: 
	rm -f *.o output

