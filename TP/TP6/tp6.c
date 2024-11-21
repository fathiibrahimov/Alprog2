#include "tp6.h"

void masuk(){//nyari masukan, jangan nyari keributan
	int i;//iterator
	scanf("%s", m1);
	scanf("%d", &panjang[0]);
	for(i=0;i<panjang[0];i++){
		scanf("%s %d %d %d", kasus[0].negara[i], &kasus[0].jumlahkasus[i], &kasus[0].sembuh[i], &kasus[0].meninggal[i]);
	}
	
	scanf("%s", m2);
	scanf("%d", &panjang[1]);
	for(i=0;i<panjang[1];i++){
		scanf("%s %d %d %d", kasus[1].negara[i], &kasus[1].jumlahkasus[i], &kasus[1].sembuh[i], &kasus[1].meninggal[i]);
	}
	
	scanf("%s", m3);
	scanf("%d", &panjang[2]);
	for(i=0;i<panjang[2];i++){
		scanf("%s %d %d %d", kasus[2].negara[i], &kasus[2].jumlahkasus[i], &kasus[2].sembuh[i], &kasus[2].meninggal[i]);
	}
	
	scanf("%s", mau);
	scanf("%s", metode);
	scanf("%s", urut);
	
	//ini biar ga error, entah kenapa pas dijalanin di cmd error, tapi kayanya udah nggak sih sekarang mah
	if(strcmp(urut, "Asc")==0){
		ab=1;
	}else if(strcmp(urut, "Desc")==0){
		ab=2;
	}
}


void gabung(){//buat gabungin data datanya
	//iterator
	int i;
	int j;
	int hitung = 0;
	
	for(i=0;i<3;i++){
		for(j=0;j<panjang[i];j++){
			strcpy(kasus[4].negara[hitung], kasus[i].negara[j]);
			kasus[4].jumlahkasus[hitung] = kasus[i].jumlahkasus[j];
			kasus[4].sembuh[hitung] = kasus[i].sembuh[j];
			kasus[4].meninggal[hitung] = kasus[i].meninggal[j];
			hitung++;
		}
	}
	panjang[4]=hitung;
}

void cariurut(){//buat nyari urutannya
	if(ab==1){
		ascending();
	}else if(ab==2){
		descending();
	}
}

void ascending(){//jika ascending dia bakal nyari make metode apa
	if(strcmp(metode, "Insertion")==0){
		if(strcmp(mau, "NamaNegara")==0){
			insertiona(1);
		}else if(strcmp(mau, "JumlahKasus")==0){
			insertiona(2);
		}else if(strcmp(mau, "Sembuh")==0){
			insertiona(3);
		}else if(strcmp(mau, "Meninggal")==0){
			insertiona(4);
		}else if(strcmp(mau, "KasusAktif")==0){
			insertiona(5);
		}
	}else if(strcmp(metode, "Selection")==0){
		if(strcmp(mau, "NamaNegara")==0){
			selectiona(1);
		}else if(strcmp(mau, "JumlahKasus")==0){
			selectiona(2);
		}else if(strcmp(mau, "Sembuh")==0){
			selectiona(3);
		}else if(strcmp(mau, "Meninggal")==0){
			selectiona(4);
		}else if(strcmp(mau, "KasusAktif")==0){
			selectiona(5);
		}
	}else if(strcmp(metode, "BubbleSort")==0){
		if(strcmp(mau, "NamaNegara")==0){
			bubblea(1);
		}else if(strcmp(mau, "JumlahKasus")==0){
			bubblea(2);
		}else if(strcmp(mau, "Sembuh")==0){
			bubblea(3);
		}else if(strcmp(mau, "Meninggal")==0){
			bubblea(4);
		}else if(strcmp(mau, "KasusAktif")==0){
			bubblea(5);
		}
	}else if(strcmp(metode, "QuickSort")==0){
		if(strcmp(mau, "NamaNegara")==0){
			quicka(1, 0, panjang[4]-1);
		}else if(strcmp(mau, "JumlahKasus")==0){
			quicka(2, 0, panjang[4]-1);
		}else if(strcmp(mau, "Sembuh")==0){
			quicka(3, 0, panjang[4]-1);
		}else if(strcmp(mau, "Meninggal")==0){
			quicka(4, 0, panjang[4]-1);
		}else if(strcmp(mau, "KasusAktif")==0){
			quicka(5, 0, panjang[4]-1);
		}
	}
}

void descending(){//jika descending dia juga bakal nyari metode apa, cuma diriku yang tidak dicariin doi
	if(strcmp(metode, "Insertion")==0){
		if(strcmp(mau, "NamaNegara")==0){
			insertionb(1);
		}else if(strcmp(mau, "JumlahKasus")==0){
			insertionb(2);
		}else if(strcmp(mau, "Sembuh")==0){
			insertionb(3);
		}else if(strcmp(mau, "Meninggal")==0){
			insertionb(4);
		}else if(strcmp(mau, "KasusAktif")==0){
			insertionb(5);
		}
	}else if(strcmp(metode, "Selection")==0){
		if(strcmp(mau, "NamaNegara")==0){
			selectionb(1);
		}else if(strcmp(mau, "JumlahKasus")==0){
			selectionb(2);
		}else if(strcmp(mau, "Sembuh")==0){
			selectionb(3);
		}else if(strcmp(mau, "Meninggal")==0){
			selectionb(4);
		}else if(strcmp(mau, "KasusAktif")==0){
			selectionb(5);
		}
	}else if(strcmp(metode, "BubbleSort")==0){
		if(strcmp(mau, "NamaNegara")==0){
			bubbleb(1);
		}else if(strcmp(mau, "JumlahKasus")==0){
			bubbleb(2);
		}else if(strcmp(mau, "Sembuh")==0){
			bubbleb(3);
		}else if(strcmp(mau, "Meninggal")==0){
			bubbleb(4);
		}else if(strcmp(mau, "KasusAktif")==0){
			bubbleb(5);
		}
	}else if(strcmp(metode, "QuickSort")==0){
		if(strcmp(mau, "NamaNegara")==0){
			quickb(1, 0, panjang[4]-1);
		}else if(strcmp(mau, "JumlahKasus")==0){
			quickb(2, 0, panjang[4]-1);
		}else if(strcmp(mau, "Sembuh")==0){
			quickb(3, 0, panjang[4]-1);
		}else if(strcmp(mau, "Meninggal")==0){
			quickb(4, 0, panjang[4]-1);
		}else if(strcmp(mau, "KasusAktif")==0){
			quickb(5, 0, panjang[4]-1);
		}
	}
}

