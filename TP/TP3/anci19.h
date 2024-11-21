#include <stdio.h>

int n;//menampung nilai fibonacci awal
int b;//menampung nilai beda
int x;//menampung panjang matriks
int y;//menampung lebar matriks
int c;//iseng aja biar gampang manggil rekursifnya
int d;//iseng juga biar gampang manggil rekursifnya
int matfibo[100][100];//matriks buat nampung matriks fibonacci
int matbanding[100][100];//matriks buat nampung matriks pembanding
int matoutput[100][100];//matriks buat ditampilin di akhir yang bagian :D dan D:
int tampung[200];//biar gampang ngitung fibonaccinya

void masuk();//prosedur buat minta masukan user
void fibonacci();//prosedur buat manggil semua prosedur lain, sekaligus penyesuaian dikit
void nambah();//prosedur rekursifnya
void cetak();//prosedur untuk mencetak output
void banding();//prosedur untuk membandingkan matriks banding dengan matriks fibonacci

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Evaluasi 3 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/