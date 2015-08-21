EXEC = test
SRC = $(EXEC).cpp
CC = g++

INC = INC = -I../../common/include -I../../common/src
COMMONSRC = ../../common/src/strings_and_arrays.cpp

default: $(SRC) $(COMMONHDR)
		$(CC) $(SRC) -o $(EXEC) $(COMMONSRC) $(INC)

run:
		./$(EXEC)

clean:
		rm $(EXEC)
