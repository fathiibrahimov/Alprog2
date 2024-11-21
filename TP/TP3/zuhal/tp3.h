#include <stdio.h>

typedef struct {
	int matriks[100][100];
}apa;

int arr[200];
apa pembanding;
apa asli;
int n,b,x,y;
void fibbonaci(int n,int b,int i,int batas);
void input();
void pisah();
void output();