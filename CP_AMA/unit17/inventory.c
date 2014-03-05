/* cp_ama p 277 */
#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25

int max_parts = 1;

struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
};


int num_parts = 0;				/* number of parts currently stored */

int find_part(int number, struct part *inventory);
void insert(struct part *inventory);
void search(struct part *inventory);
void update(struct part *inventory);
void print(struct part *inventory);

int inventory_len(struct part *inventory);

int main(int argc, char *argv[])
{
    char code;
	struct part *inventory = (struct part *)malloc(sizeof(struct part) * 1);
	
	for (; ; ) {
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while(getchar() != '\n') /* skip to the end of line */
			;
		switch(code) {
		case 'i': insert(inventory);
			break;
		case 's': search(inventory);
			break;
		case 'u': update(inventory);
			break;
		case 'p': print(inventory);
			break;
		case 'q': {free(inventory); return 0;};
		default: printf("Illegal code\n");
		}
		printf("\n");
	}
	
    return 0;
}

int find_part(int number, struct part *inventory)
{
	int count;
	
	for (count = 0; count < num_parts; count++) {
		printf("-----------------\ninventory[i] = %d\n------------\n", count);
		if (inventory[count].number == number)
			return count;
	}
	return -1;
}

void insert(struct part *inventory)
{
	int part_number;

	if (num_parts == max_parts) {
		inventory = (struct part *)realloc(inventory, sizeof(struct part) * inventory_len(inventory) * 2);
		max_parts *= 2;
	}

	printf("Enter part number: ");
	scanf("%d", &part_number);

	if (find_part(part_number, inventory) >= 0) {
		printf("Part already exists.\n");
		return;
	}

	inventory[num_parts].number = part_number;
	printf("Enter part name: ");
	read_line(inventory[num_parts].name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &inventory[num_parts].on_hand);
	num_parts++;
}

void search(struct part *inventory)
{
	int part_number;
	int i;
	
	printf("Enter part number: ");
	scanf("%d", &part_number);

	i = find_part(part_number, inventory);
	if(i >= 0) {
		printf("Part name: %s\n", inventory[i].name);
		printf("Quantity on hand: %d", inventory[i].on_hand);
		return;
	} else {
		printf("Part not found");
		return;
	}
}

void update(struct part *inventory)
{
	int i, part_number, on_hand;

	printf("Enter part number: ");
	scanf("%d", &part_number);

	i = find_part(part_number, inventory);
	if (i >= 0) {
		printf("Enter quantity on hand: ");
		scanf("%d", &on_hand);
		inventory[i].on_hand = on_hand;
		return;
	} else {
		printf("Part not found");
		return;
	}
}

void print(struct part *inventory)
{
	int i;
	printf("Part Number\tPartName\tQuantity on Hand\n");
	for (i = 0; i < num_parts; i++) {
		printf("%d\t\t%s\t\t%d\n", inventory[i].number, inventory[i].name,
			   inventory[i].on_hand);
	}
	printf("\n--------------\n");
	printf("inventory length: %d\n", inventory_len(inventory));
}

int inventory_len(struct part *inventory)
{
	return num_parts;
}
