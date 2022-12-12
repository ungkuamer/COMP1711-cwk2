
# code details

EXE = ./bin/tictactoe
SRC = main.c initGame.c playGame.c endGame.c                # ** list source code here **
OBJ = main.o initGame.o playGame.o endGame.o          # ** list object code here **

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
main.o: main.c game.h initGame.h playGame.h
playGame.o: initGame.c game.h initGame.h playGame.h playGame.c
initGame.o: initGame.h game.h playGame.h playGame.h initGame.c
endGame.o: game.h endGame.h endGame.c
#
# ** put code dependencies here **
#