void insertiona(int a){//insertion ascending
	int i,j;
	char temp1[100];
	int temp2;
	int temp3;
	int temp4;
	int temp5;
	
	if(a==1){
		for(i=1;i<panjang[4];i++){
			strcpy(temp1, kasus[4].negara[i]);
			temp2=kasus[4].jumlahkasus[i];
			temp3=kasus[4].sembuh[i];
			temp4=kasus[4].meninggal[i];
			temp5=kasus[4].kasusaktif[i];
			
			j=i-1;
			
			while(j>=0 && strcmp(temp1, kasus[4].negara[j])<0){
				//tukar posisi
				strcpy(kasus[4].negara[j+1], kasus[4].negara[j]);
				kasus[4].jumlahkasus[j+1]=kasus[4].jumlahkasus[j];
				kasus[4].sembuh[j+1]=kasus[4].sembuh[j];
				kasus[4].meninggal[j+1]=kasus[4].meninggal[j];
				kasus[4].kasusaktif[j+1]=kasus[4].kasusaktif[j];
				//j mundur 1
				j=j-1;
			}
			//menempatkan kunci pada array
			strcpy(kasus[4].negara[j+1], temp1);
			kasus[4].jumlahkasus[j+1]=temp2;
			kasus[4].sembuh[j+1]=temp3;
			kasus[4].meninggal[j+1]=temp4;
			kasus[4].kasusaktif[j+1]=temp5;
		}
	}else if(a==2){
		for(i=1;i<panjang[4];i++){
			strcpy(temp1, kasus[4].negara[i]);
			temp2=kasus[4].jumlahkasus[i];
			temp3=kasus[4].sembuh[i];
			temp4=kasus[4].meninggal[i];
			temp5=kasus[4].kasusaktif[i];
			
			j=i-1;
			
			while(j>=0 && temp2 < kasus[4].jumlahkasus[j]){
				//tukar posisi
				strcpy(kasus[4].negara[j+1], kasus[4].negara[j]);
				kasus[4].jumlahkasus[j+1]=kasus[4].jumlahkasus[j];
				kasus[4].sembuh[j+1]=kasus[4].sembuh[j];
				kasus[4].meninggal[j+1]=kasus[4].meninggal[j];
				kasus[4].kasusaktif[j+1]=kasus[4].kasusaktif[j];
				//j mundur 1
				j=j-1;
			}
			//menempatkan kunci pada array
			strcpy(kasus[4].negara[j+1], temp1);
			kasus[4].jumlahkasus[j+1]=temp2;
			kasus[4].sembuh[j+1]=temp3;
			kasus[4].meninggal[j+1]=temp4;
			kasus[4].kasusaktif[j+1]=temp5;
		}
	}else if(a==3){
		for(i=1;i<panjang[4];i++){
			strcpy(temp1, kasus[4].negara[i]);
			temp2=kasus[4].jumlahkasus[i];
			temp3=kasus[4].sembuh[i];
			temp4=kasus[4].meninggal[i];
			temp5=kasus[4].kasusaktif[i];
			
			j=i-1;
			
			while(j>=0 && temp3 < kasus[4].sembuh[j]){
				//tukar posisi
				strcpy(kasus[4].negara[j+1], kasus[4].negara[j]);
				kasus[4].jumlahkasus[j+1]=kasus[4].jumlahkasus[j];
				kasus[4].sembuh[j+1]=kasus[4].sembuh[j];
				kasus[4].meninggal[j+1]=kasus[4].meninggal[j];
				kasus[4].kasusaktif[j+1]=kasus[4].kasusaktif[j];
				//j mundur 1
				j=j-1;
			}
			//menempatkan kunci pada array
			strcpy(kasus[4].negara[j+1], temp1);
			kasus[4].jumlahkasus[j+1]=temp2;
			kasus[4].sembuh[j+1]=temp3;
			kasus[4].meninggal[j+1]=temp4;
			kasus[4].kasusaktif[j+1]=temp5;
		}
	}else if(a==4){
		for(i=1;i<panjang[4];i++){
			strcpy(temp1, kasus[4].negara[i]);
			temp2=kasus[4].jumlahkasus[i];
			temp3=kasus[4].sembuh[i];
			temp4=kasus[4].meninggal[i];
			temp5=kasus[4].kasusaktif[i];
			
			j=i-1;
			
			while(j>=0 && temp4 < kasus[4].meninggal[j]){
				//tukar posisi
				strcpy(kasus[4].negara[j+1], kasus[4].negara[j]);
				kasus[4].jumlahkasus[j+1]=kasus[4].jumlahkasus[j];
				kasus[4].sembuh[j+1]=kasus[4].sembuh[j];
				kasus[4].meninggal[j+1]=kasus[4].meninggal[j];
				kasus[4].kasusaktif[j+1]=kasus[4].kasusaktif[j];
				//j mundur 1
				j=j-1;
			}
			//menempatkan kunci pada array
			strcpy(kasus[4].negara[j+1], temp1);
			kasus[4].jumlahkasus[j+1]=temp2;
			kasus[4].sembuh[j+1]=temp3;
			kasus[4].meninggal[j+1]=temp4;
			kasus[4].kasusaktif[j+1]=temp5;
		}
	}else if(a==5){
		for(i=1;i<panjang[4];i++){
			strcpy(temp1, kasus[4].negara[i]);
			temp2=kasus[4].jumlahkasus[i];
			temp3=kasus[4].sembuh[i];
			temp4=kasus[4].meninggal[i];
			temp5=kasus[4].kasusaktif[i];
			
			j=i-1;
			
			while(j>=0 && temp5 < kasus[4].kasusaktif[j]){
				//tukar posisi
				strcpy(kasus[4].negara[j+1], kasus[4].negara[j]);
				kasus[4].jumlahkasus[j+1]=kasus[4].jumlahkasus[j];
				kasus[4].sembuh[j+1]=kasus[4].sembuh[j];
				kasus[4].meninggal[j+1]=kasus[4].meninggal[j];
				kasus[4].kasusaktif[j+1]=kasus[4].kasusaktif[j];
				//j mundur 1
				j=j-1;
			}
			//menempatkan kunci pada array
			strcpy(kasus[4].negara[j+1], temp1);
			kasus[4].jumlahkasus[j+1]=temp2;
			kasus[4].sembuh[j+1]=temp3;
			kasus[4].meninggal[j+1]=temp4;
			kasus[4].kasusaktif[j+1]=temp5;
		}
	}
}

