#include <stdio.h>
#include <string.h>

typedef struct {//membuat bungkusan untuk matriks
	char jabatan[100];
	char nama[100];
	int gaji;
}perusahaan;

int n;//menampung baris matriks
int m;//menampung kolom matriks
int o;//menampung berapa banyak jabatan mau ditukar
char cek[100];//menampung sementara jabatan yang mau ditukar
char tukar [100][100];//menampung jabatan yang mau ditukar

perusahaan karyawan [100][100];//membuat bungkusan bernama karyawan

void masuk();//prosedur untuk meminta masukan user
void gajinaik();//prosedur untuk menukar jabatan
void cetak();//prosedur untuk mencetak hasil


/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Evaluasi 2 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/