#include <stdio.h>

void main()
{
    int numl, count, sum = 0;
    printf("\nEnter a numl: "); scanf("%d", &numl);

    int n = numl;
    int i = 0;
    while(n != 0){
        n = n/10;
        i++;
    }

    count = i;
    int numlArray[i];
    n = numl;

    // Assign
    while(n != 0){
        numlArray[i-1] = n % 10;
        n /= 10;
        i--;
    }

    // Display
    for(n=0; n<=count-1; n++){
        printf("%d", numlArray[n]);
        if(n == count-1) printf(" = "); else printf(" + ");
        sum = sum + numlArray[n];
    }

    printf("\n\tTotal: %d", sum);
    getch();
}


/*
    Urutan:
    1. Menghitung ukuran dari array dengan while (line 10-13)
    2. Assign masing - masing nilai index array (line 20-23)
    3. Menampilkan & Menghitung jumlah masing masing index array (line 27-30)
    
*/
