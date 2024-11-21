#include "sblbl20.h"

void masuk(){//meminta masukan
	int i;
	scanf(" %c", &metode);
	scanf("%s", cari);
	
	scanf("%d", &panjang[0]);
	for(i=0;i<panjang[0];i++){
		scanf("%d %d %s %s", &churros[0].netto[i], &churros[0].harga[i], churros[0].merk[i], churros[0].jenis[i]);
	}
	
	scanf("%d", &panjang[1]);
	for(i=0;i<panjang[1];i++){
		scanf("%d %d %s %s", &churros[1].netto[i], &churros[1].harga[i], churros[1].merk[i], churros[1].jenis[i]);
	}
	
	scanf("%d", &panjang[2]);
	for(i=0;i<panjang[2];i++){
		scanf("%d %d %s %s", &churros[2].netto[i], &churros[2].harga[i], churros[2].merk[i], churros[2].jenis[i]);
	}
}

void hargar(){//mencari harga murah tiap baris
	int i;
	int j;
	float temph;
	float tempb;
	
	for(i=0;i<pdaftar;i++){
		temph=churros[4].harga[i]*100000;
		tempb=churros[4].netto[i];
		churros[4].hargamurah[i]=temph/tempb;
	}
	
}

void gabung(){//menggabungkan isi array berdasar jenisnya
	
	int i;
	int j;
	int hitung=0;
	
	for(i=0;i<3;i++){
		for(j=0;j<panjang[i];j++){
			if(strcmp(cari, churros[i].jenis[j])==0){
				churros[4].netto[hitung]=churros[i].netto[j];
				churros[4].harga[hitung]=churros[i].harga[j];
				churros[4].hargamurah[hitung]=churros[i].hargamurah[j];
				strcpy(churros[4].merk[hitung], churros[i].merk[j]);
				strcpy(churros[4].jenis[hitung], churros[i].jenis[j]);
				hitung++;
			}
		}
	}
	
	pdaftar=hitung;//menampung panjang array gabungan
	
}

void carisort(){//mencari metode sorting mana yang ingin digunakan
	if(metode=='i'){
		insertion();
	}else if(metode=='s'){
		selection();
	}else if(metode=='b'){
		bubble();
	}else if(metode=='q'){
		quick(0, pdaftar-1);
	}
}

void insertion(){//metode insertion
	int i,j;
	int k;
	float key;
	int temp1;
	int temp2;
	char temp3[50];
	char temp4[50];

	for(i=1;i<pdaftar;i++){
		temp1=churros[4].netto[i];
		temp2=churros[4].harga[i];
		strcpy(temp3, churros[4].merk[i]);
		strcpy(temp4, churros[4].jenis[i]);
		key=churros[4].hargamurah[i];
		
		j=i-1;
		
		while(j>=0 &&key < churros[4].hargamurah [j]){
			//tukar posisi
			churros[4].hargamurah[j+1]=churros[4].hargamurah[j];
			churros[4].netto[j+1]=churros[4].netto[j];
			churros[4].harga[j+1]=churros[4].harga[j];
			strcpy(churros[4].merk[j+1], churros[4].merk[j]);
			strcpy(churros[4].jenis[j+1], churros[4].jenis[j]);
			//j mundur 1
			j=j-1;
		}
	//menempatkan kunci pada array
	churros[4].hargamurah[j+1]=key;
	churros[4].netto[j+1]=temp1;
	churros[4].harga[j+1]=temp2;
	strcpy(churros[4].merk[j+1], temp3);
	strcpy(churros[4].jenis[j+1], temp4);
	}
	
}

