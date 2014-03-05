/* cp_ama p 277 */
#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;				/* number of parts currently stored */

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

int main(int argc, char *argv[])
{
    char code;

	for (; ; ) {
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while(getchar() != '\n') /* skip to the end of line */
			;
		switch(code) {
		case 'i': insert();
			break;
		case 's': search();
			break;
		case 'u': update();
			break;
		case 'p': print();
			break;
		case 'q': return 0;
		default: printf("Illegal code\n");
		}
		printf("\n");
	}
	
    return 0;
}

int find_part(int number)
{
	int i;
	for (i = 0; i < num_parts; i++) {
		printf("-----------------\ninventory[i] = %d\n------------\n", i);
		if (inventory[i].number == number)
			return i;
	}
	return -1;
}

void insert(void)
{
	int part_number;

	if (num_parts == MAX_PARTS) {
		printf("Database is full; can't add more part\n");
		return;
	}

	printf("Enter part number: ");
	scanf("%d", &part_number);

	if (find_part(part_number) >= 0) {
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

void search(void)
{
	int part_number;
	int i;
	
	printf("Enter part number: ");
	scanf("%d", &part_number);

	i = find_part(part_number);
	if(i >= 0) {
		printf("Part name: %s\n", inventory[i].name);
		printf("Quantity on hand: %d", inventory[i].on_hand);
		return;
	} else {
		printf("Part not found");
		return;
	}
}

void update(void)
{
	int i, part_number, on_hand;

	printf("Enter part number: ");
	scanf("%d", &part_number);

	i = find_part(part_number);
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

void print(void)
{
	int i;
	printf("Part Number\tPartName\tQuantity on Hand\n");
	for (i = 0; i < num_parts; i++) {
		printf("%d\t\t%s\t\t%d\n", inventory[i].number, inventory[i].name,
			   inventory[i].on_hand);
	}
}
