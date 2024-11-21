#include "mesinkarakterp.h"
int indeks;//untuk menentukan indeks pada pita
char cc;//variabel menampung karakter yang ditampilkan

void START(char pita[]){
	indeks=0;//merubah nilai indeks
	cc=pita[indeks];//karakter yang ditampilkan merupakan karakter awal pita
}

void INC(char pita[]){
	indeks++;//nilai indeks bertambah 1
	cc=pita[indeks];//karakter yang ditampilkan diperbaharui
}

int EOP(){
	if(cc=='.'){//apabila karakter yang ditampilkan adalah titik
		return 1;
	}else{//apabila bukan
		return 0;
	}
}

void ADV(char pita[]){
	indeks++;//nilai indeks bertambah 1
	cc=pita[indeks];
	while((cc==' ')&&(EOP()==0)){//mengecek apakah cc masih merupakan spasi atau tidak
		indeks++;
		cc=pita[indeks];
	}
}

char GETCC(){
	return cc;//mengembailkan nilai cc
}