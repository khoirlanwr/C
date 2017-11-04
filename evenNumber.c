#include <stdio.h>

int isEven(int);
int retryProgram();
char choose;

void main()
{
    int num, retry = 0;

    while(!retry){
        printf("\nEnter a number: "); scanf("%d", &num);
        printf("%d is %s number", num, (isEven(num))?"ODD":"EVEN");

        printf("\nRetry program: \n");
        printf("1. Yes \n2. No\n: ");
        retryProgram();
        retry = retryProgram();

    }
}

int isEven(int num)
{
    return (num&1);
}

int retryProgram()
{
    choose = getchar();
    switch(choose){
    case 'N':
    case 'n':
    case '2':
        return 1;
    break;
    case 'Y':
    case 'y':
    case '1':
        return 0;
    break;
    }
}
