#include <stdio.h>
#include <stdlib.h>

#define RECTANGLE 1
#define CIRCLE 2
#define PI 3.1415926

struct point {
	double x, y;
};

struct shape {
    int shape_kind;				/* RECTANGLE or CIRCLE */
	struct point center;		/* coordinates of center */
	union {
		struct {
			double height, width;
		} rectangle;
		struct {
			double radius;
		} circle;
	} u;
};

struct shape get_shape(void);
double shape_area(struct shape sh);
struct shape move_shape(struct shape sh, double x, double y);

int main(int argc, char *argv[])
{
    struct shape s;

	s = get_shape();
	printf("The aera of this shape is %.2f\n", shape_area(s));

	printf("The center of this shape is (%.2lf, %.2lf)\n",
		   s.center.x, s.center.y);
	s = move_shape(s, 2, 2);
	printf("It's (%.2lf, %.2lf\n) aftermove",
		   s.center.x, s.center.y);
	
    return 0;
}

struct shape get_shape(void)
{
	struct shape result;
	int kind;
	double height, width;
	double radius;
	struct point center;
	
	printf("What kind of shape do you want?\n1): rectangle\n2): circle\n");
	scanf("%d", &kind);
	for(;;scanf("%d", &kind)){
		if (kind == RECTANGLE) {
			printf("Enter the corrdinates of center(x, y): ");
			scanf("%lf, %lf", &center.x, &center.y);
			printf("Enter the width and height of this rectangle(exp 4 8):");
			scanf("%lf  %lf", &width, &height);
			while (height < 0 || width < 0) {
				printf("Width and height must be postive\n");
				scanf("%lf  %lf", &width, &height);
			}

			result.shape_kind = RECTANGLE;
			result.center = center;
			result.u.rectangle.width = width;
			result.u.rectangle.height = height;

			return result;
		} else if (kind == CIRCLE) {
			printf("Enter the corrdinates of center(x, y): ");
			scanf("%lf, %lf", &center.x ,&center.y);
			printf("Enter the radius of this circle:");
			scanf("%lf", &radius);
			while (radius < 0) {
				
				printf("Radius must be postive\n");
				scanf("%lf", &radius);
			}
			result.shape_kind = CIRCLE;
			result.center = center;
			result.u.circle.radius = radius;
			return result;
		} else {
			printf("Wrong selection, choose angain(1 or 2).");
		}
	}
}

double shape_area(struct shape sh)
{
	if (sh.shape_kind == RECTANGLE) {
		return sh.u.rectangle.width *
			sh.u.rectangle.height;
	} else if (sh.shape_kind == CIRCLE) {
		return PI * sh.u.circle.radius
			* sh.u.circle.radius;
	} else {
		printf("Can't calculate this shape!\n");
		exit(1);
	}
}

struct shape move_shape(struct shape sh, double x, double y)
{
	struct shape result = sh;

	result.center.x += x;
	result.center.y += y;

	return result;
}
