#include <stdio.h>;
typedef struct{
	int red;
	int green;
	int blue;
}piksel;

int main(){
	int baris;
	int kolom;
	
	printf("masukkan banyaknya baris\n");
	scanf("%d", &baris);
	
	printf("masukkan banyaknya kolom\n");
	scanf("%d", &kolom);
	
	piksel arr[baris][kolom];
	
	int b;
	int k;
	for(b=0;b<baris;b++){
		for(k=0;k<kolom;k++){
			arr[b][k].red=255;
			arr[b][k].green=255;
			arr[b][k].blue=255;
		}
	}
	
	arr[0][1].red=0;
	arr[0][1].green=255;
	arr[0][1].blue=0;
	
	for(b=0;b<baris;b++){
		for(k=0;k<kolom;k++){
			if((arr[b][k].red==225)&&(arr[b][k].green==225)&&(arr[b][k].blue==225)){
				printf(" putih ");
			}
		
			else if((arr[b][k].red==0)&&(arr[b][k].green==225)&&(arr[b][k].blue==0)){
				printf(" hijau ");
			}
		}
		printf("\n");
	}
	
	
	return 0;
}