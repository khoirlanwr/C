#include <stdio.h>

/* Variabel */
int num1, num2, result, error = 0, loop = 1;
char Op;

int startCount(int result);

void main()
{

    /* Proses input pertama */
	printf("Masukkan accumulator dengan format\n");
	printf("bilangan-1 operator bilangan-2: "); scanf("%d %c %d", &num1, &Op, &num2);

	switch(Op){
		case '*': result = num1 * num2;
		break;
		case '/': result = num1 / num2;
		break;
		case '+': result = num1 + num2;
		break;
		case '-': result = num1 - num2;
		break;
		default: error = 1;
		break;
	}

	if(!error) printf("Hasil %d %c %d = %d\n", num1, Op, num2, result);
	else printf("ERROR!\n");

    while(loop){
        result = startCount(result);
        printf("= %d\n", result);
    }
}


int startCount(int result)
{
    printf(">> "); scanf("%d %c", &num1, &Op);

    if(Op == '+') {
        result += num1;
        loop = 1;
    }else if(Op == '-') {
        result -= num1;
        loop = 1;
    }else if(Op == '*') {
        result *= num1;
        loop = 1;
    }else if(Op == '/') {
        result /= num1;
        loop = 1;
     }else loop = 0;

    return result;

}
