#include "eval.h"

void masuk(){
	int i;
	//minta masukan buat tabel 1
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d %d %d", &satu[i].bulat, &satu[i].bilang, &satu[i].sebut);
	}
	//minta masukan buat tabel 2
	scanf("%d", &m);
	for(i=0;i<m;i++){
		scanf("%d %d %d", &dua[i].bulat, &dua[i].bilang, &dua[i].sebut);
	}
	//minta sortingannya apa
	scanf("%s", metode);
}

void gabung(){
	int i;
	int hitung = 0;
	
	//memasukkan isi tabel pertama ke dalam tabel ketiga
	for(i=0;i<n;i++){
		tiga[hitung].bulat = satu[i].bulat;
		tiga[hitung].bilang = satu[i].bilang;
		tiga[hitung].sebut = satu[i].sebut;
		hitung++;
	}
	
	//memasukkan isi tabel kedua ke dalam tabel ketiga
	for(i=0;i<m;i++){
		tiga[hitung].bulat = dua[i].bulat;
		tiga[hitung].bilang = dua[i].bilang;
		tiga[hitung].sebut = dua[i].sebut;
		hitung++;
	}
	
	nm=hitung;
}

void caritotal(){
	int i;
	float a;
	float b;
	float c;
	
	for(i=0;i<nm;i++){
		//masukin ke float dulu biar gampang hitung jumlahnya
		a=tiga[i].bulat;
		b=tiga[i].bilang;
		c=tiga[i].sebut;
		
		tiga[i].total=((a*c)+b)/c;//cari jumlah pecahan
	}
	
	//iseng aja yang ini, kali aja yang desimal gak bisa
	for(i=0;i<nm;i++){
		tiga[i].total2=tiga[i].total*1000;
	}
}

void carisort(){//cari sortingan berdasarkan stringnya
	if(strcmp(metode, "Insert")==0){
		insert();
	}else if(strcmp(metode, "Select")==0){
		selection();
	}else if(strcmp(metode, "Bubble")==0){
		bubble();
	}else if(strcmp(metode, "Quick")==0){
		quick(0, nm-1);
	}
}

void insert(){
	int i,j;
	int temp1;
	int temp2;
	int temp3;
	float temp4;
	
	for(i=1;i<nm;i++){
		temp1=tiga[i].bulat;
		temp2=tiga[i].bilang;
		temp3=tiga[i].sebut;
		temp4=tiga[i].total;
		
		j=i-1;
		
		while(j>=0 && temp4 < tiga[j].total){
			//tukar posisi
			tiga[j+1].bulat=tiga[j].bulat;
			tiga[j+1].bilang=tiga[j].bilang;
			tiga[j+1].sebut=tiga[j].sebut;
			tiga[j+1].total=tiga[j].total;
			//j mundur 1
			j=j-1;
		}
		//menempatkan kunci pada array
		tiga[j+1].bulat=temp1;
		tiga[j+1].bilang=temp2;
		tiga[j+1].sebut=temp3;
		tiga[j+1].total=temp4;
	}
}

void selection(){
	int i, j, minIdx;
	//menampung sementara
	int temp1;
	int temp2;
	int temp3;
	float temp4;
		
	for(i=0;i<(nm-1);i++){
		//mencari nilai minimum dari sebuah array
		minIdx=i;
		for(j=i+1;j<nm;j++){
			if(tiga[minIdx].total>tiga[j].total){
				minIdx=j;
			}
		}
		//tukar posisi nilai minimum dengan indeks pertama
		temp1=tiga[i].bulat;
		temp2=tiga[i].bilang;
		temp3=tiga[i].sebut;
		temp4=tiga[i].total;
		
		tiga[i].bulat=tiga[minIdx].bulat;
		tiga[i].bilang=tiga[minIdx].bilang;
		tiga[i].sebut=tiga[minIdx].sebut;
		tiga[i].total=tiga[minIdx].total;
		
		tiga[minIdx].bulat=temp1;
		tiga[minIdx].bilang=temp2;
		tiga[minIdx].sebut=temp3;
		tiga[minIdx].total=temp4;
		
	}
}

void bubble(){
	int i, pindah;//variabel yang akan digunakan dalam sorting
	int temp1;
	int temp2;
	int temp3;
	float temp4;
	
	
	do{//perulangan untuk mengecek setiap anggota data
		pindah = 0;
		
		for(i=0;i<(nm-1);i++){	
			if(tiga[i].total > tiga[i+1].total){//proses membandingkan data
				//proses pemindahan data
				temp1=tiga[i].bulat;
				temp2=tiga[i].bilang;
				temp3=tiga[i].sebut;
				temp4=tiga[i].total;
				
				tiga[i].bulat=tiga[i+1].bulat;
				tiga[i].bilang=tiga[i+1].bilang;
				tiga[i].sebut=tiga[i+1].sebut;
				tiga[i].total=tiga[i+1].total;
				
				tiga[i+1].bulat=temp1;
				tiga[i+1].bilang=temp2;
				tiga[i+1].sebut=temp3;
				tiga[i+1].total=temp4;
			
				pindah =1;
			}	
		}
	}while(pindah==1);
	
}

void quick(int kiri, int kanan){
	int i, j;
	int temp1;
	int temp2;
	int temp3;
	float temp4;
	i=kiri;
	j=kanan;
	
	do{
		while((tiga[i].total<tiga[kanan].total)&&(i<=j)){
			i++;
		}
		while((tiga[j].total>tiga[kiri].total)&&(i<=j)){
			j--;
		}
		
		if(i<j){
			temp1=tiga[i].bulat;
			temp2=tiga[i].bilang;
			temp3=tiga[i].sebut;
			temp4=tiga[i].total;
			
			tiga[i].bulat=tiga[j].bulat;
			tiga[i].bilang=tiga[j].bilang;
			tiga[i].sebut=tiga[j].sebut;
			tiga[i].total=tiga[j].total;
			
			
			tiga[j].bulat=temp1;
			tiga[j].bilang=temp2;
			tiga[j].sebut=temp3;
			tiga[j].total=temp4;
		
			i++;
			j--;
		}
	}while(i<j);
	
	if(kiri<j){
		quick(kiri, j);
	}
	if(i<kanan){
		quick(i, kanan);
	}
}

void tes(){//ini iseng aja buat tau isi semua tabel setelah digabung
	int i;
	for(i=0;i<nm;i++){
		printf("%d %d %d %f %d\n", tiga[i].bulat, tiga[i].bilang, tiga[i].sebut, tiga[i].total, tiga[i].total2);
	}
	printf("selelele\n");
}

void cetak(){
	int i;
	//buat cetak yang pembilang
	for(i=0;i<nm;i++){
		if(i==0){
			printf(" %d", tiga[i].bilang);
		}else{
			printf("   %d", tiga[i].bilang);
		}
	}
	
	printf("\n");
	
	//buat cetak yang bilangan bulat
	for(i=0;i<nm;i++){
		if(i!=nm-1){
			printf("%d-, ", tiga[i].bulat);
		}else{
			printf("%d-", tiga[i].bulat);
		}
	}
	
	printf("\n");
	
	//buat cetak yang penyebut
	for(i=0;i<nm;i++){
		if(i==0){
			printf(" %d", tiga[i].sebut);
		}else{
			printf("   %d", tiga[i].sebut);
		}
	}
	
	printf("\n");
}


/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Eval 1 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/