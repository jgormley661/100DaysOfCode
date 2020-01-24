//C Libraries
#include <stdlib.h>

//My Libraries
#include "../headers/player.h"
#include "../headers/myCurses.h"

//Constructor
void player_init(Player* self, int x, int y, int width, int height, char character, int color_pair){
  self->x = x;
  self->y = y;
  self->width = width;
  self->height = height;
  self->character = character;
  self->color_pair = color_pair;
}

//Allocate NEW player
Player *player_new(int x, int y, int width, int height, char character, int color_pair){
  //Manually allocate memory on the heap for player
  Player *result = (Player*) malloc(sizeof(Player));

  //Call constructor on this player
  player_init(result, x, y, width, height, character, color_pair);

  //Return manually allocated player
  return result;
}

//Draw Player on ncurses window
void player_draw(Player *p){
  fill_section(p->x, p->y, p->x + p->width, p->y + p->height, p->character, p->color_pair);
}

//Move player incrementally from current position
void player_move_by(Player *p, int x_change, int y_change){
  p->x += x_change;
  p->y += y_change;
}

//Move player to hard coded position
void player_move_to(Player *p, int x, int y){
  p->x = x;
  p->y = y;
}
