#include <stdio.h>
#include <stdlib.h>

int main()
{   int year, month, day, anni, left;
    while (1){
        printf("Input year: ");
        scanf("%d",&year);
        if (year<0){
            printf("Wrong Number\n");
            continue;
        }
        else if (year==0){
            return 0;
        }

        printf("Input month: ");
        scanf("%d",&month);
        if (month==0){
            return 0;
        }
        else if (month<1 || month>12){
            printf("Wrong Number\n");
            continue;
        }

        printf("Input day: ");
        scanf("%d",&day);
        if ((month==1)||(month==3)||(month==5)||(month==7)||(month==8)||(month==10)||(month==12)){ //day 31
            if ((day>31) ||(day<1)){
                printf("Wrong Number\n");
                continue;
            }
        }
        else   if ((month==4)||(month==6)||(month==9)||(month==11)){ //day 30
            if ((day>31) ||(day<1)){
                printf("Wrong Number\n");
                continue;
            }
        }
        else   if (month==2){ //february
            if (((year %4==0)&& (year %100!=0))||(year%400==0)){ //leap year, 29day
                if ((day<1)||day>29){
                    printf("Wrong Number\n");
                    continue;
                }
            }
            else { //28 day
                if ((day<1)||day>28){
                    printf("Wrong Number\n");
                    continue;
                }
            }
        }


        printf("Input anniversary: ");
        scanf("%d",&anni);

        while (anni!=0){
            if ((month==1)||(month==3)||(month==5)||(month==7)||(month==8)||(month==10)||(month==12)){ //day 31
                if (day+anni-1>31) {//(anni>31){ //Delete 31days and add month
                    month++;
                    anni=anni-(31-day+1);
                    day=1;
                    if (month==13){ // year change
                        year++;
                        month=1;
                        day=1;
                    }
                }
                else { //If anni is left less than 31, add day and end
                    day+=anni-1;
                    anni=0;
                }
            }
            else   if ((month==4)||(month==6)||(month==9)||(month==11)){ //day 30
                if (day+anni-1>30) {//Delete 30days and add month
                    month++;
                    anni=anni-(30-day+1);
                }
                else { //If anni is left less than 30, add month and end
                    day+=anni-1;
                    anni=0;
                }
            }
            else   if (month==2){ //february
                if (((year %4==0)&& (year %100!=0))||(year%400==0)){ //leap year, 29day
                    if (day+anni-1>29) {//Delete 29days and add month
                        month++;
                        anni=anni-(29-day+1);
                    }
                    else { //If anni is left less than 29, add month and end
                        day+=anni-1;
                        anni=0;
                    }
                }
                else { //Not leap year
                    if (day+anni-1>28) {//Delete 28days and add month
                        month++;
                        anni=anni-(28-day+1);
                    }
                    else { //If anni is left less than 28, add month and end
                        day+=anni-1;
                        anni=0;
                    }
                }
            }
        }
        printf("Date is %d %d %d\n",year,month,day);
    }
    return 0;
}
