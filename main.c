
#include <stdio.h>
#include <stdlib.h>

#include "game.h"

/*
 * main function: program entry point
 */

int main( int argc, char *argv[] ) {

  int boardSize, winLength;
  Game *game; // pointer for the game structure

  if (argc != 3)
  {
    printf("Not enough argument");
    exit(0);
  }  

  boardSize = atoi(argv[1]);
  winLength = atoi(argv[2]);
  // allocate memory and assign starting values to the structure
  initGame(boardSize, winLength);
  // play a full game
  playGame(game);

  free( game ); // free heap memory that was used

  return 0;
}

