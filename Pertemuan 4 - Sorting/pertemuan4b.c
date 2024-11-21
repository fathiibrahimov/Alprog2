#include <stdio.h>

typedef struct{
	int pembilang;
	int penyebut;
}pecahan;

int main(){
	int i;
	int j;
	int n;
	int tempg;
	int tempt;
	
	printf("Masukkan panjang array : ");
	scanf("%d", &n);
	
	pecahan satu[n];
	
	for(i=0;i<n;i++){
		printf("Masukkan pembilang ke %d : ", i);
		scanf("%d", &satu[i].pembilang);
		printf("Masukkan penyebut ke %d : ", i);
		scanf("%d", &satu[i].penyebut);
	}
	
	for(i=1;i<n;i++){
		tempg=satu[i].pembilang;
		tempt=satu[i].penyebut;
		j=i-1;
		
		while((tempg<satu[j].pembilang)&&(j>=0)){
			satu[j+1].pembilang=satu[j].pembilang;
			satu[j+1].penyebut=satu[j].penyebut;
			j-j-1;
			
		}
		satu[j+1].pembilang=tempg;
		satu[j+1].penyebut=tempt;
	}
	
	
	return 0;
}