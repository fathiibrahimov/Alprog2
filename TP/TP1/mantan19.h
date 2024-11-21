#include <stdio.h>

int n; //VARIABEL UNTUK MENAMPUNG ORDO MATRIKS
int m; //VARIABEL UNTUK MENAMPUNG JUMLAH TRANSFORMASI MATRIKS
char matriks[100][100]; //UNTUK MATRIKS YANG SUDAH DITRANSFORMASI
char matriksasli[100][100]; //UNTUK MENAMPUNG MATRIKS YANG TIDAK DIUBAH
char transformasi[100]; //UNTUK MENGETAHUI TRANSFORMASI YANG DIINGINKAN
char matrikst[100][100]; //UNTUK MENAMPUNG SEMENTARA MATRIKS YANG DITRANSFORMASIKAN

void matmat(); //PROSEDUR UNTUK MEMINTA INPUTAN
void henshin(); //PROSEDUR UNTUK MENTRANSFORMASIKAN MATRIKS
void rotasi(); //PROSEDUR UNTUK ROTASI MATRIKS
void refleksi(); //PROSEDUR UNTUK REFLEKSI MATRIKS
void transpose(); //PROSEDUR UNTUK TRANSPOSE MATRIKS
void cetak(); //PROSEDUR UNTUK MENGHASILKAN OUTPUT SESUAI SOAL
int cekvalid(); //FUNGSI UNTUK MENGECEK APAKAH N NYA SEPOSISI

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Evaluasi 1 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/