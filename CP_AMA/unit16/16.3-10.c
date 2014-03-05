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
int point_int_rect(struct point po, struct rectangle rect);
struct point get_point(void);


int main(int argc, char *argv[])
{
	struct rectangle rect = get_rect();
	print_rect(rect);
	printf("The area of this rectangle: %d\n", rect_area(rect));

	printf("Enter a point to check if in the rectangle:");
	struct point po = get_point();

	if (point_in_rect(po, rect)) {
		printf("The point is in the rectangle\n");
	} else {
		printf("The point is not in the rectangle\n");
	}
	
    return 0;
}

struct point get_point(void)
{
	struct point po;
	printf("Enter the point(x, y): ");
	scanf("%d, %d", &po.x, &po.y);

	return po;
}

struct rectangle get_rect(void)
{
	struct rectangle retval;

	for (;;) {
		printf("Upper left:\n");
		retval.upper_left = get_point();
		printf("Lower right:\n");
		retval.lower_right = get_point();
		
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

int point_in_rect(struct point po, struct rectangle rect)
{
	if (po.x <= rect.lower_right.x &&
		po.x >= rect.upper_left.x &&
		po.y <= rect.lower_right.y &&
		po.y >= rect.upper_left.y)
		return 1;
	return 0;
}
