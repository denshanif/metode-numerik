// Deklarasi prepocessor directive
#include <stdio.h>
#include <math.h>

// Pendefinisian fungsi, yakni f(x) = (exp(-x)) -x
float f(float x) {
    float y;

    y = (exp(-x)) - x;
    return y;
}

// Inisialisasi variabel
float x, a, b, fx, fa, fb, e, nilai_error;

int i, n = 10; // iterasi (n) ditentukan dengan nilai 10

// Program utama
void main() {
    char kembali;
    do {
        up:
        system("cls");
        // Judul program
        printf("==========================================================================================================\n");
		printf("=================== PROGRAM PERHITUNGAN PERSAMAAN NON LINIER METODE REGULA FALSI =========================\n");
		printf("============================== HANIF AL FATHONI 20081010001 METNUM F081 ==================================\n");
		printf("==========================================================================================================\n");
        printf("\nTentukan nilai batas bawah (a): "); // Input batas bawah
        scanf("%f", &a);
        printf("Tentukan nilai batas ata (b): "); // Input batas atas
        scanf("%f", &b);

        fa = f(a); // Penghitungan fa dengan memasukkan nilai a ke rumus fungsi
        fb = f(b); // Penghitungan fb dengan memasukkan nilai b ke rumus fungsi

        // Kondisional if untuk pengecekan nilai fa x fb > 0, karena jika < 0, tidak ada akar
        if ((fa * fb) > 0) {
            printf("\nProses dihentikan, tidak ditemukan akar dari nilai a dan b yang ditentukan.\n");
            printf("Tekan enter untuk mengulangi.\n");
            getch();
            goto up; // Mengulangi input a dan b
        }
        // Jika kondisi di atas tidak terpenuhi, maka program dilanjutkan
        else {
            printf("\nIterasi\t\ta\t\tb\t\tx\t\tf(x)\t\t\tnilai error |f(x)|\n");
            printf("==========================================================================================================\n");

            // Looping penghitungan akar
            for (i = 1; i <= n; i++) {
                x = ((fb*a)-(fa*b))/(fb-fa); // Peghitungan nilai x dengan rumus (fb x a - fa x b) / fb - fa
                fx = f(x); // Penghitungan x dengan memasukkan nilai x ke rumus fungsi
                nilai_error = fabs(fx); // Penghitunan nilai error fx dengan absolut fx

                printf("%d\t\t%f\t%.12f\t%.12f\t%.12f\t\t%.12f\n", i, a, b, x, fx, nilai_error);

                // Kondisional if jika fx x fa < 0 maka b = x dan fb = fx
                if (fx * fa < 0) {
                    b = x;
                    fb = fx;
                }
                // Jika tidak memenuhi kondisi di atas, maka a = x dan fa = fx
                else {
                    a = x;
                    fa = fx;
                }

                //Kondisional if jika absolut b - a < error, jika terpenuhi maka program dihentikan
                if (fabs(b - a) < e)
                    break;
            }
        }

        // Output hasil akar dan nilai error
        printf("==========================================================================================================\n");
        printf("\nPada iterasi ke-%d diperoleh x = %.12f dan dengan nilai error = %.12f.\n", i-1, x, nilai_error);
        printf("\nTekan enter untuk melanjutkan.\n");
        getch();

        // Pilihan kembali ke menu awal
        printf("\nIngin kembali ke menu awal? (Y/T): ");
		scanf("%c", &kembali); scanf("%c", &kembali);
    }
    while(kembali == 'y' || kembali == 'Y');

}
