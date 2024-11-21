#include <stdio.h>
#include <string.h>

int indeks;
int panjang;
char kata[50];

void startKata(char pita[]);
void resetKata();
void incKata(char pita[]);
char* getKata();
int getPanjang();
int eopKata(char pita[]);
int vokal3();
int palindrom();