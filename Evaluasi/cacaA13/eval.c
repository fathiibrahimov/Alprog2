#include "eval.h"


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

void proses(){
	int pkata;
	int i;
	jumlaha=0;
	
	startKata(pita);
	pkata=getPanjang();
	for(i=1;i<pkata-1;i++){
		if(kata[i]=='a'){//kalau ada a dia bakal cek apa depan dan belakangnya itu spasi atau titik
			if((kata[i-1]!=' ')&&(kata[i+1]!='.')){
				jumlaha++;
			}
		}
	}
	
	while(eopKata(pita)==0){
		incKata(pita);
		pkata=getPanjang();
		for(i=1;i<pkata-1;i++){//kalau ada a dia bakal cek apa depan dan belakangnya itu spasi atau titik
			if(kata[i]=='a'){
				if((kata[i-1]!=' ')&&(kata[i+1]!='.')){
					jumlaha++;
				}
			}
		}
	}
	
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Kompetisi Latihan Alpro 2 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/