CC=g++
FILES=$(shell ls *.cpp)
OBJS=$(patsubst %.cpp,%.o,$(FILES))
target:$(OBJS)
	$(CC) -std=c++11 -o test $(OBJS)
$(OBJS):%.o:%.cpp
	$(CC) -std=c++11 -c $^ -o $@
clean:
	rm -rf *.o test