#include <stdio.h>

struct date {
	int month;
	int day;
	int year;
};

int day_of_year(struct date d);
int compare_dates(struct date d1, struct date d2);
int days_before_this_month(struct date day);
int check_leap_year(struct date date);

int main(int argc, char *argv[])
{
    struct date day;

	/* get the day */
	printf("Enter the year of day: ");
	scanf("%d", &day.year);
	printf("Enter the month of day: ");
	scanf("%d", &day.month);
	printf("Enter the day of day: ");
	scanf("%d", &day.day);

	printf("It's the %d(st) day of %d.\n", day_of_year(day), day.year);
	
    return 0;
}

int check_leap_year(struct date date)
{
	int year = date.year;

	/* if ((year % 400 == 0) || */
	/* 	((year % 4 == 0) && (year % 100 != 0)) || */
	/* 	((year % 100 == 0) && (year % 400 != 0))) { */
	/* 	return 1; */
	/* } else { */
	/* 	return 0; */
	/* } */

	if (year % 400 == 0) {
		return 1;
	} else if (year % 100 == 0) {
		return 0;
	} else if (year % 4 == 0) {
		return 1;
	} else
		return 0;
}

int days_before_this_month(struct date day)
{
	int month = day.month;
	int days, i;
	int month_day[12] = {31, 28, 31, 30, 31,
						 30, 31, 31, 30, 31,
						 30, 31};
	if (month == 1) {
		return 0;
	}

	days = 0;
	for (i = 0; i < month - 1; i++) {
		days += month_day[i];
	}

	if (check_leap_year(day)) {
		return days + 1;
	} else {
		return days;
	}
}

int day_of_year(struct date day)
{
	int days;

	days = days_before_this_month(day) + day.day;
	return days;
}

int compare_dates(struct date d1, struct date d2)
{
	if (d1.day == d2.day &&
		d1.month == d2.month &&
		d1.year == d2.year) {
		return 0;
	}

	if (d1.year < d2.year) {
		return -1;
	} else {
		return 1;
	}

	if (d1.month < d2.month)
		return -1;
	else
		return 1;

	if (d1.day < d2.day)
		return -1;
	else
		return 1;

}
