#include <stdio.h>
#include <math.h>

float fx(float x);

float xatas, xbawah, h, x, x2, y;

int n, i;

void main () {
    printf("Tentukan batas bawah: ");
    scanf("%f", &xbawah);
    printf("Tentukan batas atas: ");
    scanf("%f", &xatas);
    printf("Tentukan jumlah pembagian n: ");
    scanf("%d", &n);

    h = (xatas-xbawah)/n;

    printf("No \t\tx \t\tf(x) \t\terror\n");

    for(i=0;i<n;i++)
    {
        x = xbawah + (i*h);
        x2 = xbawah + ((i+1)*h);
        y = fx(x);
        printf("%d\t\t%f\t%f\t%f\n",i+1,x,y,fabs(y));

        if(fx(x) == 0)
        {
            printf("Titik potong sumbu x saat nilai x = %f\n", x);
            break;
        }
        else if((fx(x)*fx(x2))<0)
        {
            if(fabs(fx(x)) < fabs(fx(x2)))
            {
                printf("Titik potong sumbu x mendekati nilai x = %f dengan fx = %f dan error %f\n", x, fx(x), fabs(fx(x)));
                break;
            }
            else
            {
                printf("Titik potong sumbu x mendekati nilai x2 = %f dengan fx = %f dan error %f\n", x2, fx(x2), fabs(fx(x2)));
                break;
            }
        }
    }
}

float fx(float x) {
    float y;

    y = exp(x)+x;
    return y;
}
