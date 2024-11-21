#include "tmd.h"

void login(){
	printf("Keset di mamat's DBMS Sederhana Bahagia Version 9.9 BETA ALPHA GAMMA SIN COS TAN\n\n");
	printf("mamat's dbms> ");
	scanf("%299[^\n]s", &pita);
}

void waitinput(){
	printf("mamat's dbms> ");
	scanf("%299[^\n]s", &pita);
}

void cariperintah(){
	if((strcmp(kata, "delete")==0)||(strcmp(kata, "DELETE")==0)){
		
	}else if((strcmp(kata, "insert")==0)||(strcmp(kata, "INSERT")==0)){
		masuk();
	}else if((strcmp(kata, "update")==0)||(strcmp(kata, "UPDATE")==0)){
		
	}else if((strcmp(kata, "select")==0)||(strcmp(kata, "SELECT")==0)){
		
	}else{
		
	}
	
}

void jalan(){
	login();
	startKata();
	cariperintah();
	
	
}

int eoptaudah(){
	int i;
	int true=0;
	for(i=0;i<panjang;i++){
		if(kata[i]==';'){
			true=1;
		}
	}
	
	if(true==1){
		return 1;
	}else{
		return 0;
	}
}

int carikebenaran(){
	int i=0;
	int j=0;
	//printf("maucarieop\n");
	//printf("%s\n", kata);
	while(eoptaudah()==0){
		//printf("%s\n", kata);
		incKata();
		i++;
	}
	//printf("maucarisi i\n");
	//printf("%d\n", i);
	if(i==3){
		return 1;
	}else{
		return 0;
	}
	
}

int cekid(int tanda){
	int true=0;
	int i=0;
	
	if(tanda==1){
		while(strcmp(label[i].idlabel, "####") !=0){
			printf("%s %s %s\n", label[i].idlabel, label[i].namalabel, label[i].namapemilik);
			i++;
			if(strcmp(label[i].idlabel, temp[0])==0){
				true=1;
			}
		}
		
		if(true==1){
			return 1;
		}else{
			return 0;
		}
	}
	else if(tanda==3){
		printf("cekid 2\n");
		while(strcmp(label[i].idband, "####") !=0){	
			printf("%s %s %s\n", label[i].idband, label[i].namaband, label[i].idlabelband);
			i++;
		}
		i=0;
		while(strcmp(label[i].idband, "####") !=0){
			//printf("%s %s\n", band[i].idband, temp[0]);
			
			if(strcmp(label[i].idband, temp[0])==0){
				true=1;
			}
			i++;
		}
		
		if(true==1){
			return 1;
		}else{
			return 0;
		}
	}
	
}

void masuk(){
	int n=0;
	int i;
	int j=0;
	int kelar=0;
	int kelar2=0;
	
	
	incKata();
	if((strcmp(kata, "update")==0) || (strcmp(kata, "UPDATE")==0)){
		incKata();
		//printf("%s\n", kata);
		if(strcmp(kata, "tlabel")==0){
			bacatabel(1);
			n=0;
			
			if(carikebenaran()==1){
				startKata();//balik ke awal
				incKata();
				incKata();//balik ke nama tabel
				for(i=0;i<3;i++){
					incKata();
					strcpy(temp[i], kata);
				}
				
				
				if(cekid(1)==0){
					tulistabel(1);
				}else{
					printf("idnya sudah ada kaka\n");
				}
			
			}else{
				printf("query salah\n");
			}
		
		}else if(strcmp(kata, "tband")==0){
			bacatabel(2);
			n=0;
			if(carikebenaran()==1){
				printf("LolosBenarBand\n");
				startKata();//balik ke awal
				incKata();
				incKata();//balik ke nama tabel
				for(i=0;i<3;i++){
					incKata();
					strcpy(temp[i], kata);
				}
				//printf("%s\n", temp[0]);
				if(cekid(3)==0){
					printf("tulisband\n");
					tulistabel(2);
				}else{
					printf("idnya sudah ada kaka\n");
				}
			
			}else{
				printf("query salah\n");
			}
		
		}
		
	}else if(strcmp(kata, "tlabel")==0){
		bacatabel(1);
		n=0;
		if(carikebenaran()==1){
			startKata();//balik ke awal
			incKata();//balik ke nama tabel
			for(i=0;i<3;i++){
				incKata();
				strcpy(temp[i], kata);
			}
			if(cekid(1)==0){
				tulistabel(1);
			}else{
				printf("idnya sudah ada kaka\n");
			}
			
		}else{
			printf("query salah\n");
		}
		
	}else if(strcmp(kata, "tband")==0){
		bacatabel(2);
		n=0;
		if(carikebenaran()==1){
			printf("LolosBenarBand\n");
			startKata();//balik ke awal
			incKata();//balik ke nama tabel
			for(i=0;i<3;i++){
				incKata();
				strcpy(temp[i], kata);
			}
			//printf("%s\n", temp[0]);
			if(cekid(3)==0){
				printf("tulisband\n");
				tulistabel(2);
			}else{
				printf("idnya sudah ada kaka\n");
			}
			
		}else{
			printf("query salah\n");
		}
		//insert ke tband
	}else{
		
	}
}

void atastanggal(){
	incKata();
	if(strcmp(kata, "tlabel")==0){
		//update ke label
	}else if(strcmp(kata, "tband")==0){
		incKata();
		//update ke tband
	}else{
		
	}
}

