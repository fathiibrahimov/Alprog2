#include "eval.h"

void masuk(){
	char tanda;
	int i;
	
	scanf(" %c", &tanda);
	if(tanda=='K'){
		scanf("%d", &n);
		for(i=0;i<n;i++){
			scanf("%d", &k[i]);
		}
		scanf(" %c", &tanda);
		if(tanda=='B'){
			scanf("%d", &m);
			for(i=0;i<m;i++){
				scanf("%d", &b[i]);
			}
		}
	}else if(tanda=='B'){
		scanf("%d", &m);
		for(i=0;i<m;i++){
			scanf("%d", &b[i]);
		}
		scanf(" %c", &tanda);
		if(tanda=='K'){
			scanf("%d", &n);
			for(i=0;i<n;i++){
				scanf("%d", &k[i]);
			}
		}
	}
	
}

void proses(){
	int i;
	int j;
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			matmat[i][j]=carifpb(k[i], b[j]);
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d\n", matmat[j][i]);
		}
	}
}

int carifpb(int n1, int n2){
    if (n2 != 0)
        return carifpb(n2, n1 % n2);
    else
        return n1;
}


/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Kompetisi Latihan Alpro 2 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/