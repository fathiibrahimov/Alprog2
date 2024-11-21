#include <stdio.h>
#include <string.h>

char nama[13][50];//array of string untuk menampung nama barang
float jumlah[13];//float untuk menampung jumlah barang
int harga[13];//integer untuk menampung nilai harga barang

int gaji;//integer untuk menampung gaji orangnya
char sorting [50];//string untuk menampung masukan sorting mana yang diinginkan
char arah [50];//string untuk menampung masukan apakah menurun atau menaik sortingnya
char tipe [50];//string untuk menampung mau disorting apanya

void masuk();//prosedur untuk meminta masukan
void carisort(char nama[][50], float jumlah[], int harga[]);//prosedur untuk mencari tau apa yang diinginkan user dalam sortingannya
void insertionA(int a, char nama[][50], float jumlah[], int harga[]);//prosedur jika ingin insertion ascending
void insertionB(int a, char nama[][50], float jumlah[], int harga[]);//prosedur jika ingin insertion descending
void selectionA(int a, char nama[][50], float jumlah[], int harga[]);//prosedur jika ingin selection ascending
void selectionB(int a, char nama[][50], float jumlah[], int harga[]);//prosedur jika ingin selection descending
void cetak();//prosedur untuk mencetak output

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Evaluasi 4 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/