void insertionb(int a){//insertion descending
	int i,j;
	char temp1[100];
	int temp2;
	int temp3;
	int temp4;
	int temp5;
	
	if(a==1){
		for(i=1;i<panjang[4];i++){
			strcpy(temp1, kasus[4].negara[i]);
			temp2=kasus[4].jumlahkasus[i];
			temp3=kasus[4].sembuh[i];
			temp4=kasus[4].meninggal[i];
			temp5=kasus[4].kasusaktif[i];
			
			j=i-1;
			
			while(j>=0 && strcmp(kasus[4].negara[j], temp1)<0){
				//tukar posisi
				strcpy(kasus[4].negara[j+1], kasus[4].negara[j]);
				kasus[4].jumlahkasus[j+1]=kasus[4].jumlahkasus[j];
				kasus[4].sembuh[j+1]=kasus[4].sembuh[j];
				kasus[4].meninggal[j+1]=kasus[4].meninggal[j];
				kasus[4].kasusaktif[j+1]=kasus[4].kasusaktif[j];
				//j mundur 1
				j=j-1;
			}
			//menempatkan kunci pada array
			strcpy(kasus[4].negara[j+1], temp1);
			kasus[4].jumlahkasus[j+1]=temp2;
			kasus[4].sembuh[j+1]=temp3;
			kasus[4].meninggal[j+1]=temp4;
			kasus[4].kasusaktif[j+1]=temp5;
		}
	}else if(a==2){
		for(i=1;i<panjang[4];i++){
			strcpy(temp1, kasus[4].negara[i]);
			temp2=kasus[4].jumlahkasus[i];
			temp3=kasus[4].sembuh[i];
			temp4=kasus[4].meninggal[i];
			temp5=kasus[4].kasusaktif[i];
			
			j=i-1;
			
			while(j>=0 &&  kasus[4].jumlahkasus[j]< temp2){
				//tukar posisi
				strcpy(kasus[4].negara[j+1], kasus[4].negara[j]);
				kasus[4].jumlahkasus[j+1]=kasus[4].jumlahkasus[j];
				kasus[4].sembuh[j+1]=kasus[4].sembuh[j];
				kasus[4].meninggal[j+1]=kasus[4].meninggal[j];
				kasus[4].kasusaktif[j+1]=kasus[4].kasusaktif[j];
				//j mundur 1
				j=j-1;
			}
			//menempatkan kunci pada array
			strcpy(kasus[4].negara[j+1], temp1);
			kasus[4].jumlahkasus[j+1]=temp2;
			kasus[4].sembuh[j+1]=temp3;
			kasus[4].meninggal[j+1]=temp4;
			kasus[4].kasusaktif[j+1]=temp5;
		}
	}else if(a==3){
		for(i=1;i<panjang[4];i++){
			strcpy(temp1, kasus[4].negara[i]);
			temp2=kasus[4].jumlahkasus[i];
			temp3=kasus[4].sembuh[i];
			temp4=kasus[4].meninggal[i];
			temp5=kasus[4].kasusaktif[i];
			
			j=i-1;
			
			while(j>=0 &&  kasus[4].sembuh[j]< temp3){
				//tukar posisi
				strcpy(kasus[4].negara[j+1], kasus[4].negara[j]);
				kasus[4].jumlahkasus[j+1]=kasus[4].jumlahkasus[j];
				kasus[4].sembuh[j+1]=kasus[4].sembuh[j];
				kasus[4].meninggal[j+1]=kasus[4].meninggal[j];
				kasus[4].kasusaktif[j+1]=kasus[4].kasusaktif[j];
				//j mundur 1
				j=j-1;
			}
			//menempatkan kunci pada array
			strcpy(kasus[4].negara[j+1], temp1);
			kasus[4].jumlahkasus[j+1]=temp2;
			kasus[4].sembuh[j+1]=temp3;
			kasus[4].meninggal[j+1]=temp4;
			kasus[4].kasusaktif[j+1]=temp5;
		}
	}else if(a==4){
		for(i=1;i<panjang[4];i++){
			strcpy(temp1, kasus[4].negara[i]);
			temp2=kasus[4].jumlahkasus[i];
			temp3=kasus[4].sembuh[i];
			temp4=kasus[4].meninggal[i];
			temp5=kasus[4].kasusaktif[i];
			
			j=i-1;
			
			while(j>=0 && kasus[4].meninggal[j] < temp4){
				//tukar posisi
				strcpy(kasus[4].negara[j+1], kasus[4].negara[j]);
				kasus[4].jumlahkasus[j+1]=kasus[4].jumlahkasus[j];
				kasus[4].sembuh[j+1]=kasus[4].sembuh[j];
				kasus[4].meninggal[j+1]=kasus[4].meninggal[j];
				kasus[4].kasusaktif[j+1]=kasus[4].kasusaktif[j];
				//j mundur 1
				j=j-1;
			}
			//menempatkan kunci pada array
			strcpy(kasus[4].negara[j+1], temp1);
			kasus[4].jumlahkasus[j+1]=temp2;
			kasus[4].sembuh[j+1]=temp3;
			kasus[4].meninggal[j+1]=temp4;
			kasus[4].kasusaktif[j+1]=temp5;
		}
	}else if(a==5){
		for(i=1;i<panjang[4];i++){
			strcpy(temp1, kasus[4].negara[i]);
			temp2=kasus[4].jumlahkasus[i];
			temp3=kasus[4].sembuh[i];
			temp4=kasus[4].meninggal[i];
			temp5=kasus[4].kasusaktif[i];
			
			j=i-1;
			
			while(j>=0 && kasus[4].kasusaktif[j] < temp5){
				//tukar posisi
				strcpy(kasus[4].negara[j+1], kasus[4].negara[j]);
				kasus[4].jumlahkasus[j+1]=kasus[4].jumlahkasus[j];
				kasus[4].sembuh[j+1]=kasus[4].sembuh[j];
				kasus[4].meninggal[j+1]=kasus[4].meninggal[j];
				kasus[4].kasusaktif[j+1]=kasus[4].kasusaktif[j];
				//j mundur 1
				j=j-1;
			}
			//menempatkan kunci pada array
			strcpy(kasus[4].negara[j+1], temp1);
			kasus[4].jumlahkasus[j+1]=temp2;
			kasus[4].sembuh[j+1]=temp3;
			kasus[4].meninggal[j+1]=temp4;
			kasus[4].kasusaktif[j+1]=temp5;
		}
	}
}

void selectiona(int a){//selection ascending
	int i, j, minIdx;
	//menampung sementara
	char temp1[100];
	int temp2;
	int temp3;
	int temp4;
	int temp5;
	
	if(a==1){
		for(i=0;i<(panjang[4]-1);i++){
			//mencari nilai minimum dari sebuah array
			minIdx=i;
			for(j=i+1;j<panjang[4];j++){
				if(strcmp(kasus[4].negara[minIdx], kasus[4].negara[j])>0){
					minIdx=j;
				}
			}
			//tukar posisi nilai minimum dengan indeks pertama
			strcpy(temp1, kasus[4].negara[i]);
			temp2=kasus[4].jumlahkasus[i];
			temp3=kasus[4].sembuh[i];
			temp4=kasus[4].meninggal[i];
			temp5=kasus[4].kasusaktif[i];
			
			strcpy(kasus[4].negara[i], kasus[4].negara[minIdx]);
			kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[minIdx];
			kasus[4].sembuh[i]=kasus[4].sembuh[minIdx];
			kasus[4].meninggal[i]=kasus[4].meninggal[minIdx];
			kasus[4].kasusaktif[i]=kasus[4].kasusaktif[minIdx];
			
			strcpy(kasus[4].negara[minIdx], temp1);
			kasus[4].jumlahkasus[minIdx]=temp2;
			kasus[4].sembuh[minIdx]=temp3;
			kasus[4].meninggal[minIdx]=temp4;
			kasus[4].kasusaktif[minIdx]=temp5;
		}		
	}else if(a==2){
		for(i=0;i<(panjang[4]-1);i++){
			//mencari nilai minimum dari sebuah array
			minIdx=i;
			for(j=i+1;j<panjang[4];j++){
				if(kasus[4].jumlahkasus[minIdx]>kasus[4].jumlahkasus[j]){
					minIdx=j;
				}
			}
			//tukar posisi nilai minimum dengan indeks pertama
			strcpy(temp1, kasus[4].negara[i]);
			temp2=kasus[4].jumlahkasus[i];
			temp3=kasus[4].sembuh[i];
			temp4=kasus[4].meninggal[i];
			temp5=kasus[4].kasusaktif[i];
			
			strcpy(kasus[4].negara[i], kasus[4].negara[minIdx]);
			kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[minIdx];
			kasus[4].sembuh[i]=kasus[4].sembuh[minIdx];
			kasus[4].meninggal[i]=kasus[4].meninggal[minIdx];
			kasus[4].kasusaktif[i]=kasus[4].kasusaktif[minIdx];
			
			strcpy(kasus[4].negara[minIdx], temp1);
			kasus[4].jumlahkasus[minIdx]=temp2;
			kasus[4].sembuh[minIdx]=temp3;
			kasus[4].meninggal[minIdx]=temp4;
			kasus[4].kasusaktif[minIdx]=temp5;
		}
	}else if(a==3){
		for(i=0;i<(panjang[4]-1);i++){
			//mencari nilai minimum dari sebuah array
			minIdx=i;
			for(j=i+1;j<panjang[4];j++){
				if(kasus[4].sembuh[minIdx]>kasus[4].sembuh[j]){
					minIdx=j;
				}
			}
			//tukar posisi nilai minimum dengan indeks pertama
			strcpy(temp1, kasus[4].negara[i]);
			temp2=kasus[4].jumlahkasus[i];
			temp3=kasus[4].sembuh[i];
			temp4=kasus[4].meninggal[i];
			temp5=kasus[4].kasusaktif[i];
			
			strcpy(kasus[4].negara[i], kasus[4].negara[minIdx]);
			kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[minIdx];
			kasus[4].sembuh[i]=kasus[4].sembuh[minIdx];
			kasus[4].meninggal[i]=kasus[4].meninggal[minIdx];
			kasus[4].kasusaktif[i]=kasus[4].kasusaktif[minIdx];
			
			strcpy(kasus[4].negara[minIdx], temp1);
			kasus[4].jumlahkasus[minIdx]=temp2;
			kasus[4].sembuh[minIdx]=temp3;
			kasus[4].meninggal[minIdx]=temp4;
			kasus[4].kasusaktif[minIdx]=temp5;
		}
	}else if(a==4){
		for(i=0;i<(panjang[4]-1);i++){
			//mencari nilai minimum dari sebuah array
			minIdx=i;
			for(j=i+1;j<panjang[4];j++){
				if(kasus[4].meninggal[minIdx]>kasus[4].meninggal[j]){
					minIdx=j;
				}
			}
			//tukar posisi nilai minimum dengan indeks pertama
			strcpy(temp1, kasus[4].negara[i]);
			temp2=kasus[4].jumlahkasus[i];
			temp3=kasus[4].sembuh[i];
			temp4=kasus[4].meninggal[i];
			temp5=kasus[4].kasusaktif[i];
			
			strcpy(kasus[4].negara[i], kasus[4].negara[minIdx]);
			kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[minIdx];
			kasus[4].sembuh[i]=kasus[4].sembuh[minIdx];
			kasus[4].meninggal[i]=kasus[4].meninggal[minIdx];
			kasus[4].kasusaktif[i]=kasus[4].kasusaktif[minIdx];
			
			strcpy(kasus[4].negara[minIdx], temp1);
			kasus[4].jumlahkasus[minIdx]=temp2;
			kasus[4].sembuh[minIdx]=temp3;
			kasus[4].meninggal[minIdx]=temp4;
			kasus[4].kasusaktif[minIdx]=temp5;
		}
	}else if(a==5){
		for(i=0;i<(panjang[4]-1);i++){
			//mencari nilai minimum dari sebuah array
			minIdx=i;
			for(j=i+1;j<panjang[4];j++){
				if(kasus[4].kasusaktif[minIdx]>kasus[4].kasusaktif[j]){
					minIdx=j;
				}
			}
			//tukar posisi nilai minimum dengan indeks pertama
			strcpy(temp1, kasus[4].negara[i]);
			temp2=kasus[4].jumlahkasus[i];
			temp3=kasus[4].sembuh[i];
			temp4=kasus[4].meninggal[i];
			temp5=kasus[4].kasusaktif[i];
			
			strcpy(kasus[4].negara[i], kasus[4].negara[minIdx]);
			kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[minIdx];
			kasus[4].sembuh[i]=kasus[4].sembuh[minIdx];
			kasus[4].meninggal[i]=kasus[4].meninggal[minIdx];
			kasus[4].kasusaktif[i]=kasus[4].kasusaktif[minIdx];
			
			strcpy(kasus[4].negara[minIdx], temp1);
			kasus[4].jumlahkasus[minIdx]=temp2;
			kasus[4].sembuh[minIdx]=temp3;
			kasus[4].meninggal[minIdx]=temp4;
			kasus[4].kasusaktif[minIdx]=temp5;
		}
	}
}

