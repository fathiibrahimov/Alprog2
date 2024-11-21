#include <stdio.h>
#include <string.h>

char pita[500];//string untuk menampung pita
char yangdicari;
int tengah;
int akhir;
char tampung[500];//menampung kata tanpa spasi
int itampung;//indeks tampungan

void START();//prosedur untuk memulai mesin
void INC();//prosedur untuk maju satu karakter pada pita
int EOP();//fungsi untuk mengecek akhir dari pita
void ADV();//prosedur untuk maju untuk melewati spasi
char GETCC();//fungsi untuk mengambil nilai karakter yang ditampilkan
void proses();//prosedur proses semuanya



/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi UAS dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/