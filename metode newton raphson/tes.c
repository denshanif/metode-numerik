#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define e 0.00001

float f(float x){
	return (e*exp(x) - 5*x*exp(2));
}

float g(float x){
	return (e*exp(x) - 10*x);
}

int main(){
	 float x, x1, f1, nilai_f, nilai_g;
	 int step = 1, N=9;
	 system("cls");
	 printf("\nMasukkan nilai tebakan:\n");
	 scanf("%f", &x);
	 printf("\nStep\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
	 do
	 {
		  nilai_f = f(x);
		  nilai_g = g(x);
		  if(nilai_g == 0.0)
		  {
			   printf("Mathematical Error.");
			   exit(0);
		  }


		  x1 = x - nilai_f/nilai_g;


		  printf("%d\t\t%f\t%f\t%f\t%f\n",step,x,f,x1,f1);
		  x = x1;

		  step = step+1;

		  if(step > N)
		  {
			   printf("Not Convergent.");
			   exit(0);
		  }

		  f1 = f(x1);

	 }while(fabs(f1)>e);

	 printf("\nRoot is: %f", x1);
	 getch();
}