void selectionb(int a){//selection descending
	int i, j, minIdx;
	//menampung sementara
	char temp1[100];
	int temp2;
	int temp3;
	int temp4;
	int temp5;
	
	if(a==1){
		for(i=0;i<(panjang[4]-1);i++){
			//mencari nilai minimum dari sebuah array
			minIdx=i;
			for(j=i+1;j<panjang[4];j++){
				if(strcmp(kasus[4].negara[minIdx], kasus[4].negara[j])<0){
					minIdx=j;
				}
			}
			//tukar posisi nilai minimum dengan indeks pertama
			strcpy(temp1, kasus[4].negara[i]);
			temp2=kasus[4].jumlahkasus[i];
			temp3=kasus[4].sembuh[i];
			temp4=kasus[4].meninggal[i];
			temp5=kasus[4].kasusaktif[i];
			
			strcpy(kasus[4].negara[i], kasus[4].negara[minIdx]);
			kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[minIdx];
			kasus[4].sembuh[i]=kasus[4].sembuh[minIdx];
			kasus[4].meninggal[i]=kasus[4].meninggal[minIdx];
			kasus[4].kasusaktif[i]=kasus[4].kasusaktif[minIdx];
			
			strcpy(kasus[4].negara[minIdx], temp1);
			kasus[4].jumlahkasus[minIdx]=temp2;
			kasus[4].sembuh[minIdx]=temp3;
			kasus[4].meninggal[minIdx]=temp4;
			kasus[4].kasusaktif[minIdx]=temp5;
		}		
	}else if(a==2){
		for(i=0;i<(panjang[4]-1);i++){
			//mencari nilai minimum dari sebuah array
			minIdx=i;
			for(j=i+1;j<panjang[4];j++){
				if(kasus[4].jumlahkasus[minIdx]<kasus[4].jumlahkasus[j]){
					minIdx=j;
				}
			}
			//tukar posisi nilai minimum dengan indeks pertama
			strcpy(temp1, kasus[4].negara[i]);
			temp2=kasus[4].jumlahkasus[i];
			temp3=kasus[4].sembuh[i];
			temp4=kasus[4].meninggal[i];
			temp5=kasus[4].kasusaktif[i];
			
			strcpy(kasus[4].negara[i], kasus[4].negara[minIdx]);
			kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[minIdx];
			kasus[4].sembuh[i]=kasus[4].sembuh[minIdx];
			kasus[4].meninggal[i]=kasus[4].meninggal[minIdx];
			kasus[4].kasusaktif[i]=kasus[4].kasusaktif[minIdx];
			
			strcpy(kasus[4].negara[minIdx], temp1);
			kasus[4].jumlahkasus[minIdx]=temp2;
			kasus[4].sembuh[minIdx]=temp3;
			kasus[4].meninggal[minIdx]=temp4;
			kasus[4].kasusaktif[minIdx]=temp5;
		}
	}else if(a==3){
		for(i=0;i<(panjang[4]-1);i++){
			//mencari nilai minimum dari sebuah array
			minIdx=i;
			for(j=i+1;j<panjang[4];j++){
				if(kasus[4].sembuh[minIdx]<kasus[4].sembuh[j]){
					minIdx=j;
				}
			}
			//tukar posisi nilai minimum dengan indeks pertama
			strcpy(temp1, kasus[4].negara[i]);
			temp2=kasus[4].jumlahkasus[i];
			temp3=kasus[4].sembuh[i];
			temp4=kasus[4].meninggal[i];
			temp5=kasus[4].kasusaktif[i];
			
			strcpy(kasus[4].negara[i], kasus[4].negara[minIdx]);
			kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[minIdx];
			kasus[4].sembuh[i]=kasus[4].sembuh[minIdx];
			kasus[4].meninggal[i]=kasus[4].meninggal[minIdx];
			kasus[4].kasusaktif[i]=kasus[4].kasusaktif[minIdx];
			
			strcpy(kasus[4].negara[minIdx], temp1);
			kasus[4].jumlahkasus[minIdx]=temp2;
			kasus[4].sembuh[minIdx]=temp3;
			kasus[4].meninggal[minIdx]=temp4;
			kasus[4].kasusaktif[minIdx]=temp5;
		}
	}else if(a==4){
		for(i=0;i<(panjang[4]-1);i++){
			//mencari nilai minimum dari sebuah array
			minIdx=i;
			for(j=i+1;j<panjang[4];j++){
				if(kasus[4].meninggal[minIdx]<kasus[4].meninggal[j]){
					minIdx=j;
				}
			}
			//tukar posisi nilai minimum dengan indeks pertama
			strcpy(temp1, kasus[4].negara[i]);
			temp2=kasus[4].jumlahkasus[i];
			temp3=kasus[4].sembuh[i];
			temp4=kasus[4].meninggal[i];
			temp5=kasus[4].kasusaktif[i];
			
			strcpy(kasus[4].negara[i], kasus[4].negara[minIdx]);
			kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[minIdx];
			kasus[4].sembuh[i]=kasus[4].sembuh[minIdx];
			kasus[4].meninggal[i]=kasus[4].meninggal[minIdx];
			kasus[4].kasusaktif[i]=kasus[4].kasusaktif[minIdx];
			
			strcpy(kasus[4].negara[minIdx], temp1);
			kasus[4].jumlahkasus[minIdx]=temp2;
			kasus[4].sembuh[minIdx]=temp3;
			kasus[4].meninggal[minIdx]=temp4;
			kasus[4].kasusaktif[minIdx]=temp5;
		}
	}else if(a==5){
		for(i=0;i<(panjang[4]-1);i++){
			//mencari nilai minimum dari sebuah array
			minIdx=i;
			for(j=i+1;j<panjang[4];j++){
				if(kasus[4].kasusaktif[minIdx]<kasus[4].kasusaktif[j]){
					minIdx=j;
				}
			}
			//tukar posisi nilai minimum dengan indeks pertama
			strcpy(temp1, kasus[4].negara[i]);
			temp2=kasus[4].jumlahkasus[i];
			temp3=kasus[4].sembuh[i];
			temp4=kasus[4].meninggal[i];
			temp5=kasus[4].kasusaktif[i];
			
			strcpy(kasus[4].negara[i], kasus[4].negara[minIdx]);
			kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[minIdx];
			kasus[4].sembuh[i]=kasus[4].sembuh[minIdx];
			kasus[4].meninggal[i]=kasus[4].meninggal[minIdx];
			kasus[4].kasusaktif[i]=kasus[4].kasusaktif[minIdx];
			
			strcpy(kasus[4].negara[minIdx], temp1);
			kasus[4].jumlahkasus[minIdx]=temp2;
			kasus[4].sembuh[minIdx]=temp3;
			kasus[4].meninggal[minIdx]=temp4;
			kasus[4].kasusaktif[minIdx]=temp5;
		}
	}
}

