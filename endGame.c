
#include <stdio.h>

#include "game.h"
#include "endGame.h"

/*
 * Functions in this module check for wins and draws
 */

// test all possible ways the game can be won for one player
int winGame( Game *game, char symbol ) {

  int i, j;
  int count = 0;

  //horizontal case
  for (i = 0; i < game->boardSize; i++)
  {
    for (j = 0; j < game->boardSize; j++)
    {
      if (game->board[i][j] == symbol)
      {
        count++;
      }
      else
      {
        count = 0;
      }
    }

    if (count == (game->winLength))
    {
      return 1; //true(won)
    }
    count = 0;
  }

  //vertical case
  for (i = 0; i < game->boardSize; i++)
  {
    for (j = 0; j < game->boardSize; j++)
    {
      if (game->board[j][i] == symbol)
      {
        count++;
      }
      else
      {
        count = 0;
      }

      if (count == (game->winLength))
      {
        return 1;
      }
    }
    count = 0;
  }

  //diagonal case
  //  normal
  count = 0;
  for (i = 0; i < game->boardSize; i++)
  {
    if (game->board[i][i] == symbol)
    {
      count++;
    }
  }

  if (count == (game->winLength))
  {
    return 1;
  }

  //  inverted
  count = 0;
  for (i = 0; i < game->boardSize; i++)
  {
    j = (game->boardSize)-i-1;
    if (game -> board[i][j] == symbol)
    {
      count++;
    }
  }

  if (count == (game->winLength))
  {
    return 1;
  }

  return 0;  // continue
}

// test for a draw
int drawGame( Game *game )
{

  int i, j;

  for (i = 0; i < game->boardSize; i++)
  {
    for (j = 0; j < game->boardSize; j++)
    {
      if (game->board[i][j] == '.')
      {
        return 0;
      }
    }
  }
  
  return 1; // no more empty space
}

