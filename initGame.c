
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "initGame.h"
#include "playGame.h"

/*
 * Intialise game data for a new game
 */

Game *initGame( int boardSize, int winLength ) {

  int i, j, max_turn;
  Game *game = malloc(sizeof(Game)); // allocate the Game data structure

  //&a = boardSize; // passing value to array size pointer
  max_turn = boardSize * boardSize;

  // for incorrect boardSize or winLength you should return a NULL pointer
  if (boardSize < 3 || boardSize > 8)
  {
    printf("Incorrect parameter values for board size or win length. Exiting\n");
    return NULL;
  }

  if (winLength < 3 || winLength > boardSize)
  {
    printf("Incorrect parameter values for board size or win length. Exiting\n");
    return NULL;
  }
  
  max_turn = boardSize*boardSize;
  // intialise the Game data structure values
  game->boardSize = boardSize;
  game->winLength = winLength;
  game->maxTurns = max_turn;
  game->turns = 0;
  
  // board values should be set to '.' (unused location)
  for (i = 0; i < boardSize; ++i)
  {
    for (j = 0; j < boardSize; ++j)
    {
      game->board[i][j]= '.';
    }
  }

  return game;
}