void bubblea(int a){//bubble ascending
	int i, pindah;//variabel yang akan digunakan dalam sorting
	char temp1[100];
	int temp2;
	int temp3;
	int temp4;
	int temp5;
	
	if(a==1){
		do{//perulangan untuk mengecek setiap anggota data
			pindah = 0;
			
			for(i=0;i<(panjang[4]-1);i++){
				
				if(strcmp(kasus[4].negara[i], kasus[4].negara[i+1])>0){//proses membandingkan data
					//proses pemindahan data
					strcpy(temp1, kasus[4].negara[i]);
					temp2 = kasus[4].jumlahkasus[i];
					temp3 = kasus[4].sembuh[i];
					temp4 = kasus[4].meninggal[i];
					temp5 = kasus[4].kasusaktif[i];
				
					strcpy(kasus[4].negara[i], kasus[4].negara[i+1]);
					kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[i+1];
					kasus[4].sembuh[i]=kasus[4].sembuh[i+1];
					kasus[4].meninggal[i]=kasus[4].meninggal[i+1];
					kasus[4].kasusaktif[i]=kasus[4].kasusaktif[i+1];
				
					strcpy(kasus[4].negara[i+1], temp1);
					kasus[4].jumlahkasus[i+1]=temp2;
					kasus[4].sembuh[i+1]=temp3;
					kasus[4].meninggal[i+1]=temp4;
					kasus[4].kasusaktif[i+1]=temp5;
				
					pindah =1;
				}	
			}
		}while(pindah==1);
	}else if(a==2){
		do{//perulangan untuk mengecek setiap anggota data
			pindah = 0;
			
			for(i=0;i<(panjang[4]-1);i++){
				
				if(kasus[4].jumlahkasus[i]>kasus[4].jumlahkasus[i+1]){//proses membandingkan data
					//proses pemindahan data
					strcpy(temp1, kasus[4].negara[i]);
					temp2 = kasus[4].jumlahkasus[i];
					temp3 = kasus[4].sembuh[i];
					temp4 = kasus[4].meninggal[i];
					temp5 = kasus[4].kasusaktif[i];
				
					strcpy(kasus[4].negara[i], kasus[4].negara[i+1]);
					kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[i+1];
					kasus[4].sembuh[i]=kasus[4].sembuh[i+1];
					kasus[4].meninggal[i]=kasus[4].meninggal[i+1];
					kasus[4].kasusaktif[i]=kasus[4].kasusaktif[i+1];
				
					strcpy(kasus[4].negara[i+1], temp1);
					kasus[4].jumlahkasus[i+1]=temp2;
					kasus[4].sembuh[i+1]=temp3;
					kasus[4].meninggal[i+1]=temp4;
					kasus[4].kasusaktif[i+1]=temp5;
				
					pindah =1;
				}	
			}
		}while(pindah==1);
	}else if(a==3){
		do{//perulangan untuk mengecek setiap anggota data
			pindah = 0;
			
			for(i=0;i<(panjang[4]-1);i++){
				
				if(kasus[4].sembuh[i]>kasus[4].sembuh[i+1]){//proses membandingkan data
					//proses pemindahan data
					strcpy(temp1, kasus[4].negara[i]);
					temp2 = kasus[4].jumlahkasus[i];
					temp3 = kasus[4].sembuh[i];
					temp4 = kasus[4].meninggal[i];
					temp5 = kasus[4].kasusaktif[i];
				
					strcpy(kasus[4].negara[i], kasus[4].negara[i+1]);
					kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[i+1];
					kasus[4].sembuh[i]=kasus[4].sembuh[i+1];
					kasus[4].meninggal[i]=kasus[4].meninggal[i+1];
					kasus[4].kasusaktif[i]=kasus[4].kasusaktif[i+1];
				
					strcpy(kasus[4].negara[i+1], temp1);
					kasus[4].jumlahkasus[i+1]=temp2;
					kasus[4].sembuh[i+1]=temp3;
					kasus[4].meninggal[i+1]=temp4;
					kasus[4].kasusaktif[i+1]=temp5;
				
					pindah =1;
				}	
			}
		}while(pindah==1);
	}else if(a==4){
		do{//perulangan untuk mengecek setiap anggota data
			pindah = 0;
			
			for(i=0;i<(panjang[4]-1);i++){
				
				if(kasus[4].meninggal[i]>kasus[4].meninggal[i+1]){//proses membandingkan data
					//proses pemindahan data
					strcpy(temp1, kasus[4].negara[i]);
					temp2 = kasus[4].jumlahkasus[i];
					temp3 = kasus[4].sembuh[i];
					temp4 = kasus[4].meninggal[i];
					temp5 = kasus[4].kasusaktif[i];
				
					strcpy(kasus[4].negara[i], kasus[4].negara[i+1]);
					kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[i+1];
					kasus[4].sembuh[i]=kasus[4].sembuh[i+1];
					kasus[4].meninggal[i]=kasus[4].meninggal[i+1];
					kasus[4].kasusaktif[i]=kasus[4].kasusaktif[i+1];
				
					strcpy(kasus[4].negara[i+1], temp1);
					kasus[4].jumlahkasus[i+1]=temp2;
					kasus[4].sembuh[i+1]=temp3;
					kasus[4].meninggal[i+1]=temp4;
					kasus[4].kasusaktif[i+1]=temp5;
				
					pindah =1;
				}	
			}
		}while(pindah==1);
	}else if(a==5){
		do{//perulangan untuk mengecek setiap anggota data
			pindah = 0;
			
			for(i=0;i<(panjang[4]-1);i++){
				
				if(kasus[4].kasusaktif[i]>kasus[4].kasusaktif[i+1]){//proses membandingkan data
					//proses pemindahan data
					strcpy(temp1, kasus[4].negara[i]);
					temp2 = kasus[4].jumlahkasus[i];
					temp3 = kasus[4].sembuh[i];
					temp4 = kasus[4].meninggal[i];
					temp5 = kasus[4].kasusaktif[i];
				
					strcpy(kasus[4].negara[i], kasus[4].negara[i+1]);
					kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[i+1];
					kasus[4].sembuh[i]=kasus[4].sembuh[i+1];
					kasus[4].meninggal[i]=kasus[4].meninggal[i+1];
					kasus[4].kasusaktif[i]=kasus[4].kasusaktif[i+1];
				
					strcpy(kasus[4].negara[i+1], temp1);
					kasus[4].jumlahkasus[i+1]=temp2;
					kasus[4].sembuh[i+1]=temp3;
					kasus[4].meninggal[i+1]=temp4;
					kasus[4].kasusaktif[i+1]=temp5;
				
					pindah =1;
				}	
			}
		}while(pindah==1);
	}
}

