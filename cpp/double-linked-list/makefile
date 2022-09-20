#! bin/bash

CC= clang++
CFLAGS= -Wall -g
SRC= src/*.cpp

all: compile

compile:
	${CC} ${CFLAGS} ${SRC} -o bin/a.out

run:
	./bin/a.out

clean:
	rm -rf bin/*.out bin/*.dSYM



