
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "initGame.h"

/*
 * Intialise game data for a new game
 */

Game *initGame( int boardSize, int winLength ) {

  Game *game;
  int i, j, max_turn;

  // allocate the Game data structure
  // board values shaould be set to '.' (unused location)
  max_turn = boardSize ** 2;
  for (i = 0; i < boardSize; ++i)
  {
    for (j = 0; j < boardSize; ++j)
    {
      game -> board[i][j] = ".";
    }
  }
  // intialise the Game data structure values 
  game -> boardSize = boardSize;
  game -> winLength = winLength;
  game -> maxTurns = max_turn;
  game -> turns = 0;

  return game;
}


