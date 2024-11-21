#include "ubg19.h"

void masuk(){//meminta masukan
	scanf("%d", &gaji);
	scanf("%s", sorting);
	scanf("%s", arah);
	scanf("%s", tipe);
	
	//memasukkan nama barang ke array of string nama
	strcpy(nama[0], "Beras");
	strcpy(nama[1], "MinyakGoreng");
	strcpy(nama[2], "Gula");
	strcpy(nama[3], "KecapManis");
	strcpy(nama[4], "KecapAsin");
	strcpy(nama[5], "Saos");
	strcpy(nama[6], "Susu");
	strcpy(nama[7], "Mentega");
	strcpy(nama[8], "SabunCuciPiring");
	strcpy(nama[9], "SabunMandi");
	strcpy(nama[10], "DagingAyam");
	strcpy(nama[11], "DagingSapi");
	strcpy(nama[12], "BumbuMasak");
	
	//memasukkan jumlah barang ke float jumlah
	jumlah[0]=10.0;
	jumlah[1]=3.6;
	jumlah[2]=2.0;
	jumlah[3]=0.4;
	jumlah[4]=0.3;
	jumlah[5]=0.1;
	jumlah[6]=1.0;
	jumlah[7]=2.0;
	jumlah[8]=0.8;
	jumlah[9]=1.2;
	jumlah[10]=5.0;
	jumlah[11]=3.0;
	jumlah[12]=1.0;
	
	//memasukkan harga barang ke integer harga
	harga[0]=165000;
	harga[1]=108000;
	harga[2]=20500;
	harga[3]=16000;
	harga[4]=9000;
	harga[5]=7250;
	harga[6]=190100;
	harga[7]=50000;
	harga[8]=30000;
	harga[9]=39999;
	harga[10]=175000;
	harga[11]=300000;
	harga[12]=87560;
}

void carisort(char nama[][50], float jumlah[], int harga[]){//mencari sortingannya
	if(strcmp(arah, "Ascending")==0){//mencari tau urutannya apakah ascending atau descending
		//cek mau yang mana yang disorting
		if(strcmp(tipe, "NamaBarang")==0){
			//cek metode sorting yang mana yang mau dipakai
			if(strcmp(sorting, "Insertion")==0){
				insertionA(1, nama, jumlah, harga);
			}else if(strcmp(sorting, "Selection")==0){
				selectionA(1, nama, jumlah, harga);
			}
		}else if(strcmp(tipe, "Jumlah")==0){
			//cek metode sorting yang mana yang mau dipakai
			if(strcmp(sorting, "Insertion")==0){
				insertionA(2, nama, jumlah, harga);
			}else if(strcmp(sorting, "Selection")==0){
				selectionA(2, nama, jumlah, harga);
			}
		}else if(strcmp(tipe, "Harga")==0){
			//cek metode sorting yang mana yang mau dipakai
			if(strcmp(sorting, "Insertion")==0){
				insertionA(3, nama, jumlah, harga);
			}else if(strcmp(sorting, "Selection")==0){
				selectionA(3, nama, jumlah, harga);
			}
		}
	}else if(strcmp(arah, "Descending")==0){//mencari tau urutannya apakah ascending atau descending
		//cek mau yang mana yang disorting
		if(strcmp(tipe, "NamaBarang")==0){
			//cek metode sorting yang mana yang mau dipakai
			if(strcmp(sorting, "Insertion")==0){
				insertionB(1, nama, jumlah, harga);
			}else if(strcmp(sorting, "Selection")==0){
				selectionB(1, nama, jumlah, harga);
			}
		}else if(strcmp(tipe, "Jumlah")==0){
			//cek metode sorting yang mana yang mau dipakai
			if(strcmp(sorting, "Insertion")==0){
				insertionB(2, nama, jumlah, harga);
			}else if(strcmp(sorting, "Selection")==0){
				selectionB(2, nama, jumlah, harga);
			}
		}else if(strcmp(tipe, "Harga")==0){
			//cek metode sorting yang mana yang mau dipakai
			if(strcmp(sorting, "Insertion")==0){
				insertionB(3, nama, jumlah, harga);
			}else if(strcmp(sorting, "Selection")==0){
				selectionB(3, nama, jumlah, harga);
			}
		}
	}
	
}

