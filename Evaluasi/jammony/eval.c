#include "eval.h"

void masuk(){
	int i;
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		scanf("%d", &waktu[i]);
	}
}

void urut(){
	int i, temp, pindah;//variabel yang akan digunakan dalam sorting
	
	do{//perulangan untuk mengecek setiap anggota data
		pindah = 0;
		
		for(i=0;i<(n-1);i++){
			/*perulangan untuk mengecek data yang dipilih terhadap data yang
			*/
			if(waktu[i]>waktu[i+1]){//proses membandingkan data
				//proses pemindahan data
				temp = waktu[i];
				waktu[i]=waktu[i+1];
				waktu[i+1]=temp;
				pindah =1;
			}
			
		}
	}while(pindah==1);
	
}

void henshin(){
	int i;
	
	for(i=0;i<n;i++){
		kukuk[i].jam=(waktu[i]/3600);
		kukuk[i].menit=(waktu[i]-(3600*kukuk[i].jam))/60;
		kukuk[i].detik=(waktu[i]-(3600*kukuk[i].jam)-(kukuk[i].menit*60));
	}
	
}

void cetak(){
	int i;
	
	for(i=0;i<n;i++){
		if(kukuk[i].jam<10){
			printf("0%d:",kukuk[i].jam);	
		}else{
			printf("%d:",kukuk[i].jam);
		}
		if(kukuk[i].menit<10){
			printf("0%d:",kukuk[i].menit);
		}else{
			printf("%d:",kukuk[i].menit);
		}
		if(kukuk[i].detik<10){
			printf("0%d\n",kukuk[i].detik);
		}else{
			printf("%d\n",kukuk[i].detik);
		}
	}
	
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Kompetisi Latihan Alpro 2 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/