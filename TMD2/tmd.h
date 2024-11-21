#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char idlabel[100];
	char namalabel[100];
	char namapemilik[100];
	char idband[100];
	char namaband[100];
	char idlabelband[100];
}dataBand;

dataBand label[200];//buat yang bukan join
dataBand gabungan[200];//buat join

char pita[700];//pita tampungan
int indeks;//indeks mesin kata
int panjang;//panjang kata
char kata[200];//katanya
int prosedur;//buat tau mau ngapain
int tabel;//buat tau tabel mana yang mau diapa apain
char temp[200][200];//buat naro sementara yang di query
int tandaindeks;//buat penanda indeks
int tandasama;//buat penanda di mana id yang sama
int pexit;//ini buat tau apakah sudah exit atau belum

void proses2();//buat minta masukan yang bukan pertama kali
void startKata();//buat mulai mesin kata
void resetKata();//buat reset kata, dan disini gak dipake
void incKata();//buat majuin mesin kata
char* getKata();//buat minta kata
int getPanjang();//buat minta panjang kata
int eopKata();//buat tau mesin katanya selesai atau belum
void proses();//buat minta masukan pertama kali
void login();//minta masukan, cuma minta masukan doang tapi disini
void carimasalah();//buat cari cari masalahnya sebenernya apa, semuanya bisa diselesaikan baik baik
int cekbenar();//buat tau apa benar querynya
void masuk();//prosedur insert
int cekid();//buat tau apakah ada id yang sama atau belum di tabel
void bacabaca();//buat baca file
void naiktanggal();//buat update
void hapus();//buat delete
int cekbenardelete();//buat cek apakah querynya benar jika milih delete
int cekiddelete();//buat tau apa ada id yang sama jika milih delete
void pilih();//buat select
void bacagabung();//buat baca jika select join
void gabunginaja();//buat join
int keluar();//buat keluar dari program
int cekbenarpilih(int tanda);//buat cek apa query bener jika pilih pilih

void tessaja();//buat ngetes aja

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/