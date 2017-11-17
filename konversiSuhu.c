/*
    Nama File: TUGAS4.C
    Nama Mhs : KHOIRUL ANWAR
    Kelas    : 1D4 TK-B
    NRP      : 2210171032
*/

float suhu(float n, char s, char d)
{
    if(s == 'C' && d == 'R'){
        return (n*4) /5;      // 1
    }else if(s == 'C' && d == 'F'){
        return (9*n)/5 + 32;  // 1
    }else if(s == 'F' && d == 'C'){
        return ((n-32)*5) /9; // 1
    }else if(s == 'F' && d == 'R'){
        return ((n-32)*4) /9; // 1
    }else if(s == 'R' && d == 'C'){
        return (n*5) /4;      // 1
    }else if(s == 'R' && d == 'F'){
        return (n*9) /4 + 32; // 1
    }else{
        return 0;
    }
}

void main()
{
    char s, d, t;
    float n, hasil;
    printf("================================\n");
    printf("         PROGRAM SUHU           \n");
    printf("================================\n");

    while(t != 'N'){
        //hasil = 0;
        printf("\nMasukkan suhu sumber  : ");
        scanf("%f %c", &n, &s);

        printf("Masukkan suhu tujuan  : ");
        scanf(" %c", &d);

        // menggunakan fungsi suhu()
        hasil = suhu(n, s, d);
        if(hasil != 0){
            printf("\nHasil konversi suhu   : %0.2f %c", hasil, d);
        }else{
            printf("Format SALAH!\n");
        }

        printf("\nCoba lagi? [Y/N]: "); scanf(" %c", &t);
    }
    printf("\n================================");
    printf("\n[ENTER]");
    getch();
}
