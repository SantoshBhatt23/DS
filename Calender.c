#include <stdio.h>

int isLeap(int year){
    if((year%4==0 && year%100 != 0)||(year%400==0)) return 1;
    else return 0;
}

int daysInMonth(int month, int year){
    int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(month == 2 && isLeap(year)) return 29;
    return days[month-1];
}
int dayOfWeek(int d,int m,int y){
    if(m<3){
        m+=12;
        y--;
    }
    int k = y%100;
    int j = y/100;
    int day = (d+(13*(m+1))/5 + k + k/4 + j/4 + 5*j);
    return (day+6)%7; //converts to sunday = 0
}

int main(){
   int month ,year;
   printf("enter month and year: ");
   scanf("%d %d",&month,&year);

   int totalDays = daysInMonth(month,year);
   int startDay = dayOfWeek(1,month,year);

   //printing calendar:
   printf("\nSun Mon Tue Wed Thu Fri Sat\n");
   for (int i = 0 ; i<startDay ; i++){
        printf("    ");
    }

    for(int day = 1 ; day<= totalDays; day++){
        printf("%3d ",day);
        if((day + startDay)%7==0) printf("\n");
    }
    return 0;
}