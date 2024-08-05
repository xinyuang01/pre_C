#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(){
    int year=2000;
    int month=3;
    int day=30;
    int result=day_of_year(year,month,day);
    printf("The days in current year: %d", result);
    return 0;
}

//Row: non-leap + leap year; Col: Each month Jan-Dec 
static char daytab[2][13] = { 
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} 
    };

/* day_of_year: set day of year from month & day */ 
int day_of_year(int year, int month, int day) { 
    int i, leap; 
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0; 

    // YOU MUST USE fprintf for stderr!

    // Finds out if year entered is valid. Needs to be non negative int.
    if(year<0) {
        fprintf(stderr, "Error: The year entered must be non-negative integer. \n");
        return -1;
    }
    // Finds out if month entered is valid. Should be 1<=month<=12
    if(month<1 || month>12) {
        fprintf(stderr, "Error: Please check if the month is between 1-12, Jan-Dec. \n");
        return -1;
    }
    // Finds out if day entered is valid.
    // Should be nonnegative, and less than the total days the current month had.
    if(day<1 || day>daytab[leap][month]){
        fprintf(stderr, "Error: 1. The day is a non-negative integer. \n2. The day you entered exceeds the total days current month had\n");
        return -1;
    }

    for (i = 1; i < month; i++) 
        day += *(*(daytab+leap)+i);
        //daytab[leap][i] 
        //*(*(daytab+leap)+i)
    return day; 
}

void month_day(int year, int yearday, int *pmonth, int *pday) { 
    int i, leap; 
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0; 
    // Finds out if year entered is valid. Needs to be non negative int.
    if(year<0) {
        fprintf(stderr, "Error: The year entered must be non-negative integer. \n");
        return;
    }
    // If it's a leap year, then yearday cannot be larger than 366, otw 365.
    if(leap && (yearday<1||yearday>366)) {
        fprintf(stderr, "The yearday you entered is unavailable for conversion \n");
        return;
    }
    if(!leap && (yearday<1||yearday>365)) {
        fprintf(stderr, "The yearday you entered is unavailable for conversion \n");
        return;
    }

    for (i = 1; yearday > daytab[leap][i]; i++) 
        yearday -= daytab[leap][i]; 
    *pmonth = i; 
    *pday = yearday; 
}