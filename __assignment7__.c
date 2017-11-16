#include <stdio.h>
/*
    Factorial Table
*/
#define FCTRL 10

void main()
{
    int count = 1, i = 0, j = 0;

    for(i=1; i<=FCTRL; i++){
        printf("%d!  = ", i);
        count = 1;

        for(j=1; j<=i; ++j){
            printf("%d", j);
            if(j == i) printf(" = "); else printf(" x ");
            count *= j;
        }
        printf("%d", count);
        printf("\n");
    }

    printf("\n[Enter]");
    getch();
}
