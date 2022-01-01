/*
    Nama: Hanif Al Fathoni
    NPM: 20081010001
    Kelas: Metode Numerik F081
*/

#include <stdio.h>
#include <math.h>

#define eksak 0.4364203757557

// Deklarasi fungsi integral
float f(float x)
{
  return (exp(-x)) / (1 + sqrt(x) + x * x);
}

// Penghitungan Aturan Reimann
float reimann(float a, float b, int n)
{
  float h, x, sum, integral, fx;
  int i;

  h = fabs(b - a) / n;

  printf("\nh: %f\n", h);

  printf("\ni\t\tx\t\tf(x)\n");

  for (i = 0; i < n; i++)
  {
    x = a + (i * h);
    fx = f(x);
    sum += fx;

    printf("%d\t\t%f\t%.30f\n", i, x, fx);
  }

  printf("\n\nSUM f(x):\t\t%.14f\n", sum);

  integral = h * sum;

  return integral;
}

// Penghitungan Aturan Trapesium
float trapesium(float a, float b, int n)
{
  float h, x, sum, integral, fx;
  int i;

  h = fabs(b - a) / n;

  printf("\nh: %f\n", h);

  printf("\ni\t\tx\t\tf(x)\n");

  for (i = 0; i < n; i++)
  {
    x = a + (i * h);
    fx = f(x);
    sum = sum + (2 * fx);

    printf("%d\t\t%f\t%.30f\n", i, x, fx);
  }

  printf("\n\nSUM f(x):\t\t%.14f\n", sum);

  integral = (h / 2) * sum;

  return integral;
}

// Penghitungan Aturan Simpson 1/3
float simpson13(float a, float b, int n)
{
  float h, x, sum, integral, fx;
  int i;

  h = fabs(b - a) / n;

  printf("\nh: %f\n", h);

  printf("\ni\t\tx\t\tf(x)\n");

  for (i = 0; i <= n; i++)
  {
    x = a + (i * h);
    fx = f(x);

    if (i % 2 == 0)
    {
      sum = sum + (2 * fx);
    }
    else
    {
      sum = sum + (4 * fx);
    }

    printf("%d\t\t%f\t%.30f\n", i, x, fx);
  }

  printf("\n\nSUM f(x):\t\t%.14f\n", sum);

  integral = (h / 3) * sum;

  return integral;
}

// Penghitungan Aturan Simpson 3/8
float simpson38(float a, float b, int n)
{
  float h, x, sum, integral, fx;
  int i;

  h = fabs(b - a) / n;

  printf("\nh: %f\n", h);

  printf("\ni\t\tx\t\tf(x)\n");

  for (i = 0; i <= n; i++)
  {
    x = a + (i * h);
    fx = f(x);

    if (i % 3 == 0)
    {
      sum = sum + (2 * fx);
    }
    else
    {
      sum = sum + (3 * fx);
    }

    printf("%d\t\t%f\t%.30f\n", i, x, fx);
  }

  printf("\n\nSUM f(x):\t\t%.14f\n", sum);

  integral = (h * 3 / 8) * sum;

  return integral;
}

// Program utama
void main()
{
  int menu, n;
  float a, b, hasil;

ulang:
  system("cls");

  do
  {
    printf("===========================================================================\n");
    printf("================== PROGRAM PENGHITUNGAN INTEGRASI NUMERIK==================\n");
    printf("================= HANIF AL FATHONI 20081010001 METNUM F081 ================\n");
    printf("===========================================================================\n");
    printf("\nTentukan batas bawah integrasi (a): ");
    scanf("%f", &a);
    printf("\nTentukan batas atas integrasi (b): ");
    scanf("%f", &b);
    printf("\nTentukan jumlah pembagi (n): ");
    scanf("%d", &n);

  up:
    system("cls");
    printf("\n1. Hitung integral dengan menggunakan aturan reimann");
    printf("\n2. Hitung integral dengan menggunakan aturan trapesium");
    printf("\n3. Hitung integral dengan menggunakan aturan simpson 1/3");
    printf("\n4. Hitung integral dengan menggunakan aturan simpson 3/8");
    printf("\n5. Input ulang nilai batas bawah, batas atas, dan jumlah pembagi");

    printf("\n\n0. Keluar Program");

    printf("\nMasukkan pilihan anda: ");
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
      printf("\nIntegrasi Numerik Aturan Reimann.\n");
      hasil = reimann(a, b, n);
      printf("\nLuasan Integral:\t%.13f", hasil);
      printf("\nNilai Eksak:\t\t%.13f", eksak);
      printf("\n\nNilai Error:\t\t%.13f", fabs(eksak - hasil));
      printf("\n\n");
      printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
      getch();
      goto up;
    case 2:
      printf("\nIntegrasi Numerik Aturan Trapesium.\n");
      hasil = trapesium(a, b, n);
      printf("\nLuasan Integral:\t%.13f", hasil);
      printf("\nNilai Eksak:\t\t%.13f", eksak);
      printf("\n\nNilai Error:\t\t%.13f", fabs(eksak - hasil));
      printf("\n\n");
      printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
      getch();
      goto up;
    case 3:
      printf("\nIntegrasi Numerik Aturan Simpson 1/3.\n");
      hasil = simpson13(a, b, n);
      printf("\nLuasan Integral:\t%.13f", hasil);
      printf("\nNilai Eksak:\t\t%.13f", eksak);
      printf("\n\nNilai Error:\t\t%.13f", fabs(eksak - hasil));
      printf("\n\n");
      printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
      getch();
      goto up;
    case 4:
      printf("\nIntegrasi Numerik Aturan Simpson 3/8.\n");
      hasil = simpson38(a, b, n);
      printf("\nLuasan Integral:\t%.13f", hasil);
      printf("\nNilai Eksak:\t\t%.13f", eksak);
      printf("\n\nNilai Error:\t\t%.13f", fabs(eksak - hasil));
      printf("\n\n");
      printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
      getch();
      goto up;
    case 5:
      printf("\nTekan enter untuk input ulang nilai a, b, dan n.\n");
      getch();
      goto ulang;
    }
  } while (menu != 0);
}
