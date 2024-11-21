#include <stdio.h>
#include <string.h>

typedef struct {//membuat bungkusan untuk matriks
	char namab[100];//untuk menampung nama yang udah baris
	int tinggib;//untuk menampung jumlah spasi tiap baris, biar rapi barisannya
}bebaris;

bebaris bb[100][100];//buat ga tau ini namanya apa, lupa yang pasti buat bungkusannya lah

char tipe[50];//buat tau ini mau sorting pake apa
int am;//buat baris matriks
int bm;//buat kolom matriks
int ab;//buat tau jumlah elemen di matriks ada berapa
char nama[50][100];//buat nampung sementara sortingan tinggi
int tinggi[100];//buat nampung sementara sortingan nama

void masuk();//prosedur buat minta masukan
void carisort();//prosedur buat nyari nyari sortingan yang mau dipake
void quick();//prosedur buat sortingan cepat, tapi ga secepat bales chat doi
void bubble();//prosedur buat sortingan gelembung, biar ga kena corona kita harus cuci tangan sampe banyak gelembungnya
void cetak();//prosedur buat mencetak hasil
void lkbb();//prosedur buat ngebarisin orang di barisannya
void carispasi();//prosedur buat nyari nyari spasi, daripada cari jodoh yang ga ketemu temu

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Evaluasi 5 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/