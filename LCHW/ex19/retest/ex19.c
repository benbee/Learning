#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ex19.h"

int Monster_attack(void *self, int damage, int *player_health)
{
	Monster *monster = self;

	if (*player_health <= 0) {
		printf("\nYou have dead!");
		exit(1);
	} else {
		printf("You attack %s!\n", monster->_(description));

		monster->hit_points -= damage;
		if (monster->hit_points > 0)
			*player_health -= monster->attack_points;
		if (*player_health <= 0) printf("You have dead!");
		else printf("\nHealth Point(s): %d\n", *player_health);
	}

	if (monster->hit_points > 0) {
		printf("It is still alive.\n");
		return 0;
	} else {
		printf("It is dead!\n");
		return 1;
	}
}

int Monster_init(void *self)
{
	Monster *monster = self;
	monster->hit_points = 10;
	monster->attack_points = 4;
	return 1;
}

Object MonsterProto = {
	.init = Monster_init,
	.attack = Monster_attack,
};

void *Room_move(void *self, Direction direction)
{
	Room *room = self;
	Room *next = NULL;

	if (direction == NORTH && room->north) {
		printf("You go north, into:\n");
		next = room->north;
	} else if (direction == SOUTH && room->south) {
		printf("You go north, into:\n");
		next = room->south;
	} else if (direction == EAST && room->east) {
		printf("You go east, into:\n");
		next = room->east;
	} else if (direction == WEST && room->west) {
		printf("You go west, into:\n");
		next = room->west;
	} else {
		printf("You can't go that direction.");
		next = NULL;
	}

	if (next) {
		next->_(describe)(next);
	}

	return next;
}

int Room_attack(void *self, int damage, int *player_health)
{
	Room *room = self;
	Monster *monster = room->bad_guy;

	if (monster) {
		monster->_(attack)(monster, damage, player_health);
		return 1;
	} else {
		printf("You flail in the air at nothing. Idiot\n");
		return 0;
	}
}

Object RoomProto = {
	.move = Room_move,
	.attack = Room_attack,
};

void *Map_move(void *self, Direction direction)
{
	Map *map = self;
	Room *location = map->location;
	Room *next = NULL;

	next = location->_(move)(location, direction);

	if (next) {
		map->location = next;
	}

	return next;
}

int Map_attack(void *self, int damage, int *player_health)
{
	Map *map = self;
	Room *location = map->location;

	return location->_(attack)(location, damage, player_health);
}

int Map_init(void *self)
{
	Map *map = self;

	/* /\* make some rooms for a small map *\/ */
	/* Room *hall  = NEW(Room, "The great Hall"); */
	/* Room *throne = NEW(Room, "The throne room"); */
	/* Room *arena = NEW(Room, "The arena, with the minotaur"); */
	/* Room *kitchen = NEW(Room, "Kitchen, you have the knife now"); */

	/* /\* put the bad guy in the arena *\/ */
	/* arena->bad_guy = NEW(Monster, "The evil minotaur"); */

	/* /\* setup the map rooms *\/ */
	/* hall->north = throne; */

	/* throne->west = arena; */
	/* throne->east = kitchen; */
	/* throne->south = hall; */

	/* arena->east = throne; */
	/* kitchen->west = throne; */

	/* /\* start the map and the character off in the hall *\/ */
	/* map->start = hall; */
	/* map->location = hall; */
	
	// setup map
	Room *cai_village = NEW(Room, "The village where super hero begin.");
	Room *cai_river = NEW(Room, "The small river where cai got washed.") ;
	Room *cai_cave = NEW(Room, "Oh, yean advanture begin!");
	Room *sword_sorrow = NEW(Room, "Blade wait its master sorrowly.");
	Room *helpful_house = NEW(Room, "There is a big cock dance for you.");
	Room *shield_hotel = NEW(Room, "First enjoy for the \'GREAT\' advanture.");
	Room *recovery_center = NEW(Room, "ATTENTION! NO TIME FOR THE LADIES!");
	Room *fake_garden = NEW(Room, "Careful, maybe you need to start again...");
	Room *tiny_big_yard = NEW(Room, "The world seems weird, what happened?");
	
	// setup monster
	Monster *easy_cock = NEW(Monster, "First up, first down.");
	Monster *real_doom = NEW(Monster,
							 "It seems unreal, maybe you should in an advanture to home...");
	Monster *doom_the_shrink = NEW(Monster, "Oh, it's realy big, no, it's small.");
	
	// put monster in the map
	helpful_house->bad_guy = easy_cock;
	tiny_big_yard->bad_guy = doom_the_shrink;
	fake_garden->bad_guy = real_doom;

	easy_cock->attack_points = 2;
	doom_the_shrink->attack_points = 4;
	real_doom->attack_points = 3;

	/* connect rooms */
	cai_village->west = cai_river;

	cai_river->east = cai_village;
	cai_river->north = cai_cave;

	cai_cave->south = cai_river;
	cai_cave->north = sword_sorrow;
	
	sword_sorrow->east = helpful_house; /* there is no way back */

	helpful_house->west = sword_sorrow;
	helpful_house->south = shield_hotel;

	shield_hotel->north = helpful_house;
	shield_hotel->east = recovery_center;

	recovery_center->west = shield_hotel;
	recovery_center->south = fake_garden;
	recovery_center->north = tiny_big_yard;

	fake_garden->north = recovery_center;
	fake_garden->south = cai_village;

	tiny_big_yard->south = recovery_center;
	
	map->start = cai_village;
	map->location = cai_village;
	
	return 1;
}

Object MapProto = {
	.init = Map_init,
	.move = Map_move,
	.attack = Map_attack,
};

int process_input(Map *game, int *player_health)
{
	printf("\n>");

	char ch = getchar();
	getchar();					/* eat ENTER */

	int damage = rand() % 4;

	switch(ch) {
	case -1:
		printf("Giving up? You suck.\n");
		return 0;
		break;

	case 'n':
		game->_(move)(game, NORTH);
		break;
	case 's':
		game->_(move)(game, SOUTH);
		break;
	case 'w':
		game->_(move)(game, WEST);
		break;
	case 'e':
		game->_(move)(game, EAST);
		break;

	case 'a':
		game->_(attack)(game, damage, player_health);
		break;
	case 'l':
		printf("You can go:\n");
		if(game->location->north) printf("NORTH\n");
		if(game->location->south) printf("SOUTH\n");
		if(game->location->east) printf("EAST\n");
		if(game->location->west) printf("WEST\n");
		break;

	default:
		printf("What?: %d\n", ch);
	}
	return 1;
}

int main(int argc, char *argv[])
{
	int player_health = 10;
	
    /* simply way to set up the randomness */
	srand(time(NULL));

	/* make out map to work with */
	Map *game = NEW(Map, "The Hall of the Minotaur.");

	printf("You enter the ");
	game->location->_(describe)(game->location);

	while (process_input(game, &player_health)) {
	}
		
    return 0;
}
