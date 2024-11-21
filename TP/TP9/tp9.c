#include "tp9.h"
int indeks;//untuk menentukan indeks pada pita
char cc;//variabel menampung karakter yang ditampilkan
char cc2;
char cc3;
int banyak;

void START(char pita[]){
	indeks=0;//merubah nilai indeks
	cc=pita[indeks];//karakter yang ditampilkan merupakan karakter awal pita
	cc2=pita[indeks+1];
	cc3=pita[indeks+2];
}

void INC(char pita[]){
	indeks=indeks+2;;//nilai indeks bertambah 1
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
	if(cc2=='k'){//ini buat nyari kalo tengahnya k
		if((cc=='a')||(cc=='i')||(cc=='u')||(cc=='e')||(cc=='o')){//ini kalo vokal
			if((cc3=='a')||(cc3=='i')||(cc3=='u')||(cc3=='e')||(cc3=='o')){
				banyak++;
			}
		}
		//ini kalo konsonan
		if((cc=='b')||(cc=='c')||(cc=='d')||(cc=='f')||(cc=='g')||(cc=='h')||(cc=='j')||(cc=='k')||(cc=='l')||(cc=='m')||(cc=='n')||(cc=='p')||(cc=='q')||(cc=='r')||(cc=='s')||(cc=='t')||(cc=='v')||(cc=='w')||(cc=='x')||(cc=='y')||(cc=='z')){
			if((cc3=='b')||(cc3=='c')||(cc3=='d')||(cc3=='f')||(cc3=='g')||(cc3=='h')||(cc3=='j')||(cc3=='k')||(cc3=='l')||(cc3=='m')||(cc3=='n')||(cc3=='p')||(cc3=='q')||(cc3=='r')||(cc3=='s')||(cc3=='t')||(cc3=='v')||(cc3=='w')||(cc3=='x')||(cc3=='y')||(cc3=='z')){
				banyak++;
			}
		}
	}
}

int GETBANYAK(){
	return banyak;//mengembalikan nilai banyak
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Evaluasi 9 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/