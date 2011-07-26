#INSPUR
CXX = /usr/bin/g++ 

OBJ = .auto_layout.o \
			.write_target.o \
			.write_main.o \
			.write_replica.o \

#compile
layout.exe : ${OBJ}
	${CXX} ${OBJ} -o layout.exe

#connect
.%.o :		%.cpp
	${CXX} -c $< -o $@

#clean
clean:
	rm .*.o layout.exe
