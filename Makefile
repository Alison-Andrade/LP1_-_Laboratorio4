RM = rm -rf

CC=g++

INC=./include
SRC=./src
OBJ=./build
BIN=./bin
DOC=./doc

CPPFLAGS = -Wall -pedantic -std=c++11

.PHONY: all clean doc

all: dir doc Programa1 Programa2

debug: CPPFLAGS += -g -O0
debug: dir Programa1 Programa2

Programa1: $(OBJ)/main1.o $(OBJ)/tratarString.o
	$(CC) $(CPPFLAGS) -o $(BIN)/$@ $^

$(OBJ)/main1.o: $(SRC)/Programa1/main1.cpp $(INC)/tratarString.h
	$(CC) -c $(CPPFLAGS) -I$(INC) -o $@ $<

$(OBJ)/tratarString.o: $(SRC)/Programa1/tratarString.cpp $(INC)/tratarString.h
	$(CC) -c $(CPPFLAGS) -I$(INC) -o $@ $<

Programa2: $(OBJ)/main2.o
	$(CC) $(CPPFLAGS) -o $(BIN)/$@ $^

$(OBJ)/main2.o: $(SRC)/Programa2/main2.cpp $(INC)
	$(CC) -c $(CPPFLAGS) -I$(INC) -o $@ $<

dir:
	mkdir -p bin build doc

doc:
	$(RM) $(DOC)/*
	doxygen Doxyfile

clean:
	$(RM) $(BIN)/* $(OBJ)/* $(DOC)/* *.o *.out
