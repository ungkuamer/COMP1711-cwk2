
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "initGame.h"
#include "playGame.h"
/*
 * main function: program entry point
 */

int main( int argc, char *argv[] ) {

  Game *game = malloc(sizeof(Game)); // pointer for the game structure
  int boardSize, winLength;

  boardSize = atoi(argv[1]);
  winLength = atoi(argv[2]);

  // allocate memory and assign starting values to the structure
  game = initGame(boardSize, winLength);
  // play a full game
  playGame(game);

  free(game); // free heap memory that was used

  return 0;
}

