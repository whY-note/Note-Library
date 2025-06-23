#include<stdio.h>
int main()
{
	enum Weekday{sun=7,mon,tue,wed,thu,fri,sat}workday,weekend;
	workday = sat;
	weekend = sun;
	printf("%d\n%d\n", workday,weekend);
	if (workday > weekend)
		printf("yes");
}