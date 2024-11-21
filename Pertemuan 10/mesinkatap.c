#include "mesinkatap.h"

void startKata(char pita[]){
	indeks = 0;
	panjang = 0;
	while(pita[indeks] == ' '){
		indeks++;
	}
	while((pita[indeks] != ' ') && (pita[indeks] != '.')){
		kata[panjang] = pita[indeks];
		indeks++;
		panjang++;
	}
	kata[panjang] = '\0';
}


void resetKata(){
	panjang = 0;
	kata[panjang] = '\0';
}

void incKata(char pita[]){
	panjang = 0;
	while(pita[indeks] == ' '){
		indeks++;
	}
	while((pita[indeks] != ' ') && (pita[indeks] != '.')){
		kata[panjang] = pita[indeks];
		indeks++;
		panjang++;
	}
	kata[panjang] = '\0';
}

char* getKata(){
	return kata;
}

int getPanjang(){
	return panjang;
}

int eopKata(char pita[]){
	if(pita[indeks] == '.'){
		return 1;
	}else{
		return 0;
	}
}

int vokal3(){
	int i;
	int jvokal = 0;
	int lenkata = getPanjang();
	for(i=0; i<lenkata; i++){
		if(kata[i] == 'a' || kata[i] == 'i' || kata[i] == 'u' || kata[i] == 'e' || kata[i] == 'o' || kata[i] == 'A' || kata[i] == 'I' || kata[i] == 'U' || kata[i] == 'E' || kata[i] == 'O'){
			jvokal++;
		}
	}
	if(jvokal>=3){
		return 1;
	}else{
		return 0;
	}
}

int palindrom(){
	int i;
	int lenKata = getPanjang();
	int palin = 0;
	for(i=0;i<lenKata / 2; i++){
		if(kata[i] != kata[lenKata-i-1]){
			palin = 1;
		}
	}
	return palin;
}