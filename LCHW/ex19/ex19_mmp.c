#include <stdio.h>

int main(int argc, char *argv[])
{
    /* simply way to set up the randomness */
	srand(time(NULL));

	/* make out map to work with */
	Map *game = NEW(Map, "The Hall of the Minotaur.");

	printf("You enter the ");
	game->location->_(describe)(game->location);

	while (process_input(game)) {
	}
		
    return 0;
}
