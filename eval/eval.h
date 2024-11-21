#include <stdio.h>
#include <string.h>

typedef struct {//bungkusan tapi isinya bukan permen melainkan pecahan campuran
	int bulat;//bilangan bulatnya
	int bilang;//pembilangnya
	int sebut;//penyebutnya
	float total;//jumlah pecahannya
	int total2;//iseng aja
}pecah;//namanya bungkusan

int n;//jumlah pecahan 1
int m;//jumlah pecahan 2
int nm;//jumlah gabungan pecahan
char metode[20];//mau make metode sorting apa

pecah satu[100];//tabel 1
pecah dua[100];//tabel 2
pecah tiga[100];//tabel gabungan

void masuk();//prosedur minta masukan
void gabung();//prosedur menggabung
void caritotal();//prosedur mencari jumlah pecahan
void carisort();//prosedur mencari sorting apa yang dipakai
void insert();//prosedur sorting insertion
void selection();//prosedur sorting selection
void bubble();//prosedur sorting bubble
void quick(int kiri, int kanan);//prosedur sorting quick
void cetak();//prosedur cetak
void tes();//prosedur iseng aja buat tes

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Eval 1 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/