#include "tp3.h"

void fibbonaci(int n,int b,int i,int batas){
	if(i == 0){
		arr[i] = n;
		fibbonaci(n,b,i+1,batas);
	}else if(i < batas){
		arr[i] = arr[i - 1] + b;
		b = arr[i];
		fibbonaci(n,b,i+1,batas);
	}
}
void input(){
	scanf("%d%d",&n,&b);
	scanf("%d%d",&x,&y);
	int i,j;
	for(i = 0;i < x;i++){
		for(j = 0;j < y;j++){
			scanf("%d",&pembanding.matriks[i][j]);
		}
	}
	fibbonaci(n,b,0,(n*y));
}

void pisah(){
	int i,j;
	int a = 0;
	for(i = 0;i < x;i++){
		for(j = 0;j < y;j++){
			asli.matriks[i][j] = arr[a];
			a++;
		}
	}
}

void output(){
	pisah();
	int i,j;
	printf("Matriks Fibonacci:\n");
	for(i = 0;i < x;i++){
		for(j = 0;j < y;j++){
			if(j == y-1){
				printf("%d\n",asli.matriks[i][j]);
			}else{
				printf("%d ",asli.matriks[i][j]);
			}
		}
	}
	printf("\nMatriks Pembanding:\n");
	for(i = 0;i < x;i++){
		for(j = 0;j < y;j++){
			if(asli.matriks[i][j] >= pembanding.matriks[i][j]){
				printf(":D");
			}else{
				printf("D:");
			}
			if(j == y-1){
				printf("\n");
			}else{
				printf(" ");
			}
		}
	}

}