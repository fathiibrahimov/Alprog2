#include <stdio.h>
#include <string.h>

typedef struct{
	char idlabel[50];
	char namalabel[100];
	char namapemilik[50];
	char idband[50];
	char namaband[100];
	char idlabelband[50];
}tabelsemua;

tabelsemua label[100];

char pita[300];
int indeks;
int panjang;
char kata[50];
int tandaindeks;
char temp[50][50];
int tempatsama;

void login();
int carikebenaran();
int cekid(int tanda);
void waitinput();
void startKata();
void resetKata();
void incKata();
char* getKata();
int getPanjang();
int eopKata();
int eoptaudah();
void cariperintah();
void masuk();
void atastanggal();
void hapus();
void pilih();
void bacatabel();
void jalan();
void tulistabel(int tanda);
void bacatabel(int tanda);

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/