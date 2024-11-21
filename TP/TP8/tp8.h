#include <stdio.h>
#include <string.h>

typedef struct{
	char judul[100];
	char penulis[100];
	char genre[50];
	char toko[50];
}bukabuku;//ini bungkusan buat semuanya mulai dari list sampai list lagi

bukabuku jualbuku[100];//buat list buku mentah sama final, nanti diedit di sini
bukabuku kobuku[100];//buat toko buku
bukabuku gebuku[100];//buat genre buku
bukabuku pebuku[100];//buat author buku

void bacabaca();//prosedur buat baca baca filenya
void henshin();//prosedur buat berubah jadi yang lebih baik lagi
void finis();//prosedur buat bikin list final
void bikintabel();//prosedur buat bikin tampilan tabel yang list buku final
void menunyatuan();//prosedur menu awal
void semuabutuhproses();//prosedur manggil prosedur
void tambahrekor(int pilahpilih);//prosedur buat nambah record di tiap file
void menudua();//prosedur menu tidak awal

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Evaluasi 8 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/