void selection(){//metode selection
	int i, j, minIdx;
	//menampung sementara
	int temp1;
	int temp2;
	float key;
	char temp3[50];
	char temp4[50];
	

	for(i=0;i<(pdaftar-1);i++){
		//mencari nilai minimum dari sebuah array
		minIdx=i;
		for(j=i+1;j<pdaftar;j++){
			if(churros[4].hargamurah[minIdx]>churros[4].hargamurah[j]){
				minIdx=j;
			}
		}
		//tukar posisi nilai minimum dengan indeks pertama
		temp1=churros[4].netto[i];
		temp2=churros[4].harga[i];
		strcpy(temp3, churros[4].merk[i]);
		strcpy(temp4, churros[4].jenis[i]);
		key=churros[4].hargamurah[i];
		
		churros[4].netto[i]=churros[4].netto[minIdx];
		churros[4].harga[i]=churros[4].harga[minIdx];
		churros[4].hargamurah[i]=churros[4].hargamurah[minIdx];
		strcpy(churros[4].merk[i], churros[4].merk[minIdx]);
		strcpy(churros[4].jenis[i], churros[4].jenis[minIdx]);
		
		churros[4].netto[minIdx]=temp1;
		churros[4].harga[minIdx]=temp2;
		churros[4].hargamurah[minIdx]=key;
		strcpy(churros[4].merk[minIdx], temp3);
		strcpy(churros[4].jenis[minIdx], temp4);
	}
	
}

void bubble(){//metode bubble
	int i, pindah;//variabel yang akan digunakan dalam sorting
	int temp1;
	int temp2;
	float key;
	char temp3[50];
	char temp4[50];
	
	do{//perulangan untuk mengecek setiap anggota data
		pindah = 0;
		
		for(i=0;i<(pdaftar-1);i++){
			/*perulangan untuk mengecek data yang dipilih terhadap data yang
			*/
			if(churros[4].hargamurah[i]>churros[4].hargamurah[i+1]){//proses membandingkan data
				//proses pemindahan data
				temp1 = churros[4].netto[i];
				temp2 = churros[4].harga[i];
				key = churros[4].hargamurah[i];
				strcpy(temp3, churros[4].merk[i]);
				strcpy(temp4, churros[4].jenis[i]);
				
				churros[4].netto[i]=churros[4].netto[i+1];
				churros[4].harga[i]=churros[4].harga[i+1];
				churros[4].hargamurah[i]=churros[4].hargamurah[i+1];
				strcpy(churros[4].merk[i], churros[4].merk[i+1]);
				strcpy(churros[4].jenis[i], churros[4].jenis[i+1]);
				
				churros[4].netto[i+1]=temp1;
				churros[4].harga[i+1]=temp2;
				churros[4].hargamurah[i+1]=key;
				strcpy(churros[4].merk[i+1], temp3);
				strcpy(churros[4].jenis[i+1], temp4);
				
				pindah =1;
			}
			
		}
	}while(pindah==1);
}

void quick(int kiri, int kanan){//metode quick pinggir
	int i, j;
	int temp1;
	int temp2;
	float key;
	char temp3[50];
	char temp4[50];
	i=kiri;
	j=kanan;
	
	do{
		while((churros[4].hargamurah[i]<churros[4].hargamurah[kanan])&&(i<=j)){
			i++;
		}
		while((churros[4].hargamurah[j]>churros[4].hargamurah[kiri])&&(i<=j)){
			j--;
		}
		
		if(i<j){
			temp1 = churros[4].netto[i];
			temp2 = churros[4].harga[i];
			key = churros[4].hargamurah[i];
			strcpy(temp3, churros[4].merk[i]);
			strcpy(temp4, churros[4].jenis[i]);
			
			churros[4].netto[i]=churros[4].netto[j];
			churros[4].harga[i]=churros[4].harga[j];
			churros[4].hargamurah[i]=churros[4].hargamurah[j];
			strcpy(churros[4].merk[i], churros[4].merk[j]);
			strcpy(churros[4].jenis[i], churros[4].jenis[j]);
				
			churros[4].netto[j]=temp1;
			churros[4].harga[j]=temp2;
			churros[4].hargamurah[j]=key;
			strcpy(churros[4].merk[j], temp3);
			strcpy(churros[4].jenis[j], temp4);
			
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

void tes(){//mencetak
	int i;
	int p=panjang[0]+panjang[1]+panjang[2];
	
	/*for(i=0;i<pdaftar;i++){
		printf("%f\n", churros[4].hargamurah[i]);
	}
	*/
	
	for(i=0;i<pdaftar;i++){
		printf("%d %d %s %s\n", churros[4].netto[i], churros[4].harga[i], churros[4].merk[i], churros[4].jenis[i]);
	}
}



/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi UTS dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/