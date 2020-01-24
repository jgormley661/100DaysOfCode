//Player struct
typedef struct Player{
  int x, y;
  int width, height;
  char character;
  int color_pair;
}Player;

//Constructor
void player_init(Player *self, int x, int y, int width, int height, char character, int color_pair);

//Allocate NEW player
Player *player_new(int x, int y, int width, int height, char character, int color_pair);

//Draw player on ncurses window
void player_draw(Player *p);

//Move player incrementally from current position
void player_move_by(Player *p, int x_change, int y_change);

//Move player to hard coded position
void player_move_to(Player *p, int x, int y);
