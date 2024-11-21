#include "uas.h"
int indeks;//untuk menentukan indeks pada pita
char cc;//variabel menampung karakter yang ditampilkan

void START(){
	indeks=0;//merubah nilai indeks
	cc=pita[indeks];//karakter yang ditampilkan merupakan karakter awal pita
}

void INC(){
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


void ADV(){
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

void proses(){
	int jalan=0;//buat tau panjang tampungan
	int i;//iterator
	itampung=0;//indeks nampung diset nol dulu
	scanf("%499[^\n]s", &pita);//scan f
	tengah=0;//buat tau true false tengahnya
	akhir=0;//buat tau true atau false bagian akhirnya
	
	START();//memulai mesin
	//selama perjalanan, mesin kata akan menampung kata satu persatu ke tampungan dengan menghilangkan spasi
	if(cc==' '){//kalau yang awalnya spasi langsung advance
		ADV();
		yangdicari=GETCC();
		tampung[itampung]=GETCC();
		itampung++;
	}else{//kalau tidak spasi
		yangdicari=GETCC();
		tampung[itampung]=GETCC();
		itampung++;
	}
	
	
	while(EOP()==0){//apabila pita belum habis
		INC();
		if(cc==' '){
			ADV();
			jalan++;
			tampung[itampung]=GETCC();
			itampung++;
		}else{
			jalan++;
			tampung[itampung]=GETCC();
			itampung++;
		}
	}
	tengah=0;//set ke nol semua
	akhir=0;
	
	for(i=1;i<jalan-1;i++){//mencari tengahnya
		if(tampung[i]==yangdicari){
			tengah=1;
		}
	}
	
	if(tampung[jalan-1]==yangdicari){//mencari akhirnya
		akhir=1;
	}
	
	
	if((tengah==1)&&(akhir==1)){//kalau benar print hore
		printf("Hore.\n");
	}else{
		printf("Sabar Menanti.\n");
	}
	
}




/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi UAS dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/