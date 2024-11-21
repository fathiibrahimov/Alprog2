#include "anci19.h"

void masuk(){//minta masukan user
	//iterator
	int i;
	int j;
	
	//minta terus
	scanf("%d", &n);
	scanf("%d", &b);
	scanf("%d %d", &x, &y);
	
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			scanf("%d", &matbanding[i][j]);
		}
	}
}

void nambah(){//rekursifnya disini *harusnya/kayanya
	//sengaja pakai array dulu biar gampang, baru dimasukin ke matriks kemudian
	if(c==0){//jika posisi masih diawal maka langsung masukin n
		tampung[c]=n;
		c++;
	}else{//jika posisinya udah ga diawal lagi langsung aja masukin sesuai ketentuan
		tampung[c]=tampung[c-1]+b;
		b=tampung[c-1]+b;
		c++;
	}
	if(c<(x*y)){//jika belum selesai lanjut manggil lagi, disini rekursifnya
		nambah();
	}
}

void fibonacci(){//prosedur buat manggil prosedur lain
	int i, j, k=0;//iterator
	masuk();//manggil prosedur masuk
	c=0;//ini dua variabel diset nol biar sesuai dengan prosedur nambah
	d=0;
	nambah();//manggil prosedur nambah
	
	//nah ini mindahin isi array ke matriks
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			matfibo[i][j]=tampung[k];
			k++;
		}
	}
	
	banding();//manggil prosedur banding
	cetak();//manggil prosedur cetak
	
}

void banding(){//prosedur buat bandingin dua matriks
	//iterator
	int i;
	int j;
	
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			if(matfibo[i][j]>=matbanding[i][j]){//jika lebih besar nilai di matriks output 1
				matoutput[i][j]=1;
			}else{
				matoutput[i][j]=2;//jika lebih kecil nilainya 2
			}
		}
	}
}

void cetak(){//prosedur buat nyetak output
	//iterator
	int i;
	int j;
	
	//mulai mencetak matriks fibonacci
	printf("Matriks Fibonacci:\n");
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			printf("%d", matfibo[i][j]);
			if(j<y-1){
				printf(" ");
			}
		}
		printf("\n");
	}
	
	//mencetak matriks pembanding, jika nilai di matriks output 1 maka keluar :D, jika 2 maka keluar D:
	printf("\nMatriks Pembanding:\n");
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			if(matoutput[i][j]==1){
				printf(":D");
			}else if(matoutput[i][j]==2){
				printf("D:");
			}
			if(j<y-1){
				printf(" ");
			}
		}
		printf("\n");
	}
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Evaluasi 3 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/