#include <cmath>
#include <iostream>
using namespace std;

int maks = 1000; //iterasi maksimum hingga 100
double ketelitian = 10E-10; //presisi angka

// kita menggunakan fungsi (1 - (0.6 * x)) / x sesuai ppt komnum 2 latihan nomor 5
double f(double x){
    return (1 - (0.6 * x)) / x;
}

int main(){

    double x1, x2;
    cout<< "Masukkan x1: ";
    cin>> x1;
    cout<<"Masukkan x2: ";
    cin>> x2;

    double a, b;
    a = f(x1);
    b = f(x2);

    //apabila hasil f(x1) dan f(x2) bertanda sama maka tidak memenuhi kriteria bolzano
    if(a * b > 0) puts("Angka tidak memenuhi kriteria bolzano (bertanda sama)");
    else{

        puts("-------------------------------------------------------------------------------------------------------------------------------------------------------------");
        printf("iterasi \t      x1\t\t     x2\t\t\t      xt\t\t     f(x1)\t\t     f(x2)\t\t     f(xt)\t\t\t");
        puts("");
        puts("-------------------------------------------------------------------------------------------------------------------------------------------------------------");

        double xt;
        for(int i = 1; i <= maks; i++){
            
            xt = (x1 + x2) / 2;
            printf("  %d \t\t %.10lf\t\t %.10lf\t\t %.10lf\t\t %.10lf\t\t %.10lf\t\t %.10lf\t\t", i, x1, x2, xt, a, b, f(xt));
            puts("");

            //substitusi xt (batas baru yang lebih mendekati 0)  
            if((a >= 0 && f(xt) >= 0) || (a <= 0 && f(xt) <= 0)){
                x1 = xt;
                a = f(xt);
            }
            else {
                x2 = xt;
                b = f(xt);
            }

            //apabila f(xt) sudah mendekati angka ketelitian yang diinginkan maka cetak nilai akar
            if(abs(f(xt)) < ketelitian){
                puts("-------------------------------------------------------------------------------------------------------------------------------------------------------------");

                printf("Nilai akar: %.15lf", xt);
                break;
            }   

        }
    }

    return 0;
}
