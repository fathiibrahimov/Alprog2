#include <stdio.h>
#include <string.h>

int indeks;//buat indeks mesin kata
int panjang;//panjang kata di mesin kata
char kata[50];//ini buat nampung kata
char kataprima[50][50];//ini buat nampung sementara kata yang prima
int p1;//ini buat nunjukin indeks yang kata prima
char katanon[50][50];//buat nampung sementara kata yang non vokal
int p2;//indeks yang kata non vokal

void startKata(char pita[]);//mulai mesin kata
void resetKata();//buat reset kata, biarpun gak dipake disini tapi saya tidak hapus karena iseng
void incKata(char pita[]);//buat lanjut ke kata selanjutnya
char* getKata();//buat dapetin katanya
int getPanjang();//buat dapetin panjangnya
int eopKata(char pita[]);//akhir dari kalimat
void proses();//prosesnya disini semua
int prime(int n);//fungsi buat tau katanya prima atau nggak
int nonvoko();//fungsi buat tau katanya non vokal atau nggak
void keluar();//ini prosedur buat nampilin output, bukan buat keluar dari tp10

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Evaluasi 10 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/