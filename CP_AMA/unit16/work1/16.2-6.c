#include <stdio.h>

typedef struct {
	int hours;
	int minutes;
	int seconds;
} Time;

Time split_time(long total_seconds);

int main(int argc, char *argv[])
{
	long total_seconds;
	Time time;
	
	printf("Enter the total seconds: ");
	scanf("%ld", &total_seconds);

	time = split_time(total_seconds);

	printf("It's %2d:%2d:%2d\n", time.hours, time.minutes, time.seconds);
	
    return 0;
}

Time split_time(long total_seconds)
{
	Time time;

	time.hours = total_seconds / 3600;
	time.minutes = (total_seconds % 3600) / 60;
	time.seconds = total_seconds % 60;

	return time;
}
