#include "rekbd20.h"

void masuk(){//meminta masukan user
	scanf("%d", &n);//meminta awal deret
	scanf("%d", &p);//meminta panjang deret	
}

void deret(){//membuat deret
	if(n!=0 && p>0){
		printf("%d", n);//mencetak deret per deret
		if(p>1){//jika deret belum selesai print spasi
			printf(" ");
		}
		n=n/2;//membagi deret sebelumnya dengan 2
		p--;//mengurangi baris deret supaya tidak berlebihan deretnya
		deret();//memanggil prosedur kembali
	}else if(n==0){//jika deret 0
		printf("0\n");
	}else{//jika deret tidak mencapai 0
		printf("\n");
	}
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi QUIZ 1 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/