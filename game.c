// GAME
// Copyright 2019 Peter Mezei
// All right reserved
// GNU GPL2 License

// DEMO
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef _WIN32
	#include <windows.h>
#else
	#include <unistd.h>
#endif

//
#define CLEAR_SCREEN "\e[1;1H\e[2J"
#define CLEAR_EOL    "\x1B[K"
#define MOVE_CURSOR  "\x1B[%d;%df"

#define MAX_ROW    10
#define MAX_COLUMN 10

typedef struct {
  char *avatar;
  int x;
  int y;
} Character;

void sleep_sec(int time) {
  #ifdef _WIN32
  Sleep(time);
	#else
  sleep(time);
	#endif
}

void sleep_millisec(int time) {
  #ifdef _WIN32
  Sleep(time / 1000);
	#else
  usleep(time * 1000);
	#endif
}

// Get random number
int get_random() {
  int r = rand() % 2;
  return r;
}

// Set player position using random
void set_new_position(Character *character) {
  // Set x chord
  if (get_random() == 0 && character->x < (MAX_COLUMN - 1)) {
    character->x++;
  } else if (character->x > 0){
    character->x--;
  }

  // Set y chord
  if (get_random() == 0 && character->y < (MAX_ROW - 1)) {
    character->y++;
  } else if (character->y > 0) {
    character->y--;
  }
}

// Print players;
void print_players(Character *player_a, Character *player_b) {
  // Print player A
  printf(MOVE_CURSOR, player_a->x, player_a->y);
  printf("%s\n", player_a->avatar);

  // Print player B
  printf(MOVE_CURSOR, player_b->x, player_b->y);
  printf("%s\n", player_b->avatar);
}

// Print player position
void print_position(int position, Character *player) {
  printf(MOVE_CURSOR, (10 + position), 30);
  printf("|   %s x:%d, y:%d\n", player->avatar, player->x, player->y);
}

int main() {

  printf(CLEAR_SCREEN);
  printf(MOVE_CURSOR, 0, 0);
  
  char *intro[] = {
    "--------------------------",
    "| Catch me! (L)          |",
    "|                        |",
    "| To start, press enter! |",
    "--------------------------",
    NULL
  };

  for (int i = 0; intro[i]; i++) {
    printf("%s\n", intro[i]);
  }

  char start[20];
  scanf("%s", start);

  Character *panda = malloc(sizeof(Character));
  Character *fox = malloc(sizeof(Character));

  panda->avatar = "🐼";
  panda->x = 10;
  panda->y = 10;

  fox->avatar = "🦊";
  panda->x = 15;
  panda->y = 15;
  
  while(1) {
    // Clear screen
    /* printf(CLEAR_SCREEN); */
    system("clear");
    
    // Print players;
    print_players(panda, fox);

    // Print positions;
    print_position(0, panda);
    print_position(1, fox);

    // Check crash!
    if ((panda->x == fox->x) && (panda->y == fox->y)) {
      system("clear");
      printf(MOVE_CURSOR, panda->x, panda->y);
      printf("🔥\n");
      sleep_sec(3);
      break;
    }

    // Set new random positions;
    set_new_position(fox);
    set_new_position(panda);
    
    // Sleep in ms;
    sleep_millisec(500);
  }

  // Clear screen
  system("clear");
  
  printf(MOVE_CURSOR, 0, 0);
  
  char *msg[] = {
    "--------------------------",
    "| Game Over!             |",
    "--------------------------",
    NULL
  };

  for (int i = 0; msg[i]; i++) {
    printf("%s\n", msg[i]);
  }
}
