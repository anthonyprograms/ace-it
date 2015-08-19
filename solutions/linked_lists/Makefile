EXEC = test
SRC = $(EXEC).cpp
CC = g++

INC = -I../../common/include -I../../common/src
COMMONSRC = ../../common/src/linkedList.cpp

default: $(SRC) $(COMMONHDR)
	$(CC) $(SRC) -o $(EXEC) $(COMMONSRC) $(INC)

run:
	./$(EXEC)

clean:
	rm $(EXEC)
