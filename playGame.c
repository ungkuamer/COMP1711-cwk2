
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
  printf("Win length is %i", game->winLength);
  showGame( game );
  
  // Your game should be controlled by an outer loop
  // Each pass through the loop is one completed move by a player
  for (i = 0; i < game->maxTurns; ++i)
  {
    player = current_turn%2;
    int if_success = 0;

    printf("player number %i\n", player);
    printf("Player %c: Enter your move as row column values:\n",symbols[player]);
    if_success = makeMove(game, symbols[player]);

    while (if_success == 0)
    {
      printf("Move rejected. Please try again\n");
      printf("Player %c: Enter your move as row column values:\n",symbols[player]);
      if_success = makeMove(game, symbols[player]);
    }

    showGame( game );
    
    if (winGame(game, symbols[player]) == 1)
    {
      printf("Player %c has won\n",symbols[player]);
      exit(0); 
    }

    if (drawGame(game) == 1)
    {
      printf("Match is drawn\n");
      exit(0);
    }

    current_turn++;
  }

   
  // Request a move from the next player and check it is valid (an unused square within the board)
  //printf("Player %c: Enter your move as row column values:\n",symbols[player]); // use this to request the player move

  // If the move is invalid you should repeat the request for the current player
  //printf("Move rejected. Please try again\n"); // use this message if move cannot be made. You must repeat the request for a move

  // If the move is valid update the board
  
  // After each completed move display the board 

  // After each valid move you can test for win or draw using functions you implement in endGame.c
  //printf("Player %c has won\n",symbols[player]); // use to announce a winner - game is over
  //printf("Match is drawn\n"); // use to announce a draw - game is over
  
  return;
}

/*
 * Display the game board - do not adjust the formatting
 */

void showGame( Game *game ) {

  printf("\n");
  printf("      0  1  2\n");
  printf("\n");
  printf(" 0    %c  %c  %c\n", game->board[0][0], game->board[0][1], game->board[0][2]);
  printf(" 1    %c  %c  %c\n", game->board[1][0], game->board[1][1], game->board[1][2]);
  printf(" 2    %c  %c  %c\n", game->board[2][0], game->board[2][1], game->board[2][2]);
  printf("\n");

}

/*
 * Read in the players chosen location
 * Check that the input is a valid empty square
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
    printf("%i %i", row, column);

    if (row < 0 || row > 2)
    {
      return 0;
    }

    if (game->board[column][row] == '.') // test that the chosen location is a valid empty space
    {
      game->board[column][row] = symbol;
      return 1; // if we accept then update the board and return 1
    }
    else
    {
      return 0; // if we do not accept the move return 0
    }
  }

  return 0; // move not accepted
}

