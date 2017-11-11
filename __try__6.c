/*
    Nama  : Khoirul Anwar
    Kelas : 1D4 TK-B
    NRP   : 22101071032
*/

#include <stdio.h>

void main()
{
    int numl, count, sum = 0, loop = 1, res;
system:
    printf("\nMasukkan bilangan bulat positif: "); scanf("%d", &numl);
    int n = numl;
    int i = 0;
    sum = 0;

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
    printf("Jumlah angka dalam bilangan %d adalah: ", numl);
    for(n=0; n<=count-1; n++){
        printf("%d", numlArray[n]);
        if(n == count-1) printf(" = "); else printf(" + ");
        sum = sum + numlArray[n];
    }
    printf(" %d", sum);
    printf("\n\nCoba lagi? (y/n): ");

    loopFunc();
    res = loopFunc();
    if(res) goto system; else exit(0);

    getch();
}

int loopFunc()
{
    char ans;
    ans = getchar();
    switch(ans){
    case 'y':
    case 'Y':
        return 1;
        break;

    case 'n':
    case 'N':
        return 0;
        break;
    }
}


/*
    Urutan:
    1. Menghitung ukuran dari array dengan while (line 10-13)
    2. Assign masing - masing nilai index array (line 20-23)
    3. Menampilkan dan menghitung jumlah index array (line 27-31)
*/
