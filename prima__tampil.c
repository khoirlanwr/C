#include <stdio.h>
void main()
{
    /*
        Expected Output:
        1 adalah prima
        2 adalah prima
        3 adalah prima
        4 bukan prima
        dst...
    */

    int start, stop, i, x, prima;
    printf("Masukkan batas mulai: ");
    scanf("%d", &start);
    printf("Masukkan batas akhir: ");
    scanf("%d", &stop);

    for(i = start; i<=stop; i++){
        prima = 1;
        for(x=2; x<i; ++x){
            if(i % x == 0){
                prima = 0;
                break;
            }else {
                prima = 1;
            }
        }
        if(prima) printf("\n%d\t: PRIMA", i);
        else printf("\n%d\t: BUKAN PRIMA", i);
    }

    printf("\n[END]");
    getch();
}