void hapus(){
	int n=0;
	int c;
	incKata();
	if(strcmp(kata, "tlabel")==0){
		bacatabel(1);
		incKata();
		if(strcmp(kata, "idlabel")==0){
			incKata();
			
		}else if(strcmp(kata, "namalabel")==0){
			incKata();
		}else if(strcmp(kata, "namapemilik")==0){
			incKata();
		}else{
			
		}
	}else if(strcmp(kata, "tband")==0){
		bacatabel(2);
		incKata();
		if(strcmp(kata, "idband")==0){
			incKata();
		}else if(strcmp(kata, "namaband")==0){
			incKata();
		}else if(strcmp(kata, "idlabelband")==0){
			incKata();
		}else{
			
		}
	}else{
		
	}
}

void pilih(){
	incKata();
	if(strcmp(kata, "tlabel")==0){
		incKata();
		if(strcmp(kata, ";")==0){
			
		}else if(strcmp(kata, "tband")==0){
			
		}else{
			
		}
	}else if(strcmp(kata, "tband")==0){
		incKata();
		if(strcmp(kata, ";")==0){
			
		}else{
			
		}
	}else{
		
	}
}

void bacatabel(int tanda){
	int n;
	int i=0;
	int j;
	int k;
	FILE *fbukaaja;
	
	for(j=0;j<50;j++){
		for(k=0;k<50;k++){
			label[j].idlabel[k]='\0';
			label[j].namalabel[k]='\0';
			label[j].namapemilik[k]='\0';
			label[j].idband[k]='\0';
			label[j].namaband[k]='\0';
			label[j].idlabelband[k]='\0';
		}
	}
	
	if(tanda==1){
		n=0;
		//baca yang label
		fbukaaja = fopen("tlabel.dat", "r");
		fscanf(fbukaaja, "%s %s %s", label[n].idlabel, label[n].namalabel, label[n].namapemilik);
		while(strcmp(label[n].idlabel, "####") !=0){
			n++;
			fscanf(fbukaaja, "%s %s %s", label[n].idlabel, label[n].namalabel, label[n].namapemilik);
		}
		fclose(fbukaaja);
	}else if(tanda==2){
		n=0;
		//printf("bacayang band\n");
		//baca yang band
		fbukaaja = fopen("tband.dat", "r");
		fscanf(fbukaaja, "%s %s %s", label[n].idband, label[n].namaband, label[n].idlabelband);
		while(strcmp(label[n].idband, "####") !=0){
			n++;
			fscanf(fbukaaja, "%s %s %s", label[n].idband, label[n].namaband, label[n].idlabelband);
		}
		fclose(fbukaaja);
		/*
		while(strcmp(band[i].idband, "####") !=0){	
			printf("%s %s %s\n", band[i].idband, band[i].namaband, band[i].idlabelband);
			i++;
		}*/
	}
	tandaindeks=n;
	
}

void tulistabel(int tanda){
	FILE *fbukaaja;
	int n;
	int i=0;
	if(tanda==1){
		
		while(temp[2][i]!=';'){
			i++;
		}
		temp[2][i]='\0';
		
		strcpy(label[tandaindeks].idlabel, temp[0]);
		strcpy(label[tandaindeks].namalabel, temp[1]);
		strcpy(label[tandaindeks].namapemilik, temp[2]);
		
		
		tandaindeks++;
		strcpy(label[tandaindeks].idlabel, "####");
		strcpy(label[tandaindeks].namalabel, "####");
		strcpy(label[tandaindeks].namapemilik, "####");
		tandaindeks++;
	
	
	
		fbukaaja = fopen("tlabel.dat", "w");
		n=0;
		while(strcmp(label[n].idlabel, "####") !=0){
			fprintf(fbukaaja, "%s %s %s\n", label[n].idlabel, label[n].namalabel, label[n].namapemilik);
			++n;
		}
	
		fprintf(fbukaaja, "#### #### ####");
		fclose(fbukaaja);
	}else if(tanda==2){
		
		while(temp[2][i]!=';'){
			i++;
		}
		temp[2][i]='\0';
		
		strcpy(label[tandaindeks].idband, temp[0]);
		strcpy(label[tandaindeks].namaband, temp[1]);
		strcpy(label[tandaindeks].idlabelband, temp[2]);
		
		tandaindeks++;
		strcpy(label[tandaindeks].idband, "####");
		strcpy(label[tandaindeks].namaband, "####");
		strcpy(label[tandaindeks].idlabelband, "####");
		tandaindeks++;
	
		fbukaaja = fopen("tband.dat", "w");
		n=0;
		while(strcmp(label[n].idband, "####") !=0){
			fprintf(fbukaaja, "%s %s %s\n", label[n].idband, label[n].namaband, label[n].idlabelband);
			++n;
		}
	
		fprintf(fbukaaja, "#### #### ####");
		fclose(fbukaaja);
	}
	
	
}

void startKata(){
	indeks = 0;
	panjang = 0;
	while(pita[indeks] == ' '){
		indeks++;
	}
	while((pita[indeks] != ' ') && (pita[indeks] != ';')){
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

void incKata(){
	panjang = 0;
	while(pita[indeks] == ' '){
		indeks++;
	}
	while((pita[indeks] != ' ') && (pita[indeks] != ';')){
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

int eopKata(){
	if(pita[indeks] == ';'){
		return 1;
	}else{
		return 0;
	}
}


/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/