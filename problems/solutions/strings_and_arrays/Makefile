EXEC = test
SRC = $(EXEC).cpp
CC = g++

INC = -I../../common/include -I../../common/src
COMMONSRC = #../../common/src/strings_and_arrays.cpp

default: $(SRC) $(COMMONHDR)
		$(CC) $(SRC) -o $(EXEC) $(COMMONSRC) $(INC)

run:
	./$(EXEC)

vim:
	vim $(SRC)

clean:
	rm $(EXEC)
