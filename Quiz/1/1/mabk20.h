#include <stdio.h>
//Membuat bungkusan pecahan
typedef struct {
	int pembilang;
	int penyebut;
}pecahan;

pecahan matriks[50][50];//matriks pertama
pecahan matriks2[50][50];//matriks kedua
int b;//menampung baris matriks
int k;//menampung kolom matriks

void masukan();//prosedur untuk meminta masukan user
void banding();//prosedur untuk membandingkan matriks
void cetak();//prosedur untuk mencetak matriks yang besar

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi QUIZ 1 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/