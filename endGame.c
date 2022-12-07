
#include <stdio.h>

#include "game.h"
#include "endGame.h"

/*
 * Functions in this module check for wins and draws
 */

// test all possible ways the game can be won for one player
int winGame( Game *game, char symbol ) {

  int i, j, x, y;
  int count = 0;
  // return 1(true) if game is won, 0(false) otherwise
  //
  // You may wish to define further functions to test different win conditions
  // Games can be won with horizontal, vertical or diagonal lines

  // horizontal case
  for (i = 0; i < boardSize; i++)
  {
    for (j = 0; j < boardSize; j++)
    {
      if (game -> board[j][i] == symbol)
      {
        count++;
      }
      else
      {
        count = 0;
      }
    }
    // checks and resets when jumping row
    if (count == (game -> winLength))
    {
      return 1;
    }
    count = 0;
  }

  // vertical case
  count = 0;
  for (i = 0; i < boardSize; i++)
  {
    for (j = 0; j < boardSize; j++)
    {
      if (game -> board[i][j] == symbol)
      {
        count++;
      }
      else
      {
        count = 0;
      }
    }
    // checks and resets when jumping colomn
    if (count == (game -> winLength))
    {
      return 1;
    }
    count = 0; 
  }

  if (final == (game -> winLength))
  {
    return 1;
  }

  // diagonal case
  //    1 - first diag
  count = 0
  for (i = 0; i < boardSize; i++)
  {
    if (game -> board[i][j] == symbol)
    {
      count++;
    }
    else
    {
      count = 0;
    }
  }

  if (count == (game -> winLength))
  {
    return 1;
  }

  //    2 - second diag
  count = 0
  for (i = 0; i < boardSize; i++)
  {
    y = boardSize-1-i;
    if (game -> board[i][y] == symbol)
    {
      count++;
    }
    else
    {
      count = 0;
    }
  }

  if (count == (game -> winLength))
  {
    return 1;
  }

  return 0;  // continue
}

// test for a draw
int drawGame( Game *game ) {

  // return 1(true) if game is drawn, 0(false) otherwise
  for (i = 0; i < boardSize; i++)
  {
    for (j = 0; j < boardSize; j++)
    {
      if (game -> board[i][j] == ".")
      {
        return 0; // continue
      }
    }
  }
  return 1; 
}
