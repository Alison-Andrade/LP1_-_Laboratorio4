RM = rm -rf

CC=g++

INC=./include
SRC=./src
OBJ=./build
BIN=./bin
DOC=./doc

CPPFLAGS = -Wall -pedantic -std=c++11

.PHONY: all clean doc

all: dir Programa1 Programa2 Programa3

debug: CPPFLAGS += -g -O0
debug: dir Programa1 Programa2 Programa3

Programa1: $(OBJ)/main1.o $(OBJ)/tratarString.o
	@echo "-------------------------------"
	@echo "Compilando Programa 1"
	$(CC) $(CPPFLAGS) -o $(BIN)/$@ $^
	@echo "Binario criado em ./bin/Programa1"

$(OBJ)/main1.o: $(SRC)/Programa1/main1.cpp $(INC)/tratarString.h $(INC)/pilha.h
	@$(CC) -c $(CPPFLAGS) -I$(INC) -o $@ $<

$(OBJ)/tratarString.o: $(SRC)/Programa1/tratarString.cpp $(INC)/tratarString.h
	@$(CC) -c $(CPPFLAGS) -I$(INC) -o $@ $<

Programa2: $(OBJ)/main2.o
	@echo "-------------------------------"
	@echo "Compilando Programa 2"
	$(CC) $(CPPFLAGS) -o $(BIN)/$@ $^
	@echo "Binario criado em ./bin/Programa1"

$(OBJ)/main2.o: $(SRC)/Programa2/main2.cpp
	@$(CC) -c $(CPPFLAGS) -I$(INC) -o $@ $<

Programa3: $(OBJ)/main3.o
	@echo "-------------------------------"
	@echo "Compilando Programa 3"
	$(CC) $(CPPFLAGS) -o $(BIN)/$@ $^
	@echo "Binario criado em ./bin/Programa1"

$(OBJ)/main3.o: $(SRC)/Programa3/main3.cpp
	@$(CC) -c $(CPPFLAGS) -I$(INC) -o $@ $<

dir:
	mkdir -p bin build doc

doc:
	$(RM) $(DOC)/*
	doxygen Doxyfile

valg1:
	valgrind -v --leak-check=full --show-reachable=yes ./bin/Programa1

valg2:
	valgrind -v --leak-check=full --show-reachable=yes ./bin/Programa2

valg3:
	valgrind -v --leak-check=full --show-reachable=yes ./bin/Programa3

clean:
	$(RM) $(BIN)/* $(OBJ)/* $(DOC)/* *.o *.out
