#include <stdio.h>
#include <math.h>

float f(float x);

float x, a, b, fx, fa, fb, e;

int iterasi;

void main() {
    printf("Tentukan nilai a: ");
    scanf("%f", &a);
    printf("Tentukan nilai b: ");
    scanf("%f", &b);
    printf("Tentukan toleransi e: ");
    scanf("%f", &e);

    fa = f(a);
    fb = f(b);

    if ((fa * fb) > 0) {
        printf("Proses dihentikan, tidak ditemukan akar.\n");
        return;
    }
    else {
        printf("\nIterasi\t\ta\t\tb\t\tx\t\tf(x)\t\tf(a)\n");
        do {
            x = (a + b)/2;
            fx = f(x);

            printf("%d\t\t%f\t%f\t%f\t%f\t%f\n", iterasi + 1, a, b, x, fx, fa);

            if ((fx * fa) < 0 || (fabs(fx) < e)) {
                b = x;
                fb = fx;
            }
            else {
                a = x;
                fa = fx;
            }
            iterasi = iterasi + 1;
        }while(fabs(b - a) > e);
    }

    printf("Pada iterasi ke-%d diperoleh x = %f dan f(x) = %f", iterasi, x, fx);
}

float f(float x) {
    float y;

    y = x * exp(-x) + 1;
    return y;
}
