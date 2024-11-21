#include "unic20.h"

void masuk(){
	int i;//iterator
	
	for(i=0;i<50;i++){//iseng aja, entah kenapa dibuat begini padahal gak ada error apa apa
		u[i]='\0';
	}
	
	scanf("%s", u);//minta masukan stringnya
	panjangu=strlen(u);//nyari panjang stringnya
}

void carisatu(){
	int i;//iterator
	int j;
	
	for(i=0;i<panjangu;i++){//buat muter
		for(j=0;j<panjangu;j++){//buat muter di bagian yang muter
			if(u[i]==u[j]){//kalo hasil muter muter ternyata sama nanti nambah uwuwunya
				uwuwu[i]++;
			}
		}
	}
}

int cekunik(){
	int i=0;//iterator
	int ambyar=0;//kalo ada yang unik nanti jadinya ambyar muternya
	
	while((i<panjangu) && ambyar==0){//cari yang frekuensinya cuma satu
		if(uwuwu[i]==1){
			ambyar=1;
		}else{
			i++;
		}
	}
	
	gaktauapa=i;//mastiin posisi yang unik ada dimana
	
	if(ambyar==1){
		return 1;
	}else{
		return 2;
	}
}

void cetak(int x){
	int i;
	if(x==1){//kalo proses ambyarnya berhasil
		printf("%c\n", u[gaktauapa]);
	}else{//kalo gak ambyar ambyar
		printf("tidak ada chara unik.\n");
	}
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Evaluasi 7 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/