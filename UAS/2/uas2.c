#include "uas2.h"


void startKata(){//memulai
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


void resetKata(){//buat reset
	panjang = 0;
	kata[panjang] = '\0';
}

void incKata(){//buat maju
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

char* getKata(){//buat ngambil kata
	return kata;
}

int getPanjang(){//buat ngambil panjang kata
	return panjang;
}

int eopKata(){//buat tau apa selesai
	if(pita[indeks] == '.'){
		return 1;
	}else{
		return 0;
	}
}

void proses(){
	bener=0;
	scanf("%699[^\n]s", &pita);
	//jadi saya ngecek dulu tiap kata konsonan dan vokalnya, kalau sesuai syarat langsung selesai keluar dari loop
	startKata();
	while((eopKata() == 0)&&(bener==0)){
		cekcek();
		
		//printf("%d %d %d %d\n", konsonansatu, konsonandua, vokalsatu, vokaldua);
		konsonansatu=0;
		konsonandua=0;
		vokalsatu=0;
		vokaldua=0;
	}
	
	if(bener==1){
		printf("Perjuangan dengan Senyuman.\n");
	}else{
		printf("Pembelajaran untuk Jiwa.\n");
	}
	
}

void cekcek(){//buat ngecek konsonan vokal
	int i;
	int panjangkata=getPanjang();
	
	for(i=0;i<panjangkata;i++){
		if((kata[i]=='a')||(kata[i]=='i')||(kata[i]=='u')||(kata[i]=='e')||(kata[i]=='o')||(kata[i]=='A')||(kata[i]=='I')||(kata[i]=='U')||(kata[i]=='E')||(kata[i]=='O')){
			vokalsatu++;
		}else{
			konsonansatu++;
		}
	}
	incKata();
	panjangkata=getPanjang();
	for(i=0;i<panjangkata;i++){
		if((kata[i]=='a')||(kata[i]=='i')||(kata[i]=='u')||(kata[i]=='e')||(kata[i]=='o')||(kata[i]=='A')||(kata[i]=='I')||(kata[i]=='U')||(kata[i]=='E')||(kata[i]=='O')){
			vokaldua++;
		}else{
			konsonandua++;
		}
	}
	
	if((konsonansatu>konsonandua)&&(vokaldua>vokalsatu)){
		bener=1;
		
	}else{
		
	}
	
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi UAS dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/