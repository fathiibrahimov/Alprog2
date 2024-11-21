#include <stdio.h>
#include <string.h>

int indeks;//buat indeks mesin kata
int panjang;//buat panjang kata
char kata[50];//buat nampung kata
char pita[300];//buat nampung kalimat
int jumlaha;//buat jumlah a

void startKata(char pita[]);//mulai mesin kata
void resetKata();//buat reset kata
void incKata(char pita[]);//buat majuin mesin kata
char* getKata();//buat dapetin kata
int getPanjang();//buat dapetin panjang
int eopKata(char pita[]);//buat tau akhir mesin kata
void proses();//prosedur buat prosesnya

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Kompetisi Latihan Alpro 2 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/