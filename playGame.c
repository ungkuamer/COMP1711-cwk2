
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "game.h"
#include "playGame.h"
#include "endGame.h"

/*
 * Controls the game logic from start to end
 */

void playGame( Game *game ) {

  char symbols[2] = { 'X','O' };
  // player 'X' plays first
  int player = 0;
  int current_turn = 0;
  int i;

  // starting board
  printf("New game starting\n");
  showGame( game );
  
  // Your game should be controlled by an outer loop
  // Each pass through the loop is one completed move by a player
  for (i = 0; i < game->maxTurns; i++)
  {
    player = current_turn%2;
    int if_success = 0;

    // Request a move from the next player and check it is valid (an unused square within the board)
    printf("Player %c: Enter your move as row column values:\n",symbols[player]);
    if_success = makeMove(game, symbols[player]);

    // If the move is invalid you should repeat the request for the current player
    while (if_success == 0)
    {
      printf("Move rejected. Please try again\n");
      printf("Player %c: Enter your move as row column values:\n",symbols[player]);
      if_success = makeMove(game, symbols[player]);
    }

    showGame( game ); // After each completed move display the board

    if (winGame(game, symbols[player]) == 1)
    {
      printf("Player %c has won\n",symbols[player]);
      return;
    }

    if (drawGame(game) == 1)
    {
      printf("Match is drawn\n");
      return;
    }

    current_turn++;

  }
  
  

  // After each valid move you can test for win or draw using functions you implement in endGame.c
   // use to announce a winner - game is over
  printf("Match is drawn\n"); // use to announce a draw - game is over
 
  return;
}

/*
 * Display the game board - do not adjust the formatting
 */

void showGame( Game *game ) {
  int i, j;

  printf("\n");
  printf("      ");
  for (i = 0; i < game->boardSize; i++)
  {
    if (i == (game->boardSize)-1)
    {
      printf("%i\n", i);
    }
    else
    {
      printf("%i  ", i);
    }
  }
  printf("\n");

  for (i = 0; i < game->boardSize; i++)
  {

    printf(" %i    ", i);

    for (j = 0; j < game->boardSize; j++)
    {
      if (j == (game->boardSize)-1)
      {
        printf("%c\n", game->board[i][j]);
      }
      else
      {
        printf("%c  ", game->board[i][j]);
      }
    }
  }
  printf("\n");

  return;
}

/*
 * Read in the players chosen location
 * Check that the input is a valid empty square
 * created by Ungku Amer Ungku Aziz sc22uaib
 * If valid then update the board (return 1)
 * If invalid reject the move (return 0)
 */

int makeMove( Game *game, char symbol ) {

  char player_input[100];
  int row, column;
  // read the players move from the keyboard, expected as two integers coordinates as shown on the board 
  fgets(player_input, 100, stdin);

  if (isdigit(player_input[0]) && isdigit(player_input[2]) && (player_input[1] == ' '))
  {
    row = atoi(&player_input[0]);
    column = atoi(&player_input[2]);

    if (row < 0 || row > (game->boardSize)-1) // checks if num is out of range
    {
      return 0; // move rejected
    }

    if (game->board[row][column] == '.') // test that the chosen location is a valid empty space
    {
      game->board[row][column] = symbol;
      return 1; // move accepted
    }
    else
    {
      return 0;
    }
  }

  return 0; // move accepted
}

