#include <stdio.h>
void main()
{
    int num, result;
    printf("Masukkan bilangan: ");
    scanf("%d", &num);
    
    result = prima(num);
    
    if(result) printf("%d PRIMA", num);
    else printf("%d BUKAN PRIMA", num);

    printf("\n[END]");
    getch();
}

/*
    Jika 1 maka prima, bukan 0
*/

int prima(x)
{
    int i, flag;
    for(i=2; i<x; ++i){
        flag = 1;
        if(x%i == 0){
            flag = 0;
            break;
        }
    }
    return flag;
}

