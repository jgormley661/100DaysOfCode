/* Moveable Player object using Object oriented C and ncurses */

//C Libraries
#include <ncurses.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <unistd.h>

//My Libraries
#include "headers/player.h"
#include "headers/myCurses.h"

//Keys to control program
#define KEY_MOVE_UP 'w'
#define KEY_MOVE_DOWN 's'
#define KEY_MOVE_LEFT 'a'
#define KEY_MOVE_RIGHT 'd'
#define KEY_EXIT_PROGRAM  'q'

//Create the color pairs
void initColorPairs(){
  init_pair(1, COLOR_BLACK, COLOR_BLACK);
  init_pair(2, COLOR_RED, COLOR_WHITE);
}

int main(void){

  //Program Settings
  const unsigned int PLAYER_WIDTH = 4;
  const unsigned int PLAYER_HEIGHT = 2;

  const unsigned int PLAYER_START_X = 3;
  const unsigned int PLAYER_START_Y = 3;

  const int PLAYER_SPEED_X = 2;
  const int PLAYER_SPEED_Y = 1;

  const char PLAYER_CHARACTER = 'X';
  
  //Initialize ncurses
  initscr();
  start_color();
  use_default_colors();
  initColorPairs();
  noecho();
  curs_set(0);

  //create Player object
  Player *p = player_new(PLAYER_START_X, PLAYER_START_Y, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_CHARACTER, COLOR_PAIR(2));

  //game loop (always true)
  while(true){

    //Reset background
    fill_section(0,0,500,500, ' ', COLOR_PAIR(1));
    //Draw player on top
    player_draw(p);
    
    //Get key presses
    char input = getch();

    switch(input){
    case KEY_MOVE_UP:
      player_move_by(p, 0, -PLAYER_SPEED_Y);
      break;

    case (const int)KEY_MOVE_DOWN:
      player_move_by(p, 0, PLAYER_SPEED_Y);
      break;

    case KEY_MOVE_LEFT:
      player_move_by(p, -PLAYER_SPEED_X, 0);
      break;

    case KEY_MOVE_RIGHT:
      player_move_by(p, PLAYER_SPEED_X, 0);
      break;

    case KEY_EXIT_PROGRAM:
      //Destroy player object
      free(p);
      //Destroy ncurses window
      endwin();
      //Exit successfully
      return EXIT_SUCCESS;
    }
  }
}
