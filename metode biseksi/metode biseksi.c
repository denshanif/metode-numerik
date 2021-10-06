#include <stdio.h>
#include <math.h>

float f(float x);

float x, a, b, fx, fa, fb, fi[10], e;

int i, n = 10;

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
        for (i = 0; i <= n; i++) {
            x = (a + b)/2;
            fx = f(x);

            printf("%d\t\t%f\t%f\t%f\t%f\t%f\n", i + 1, a, b, x, fx, fa);

	        if ((fx * fa) < 0) {
	            b = x;
	            fb = fx;
	        }
	        else {
	            a = x;
	            fa = fx;
	        }

            if (fabs(b - a) <= e)
            	break;
        }
    }

    printf("\nPada iterasi ke-%d diperoleh x = %f dan f(x) = %f\n", i+1, x, fx);
}

float f(float x) {
    float y;

    y = x * exp(-x) + 1;
    return y;
}
