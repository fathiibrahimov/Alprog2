#include <stdio.h>
#include <string.h>

int indeks;//buat indeks mesin kata
int panjang;//buat panjang kata
char kata[50];//buat nampung kata
int jumlaha[300];//buat nampung jumlah a pada tiap kata
char pita[300];//buat nampung kalimat
int banyakkata;//buat nampung banyak kata pada kalimat
char tempk[300][300];//buat nampung kata sementara sebelum di sorting dan akhirnya disorting

void startKata(char pita[]);//mulai mesin kata
void resetKata();//buat reset kata
void incKata(char pita[]);//buat majuin mesin kata
char* getKata();//buat dapetin kata
int getPanjang();//buat dapetin panjang
int eopKata(char pita[]);//buat tau akhir mesin kata
void proses();//prosedur buat prosesnya
void urut();//prosedur buat ngurut
void cetak();//prosedur buat mencetak hasil

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Kompetisi Latihan Alpro 2 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/