void insertionA(int a, char nama[][50], float jumlah[], int harga[]){//insertion sort ascending
	int i,j;//iterator
	//untuk menampung sementara
	int temph;
	char tempn[50];
	float tempf;
	
	if(a==1){
		for(i=1;i<13;i++){
			tempf=jumlah[i];
			strcpy(tempn, nama[i]);
			temph=harga[i];
			
			j=i-1;
			
			while(j>=0 && strcmp(tempn, nama[j])<0){
				//tukar posisi
				jumlah[j+1]=jumlah[j];
				harga[j+1]=harga[j];
				strcpy(nama[j+1], nama[j]);
				//j mundur 1
				j=j-1;
			}
			//menempatkan kunci pada array
			jumlah[j+1]=tempf;
			harga[j+1]=temph;
			strcpy(nama[j+1], tempn);
		}
	}else if(a==2){
		for(i=1;i<13;i++){
			tempf=jumlah[i];
			strcpy(tempn, nama[i]);
			temph=harga[i];
			
			j=i-1;
			
			while(j>=0 &&tempf < jumlah [j]){
				//tukar posisi
				jumlah[j+1]=jumlah[j];
				harga[j+1]=harga[j];
				strcpy(nama[j+1], nama[j]);
				//j mundur 1
				j=j-1;
			}
			//menempatkan kunci pada array
			jumlah[j+1]=tempf;
			harga[j+1]=temph;
			strcpy(nama[j+1], tempn);
		}
	}else if(a==3){
		for(i=1;i<13;i++){
			tempf=jumlah[i];
			strcpy(tempn, nama[i]);
			temph=harga[i];
			
			j=i-1;
			
			while(j>=0 &&temph < harga [j]){
				//tukar posisi
				jumlah[j+1]=jumlah[j];
				harga[j+1]=harga[j];
				strcpy(nama[j+1], nama[j]);
				//j mundur 1
				j=j-1;
			}
			//menempatkan kunci pada array
			jumlah[j+1]=tempf;
			harga[j+1]=temph;
			strcpy(nama[j+1], tempn);
		}
	}
	
}

void insertionB(int a, char nama[][50], float jumlah[], int harga[]){//insertion sort descending
	int i,j;
	//menampung sementara
	int temph;
	char tempn[50];
	float tempf;
	
	if(a==1){
		for(i=1;i<13;i++){
			tempf=jumlah[i];
			strcpy(tempn, nama[i]);
			temph=harga[i];
			
			j=i-1;
			
			while(j>=0 && strcmp(nama[j], tempn)<0){
				//tukar posisi
				jumlah[j+1]=jumlah[j];
				harga[j+1]=harga[j];
				strcpy(nama[j+1], nama[j]);
				//j mundur 1
				j=j-1;
			}
			//menempatkan kunci pada array
			jumlah[j+1]=tempf;
			harga[j+1]=temph;
			strcpy(nama[j+1], tempn);
		}
	}else if(a==2){
		for(i=1;i<13;i++){
			tempf=jumlah[i];
			strcpy(tempn, nama[i]);
			temph=harga[i];
			
			j=i-1;
			
			while(j>=0 &&jumlah [j] < tempf){
				//tukar posisi
				jumlah[j+1]=jumlah[j];
				harga[j+1]=harga[j];
				strcpy(nama[j+1], nama[j]);
				//j mundur 1
				j=j-1;
			}
			//menempatkan kunci pada array
			jumlah[j+1]=tempf;
			harga[j+1]=temph;
			strcpy(nama[j+1], tempn);
		}
	}else if(a==3){
		for(i=1;i<13;i++){
			tempf=jumlah[i];
			strcpy(tempn, nama[i]);
			temph=harga[i];
			
			j=i-1;
			
			while(j>=0 &&harga [j] < temph){
				//tukar posisi
				jumlah[j+1]=jumlah[j];
				harga[j+1]=harga[j];
				strcpy(nama[j+1], nama[j]);
				//j mundur 1
				j=j-1;
			}
			//menempatkan kunci pada array
			jumlah[j+1]=tempf;
			harga[j+1]=temph;
			strcpy(nama[j+1], tempn);
		}
	}
	
}

void selectionA(int a, char nama[][50], float jumlah[], int harga[]){//selection sort ascending
	int i, j, minIdx;
	//menampung sementara
	int temph;
	float tempf;
	char tempn[50];
	
	if(a==1){
		for(i=0;i<(13-1);i++){
			//mencari nilai minimum dari sebuah array
			minIdx=i;
			for(j=i+1;j<13;j++){
				if(strcmp(nama[minIdx], nama[j])>0){
					minIdx=j;
				}
			}
			//tukar posisi nilai minimum dengan indeks pertama
			temph=harga[i];
			tempf=jumlah[i];
			strcpy(tempn, nama[i]);
			
			harga[i]=harga[minIdx];
			jumlah[i]=jumlah[minIdx];
			strcpy(nama[i], nama[minIdx]);
			
			harga[minIdx]=temph;
			jumlah[minIdx]=tempf;
			strcpy(nama[minIdx], tempn);
		}
	}else if(a==2){
		for(i=0;i<(13-1);i++){
			//mencari nilai minimum dari sebuah array
			minIdx=i;
			for(j=i+1;j<13;j++){
				if(jumlah[minIdx]>jumlah[j]){
					minIdx=j;
				}
			}
			//tukar posisi nilai minimum dengan indeks pertama
			temph=harga[i];
			tempf=jumlah[i];
			strcpy(tempn, nama[i]);
			
			harga[i]=harga[minIdx];
			jumlah[i]=jumlah[minIdx];
			strcpy(nama[i], nama[minIdx]);
			
			harga[minIdx]=temph;
			jumlah[minIdx]=tempf;
			strcpy(nama[minIdx], tempn);
		}
	}else if(a==3){
		for(i=0;i<(13-1);i++){
			//mencari nilai minimum dari sebuah array
			minIdx=i;
			for(j=i+1;j<13;j++){
				if(harga[minIdx]>harga[j]){
					minIdx=j;
				}
			}
			//tukar posisi nilai minimum dengan indeks pertama
			temph=harga[i];
			tempf=jumlah[i];
			strcpy(tempn, nama[i]);
			
			harga[i]=harga[minIdx];
			jumlah[i]=jumlah[minIdx];
			strcpy(nama[i], nama[minIdx]);
			
			harga[minIdx]=temph;
			jumlah[minIdx]=tempf;
			strcpy(nama[minIdx], tempn);
		}
	}
}