void bubbleb(int a){//bubble descending
	int i, pindah;//variabel yang akan digunakan dalam sorting
	char temp1[100];
	int temp2;
	int temp3;
	int temp4;
	int temp5;
	
	if(a==1){
		do{//perulangan untuk mengecek setiap anggota data
			pindah = 0;
			
			for(i=0;i<(panjang[4]-1);i++){
				
				if(strcmp(kasus[4].negara[i], kasus[4].negara[i+1])<0){//proses membandingkan data
					//proses pemindahan data
					strcpy(temp1, kasus[4].negara[i]);
					temp2 = kasus[4].jumlahkasus[i];
					temp3 = kasus[4].sembuh[i];
					temp4 = kasus[4].meninggal[i];
					temp5 = kasus[4].kasusaktif[i];
				
					strcpy(kasus[4].negara[i], kasus[4].negara[i+1]);
					kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[i+1];
					kasus[4].sembuh[i]=kasus[4].sembuh[i+1];
					kasus[4].meninggal[i]=kasus[4].meninggal[i+1];
					kasus[4].kasusaktif[i]=kasus[4].kasusaktif[i+1];
				
					strcpy(kasus[4].negara[i+1], temp1);
					kasus[4].jumlahkasus[i+1]=temp2;
					kasus[4].sembuh[i+1]=temp3;
					kasus[4].meninggal[i+1]=temp4;
					kasus[4].kasusaktif[i+1]=temp5;
				
					pindah =1;
				}	
			}
		}while(pindah==1);
	}else if(a==2){
		do{//perulangan untuk mengecek setiap anggota data
			pindah = 0;
			
			for(i=0;i<(panjang[4]-1);i++){
				
				if(kasus[4].jumlahkasus[i]<kasus[4].jumlahkasus[i+1]){//proses membandingkan data
					//proses pemindahan data
					strcpy(temp1, kasus[4].negara[i]);
					temp2 = kasus[4].jumlahkasus[i];
					temp3 = kasus[4].sembuh[i];
					temp4 = kasus[4].meninggal[i];
					temp5 = kasus[4].kasusaktif[i];
				
					strcpy(kasus[4].negara[i], kasus[4].negara[i+1]);
					kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[i+1];
					kasus[4].sembuh[i]=kasus[4].sembuh[i+1];
					kasus[4].meninggal[i]=kasus[4].meninggal[i+1];
					kasus[4].kasusaktif[i]=kasus[4].kasusaktif[i+1];
				
					strcpy(kasus[4].negara[i+1], temp1);
					kasus[4].jumlahkasus[i+1]=temp2;
					kasus[4].sembuh[i+1]=temp3;
					kasus[4].meninggal[i+1]=temp4;
					kasus[4].kasusaktif[i+1]=temp5;
				
					pindah =1;
				}	
			}
		}while(pindah==1);
	}else if(a==3){
		do{//perulangan untuk mengecek setiap anggota data
			pindah = 0;
			
			for(i=0;i<(panjang[4]-1);i++){
				
				if(kasus[4].sembuh[i]<kasus[4].sembuh[i+1]){//proses membandingkan data
					//proses pemindahan data
					strcpy(temp1, kasus[4].negara[i]);
					temp2 = kasus[4].jumlahkasus[i];
					temp3 = kasus[4].sembuh[i];
					temp4 = kasus[4].meninggal[i];
					temp5 = kasus[4].kasusaktif[i];
				
					strcpy(kasus[4].negara[i], kasus[4].negara[i+1]);
					kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[i+1];
					kasus[4].sembuh[i]=kasus[4].sembuh[i+1];
					kasus[4].meninggal[i]=kasus[4].meninggal[i+1];
					kasus[4].kasusaktif[i]=kasus[4].kasusaktif[i+1];
				
					strcpy(kasus[4].negara[i+1], temp1);
					kasus[4].jumlahkasus[i+1]=temp2;
					kasus[4].sembuh[i+1]=temp3;
					kasus[4].meninggal[i+1]=temp4;
					kasus[4].kasusaktif[i+1]=temp5;
				
					pindah =1;
				}	
			}
		}while(pindah==1);
	}else if(a==4){
		do{//perulangan untuk mengecek setiap anggota data
			pindah = 0;
			
			for(i=0;i<(panjang[4]-1);i++){
				
				if(kasus[4].meninggal[i]<kasus[4].meninggal[i+1]){//proses membandingkan data
					//proses pemindahan data
					strcpy(temp1, kasus[4].negara[i]);
					temp2 = kasus[4].jumlahkasus[i];
					temp3 = kasus[4].sembuh[i];
					temp4 = kasus[4].meninggal[i];
					temp5 = kasus[4].kasusaktif[i];
				
					strcpy(kasus[4].negara[i], kasus[4].negara[i+1]);
					kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[i+1];
					kasus[4].sembuh[i]=kasus[4].sembuh[i+1];
					kasus[4].meninggal[i]=kasus[4].meninggal[i+1];
					kasus[4].kasusaktif[i]=kasus[4].kasusaktif[i+1];
				
					strcpy(kasus[4].negara[i+1], temp1);
					kasus[4].jumlahkasus[i+1]=temp2;
					kasus[4].sembuh[i+1]=temp3;
					kasus[4].meninggal[i+1]=temp4;
					kasus[4].kasusaktif[i+1]=temp5;
				
					pindah =1;
				}	
			}
		}while(pindah==1);
	}else if(a==5){
		do{//perulangan untuk mengecek setiap anggota data
			pindah = 0;
			
			for(i=0;i<(panjang[4]-1);i++){
				
				if(kasus[4].kasusaktif[i]<kasus[4].kasusaktif[i+1]){//proses membandingkan data
					//proses pemindahan data
					strcpy(temp1, kasus[4].negara[i]);
					temp2 = kasus[4].jumlahkasus[i];
					temp3 = kasus[4].sembuh[i];
					temp4 = kasus[4].meninggal[i];
					temp5 = kasus[4].kasusaktif[i];
				
					strcpy(kasus[4].negara[i], kasus[4].negara[i+1]);
					kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[i+1];
					kasus[4].sembuh[i]=kasus[4].sembuh[i+1];
					kasus[4].meninggal[i]=kasus[4].meninggal[i+1];
					kasus[4].kasusaktif[i]=kasus[4].kasusaktif[i+1];
				
					strcpy(kasus[4].negara[i+1], temp1);
					kasus[4].jumlahkasus[i+1]=temp2;
					kasus[4].sembuh[i+1]=temp3;
					kasus[4].meninggal[i+1]=temp4;
					kasus[4].kasusaktif[i+1]=temp5;
				
					pindah =1;
				}	
			}
		}while(pindah==1);
	}
}

