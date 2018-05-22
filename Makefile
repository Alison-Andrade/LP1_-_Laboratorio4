RM = rm -rf

CC=g++

INC=./include
SRC=./src
OBJ=./build
BIN=./bin
DOC=./doc

CPPFLAGS = -Wall -pedantic -std=c++11

.PHONY: all clean

all: dir Programa1 Programa2

debug: CFLAGS += -g -O0 -pg
debug: dir Programa1 Programa2

Programa1: $(OBJ)/main1.o
	$(CC) $(CPPFLAGS) -o $(BIN)/$@ $^

$(OBJ)/main1.o: $(SRC)/main1.cpp
	$(CC) -c $(CPPFLAGS) -I$(INC) -o $@ $<

Programa2: $(OBJ)/main2.o
	$(CC) $(CPPFLAGS) -o $(BIN)/$@ $^

$(OBJ)/main2.o: $(SRC)/main2.cpp
	$(CC) -c $(CPPFLAGS) -I$(INC) -o $@ $<

dir:
	mkdir -p bin build

clean: dir
	$(RM) $(BIN)/*
	$(RM) $(OBJ)/*