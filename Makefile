
# code details

EXE = ./bin/tictactoe
SRC = main.c initGame.c playGame.c               # ** list source code here **
OBJ = main.o initGame.o playGame.o                # ** list object code here **

# generic build details

CC     = gcc
CFLAGS = -std=c99 -Wall
CLIBS  = 
CLINK  = 

# compile to object code

%.o: %.c
	$(CC) -c $(CFLAGS) $(CLIBS) $< -o $@

# build executable: type 'make'

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CLINK) -o $(EXE) 

# clean up and remove object code and executable: type 'make clean'

clean:
	rm -f $(OBJ) $(EXE)

# dependencies
main.o: main.c game.h initGame.h
initGame.o: initGame.h game.h initGame.c
playGame.o: initGame.c game.h initGame.h playGame.c playGame.h

#
# ** put code dependencies here **
#
