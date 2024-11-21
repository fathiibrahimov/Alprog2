#include "eval.h"
int indeks;//untuk menentukan indeks pada pita
char cc;//variabel menampung karakter yang ditampilkan
char cc2;
char cc3;


void START(char pita[]){
	indeks=0;//merubah nilai indeks
	cc=pita[indeks];//karakter yang ditampilkan merupakan karakter awal pita
	cc2=pita[indeks+1];
	cc3=pita[indeks+2];
}

void INC(char pita[]){
	indeks++;//nilai indeks bertambah 1
	cc=pita[indeks];//karakter yang ditampilkan diperbaharui
	cc2=pita[indeks+1];
	cc3=pita[indeks+2];
}

int EOP(){
	if((cc=='.')||(cc2=='.')||(cc3=='.')){//apabila karakter yang ditampilkan adalah titik
		return 1;
	}else{//apabila bukan
		return 0;
	}
}

void ADV(char pita[]){//ini gak dipake disini
	indeks++;//nilai indeks bertambah 1
	cc=pita[indeks];
	while((cc==' ')&&(EOP()==0)){//mengecek apakah cc masih merupakan spasi atau tidak
		indeks++;
		cc=pita[indeks];
	}
}

char GETCC(){
	return cc;//mengembalikan nilai cc
}

char GETCC2(){
	return cc2;//mengembalikan nilai cc2
}

char GETCC3(){
	return cc3;//mengembalikan nilai cc3
}

void cek(){
	if(cc2=='a'){//ini buat nyari kalo tengahnya spasi
		if((cc!=' ')&&(cc!='.')){//ini kalo bukan spasi atau titik
			if((cc3!=' ')&&(cc3!='.')){
				banyak++;
			}
		}
	}
}

int GETBANYAK(){
	return banyak;//mengembalikan nilai banyak
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Kompetisi Latihan Alpro 2 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/