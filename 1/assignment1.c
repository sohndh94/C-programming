#include <stdio.h>
#include <stdlib.h>

int main()
{
    int scr1, scr2, scr3, scr4;
    float avg;

    printf("Input each of 4 students score (0~100) : ");
    scanf("%d %d %d %d", &scr1, &scr2, &scr3, &scr4 );

    if ( (scr1<0 || scr1>100) || (scr2<0 || scr2>100) || (scr3<0 || scr3>100) || (scr4<0 || scr4>100))
        printf("Invalid entry!\n");
    else{
        avg= (scr1+scr2+scr3+scr4)/4;
        printf("The average score : %.2f\n", avg );

        printf("The 1st student: %d ",scr1);
        if (avg + 10 <=scr1)
            printf("A grade\n");
        else if ( (avg <=scr1) && (scr1< avg +10 ) )
            printf("B grade\n");
        else if ( (avg-10 <=scr1) && (scr1< avg  ) )
            printf("C grade\n");
        else if ( scr1 < avg -10 )
            printf("D grade\n");



        printf("The 2nd student: %d ",scr2);
        if (avg + 10 <=scr2)
            printf("A grade\n");
        else if ( (avg <=scr2) && (scr2< avg +10 ) )
            printf("B grade\n");
        else if ( (avg-10 <=scr2) && (scr2< avg  ) )
            printf("C grade\n");
        else if ( scr2 < avg -10 )
            printf("D grade\n");


        printf("The 3rd student: %d ",scr3);
        if (avg + 10 <=scr3)
            printf("A grade\n");
        else if ( (avg <=scr3) && (scr3< avg +10 ) )
            printf("B grade\n");
        else if ( (avg-10 <=scr3) && (scr3< avg  ) )
            printf("C grade\n");
        else if ( scr3 < avg -10 )
            printf("D grade\n");


        printf("The 4th student: %d ",scr4);
        if (avg + 10 <=scr4)
            printf("A grade");
        else if ( (avg <=scr4) && (scr4< avg +10 ) )
            printf("B grade");
        else if ( (avg-10 <=scr4) && (scr4< avg  ) )
            printf("C grade");
        else if ( scr4 < avg -10 )
            printf("D grade");
    }



}
