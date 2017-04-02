CXXFLAGS =

all: robot
debug: CXXFLAGS += -G
debug: robot

rebuild: clean robot

robot: robot.cpp
	${CXX} ${CXXFLAGS} -std=c++11 -o robot robot.cpp
clean:
	rm -f *.o a.out
