#include <stdio.h>
#include <math.h>

float f(float x) {
    float y;

    y = (exp(-x)) - x;
    return y;
}

float x, a, b, fx, fa, fb, fi[10], e, nilai_error;

int i, n;

void main() {
    printf("Tentukan nilai a: ");
    scanf("%f", &a);
    printf("Tentukan nilai b: ");
    scanf("%f", &b);
    printf("Tentukan toleransi e: ");
    scanf("%f", &e);
    printf("Tentukan iterasi maksimum n: ");
    scanf("%d", &n);

    fa = f(a);
    fb = f(b);

    if ((fa * fb) > 0) {
        printf("Proses dihentikan, tidak ditemukan akar.\n");
        return;
    }
    else {
        printf("\nIterasi\t\ta\t\tb\t\tx\t\tf(x)\t\t\tnilai error |f(x)|\n");
        for (i = 0; i <= n-1; i++) {
            x = ((fb*a)-(fa*b))/(fb-fa);
            fx = f(x);
            nilai_error = fabs(fx);

            printf("%d\t\t%f\t%.10f\t%.10f\t%.10f\t\t%.10f\n", i+1, a, b, x, fx, nilai_error);

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

    printf("\nPada iterasi ke-%d diperoleh x = %.10f dan dengan nilai error = %.10f\n", i, x, nilai_error);
}
