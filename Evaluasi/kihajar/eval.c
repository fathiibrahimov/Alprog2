#include "eval.h"

void masuk(){
	scanf("%d", &n);//minta masukan
	
}

void prima(){
	int i=3;
	int count, c;
	int indeks=1;
	
	noprima[0]=2;//masukin 2 ke prima pertama
	
	//ini saya ngambil dari programming simplified
	for (count=2;count<=n;){//dimulai dari 2
		for (c=2;c<=i-1;c++){
			if (i%c==0){//kalau ternyata bisa dibagi langsung keluar loop
				break;
			}
		}
		if (c==i){//kalau ternyata yang dibagi itu sama dengan pembagi
			noprima[indeks]=i;//berarti prima
			indeks++;
			count++;
		}
		i++;//fornya jalan
	}
	
}

void kaliprima(){
	int i;
	
	for(i=0;i<n;i++){
		hasilprima[i]=noprima[i]*(i+1);//ini buat kaliin hasil primanya
	}
}

void cetak(){
	int i;
	
	for(i=0;i<n;i++){
		printf("%d %d\n", i+1, hasilprima[i]);//cetak
	}
}


/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Kompetisi Latihan Alpro 2 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/