# P1_Komnum_D03


## Identitas Kelompok 3
| Name                                  | NRP         | Kelas      |
| ---                                   | ---         | -----------|
| Gabrielle Immanuel Osvaldo Kurniawan  | 5025211135  | Komnum  D  |
| Rr. Diajeng Alfisyahrinnisa Anandha   | 5025211147  | Komnum  D  |
| Victor Gustinova                      | 5025211159  | Komnum  D  |

## Apa itu metode bolzano?

<img width="1000" alt="image" src="https://user-images.githubusercontent.com/91377782/198026627-577b1e3f-f958-45fe-bba5-1ba6f4e5e3c7.png">

> Secara umum, metode bolzano dilakukan dengan mencari nilai tengah dari suatu interval yang memiliki tanda yang berlawanan. Kemudian, nilai tengah tersebut akan menggantikan salah satu ujung interval yang ada. 

## Penjelasan Kode Iterasi Bolzano

``` Volt
int maks = 1000; 
double ketelitian = 10E-10; 

double f(double x){
    return (1 - (0.6 * x)) / x;
}
```
> Mula-mula kita mendeklarasikan kondisi dimana kode bolzano kita akan bekerja.

``` Volt
double x1, x2;
cout<< "Masukkan x1: ";
cin>> x1;
cout<<"Masukkan x2: ";
cin>> x2;

double a, b;
a = f(x1);
b = f(x2);
```

>Lalu, seperti yang kita ketahui, bolzano membutuhkan 2 parameter awal yang mana ketika dimasukkan fungsi menghasilkan f(x) yang berlawanan. Untuk itu, akan dicek sebagai berikut:

``` Volt
 if(a * b > 0) puts("Angka tidak memenuhi kriteria bolzano (bertanda sama)");
```

>Ketika batas yang dimasukkan tidak dapat digunakan untuk metode bolzano maka kita akan return dengan error message

>Apabila data awal yang dimasukkan sesuai, maka kita lanjut ke next step

``` Volt
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
```

>Kode diatas adalah core dari proses bolzano. 

### Gambar dibawah merupakan output dari misal `x1 = 0.5` dan `x2 = 2` 

<img width="1000" alt="image" src="https://user-images.githubusercontent.com/91377782/198030007-240fa9fa-d24e-4dd0-a109-348cf4d4028c.png">


## Penjelasan Kode Grafik Bolzano
> Dalam pengerjaan, akan dipergunakan 2 library dalam python yaitu

``` Volt
import numpy as np
import matplotlib.pyplot as plt
```

> Numpy akan dipergunakan untuk men-generate x pada rentang interval tertentu. Dan matplot digunakan untuk membuat grafik

``` Volt
x = np.linspace(-10, 10, 200); 
```

> Kode diatas adalah aplikasi dari numpy yang digunakan untuk mengenerate 200 titik uji pada interval -10 hingga 10

``` Volt
y = (1 - (0.6 * x)) / x
```
> Disini, kita perlu mendefinisikan fungsi yang akan dibuat grafiknya. 

``` Volt
fig = plt.figure() #buat canvas grafik
ax = fig.add_subplot(1, 1, 1) #karena kita cuma butuh 1 gambar maka cuma butuh 1 baris dan 1 kolom

#menempatkan sumbu utama y di posisi center
ax.spines['left'].set_position('center')

#menempatkan sumbu utama x posisi center
ax.spines['bottom'].set_position('center')

#memberi warna transparan garis yang tidak dibutuhkan
ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')
```

> Kode diatas digunakan untuk mengatur bidang grafik fungsi dimana pengaturan yang dilakukan adalah buat canvas dan membuat sumbu x dan y pada posisi center

``` Volt
plt.plot(x, y, 'y')
```
> Lalu kode diatas digunakan untuk memplotting pada canvas dengan tipe 'y' setelah cartesius dibuat. 

``` Volt
plt.show()
```
> Kode diatas digunakan untuk memungkinkan user melihat hasil plottingan yang sudah dilakukan. 

### Gambar dibawah merupakan hasil dari grafik bolzano yang dibuat dengan `fungsi (1 - (0.6 * x)) / x`

<img width="1000" alt="image" src="https://user-images.githubusercontent.com/91377782/198032456-05d49312-7b46-4012-9109-7b56897422df.png">



