CXXFLAGS =

all: main
debug: CXXFLAGS += -G
debug: main

rebuild: clean main

main: main.cpp
	${CXX} ${CXXFLAGS} -std=c++11 -o main main.cpp
clean:
	rm -f *.o a.out
