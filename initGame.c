
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "initGame.h"
#include "playGame.h"

/*
 * Intialise game data for a new game
 */

Game *initGame( int boardSize, int winLength ) {

  int i = 0;
  int j = 0; 
  int max_turn;

  Game *game = malloc(sizeof(Game)); // allocate the Game data structure

  max_turn = boardSize * boardSize;
  // intialise the Game data structure values 
  game->boardSize = boardSize; 
  game->winLength = winLength;
  game->maxTurns = max_turn;
  game->turns = 0;

  for (i = 0; i < boardSize; ++i)
  {
    for (j = 0; j < boardSize; ++j)
    {
      game->board[i][j] = '.';
    }
  }
  
  return game;
}


