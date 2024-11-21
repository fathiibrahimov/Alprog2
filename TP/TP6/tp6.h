#include <stdio.h>
#include <string.h>

typedef struct {//bungkusan tapi isinya bukan permen melainkan data kasus cororo
	char negara[100][100];//asal dari mana gan
	int jumlahkasus[100];//kasusnya ada berapa
	int sembuh[100];//yang sembuh berarti ga sakit lagi
	int meninggal[100];//yang meninggal juga ga sakit lagi
	int kasusaktif[100];//ini yang sakit
}corocoro;//namanya bungkusan

corocoro kasus[6];//dibuat namanya kasus


char m1[100];//nampung nama orang pertama
char m2[100];//nampung nama orang kedua
char m3[100];//nampung nama orang ketiga tapi bukan pho
int panjang[4];//nampung berapa banyak daerah yang dicari kasusnya
char mau[12];//nampung mau pake yang mana ngurutnya
char metode[11];//nampung mau make metode apa ngurutnya
char urut[5];//nampung cara ngurutnya naik atau turun
int ab;//ini iseng aja gara gara programnya error ga jelas, begitu dijalanin prosedur gabung


void masuk();//minta masukan user
void gabung();//ngegabungin isinya
void cariurut();//nyari urutan naik turun
void cariaktif();//nyari jumlah kasus aktif
void cetak();//mencetak output
void ascending();//kalo urutannya naik
void descending();//kalo urutannya turun
void insertiona(int a);//kalo butuhnya insertion ascending
void selectiona(int a);//kalo butuhnya selection ascending
void bubblea(int a);//kalo butuhnya bubble ascending
void quicka(int a, int kiri, int kanan);//kalo butuhnya quick ascending
void insertionb(int a);//kalo butuhnya insertion descending
void selectionb(int a);//kalo butuhnya selection descending
void bubbleb(int a);//kalo butuhnya bubble descending
void quickb(int a, int kiri, int kanan);//kalo butuhnya quick descending

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Evaluasi 6 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/