#include <stdio.h>
#include <string.h>
/*saya adhi susetyo mengerjakan evaluasi MABUK19 dalam mata kuliah alpro 2 untuk keberkahanNya maka 
    saya tidak melakukan kecuragan sperti yang telah dispesifikasikan. Aamin.*/

typedef struct{
    int gaji;
    char nama[50];
    char kerja[50];
}input;

input job[50][50];

int y;//banyaknya kerja yang diganti
int a;
int b;
char masuktukar[50][50];

void masukkan();
void pisah();
void output();