void quicka(int a, int kiri, int kanan){//quick ascending
	int i, j;
	char temp1[100];
	int temp2;
	int temp3;
	int temp4;
	int temp5;
	i=kiri;
	j=kanan;
	
	if(a==1){
		do{
			
			while((strcmp(kasus[4].negara[i], kasus[4].negara[kanan])<0)&&(i<=j)){
				i++;
			}
			while((strcmp(kasus[4].negara[j], kasus[4].negara[kiri])>0)&&(i<=j)){
				j--;
			}
			
			if(i<j){
				strcpy(temp1, kasus[4].negara[i]);
				temp2 = kasus[4].jumlahkasus[i];
				temp3 = kasus[4].sembuh[i];
				temp4 = kasus[4].meninggal[i];
				temp5 = kasus[4].kasusaktif[i];
				
				strcpy(kasus[4].negara[i], kasus[4].negara[j]);
				kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[j];
				kasus[4].sembuh[i]=kasus[4].sembuh[j];
				kasus[4].meninggal[i]=kasus[4].meninggal[j];
				kasus[4].kasusaktif[i]=kasus[4].kasusaktif[j];
				
				strcpy(kasus[4].negara[j], temp1);
				kasus[4].jumlahkasus[j]=temp2;
				kasus[4].sembuh[j]=temp3;
				kasus[4].meninggal[j]=temp4;
				kasus[4].kasusaktif[j]=temp5;
			
				i++;
				j--;
			}
		}while(i<j);
	
		if(kiri<j){
			quicka(a, kiri, j);
		}
		if(i<kanan){
			quicka(a, i, kanan);
		}
	}else if(a==2){
		do{
			while((kasus[4].jumlahkasus[i]<kasus[4].jumlahkasus[kanan])&&(i<=j)){
				i++;
			}
			while((kasus[4].jumlahkasus[j]>kasus[4].jumlahkasus[kiri])&&(i<=j)){
				j--;
			}
			
			if(i<j){
				strcpy(temp1, kasus[4].negara[i]);
				temp2 = kasus[4].jumlahkasus[i];
				temp3 = kasus[4].sembuh[i];
				temp4 = kasus[4].meninggal[i];
				temp5 = kasus[4].kasusaktif[i];
				
				strcpy(kasus[4].negara[i], kasus[4].negara[j]);
				kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[j];
				kasus[4].sembuh[i]=kasus[4].sembuh[j];
				kasus[4].meninggal[i]=kasus[4].meninggal[j];
				kasus[4].kasusaktif[i]=kasus[4].kasusaktif[j];
				
				strcpy(kasus[4].negara[j], temp1);
				kasus[4].jumlahkasus[j]=temp2;
				kasus[4].sembuh[j]=temp3;
				kasus[4].meninggal[j]=temp4;
				kasus[4].kasusaktif[j]=temp5;
			
				i++;
				j--;
			}
		}while(i<j);
	
		if(kiri<j){
			quicka(a, kiri, j);
		}
		if(i<kanan){
			quicka(a, i, kanan);
		}
	}else if(a==3){
		do{
			while((kasus[4].sembuh[i]<kasus[4].sembuh[kanan])&&(i<=j)){
				i++;
			}
			while((kasus[4].sembuh[j]>kasus[4].sembuh[kiri])&&(i<=j)){
				j--;
			}
			
			if(i<j){
				strcpy(temp1, kasus[4].negara[i]);
				temp2 = kasus[4].jumlahkasus[i];
				temp3 = kasus[4].sembuh[i];
				temp4 = kasus[4].meninggal[i];
				temp5 = kasus[4].kasusaktif[i];
				
				strcpy(kasus[4].negara[i], kasus[4].negara[j]);
				kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[j];
				kasus[4].sembuh[i]=kasus[4].sembuh[j];
				kasus[4].meninggal[i]=kasus[4].meninggal[j];
				kasus[4].kasusaktif[i]=kasus[4].kasusaktif[j];
				
				strcpy(kasus[4].negara[j], temp1);
				kasus[4].jumlahkasus[j]=temp2;
				kasus[4].sembuh[j]=temp3;
				kasus[4].meninggal[j]=temp4;
				kasus[4].kasusaktif[j]=temp5;
			
				i++;
				j--;
			}
		}while(i<j);
	
		if(kiri<j){
			quicka(a, kiri, j);
		}
		if(i<kanan){
			quicka(a, i, kanan);
		}
	}else if(a==4){
		do{
			while((kasus[4].meninggal[i]<kasus[4].meninggal[kanan])&&(i<=j)){
				i++;
			}
			while((kasus[4].meninggal[j]>kasus[4].meninggal[kiri])&&(i<=j)){
				j--;
			}
			
			if(i<j){
				strcpy(temp1, kasus[4].negara[i]);
				temp2 = kasus[4].jumlahkasus[i];
				temp3 = kasus[4].sembuh[i];
				temp4 = kasus[4].meninggal[i];
				temp5 = kasus[4].kasusaktif[i];
				
				strcpy(kasus[4].negara[i], kasus[4].negara[j]);
				kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[j];
				kasus[4].sembuh[i]=kasus[4].sembuh[j];
				kasus[4].meninggal[i]=kasus[4].meninggal[j];
				kasus[4].kasusaktif[i]=kasus[4].kasusaktif[j];
				
				strcpy(kasus[4].negara[j], temp1);
				kasus[4].jumlahkasus[j]=temp2;
				kasus[4].sembuh[j]=temp3;
				kasus[4].meninggal[j]=temp4;
				kasus[4].kasusaktif[j]=temp5;
			
				i++;
				j--;
			}
		}while(i<j);
	
		if(kiri<j){
			quicka(a, kiri, j);
		}
		if(i<kanan){
			quicka(a, i, kanan);
		}
	}else if(a==5){
		do{
			while((kasus[4].kasusaktif[i]<kasus[4].kasusaktif[kanan])&&(i<=j)){
				i++;
			}
			while((kasus[4].kasusaktif[j]>kasus[4].kasusaktif[kiri])&&(i<=j)){
				j--;
			}
			
			if(i<j){
				strcpy(temp1, kasus[4].negara[i]);
				temp2 = kasus[4].jumlahkasus[i];
				temp3 = kasus[4].sembuh[i];
				temp4 = kasus[4].meninggal[i];
				temp5 = kasus[4].kasusaktif[i];
				
				strcpy(kasus[4].negara[i], kasus[4].negara[j]);
				kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[j];
				kasus[4].sembuh[i]=kasus[4].sembuh[j];
				kasus[4].meninggal[i]=kasus[4].meninggal[j];
				kasus[4].kasusaktif[i]=kasus[4].kasusaktif[j];
				
				strcpy(kasus[4].negara[j], temp1);
				kasus[4].jumlahkasus[j]=temp2;
				kasus[4].sembuh[j]=temp3;
				kasus[4].meninggal[j]=temp4;
				kasus[4].kasusaktif[j]=temp5;
			
				i++;
				j--;
			}
		}while(i<j);
	
		if(kiri<j){
			quicka(a, kiri, j);
		}
		if(i<kanan){
			quicka(a, i, kanan);
		}
	}
}

