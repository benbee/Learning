/* color? */
#include <stdio.h>
#include <stdbool.h>

typedef struct {
	int red;
	int green;
	int blue;
} Color;

const Color MAGENTA = {.red = 255,
					   .green = 0,
					   .blue = 255,};

void print_color(Color color);
Color make_color(int red, int green, int blue);

int getRed(Color color);
int getGreen(Color color);
int getBlue(Color color);
bool equal_color(Color color1, Color color2);
Color brighter(Color c);
int brighter_color(int val, float factor);
Color darker(Color c);
int darker_color(int val, float factor);
Color get_color(void);

int main(int argc, char *argv[])
{
	Color color1 = get_color();
    //print_color(MAGENTA);
	printf("Brighter color:\n");
	print_color(brighter(color1));

	printf("Darker color:\n");
	print_color(darker(color1));
	
    return 0;
}

void print_color(Color color)
{
	printf("RED: \t%d\nGREEN: \t%d\nBLUE: \t%d\n",
		   color.red, color.green, color.blue);
}

Color make_color(int red, int green, int blue)
{
	Color retval;

	if (red < 0)
		retval.red = 0;
	else if (red > 255)
		retval.red = 255;
	else
		retval.red = red;

	if (green < 0)
		retval.green = 0;
	else if (green > 255)
		retval.green = 255;
	else
		retval.green = green;

	if (blue < 0)
		retval.blue = 0;
	else if (blue > 255)
		retval.blue = 255;
	else
		retval.blue = blue;

	return retval;
}

int getRed(Color color)
{
	return color.red;
}

int getGreen(Color color)
{
	return color.green;
}

int getBlue(Color color)
{
	return color.blue;
}

bool equal_color(Color c1, Color c2)
{
	if (c1.red == c2.red &&
		c1.green == c2.green &&
		c1.blue == c2.blue)
		return true;
	else
		return false;
}

Color brighter(Color c)
{
	Color retval;

	if (c.red == 0 &&
		c.green == 0 &&
		c.blue == 0) {
		retval.red = 3;
		retval.green = 3;
		retval.blue = 3;

		return retval;
	}

	retval.red = brighter_color(c.red, 0.7);
	retval.green = brighter_color(c.green, 0.7);
	retval.blue = brighter_color(c.blue, 0.7);

	return retval;
}

int brighter_color(int val, float factor)
{
	int retval;
	
	if (val >= 0 &&
		val < 3) {
		retval = 3;
		return val;
	}

	retval = val / factor;
	if (retval > 255)
		retval = 255;

	return retval;
}

Color darker(Color c)
{
	Color retval;

	retval.red = darker_color(c.red, 0.7);
	retval.green = darker_color(c.green, 0.7);
	retval.blue = darker_color(c.blue, 0.7);

	return retval;
}

int darker_color(int val, float factor)
{
	return val * factor;
}

Color get_color(void)
{
	Color retval;

	printf("RED: ");
	scanf("%d", &retval.red);
	printf("GREEN: ");
	scanf("%d", &retval.green);
	printf("BLUE: ");
	scanf("%d", &retval.blue);

	return retval;
}
