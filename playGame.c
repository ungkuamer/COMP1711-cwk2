
#include <stdio.h>
#include "game.h"
#include "playGame.h"

/*
 * Controls the game logic from start to end
 */

void playGame( Game *game ) {

  char symbols[2] = { 'X','O' };
  // player 'X' plays first
  int player = 0;

  // starting board
  printf("New game starting\n");
  showGame( game );
  
  // Your game should be controlled by an outer loop
  for (i = 0; i < (game -> maxTurns); ++i)
  {
    current_turn = game -> turns;
    player = current_turn%2;
    int if_success = 0;

    // Request a move from the next player and check it is valid (an unused square within the board)
    // If the move is valid update the board
    printf("Player %c: Enter your move as row column values:\n",symbols[player]);
    if_success = makeMove(game, symbols[player])

    if (if_success == 0)
    {
      printf("Move rejected. Please try again\n");
      printf("Player %c: Enter your move as row column values:\n",symbols[player]);
      if_success = makeMove(game, symbols[player]);
    }


    // After each completed move display the board 
    showGame( game );
    ++current_turn;

  }

  // After each valid move you can test for win or draw using functions you implement in endGame.c
  printf("Player %c has won\n",symbols[player]); // use to announce a winner - game is over
  printf("Match is drawn\n"); // use to announce a draw - game is over
 
  return;
}

/*
 * Display the game board - do not adjust the formatting
 */

void showGame( Game *game ) {

  printf("\n");
  printf("      0  1  2\n");
  printf("\n");
  printf(" 0    %c  %c  %c\n",game->board[0][0],game->board[0][1],game->board[0][2]);
  printf(" 1    %c  %c  %c\n",game->board[1][0],game->board[1][1],game->board[1][2]);
  printf(" 2    %c  %c  %c\n",game->board[2][0],game->board[2][1],game->board[2][2]);
  printf("\n");

  return;
}

/*
 * Read in the players chosen location
 * Check that the input is a valid empty square
 * If valid then update the board (return 1)
 * If invalid reject the move (return 0)
 */

int makeMove( Game *game, char symbol ) {

  char player_input[4];
  int row, column;
  char row_s, column_s;
  // read the players move from the keyboard, expected as two integers coordinates as shown on the board 
  fgets(player_input, 4, stdin);

  // test that the chosen location is a valid empty space
  row_s = player_input[0];
  column_s = player_input[2];

  // if we do not accept the move return 0
  if (row_s != isdigit() && column_s != isdigit())
  {
    return 0;
  }

  row = atoi(row);
  column = atoi(column);

  if (game -> board[row][column] == ".")
  {
    return 0;
  }
  
  // if we accept then update the board and return 1
  game -> board[row][column] = symbol;

  return 1; // move accepted
}