void quickb(int a, int kiri, int kanan){//quick descending
	int i, j;
	char temp1[100];
	int temp2;
	int temp3;
	int temp4;
	int temp5;
	int p;
	char p2[100];
	i=kiri;
	j=kanan;

	
	if(a==1){
		strcpy(p2, kasus[4].negara[kiri+((kanan-kiri)/2)]);
		do{
			while((strcmp(kasus[4].negara[i], p2)>0)&&(i<=j)){
				i++;
			}
			while((strcmp(kasus[4].negara[j], p2)<0)&&(i<=j)){
				j--;
			}
			
			if(i<=j){
				strcpy(temp1, kasus[4].negara[i]);
				temp2 = kasus[4].jumlahkasus[i];
				temp3 = kasus[4].sembuh[i];
				temp4 = kasus[4].meninggal[i];
				temp5 = kasus[4].kasusaktif[i];
				
				strcpy(kasus[4].negara[i], kasus[4].negara[j]);
				kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[j];
				kasus[4].sembuh[i]=kasus[4].sembuh[j];
				kasus[4].meninggal[i]=kasus[4].meninggal[j];
				kasus[4].kasusaktif[i]=kasus[4].kasusaktif[j];
				
				strcpy(kasus[4].negara[j], temp1);
				kasus[4].jumlahkasus[j]=temp2;
				kasus[4].sembuh[j]=temp3;
				kasus[4].meninggal[j]=temp4;
				kasus[4].kasusaktif[j]=temp5;
			
				i++;
				j--;
			}
		}while(i<=j);
	
		if(kiri<j){
			quickb(a, kiri, j);
		}
		if(i<kanan){
			quickb(a, i, kanan);
		}
	}else if(a==2){
		p=kasus[4].jumlahkasus[kiri+((kanan-kiri)/2)];
		do{
			while((kasus[4].jumlahkasus[i]>p)&&(i<=j)){
				i++;
			}
			while((kasus[4].jumlahkasus[j]<p)&&(i<=j)){
				j--;
			}
			
			if(i<=j){
				strcpy(temp1, kasus[4].negara[i]);
				temp2 = kasus[4].jumlahkasus[i];
				temp3 = kasus[4].sembuh[i];
				temp4 = kasus[4].meninggal[i];
				temp5 = kasus[4].kasusaktif[i];
				
				strcpy(kasus[4].negara[i], kasus[4].negara[j]);
				kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[j];
				kasus[4].sembuh[i]=kasus[4].sembuh[j];
				kasus[4].meninggal[i]=kasus[4].meninggal[j];
				kasus[4].kasusaktif[i]=kasus[4].kasusaktif[j];
				
				strcpy(kasus[4].negara[j], temp1);
				kasus[4].jumlahkasus[j]=temp2;
				kasus[4].sembuh[j]=temp3;
				kasus[4].meninggal[j]=temp4;
				kasus[4].kasusaktif[j]=temp5;
			
				i++;
				j--;
			}
		}while(i<=j);
	
		if(kiri<j){
			quickb(a, kiri, j);
		}
		if(i<kanan){
			quickb(a, i, kanan);
		}
	}else if(a==3){
		p=kasus[4].sembuh[kiri+((kanan-kiri)/2)];
		do{
			while((kasus[4].sembuh[i]>p)&&(i<=j)){
				i++;
			}
			while((kasus[4].sembuh[j]<p)&&(i<=j)){
				j--;
			}
			
			if(i<=j){
				strcpy(temp1, kasus[4].negara[i]);
				temp2 = kasus[4].jumlahkasus[i];
				temp3 = kasus[4].sembuh[i];
				temp4 = kasus[4].meninggal[i];
				temp5 = kasus[4].kasusaktif[i];
				
				strcpy(kasus[4].negara[i], kasus[4].negara[j]);
				kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[j];
				kasus[4].sembuh[i]=kasus[4].sembuh[j];
				kasus[4].meninggal[i]=kasus[4].meninggal[j];
				kasus[4].kasusaktif[i]=kasus[4].kasusaktif[j];
				
				strcpy(kasus[4].negara[j], temp1);
				kasus[4].jumlahkasus[j]=temp2;
				kasus[4].sembuh[j]=temp3;
				kasus[4].meninggal[j]=temp4;
				kasus[4].kasusaktif[j]=temp5;
			
				i++;
				j--;
			}
		}while(i<=j);
	
		if(kiri<j){
			quickb(a, kiri, j);
		}
		if(i<kanan){
			quickb(a, i, kanan);
		}
	}else if(a==4){
		p=kasus[4].meninggal[kiri+((kanan-kiri)/2)];
		do{
			while((kasus[4].meninggal[i]>p)&&(i<=j)){
				i++;
			}
			while((kasus[4].meninggal[j]<p)&&(i<=j)){
				j--;
			}
			
			if(i<=j){
				strcpy(temp1, kasus[4].negara[i]);
				temp2 = kasus[4].jumlahkasus[i];
				temp3 = kasus[4].sembuh[i];
				temp4 = kasus[4].meninggal[i];
				temp5 = kasus[4].kasusaktif[i];
				
				strcpy(kasus[4].negara[i], kasus[4].negara[j]);
				kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[j];
				kasus[4].sembuh[i]=kasus[4].sembuh[j];
				kasus[4].meninggal[i]=kasus[4].meninggal[j];
				kasus[4].kasusaktif[i]=kasus[4].kasusaktif[j];
				
				strcpy(kasus[4].negara[j], temp1);
				kasus[4].jumlahkasus[j]=temp2;
				kasus[4].sembuh[j]=temp3;
				kasus[4].meninggal[j]=temp4;
				kasus[4].kasusaktif[j]=temp5;
			
				i++;
				j--;
			}
		}while(i<=j);
	
		if(kiri<j){
			quickb(a, kiri, j);
		}
		if(i<kanan){
			quickb(a, i, kanan);
		}
	}else if(a==5){
		p=kasus[4].kasusaktif[kiri+((kanan-kiri)/2)];
		do{
			while((kasus[4].kasusaktif[i]>p)&&(i<=j)){
				i++;
			}
			while((kasus[4].kasusaktif[j]<p)&&(i<=j)){
				j--;
			}
			
			if(i<=j){
				strcpy(temp1, kasus[4].negara[i]);
				temp2 = kasus[4].jumlahkasus[i];
				temp3 = kasus[4].sembuh[i];
				temp4 = kasus[4].meninggal[i];
				temp5 = kasus[4].kasusaktif[i];
				
				strcpy(kasus[4].negara[i], kasus[4].negara[j]);
				kasus[4].jumlahkasus[i]=kasus[4].jumlahkasus[j];
				kasus[4].sembuh[i]=kasus[4].sembuh[j];
				kasus[4].meninggal[i]=kasus[4].meninggal[j];
				kasus[4].kasusaktif[i]=kasus[4].kasusaktif[j];
				
				strcpy(kasus[4].negara[j], temp1);
				kasus[4].jumlahkasus[j]=temp2;
				kasus[4].sembuh[j]=temp3;
				kasus[4].meninggal[j]=temp4;
				kasus[4].kasusaktif[j]=temp5;
			
				i++;
				j--;
			}
		}while(i<=j);
	
		if(kiri<j){
			quickb(a, kiri, j);
		}
		if(i<kanan){
			quickb(a, i, kanan);
		}
	}
}

void cariaktif(){//nyari jumlah kasus aktif di tiap negara
	int i;
	
	for(i=0;i<panjang[4];i++){
		kasus[4].kasusaktif[i]=kasus[4].jumlahkasus[i]-kasus[4].sembuh[i]-kasus[4].meninggal[i];
	}
	
}

void cetak(){//cetak outputnya
	int i;//iterator
	//buat totalnya
	int total1=0;
	int total2=0;
	int total3=0;
	int total4=0;
	
	for(i=0;i<panjang[4];i++){//nyari totalnya
		total1=total1+kasus[4].jumlahkasus[i];
		total2=total2+kasus[4].sembuh[i];
		total3=total3+kasus[4].meninggal[i];
		total4=total4+kasus[4].kasusaktif[i];
	}
	
	printf("Data Corona Virus di Beberapa Negara:\n");
	for(i=0;i<panjang[4];i++){
		printf("%s %d %d %d %d\n", kasus[4].negara[i], kasus[4].jumlahkasus[i], kasus[4].sembuh[i], kasus[4].meninggal[i], kasus[4].kasusaktif[i]);
	}
	printf("Total: %d %d %d %d\n", total1, total2, total3, total4);
	
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Evaluasi 6 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/