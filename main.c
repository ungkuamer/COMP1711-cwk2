
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "initGame.h"
#include "playGame.h"

/*
 * main function: program entry point
 */

int main( int argc, char *argv[] ) {

  Game *game; // pointer for the game structure
  int boardSize, winLength;
  // allocate memory and assign starting values to the structure

  if (argc != 3) // checks for number of argument
  {
    printf("Not enought argument");
    return 0;
  }

  boardSize = atoi(argv[1]);
  winLength = atoi(argv[2]);

  game = initGame(boardSize, winLength);
  if (game == NULL)
  {
    exit(0);
  }

  // play a full game
  playGame(game);

  free( game ); // free heap memory that was used

  return 0;
}