void selectionB(int a, char nama[][50], float jumlah[], int harga[]){//selection sort descending
	int i, j, minIdx;
	int temph;
	float tempf;
	char tempn[50];
	
	if(a==1){
		for(i=0;i<(13-1);i++){
			//mencari nilai maksimum dari sebuah array
			minIdx=i;
			for(j=i+1;j<13;j++){
				if(strcmp(nama[minIdx], nama[j])<0){
					minIdx=j;
				}
			}
			//tukar posisi nilai maksimum dengan indeks pertama
			temph=harga[i];
			tempf=jumlah[i];
			strcpy(tempn, nama[i]);
			
			harga[i]=harga[minIdx];
			jumlah[i]=jumlah[minIdx];
			strcpy(nama[i], nama[minIdx]);
			
			harga[minIdx]=temph;
			jumlah[minIdx]=tempf;
			strcpy(nama[minIdx], tempn);
		}
	}else if(a==2){
		for(i=0;i<(13-1);i++){
			//mencari nilai maksimum dari sebuah array
			minIdx=i;
			for(j=i+1;j<13;j++){
				if(jumlah[minIdx]<jumlah[j]){
					minIdx=j;
				}
			}
			//tukar posisi nilai maksimum dengan indeks pertama
			temph=harga[i];
			tempf=jumlah[i];
			strcpy(tempn, nama[i]);
			
			harga[i]=harga[minIdx];
			jumlah[i]=jumlah[minIdx];
			strcpy(nama[i], nama[minIdx]);
			
			harga[minIdx]=temph;
			jumlah[minIdx]=tempf;
			strcpy(nama[minIdx], tempn);
		}
	}else if(a==3){
		for(i=0;i<(13-1);i++){
			//mencari nilai maksimum dari sebuah array
			minIdx=i;
			for(j=i+1;j<13;j++){
				if(harga[minIdx]<harga[j]){
					minIdx=j;
				}
			}
			//tukar posisi nilai maksimum dengan indeks pertama
			temph=harga[i];
			tempf=jumlah[i];
			strcpy(tempn, nama[i]);
			
			harga[i]=harga[minIdx];
			jumlah[i]=jumlah[minIdx];
			strcpy(nama[i], nama[minIdx]);
			
			harga[minIdx]=temph;
			jumlah[minIdx]=tempf;
			strcpy(nama[minIdx], tempn);
		}
	}
}

void cetak(){//mencetak output
	int i=0;//iterator
	int tempgaji=gaji;//menampung gaji sementara
	int count=0;//buat nampung kapan i nya berhenti di bagian kebeli
	int totharga=0;//menampung total harga
	int sisa=0;//menampung sisa uang belanjaan
	int true=1;//ini iseng aja, biar begitu ada yang gak kebeli langsung berhenti
	int cek=0;//buat tau apa gak kebeli semua atau gimana
	
	printf("=== Hasil Sorting ===\n");//mencetak hasil sortingan
	for(i=0;i<13;i++){
		printf("%s ", nama[i]);
		printf("%.1fkg ", jumlah[i]);
		printf("Rp%d\n", harga[i]);
	}
	printf("=== Kebeli ===\n");//mencetak apa aja yang kebeli
		for(i=0;i<13;i++){
			if(tempgaji>=harga[i]&&true==1){//jika dia bisa beli terus dia akan terus muter, kalo gak langsung berhenti
				printf("%s\n", nama[i]);
				tempgaji=tempgaji-harga[i];
				count=i;
				totharga=totharga+harga[i];
				cek++;
			}else{
				true=0;
			}
		}

	if(cek==0){
		printf("=== Tidak Kebeli ===\n");//cetak apa aja yang gak kebeli
		for(i=0;i<13;i++){//cetak cetak
			printf("%s\n", nama[i]);
		}
	}else{
		printf("=== Tidak Kebeli ===\n");//cetak apa aja yang gak kebeli
		for(i=count+1;i<13;i++){//mulainya berdasarkan dari yang kebeli
			printf("%s\n", nama[i]);
		}
	}
	
	
	printf("Total Harga: Rp%d\n", totharga);//cetak total harga
	sisa=gaji-totharga;//mencari sisa uang belanjaan
	printf("Sisa: Rp%d\n", sisa);//cetak sisa uang belanjaan
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Evaluasi 4 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/