/*
    Nama File: TUGAS1.C
    Nama Mhs : KHOIRUL ANWAR
    Kelas    : 1D4 TK-B
    NRP      : 2210171032
*/

#include <stdio.h>

void main()
{
    /*
        i sebagai control variable baris
        j sebagai control variable kolom
    */
    int i, j, n = 0;
    for(i=1; i<=5; i++){

        for(j=1; j<=5; j++){
            if (i == j) n = 1; else n = 0;
            printf(" %d ", n);
        }

        printf("\n");
    }
    getch();
}

/*
    ANALISA:
    - variabel i sebagai variable pengendali baris
    - variabel j sebagai variable pengendali kolom
    - for() pertama untuk melakukan perulangan terhadap
    nilai baris.
    - for() kedua untuk melaukukan perulangan terhadap
    nilai kolom.
    - apabila nilai var. 'j' sudah terpenuhi maka, proses
    selanjutnya adalah mengeksekusi statement for() pertama
    lainnya, yaitu mengganti baris.
    - apabila nilai var. 'i' dan var 'j' sama maka yang akan
    ditampilkan adalah 1, bukan 0
*/
