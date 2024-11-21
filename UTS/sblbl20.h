#include <stdio.h>
#include <string.h>

typedef struct {//membuat bungkusannya
	int netto[50];
	int harga[50];
	char merk[50][50];
	char jenis[50][50];
	float hargamurah[50];
}daftar;

daftar churros[100];

int n1;//menampung jumlah baris
int n2;
int n3;

char cari[50];//menampung mau dicari berdasarkan jenis apa
char metode;//menampung metode yang ingin digunakan sortingannya
int panjang[3];//menampung panjang tiap baris
int pdaftar;//menampung panjang harga termurah

void masuk();
void hargar();
void gabung();
void tes();
void carisort();
void insertion();
void selection();
void bubble();
void quick(int kiri, int kanan);

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi UTS dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/