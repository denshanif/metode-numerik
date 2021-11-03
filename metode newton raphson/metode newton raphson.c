#include <stdio.h>
#include <math.h>

float f(float x) {
    return exp(x) - 5 * (x * x);
}

float f_aksen(float x) {
    return exp(x) - 10 * x;
}

float x0, x1, x2, f0, f1, e;
int i, n = 10;

void main() {
    char kembali;

    do {
        up:
        system("cls");
        printf("===========================================================================\n");
		printf("============== PROGRAM METODE TERBUKA METODE NEWTON RAPHSON ===============\n");
		printf("================= HANIF AL FATHONI 20081010001 METNUM F081 ================\n");
		printf("===========================================================================\n");
        printf("\nTentukan nilai tebakan awal: ");
        scanf("%f", &x0);
        printf("\nTentukan toleransi error: ");
        scanf("%f", &e);

        printf("\nIterasi\t\tx0\t\t|(x1-x0)/x1|\n");
        printf("===========================================================================\n");

        x1 = x0;
        do {

            f0 = f(x0);
            f1 = f_aksen(x0);

            if (f1 == 0.0) {
                printf("\nProses dihentikan, perhitungan error\n");
                printf("Tekan enter untuk mengulangi.\n");
                getch();
                goto up;
            }

            x1 = x0 - f0/f1;

            x2 = fabs((x1 - x0) / x1);

            printf("%d\t\t%f\t%f\n", i + 1, x0, x2);

            x0 = x1;

            i++;

            if (i > n) {
                printf("\nProses dihentikan, tidak konvergen (divergen)\n");
                printf("Tekan enter untuk mengulangi.\n");
                getch();
                goto up;
            }


        }while (x2 > e);

        printf("===========================================================================\n");

        printf("\nHampiran akar x = %f\n", x1);
        printf("\nTekan enter untuk melanjutkan.\n");
        getch();

        printf("\nIngin kembali ke menu awal? (Y/T): ");
		scanf("%c", &kembali); scanf("%c", &kembali);
    }

    while(kembali == 'y' || kembali == 'Y');
}
