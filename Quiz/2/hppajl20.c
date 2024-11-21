#include "hppajl20.h"

void masuk(){
	int i;
	float a;//biar gampang nyari nilai riil
	float b;
	scanf("%d", &n);
	
	
	for(i=0;i<n;i++){
		scanf("%d %d", &cuy[i].bilang, &cuy[i].sebut);
		
		a=cuy[i].bilang;//minta pembilang
		b=cuy[i].sebut;//minta penyebut
		
		riil[i]=a/b;//ini nyari nilai riil dari pecahan
	}
	
	scanf("%d %d", &carib, &caris);//minta yang dicari
}

void urut(){
	int i;
	int j=0;
	float temp;
	int temp1;
	int temp2;
	int pindah;
	
	/*
	do{//perulangan untuk mengecek setiap anggota data
		pindah = 0;
		
		for(i=0;i<(n-1);i++){
			if(riil[i]<riil[i+1]){//proses membandingkan data
				//proses pemindahan data
				temp = riil[i];
				temp1=cuy[i].bilang;
				temp2=cuy[i].sebut;
				
				riil[i]=riil[i+1];
				cuy[i].bilang=cuy[i+1].bilang;
				cuy[i].sebut=cuy[i+1].sebut;
				
				riil[i+1]=temp;
				cuy[i+1].bilang=temp1;
				cuy[i+1].sebut=temp2;
				
				pindah =1;
			}
			
		}
	}while(pindah==1);
	*/
	
	for(i=1;i<n;i++){
		temp = riil[i];
		temp1=cuy[i].bilang;
		temp2=cuy[i].sebut;
			
		j=i-1;
		
		while(j>=0 && riil[j] < temp){
			//tukar posisi
			riil[j+1]=riil[j];
			cuy[j+1].bilang=cuy[j].bilang;
			cuy[j+1].sebut=cuy[j].sebut;
			//j mundur 1
			j=j-1;
		}
		//menempatkan kunci pada array
		riil[j+1]=temp;
		cuy[j+1].bilang=temp1;
		cuy[j+1].sebut=temp2;
	}
	
}

void cari(){
	temu = 0;
	int i,j,k;
	i=0;
	j=n-1;
	float a=carib;
	float b=caris;
	carip = a/b;
	k=0;
	
	while((i<=j) && (temu==0)){//cari yang dicari
		k=(int)(i+j)/2;
		//printf("k ke %d \n", k);
		if((cuy[k].bilang==carib)&&(cuy[k].sebut==caris)){
			temu=1;
		}else{
			if(riil[k]<carip){
				j=k-1;
			}else{
				i=k+1;
			}
		}
	}
	//(cuy[k].bilang==carib)&&(cuy[k].sebut==caris)
}

void cetak(){
	int i;
	
	//manggil prosedur
	masuk();
	urut();
	cari();
	
	
	/*for(i=0;i<n;i++){
		printf("%d %d %f\n", cuy[i].bilang, cuy[i].sebut, riil[i]);
	}
	*/
	
	if(temu==1){//kalau ketemu
		printf("ditemukan\n");
	}else if(temu==0){//kalau gak ketemu
		printf("tidak ditemukan\n");
	}
	
	
	
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Quiz 2 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/