#include "header.h"
void input(){
	int i;
	int j;
	int n, b;
	scanf("%d", &n);
	scanf("%d", &b);
	scanf("%d", &x);
	scanf("%d", &y);
	for(i = 0; i < x; i++){
		for(j = 0; j < y; j++){
			scanf("%d", &pembanding[i][j]);
		}
	}
	int indeks = x*y;
	//fib(n, b, indeks);
	output(n, b, indeks);
}
int fib(int n, int b, int indeks){

	if(indeks == 0){
		arr[indeks] = n;
		return arr[indeks];
	}if(indeks == 1){
		arr[indeks] = fib(n, b, indeks-1) + b;
		return arr[indeks];
	}else{
		arr[indeks] = fib(n, b, indeks-1) + fib(n, b, indeks-1);
		return arr[indeks];
	}
}
void baru(int n, int b, int indeks){
	int i;
	int j;
	int k=0;
	for(i = 0; i < x; i++){
		for(j = 0; j < y; j++){
			newmatriks[i][j] = arr[k];
			k++;
		}
	}
}
void output(int n, int b, int indeks){
	fib(n, b, indeks);
	baru(n, b, indeks);
	int i;
	int j;
	printf("Matriks Fibonacci:\n");
	for(i = 0; i < x; i++){
		for(j = 0; j <y; j++){
			printf("%d",newmatriks[i][j]);
			if(j <  y-1){
				printf(" ");
			}
		}printf("\n");
	}
	printf("\nMatriks Pembanding:\n");
	for(i = 0 ; i< x; i++){
		for(j = 0; j < y; j++){
			if(newmatriks[i][j] >= pembanding[i][j]){
				printf(":D");
			}else{
				printf("D:");
			}
			if(j < y-1){
				printf(" ");
			}
		}printf("\n");
	}
}