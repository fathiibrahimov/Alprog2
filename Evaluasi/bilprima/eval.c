#include "eval.h"

void masuk(){//minta masukan
	int i;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &angka[i]);
	}
	
}

//ini saya nyolong dari programiz seinget saya, lupa soalnya udah diambil dari dulu kodingannya
int cekprima(int m) {//cek prima
    int i;
	int flag = 0;
 	int c;
 	int a;
	
	for(i=2;i<m/2;i++){
		if(m%i==0){//kalo bisa dibagi maka selesai loopnya
			flag=1;
			break;
		}
	}
	if(m==1){
		return 0;
	}else{
		if(flag==0){
			return 1;
		}else{
			return 0;
		}
	}
}

void proses(){
	int i;
	int j;
	int hasilprima[100];//buat hasil prima terdekat
	
	
	for(i=0;i<n;i++){//masukin angka ke hasil prima
		hasilprima[i]=angka[i];
	}//sebenernya gak perlu, tapi saya iseng
	
	for(i=0;i<n;i++){//cek, nilai prima bakal nambah terus sampe 1000 sampe ketemu hasil prima
		for(j=hasilprima[i];j<1000;j++){
			hasilprima[i]=hasilprima[i]+1;
			if(cekprima(hasilprima[i])==1){
				break;
			}
		}
	}
	for(i=0;i<n;i++){//kalo misalnya lebih dari 997 mustahil ada bilangan prima diatasnya
		if(hasilprima[i]>997){
			printf("0\n");
		}else{
			printf("%d\n", hasilprima[i]);
		}
	}
	
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Kompetisi Latihan Alpro 2 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/