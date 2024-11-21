#include "bbm19.h"

void masuk(){//minta masukan disini
	int i;//iterator
	
	scanf("%s", tipe);
	scanf("%d %d", &am, &bm);
	
	ab=am*bm;
	for(i=0;i<ab;i++){
		scanf("%s %d", nama[i], &tinggi[i]);
	}
}

void carisort(){//cari sortingan disini
	if(strcmp(tipe, "bubble")==0){
		bubble();//panggil bubble
	}else if(strcmp(tipe, "quick")==0){
		quick(0, ab-1);//panggil quick
	}
	
}

void bubble(){//sorting bubble disini
	int i, tempt, pindah;//variabel yang akan digunakan dalam sorting
	char tempn[50];
	
	do{//perulangan untuk mengecek setiap anggota data
		pindah = 0;
		
		for(i=0;i<(ab-1);i++){
			/*perulangan untuk mengecek data yang dipilih terhadap data yang
			*/
			if(tinggi[i]<tinggi[i+1]){//proses membandingkan data
				//proses pemindahan data
				tempt = tinggi[i];
				strcpy(tempn, nama[i]);
				tinggi[i]=tinggi[i+1];
				strcpy(nama[i], nama[i+1]);
				tinggi[i+1]=tempt;
				strcpy(nama[i+1], tempn);
				pindah =1;
			}
			
		}
	}while(pindah==1);
}

void quick(int kiri, int kanan){//sorting quick disini
	int i, j, tempt;
	char tempn[50];
	
	i=kiri;
	j=kanan;
	
	int p=tinggi[kiri+((kanan-kiri)/2)];//hasil liat quora, karena kodingannya ga bisa
	/*ini pseudo codenya
	    I=low
		J=high
		Partition= a[low+floor((high-low)/2)
		Do while I<=j {
			While a[I]>parition {
				I++
			}
			While a[j]<partition {
			J--
			}
		If I<=j {
			Swap a[],I,j
			I++
			J--
		}
	*/
	do{
		while((tinggi[i]>p)&&(i<=j)){
			i++;
		}
		while((tinggi[j]<p)&&(i<=j)){
			j--;
		}
		
		if(i<=j){
			tempt = tinggi[i];
			strcpy(tempn, nama[i]);
			tinggi[i]=tinggi[j];
			strcpy(nama[i], nama[j]);
			tinggi[j]=tempt;
			strcpy(nama[j], tempn);
			i++;
			j--;
		}
	}while(i<=j);
	
	if(kiri<j){
		quick(kiri, j);
	}
	if(i<kanan){
		quick(i, kanan);
	}
}

void lkbb(){//masukin orang ke barisan
	//iterator
	int i;
	int j;
	int k=0;
	
	for(i=0;i<am;i++){//skuy baris
		//biar bisa kaya uler maka dibagi ganjil genap
		if(i%2==0){
			for(j=0;j<bm;j++){
				strcpy(bb[i][j].namab, nama[k]);
				k++;
			}
		}else{
			for(j=bm-1;j>=0;j--){
				strcpy(bb[i][j].namab, nama[k]);
				k++;
			}
		}
	}
}

void carispasi(){//cari spasi disini
	int i;
	int j;
	int max=0;
	int k=0;
	int barismax[50];
	
	for(j=0;j<bm;j++){//cari nama terpanjang tiap baris
		for(i=0;i<am;i++){
			if(strlen(bb[i][j].namab)>max){
				max=strlen(bb[i][j].namab);
			}
		}
		barismax[j]=max;
		max=0;
	}
	
	for(i=0;i<am;i++){//liat butuh berapa spasi
		for(j=0;j<bm;j++){
			if(j!=bm-1){
				bb[i][j].tinggib=(barismax[j]-strlen(bb[i][j].namab))+2;
			}else{
				barismax[j]=0;
			}
		}
	}
	
	/*
	printf("spasi:\n");
	for(i=0;i<am;i++){
		for(j=0;j<bm;j++){
			printf("%d ", bb[i][j].tinggib);
		}
		printf("\n");
	}
	*/
}

void cetak(){//cetak disini
	int i;
	int j;
	int k=0;

	for(i=0;i<am;i++){
		for(j=0;j<bm;j++){
			printf("%s", bb[i][j].namab);
			for(k=0;k<bb[i][j].tinggib;k++){
				printf(" ");
			}
		}
		printf("\n");
	}
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Evaluasi 5 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/