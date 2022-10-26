import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-10, 10, 200); 
#mendefinisikan x terlebih dahulu. 
#mulai dari interval -5 hingga 5. dan juga banyaknya tingkat presisi yang akan kita gunakan. 

y = (1 - (0.6 * x)) / x #deklarasikan fungsi yang diuji terhadap x

fig = plt.figure() #buat canvas grafik
ax = fig.add_subplot(1, 1, 1) #karena kita cuma butuh 1 gambar maka cuma butuh 1 baris dan 1 kolom

#menempatkan sumbu utama y di posisi center
ax.spines['left'].set_position('center')

#menempatkan sumbu utama x posisi center
ax.spines['bottom'].set_position('center')

#memberi warna transparan garis yang tidak dibutuhkan
ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')

#lakukan plottingan pada canvas dengan tipe 'y'
plt.plot(x, y, 'y')

#Tunjukkan plottingan
plt.show()
