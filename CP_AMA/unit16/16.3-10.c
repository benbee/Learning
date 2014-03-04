#include <stdio.h>

struct point {
    int x, y;
};

struct rectangle {
	struct point upper_left,
		lower_right;
};

int rect_area(struct rectangle);
struct rectangle get_rect(void);
void print_rect(struct rectangle);

int main(int argc, char *argv[])
{
	struct rectangle rect = get_rect();
	print_rect(rect);
	printf("The are of this rectangel: %d\n", rect_area(rect));
	
    return 0;
}

struct rectangle get_rect(void)
{
	struct rectangle retval;

	for (;;) {
		printf("Enter the UPPER LEFT point(x, y): ");
		scanf("%d, %d", &retval.upper_left.x,
			  &retval.upper_left.y);

		printf("Enter the LOWER RIGHT point(x, y): ");
		scanf("%d, %d", &retval.lower_right.x,
			  &retval.lower_right.y);

		if (retval.upper_left.x <= retval.lower_right.x &&
			retval.upper_left.y <= retval.lower_right.y) {
			break;
		} else {
			printf("Warning: Right point must bigger than left point.\n");
		}
	}
	return retval;
}

void print_rect(struct rectangle rect)
{
	printf("Upper left point: (%d, %d)\n",
		   rect.upper_left.x,
		   rect.upper_left.y);

	printf("Lower right point: (%d, %d)\n",
		   rect.lower_right.x,
		   rect.lower_right.y);
}

int rect_area(struct rectangle rect)
{
	int width, height;

	width = rect.lower_right.x -
		rect.upper_left.x;
	height = rect.lower_right.y -
		rect.upper_left.y;

	return width * height;
}
