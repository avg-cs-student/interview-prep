CC= clang++
CFLAGS= -std=c++11 -Wall -g

SRC:= main.cpp
EXE:= ${SRC:.cpp=.out}
TESTFILE:= ./sample-input.txt

all: compile test

compile: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXE)

test: compile
	@echo ""
	@echo ""
	@echo Testing with $(TESTFILE)...
	@echo ""
	@echo "---BEGIN TEST---"
	@./$(EXE) < $(TESTFILE)
	@echo "----END TEST----"

clean:
	rm -rf *.dSYM $(EXE)
