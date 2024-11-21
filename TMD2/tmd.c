#include "tmd.h"

void startKata(){//buat mulai mesin kata
	indeks = 0;
	panjang = 0;
	while(pita[indeks] == ' '){//kalau spasi dilewat
		indeks++;
	}
	while((pita[indeks] != ' ') && (pita[indeks] != ';')){//selama bukan spasi dan titik dia akan ngambil katanya
		kata[panjang] = pita[indeks];
		indeks++;
		panjang++;
	}
	kata[panjang] = '\0';
}

void resetKata(){//buat reset kata
	panjang = 0;
	kata[panjang] = '\0';
}

void incKata(){//buat majuin mesin kata, konsepnya sama aja kaya start kata, cuma bedanya kalo disini gak dibuat indeksnya nol
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

char* getKata(){//buat ngambil kata
	return kata;
}

int getPanjang(){//buat ngambil panjang
	return panjang;
}

int eopKata(){//buat tau kapan mesin katanya harus selesai
	if(pita[indeks] == ';'){
		return 1;
	}else{
		return 0;
	}
}

void proses(){//ini proses awalnya, mulai dari minta masukan dulu di login
	login();//minta masukan disini
	if(pexit==0){//kalau ternyata nice to meet you maka bye
		carimasalah();//cari masalah dan mulai jalanin querynya
		fflush(stdin);//ini buat ngilangin masalah di buffer, kalo gak diflush nanti loop terus
		proses2();//mulai proses2, sebenernya gak perlu ini tapi saya iseng
	}
	
}

void proses2(){//ini sama aja kaya proses pertama, saya lupa kenapa saya buat ini
	login();
	if(pexit==0){
		carimasalah();
		fflush(stdin);
		proses2();
	}
}

void login(){//buat minta masukan
	printf("mamat's dbms> ");
	scanf("%699[^\n]s", &pita);
	if(keluar()==1){//kalo ternyata keluar maka print bye
		printf("bye\n");
		pexit=1;
	}
}

int keluar(){//ini buat tau apa kalimatnya nice to meet you
	int benar=0;
	startKata();
	if(strcmp(kata, "nice")==0){
		incKata();
		if(strcmp(kata, "to")==0){
			incKata();
			if(strcmp(kata, "meet")==0){
				incKata();
				if(strcmp(kata, "you")==0){
					benar= 1;
				}
			}
		}
	}
	
	return benar;
}

void carimasalah(){//disini cari masalahnya apa
	tabel=0;//set tabelnya jadi nol dulu
	
	//cek mintanya apa, insert update itu 1, insert 2, update 3, delete 4, select 5
	startKata();
	if((strcmp(kata, "insert")==0)||(strcmp(kata, "INSERT")==0)){
		incKata();
		if((strcmp(kata, "update")==0)||(strcmp(kata, "UPDATE")==0)){
			prosedur=1;
			incKata();
		}else{
			prosedur=2;
		}
	}else if((strcmp(kata, "update")==0)||(strcmp(kata, "UPDATE")==0)){
		prosedur=3;
	}else if((strcmp(kata, "delete")==0)||(strcmp(kata, "DELETE")==0)){
		prosedur=4;
	}else if((strcmp(kata, "select")==0)||(strcmp(kata, "SELECT")==0)){
		prosedur=5;
	}else{
		prosedur=0;
	}
	
	//cek minta tabel apa, tlabel 1, tband 2
	if(prosedur==1){
		if(strcmp(kata, "tlabel")==0){
			tabel=1;
			masuk();
		}else if(strcmp(kata, "tband")==0){
			tabel=2;
			masuk();
		}
	}else if(prosedur==2){
		if(strcmp(kata, "tlabel")==0){
			tabel=1;
			masuk();
		}else if(strcmp(kata, "tband")==0){
			tabel=2;
			masuk();
		}
	}else if(prosedur==3){
		incKata();
		if(strcmp(kata, "tlabel")==0){
			tabel=1;
			naiktanggal();
		}else if(strcmp(kata, "tband")==0){
			tabel=2;
			naiktanggal();
		}
	}else if(prosedur==4){
		incKata();
		if(strcmp(kata, "tlabel")==0){
			tabel=1;
			hapus();
		}else if(strcmp(kata, "tband")==0){
			tabel=2;
			hapus();
		}
	}else if(prosedur==5){
		incKata();
		if(strcmp(kata, "tlabel")==0){
			tabel=1;
			incKata();
			if(strcmp(kata, "tband")==0){
				tabel=3;
			}
			pilih();
			
		}else if(strcmp(kata, "tband")==0){
			tabel=2;
			incKata();
			if(strcmp(kata, "tlabel")==0){
				tabel=3;
			}
			pilih();
			
		}
	}
	//kalau ternyata gak ada yang diminta
	if((prosedur==0) || (tabel==0)){
		printf("\nPerintah yang kau inginkan tak terdengar oleh diriku\n\n");
	}
}

int cekbenarpilih(int tanda){//ini buat ngecek bener atau nggak querynya di bagian select
	int i=1;
	
	startKata();//mulai dari awal dulu
	
	while(eopKata()==0){//cek ada berapa kata
		incKata();
		i++;
	}
	if(tanda==1){//ini kalau select biasa
		if(i==2){//kalau katanya ada 2 berarti benar, misal select tlabel;
			return 1;
		}else {
			return 0;
		}
	}else if(tanda==2){//ini kalau join
		if(i==3){//kalau katanya ada 3 berarti benar, misal select tlabel tband;
			return 1;
		}else{
			return 0;
		}
	}
	
}

void masuk(){//ini prosedur buat insert
	FILE *fbukaaja;//filenya
	int n;//dipake buat indeks filenya
	
	if(prosedur==2){//kalau prosedurnya insert saja
		if(cekbenar()==1){//cek querynya
			if(cekid()==0){//cek apa ada id yang sama
				if(tabel==1){//cek tabelnya apa
					
					printf("\nKenapa kau masuki hatiku jika kau hancurkan juga akhirnya?\n\n");
					//masukin yang mau diinsert ke temp
					strcpy(label[tandaindeks].idlabel, temp[0]);
					strcpy(label[tandaindeks].namalabel, temp[1]);
					strcpy(label[tandaindeks].namapemilik, temp[2]);
					tandaindeks++;//masukin dummy
					strcpy(label[tandaindeks].idlabel, "####");
					strcpy(label[tandaindeks].namalabel, "####");
					strcpy(label[tandaindeks].namapemilik, "####");
					tandaindeks++;
					
					fbukaaja = fopen("tlabel.dat", "w");//mulai masukin ke file disini
					n=0;
					while(strcmp(label[n].idlabel, "####") !=0){
						fprintf(fbukaaja, "%s %s %s\n", label[n].idlabel, label[n].namalabel, label[n].namapemilik);
						++n;
					}
	
					fprintf(fbukaaja, "#### #### ####");
					fclose(fbukaaja);
				}else if(tabel==2){//cek tabel
					
					printf("\nKenapa kau masuki hatiku jika kau hancurkan juga akhirnya?\n\n");
					//masukin yang mau diinsert ke temp
					strcpy(label[tandaindeks].idband, temp[0]);
					strcpy(label[tandaindeks].namaband, temp[1]);
					strcpy(label[tandaindeks].idlabelband, temp[2]);
					tandaindeks++;//masukin dummy
					strcpy(label[tandaindeks].idband, "####");
					strcpy(label[tandaindeks].namaband, "####");
					strcpy(label[tandaindeks].idlabelband, "####");
					tandaindeks++;
	
					fbukaaja = fopen("tband.dat", "w");//mulai masukin ke file
					n=0;
					while(strcmp(label[n].idband, "####") !=0){
						fprintf(fbukaaja, "%s %s %s\n", label[n].idband, label[n].namaband, label[n].idlabelband);
						++n;
					}
	
					fprintf(fbukaaja, "#### #### ####");
					fclose(fbukaaja);
				}	
			}else{//kalau idnya udah ada
				printf("\nMaaf, hatiku sudah ada yang mengisi\n\n");
			}
		}else{
			printf("\nPerintah yang kau inginkan tak terdengar oleh diriku\n\n");
		}
	}else if(prosedur==1){//kalau prosedurnya insert update
		if(cekbenar()==1){//cek query
			if(cekid()==0){//cek idnya ada atau tidak
				if(tabel==1){//cek tabel
					//ini sama aja kaya kalau misalnya diminta insert, cuma beda di bagian cek idnya
					printf("\nTak ada kesamaan dalam perlakuanmu, tetap kau masuki hatiku\n\n");
					
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
				}else if(tabel==2){
					
					printf("\nTak ada kesamaan dalam perlakuanmu, tetap kau masuki hatiku\n\n");
					
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
			}else if(cekid()==1){//nah ini kalau ternyata ada id yang sama maka dia update
				naiktanggal();
			}
		}else{
			printf("\nPerintah yang kau inginkan tak terdengar oleh diriku\n\n");
		}
	}
	
}

void naiktanggal(){//ini prosedur buat update
	FILE *fbukaaja;//filenya
	int n=0;//buat indeks filenya
	
	if(prosedur==3){//cek prosedurnya bener atau nggak
		if(cekbenar()==1){//cek quert
			if(cekid()==1){//cek apa ada idnya
				if(tabel==1){//cek tabel
					
					printf("\nDisaat dirimu berpisah dengannya, bisakah kau update hatimu dengan diriku?\n\n");
					//masukin yang mau diupdate dari temp
					strcpy(label[tandasama].idlabel, temp[0]);
					strcpy(label[tandasama].namalabel, temp[1]);
					strcpy(label[tandasama].namapemilik, temp[2]);
					tandasama++;
					//mulai ubah deh
					fbukaaja = fopen("tlabel.dat", "w");
					n=0;
					while(strcmp(label[n].idlabel, "####") !=0){
						fprintf(fbukaaja, "%s %s %s\n", label[n].idlabel, label[n].namalabel, label[n].namapemilik);
						++n;
					}
	
					fprintf(fbukaaja, "#### #### ####");
					fclose(fbukaaja);
				}else if(tabel==2){//cek tabel
					
					printf("\nDisaat dirimu berpisah dengannya, bisakah kau update hatimu dengan diriku?\n\n");
					
					strcpy(label[tandasama].idband, temp[0]);
					strcpy(label[tandasama].namaband, temp[1]);
					strcpy(label[tandasama].idlabelband, temp[2]);
					tandasama++;
	
					fbukaaja = fopen("tband.dat", "w");
					n=0;
					while(strcmp(label[n].idband, "####") !=0){
						fprintf(fbukaaja, "%s %s %s\n", label[n].idband, label[n].namaband, label[n].idlabelband);
						++n;
					}
	
					fprintf(fbukaaja, "#### #### ####");
					fclose(fbukaaja);
				}
			}else{
				printf("\nTak bisa mengupdate, lupa kalau hati sudah lama hancur\n\n");
			}
		}else{
			printf("\nPerintah yang kau inginkan tak terdengar oleh diriku\n\n");
		}
	}else if(prosedur==1){//ini kalau diminta insert update
		if(tabel==1){
			//sebenernya sama aja kaya kalo misalnya diminta update saja, cuma gak ada cek cek disini karena sudah cek
			printf("\nKita memiliki kesamaan, sama sama ingin memperbarui rasa lama\n\n");
			
			strcpy(label[tandasama].idlabel, temp[0]);
			strcpy(label[tandasama].namalabel, temp[1]);
			strcpy(label[tandasama].namapemilik, temp[2]);
			tandasama++;
		
			fbukaaja = fopen("tlabel.dat", "w");
			n=0;
			while(strcmp(label[n].idlabel, "####") !=0){
				fprintf(fbukaaja, "%s %s %s\n", label[n].idlabel, label[n].namalabel, label[n].namapemilik);
				++n;
			}
	
			fprintf(fbukaaja, "#### #### ####");
			fclose(fbukaaja);
		}else if(tabel==2){
			
			printf("\nKita memiliki kesamaan, sama sama ingin memperbarui rasa lama\n\n");
			
			strcpy(label[tandasama].idband, temp[0]);
			strcpy(label[tandasama].namaband, temp[1]);
			strcpy(label[tandasama].idlabelband, temp[2]);
			tandasama++;
	
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
}

void hapus(){//ini prosedur buat delete
	int i=0;//iterator
	int n=0;//indeks buat file
	int batas=0;//buat tau tabelnya selesai dimana
	
	FILE *fbukaaja;
	
	if(tabel==1){//cek tabel
		if(cekbenardelete()==1){//cek querynya bener atau nggak
			if(cekiddelete()==1){//cek idnya ada atau nggak
				
				printf("\nMenghapus semua kenangan dengan dirinya...\n\n");
				
				while(strcmp(label[n].idlabel, "####") !=0){//cari batasnya dimana
					batas++;
					n++;
				}
				
				for(i=tandasama;i<batas;i++){//ini mulai timpa timpaan yang mau dihapus
					strcpy(label[i].idlabel, label[i+1].idlabel);
					strcpy(label[i].namalabel, label[i+1].namalabel);
					strcpy(label[i].namapemilik, label[i+1].namapemilik);
				}
				//tulis deh di file
				fbukaaja = fopen("tlabel.dat", "w");
				n=0;
				while(strcmp(label[n].idlabel, "####") !=0){
					fprintf(fbukaaja, "%s %s %s\n", label[n].idlabel, label[n].namalabel, label[n].namapemilik);
					++n;
				}
	
				fprintf(fbukaaja, "#### #### ####");
				fclose(fbukaaja);
				
			}else{
				printf("\nYang terhapus sudah lama ditinggalkan\n\n");
			}
		}else{
			printf("\nPerintahmu tidak terdengar oleh diriku\n\n");
		}
	}else if(tabel==2){
		if(cekbenardelete()==1){
			if(cekiddelete()==1){
				//sama aja kaya diatas, cuma beda tabel aja
				printf("\nMenghapus semua kenangan dengan dirinya...\n\n");
				
				while(strcmp(label[n].idband, "####") !=0){
					batas++;
					n++;
				}
				
				for(i=tandasama;i<batas;i++){
					strcpy(label[i].idband, label[i+1].idband);
					strcpy(label[i].namaband, label[i+1].namaband);
					strcpy(label[i].idlabelband, label[i+1].idlabelband);
				}
				
				fbukaaja = fopen("tband.dat", "w");
				n=0;
				while(strcmp(label[n].idband, "####") !=0){
					fprintf(fbukaaja, "%s %s %s\n", label[n].idband, label[n].namaband, label[n].idlabelband);
					++n;
				}
	
				fprintf(fbukaaja, "#### #### ####");
				fclose(fbukaaja);
			}else{
				printf("\nYang terhapus sudah lama ditinggalkan\n\n");
			}
		}else{
			printf("\nPerintahmu tidak terdengar oleh diriku\n\n");
		}
	}
}

void pilih(){//ini prosedur buat select
	int n=0;
	int i=0;
	int p1=0;
	int p2=0;
	int p3=0;
	int p4=0;
	int p5=0;
	int beda;
		
		
	if(tabel==1){//cek tabel
		if(cekbenarpilih(1)==1){//cek query bener atau tidak
			
			printf("\nIni kan yang selama ini kau inginkan ?!\n\n");
			
			bacabaca();//baca filenya
			//ini set minimum kata ke judul atributnya
			p1=7;
			p2=9;
			p3=11;
			if(strcmp(label[0].idlabel, "####")==0){//kalau tabelnya kosong
				printf("\ntabelkosong\n\n");
			}else{//cek panjang maksimum
				while(strcmp(label[n].idlabel, "####") != 0){
					if(strlen(label[n].idlabel)>p1){
						p1=strlen(label[n].idlabel);
					}
					if(strlen(label[n].namalabel)>p2){
						p2=strlen(label[n].namalabel);
					}
						if(strlen(label[n].namapemilik)>p3){
						p3=strlen(label[n].namapemilik);
					}
					n++;
				}
				//print tabel bagian atas yang buat judul atribut
				printf("+");
				for(i=0;i<p1+2;i++){
					printf("=");
				}
				printf("+");
				for(i=0;i<p2+2;i++){
					printf("=");
				}
				printf("+");
				for(i=0;i<p3+2;i++){
					printf("=");
				}
				printf("+\n");
				
				while(strcmp(label[n].idlabel, "####") !=0){//print yang bagian bawahnya atas tabel
					if(strlen(label[n].idlabel)<p1){
						beda=p1-strlen(label[n].idlabel);
					}
					if(strlen(label[n].namalabel)<p2){
						beda=p2-strlen(label[n].namalabel);	
					}
					if(strlen(label[n].namapemilik)<p3){
						beda=p3-strlen(label[n].namapemilik);
					}
					n++;
				}
					
				printf("|");
				if(p1>7){
					beda=p1-7;
					printf(" IDLabel ");
					for(i=0;i<beda;i++){
						printf(" ");
					}
				}else{
					printf(" IDLabel ");
				}
				printf("|");
				if(p2>9){
					beda=p2-9;
					printf(" NamaLabel ");
					for(i=0;i<beda;i++){
						printf(" ");
					}
				}else{
					printf(" NamaLabel ");
				}
				printf("|");
				if(p3>11){
					beda=p3-11;
					printf(" NamaPemilik ");
					for(i=0;i<beda;i++){
						printf(" ");
					}
				}else{
					printf(" NamaPemilik ");
				}
				printf("|\n");
				
				//print buat yang bagian bawah judul atribut
				printf("+");
				for(i=0;i<p1+2;i++){
					printf("=");
				}
				printf("+");
				for(i=0;i<p2+2;i++){
					printf("=");
				}
				printf("+");
				for(i=0;i<p3+2;i++){
					printf("=");
				}
				printf("+");
				
				n=0;
		
				while(strcmp(label[n].idlabel, "####") !=0){//print yang bagian bawahnya atas tabel
					printf("\n");
					printf("|");//print yang bagian label
					if(strlen(label[n].idlabel)<p1){
						beda=p1-strlen(label[n].idlabel);
						printf(" %s ", label[n].idlabel);
						for(i=0;i<beda;i++){
							printf(" ");
						}
					}else{
						printf(" %s ", label[n].idlabel);
					}
					printf("|");
					
					if(strlen(label[n].namalabel)<p2){
						beda=p2-strlen(label[n].namalabel);
						printf(" %s ", label[n].namalabel);
						for(i=0;i<beda;i++){
							printf(" ");
						}
					}else{
						printf(" %s ", label[n].namalabel);
					}
					printf("|");
					
					if(strlen(label[n].namapemilik)<p3){
						beda=p3-strlen(label[n].namapemilik);
						printf(" %s ", label[n].namapemilik);
						for(i=0;i<beda;i++){
							printf(" ");
						}
					}else{
						printf(" %s ", label[n].namapemilik);
					}
					printf("|");
					n++;
				}
				printf("\n");
				printf("+");
				for(i=0;i<p1+2;i++){
					printf("=");
				}
				printf("+");
				for(i=0;i<p2+2;i++){
					printf("=");
				}
				printf("+");
				for(i=0;i<p3+2;i++){
					printf("=");
				}
				printf("+");
				printf("\n");
				
			}
		}else{
			printf("\nPerintahmu tidak terdengar oleh diriku\n\n");
		}
	}else if(tabel==2){
		if(cekbenarpilih(1)==1){
			//konsepnya sama kaya kalo misalnya tabelnya tlabel
			printf("\nIni kan yang selama ini kau inginkan ?!\n\n");
			
			p1=6;
			p2=8;
			p3=11;
			bacabaca();
			if(strcmp(label[0].idband, "####")==0){
				printf("tabelkosong\n");
			}else{
				while(strcmp(label[n].idband, "####") != 0){
					if(strlen(label[n].idband)>p1){
						p1=strlen(label[n].idband);
					}
					if(strlen(label[n].namaband)>p2){
						p2=strlen(label[n].namaband);
					}
					if(strlen(label[n].idlabelband)>p3){
						p3=strlen(label[n].idlabelband);
					}
					n++;
				}
				
				printf("+");
				for(i=0;i<p1+2;i++){
					printf("=");
				}
				printf("+");
				for(i=0;i<p2+2;i++){
					printf("=");
				}
				printf("+");
				for(i=0;i<p3+2;i++){
					printf("=");
				}
				printf("+\n");
				
				while(strcmp(label[n].idband, "####") !=0){//print yang bagian bawahnya atas tabel
					if(strlen(label[n].idband)<p1){
						beda=p1-strlen(label[n].idband);
					}
					if(strlen(label[n].namaband)<p2){
						beda=p2-strlen(label[n].namaband);	
					}
					if(strlen(label[n].idlabelband)<p3){
						beda=p3-strlen(label[n].idlabelband);
					}
					n++;
				}
				
				printf("|");
				if(p1>6){
					beda=p1-6;
					printf(" IDBand ");
					for(i=0;i<beda;i++){
						printf(" ");
					}
				}else{
					printf(" IDBand ");
				}
				printf("|");
				if(p2>8){
					beda=p2-8;
					printf(" NamaBand ");
					for(i=0;i<beda;i++){
						printf(" ");
					}
				}else{
					printf(" NamaBand ");
				}
				printf("|");
				if(p3>11){
					beda=p3-11;
					printf(" IDLabelBand ");
					for(i=0;i<beda;i++){
						printf(" ");
					}
				}else{
					printf(" IDLabelBand ");
				}
				printf("|\n");
				
				printf("+");
				for(i=0;i<p1+2;i++){
					printf("=");
				}
				printf("+");
				for(i=0;i<p2+2;i++){
					printf("=");
				}
				printf("+");
				for(i=0;i<p3+2;i++){
					printf("=");
				}
				printf("+");
				
				n=0;
		
				while(strcmp(label[n].idband, "####") !=0){//print yang bagian bawahnya atas tabel
					printf("\n");
					printf("|");//print yang bagian band
					if(strlen(label[n].idband)<p1){
						beda=p1-strlen(label[n].idband);
						printf(" %s ", label[n].idband);
						for(i=0;i<beda;i++){
							printf(" ");
						}
					}else{
						printf(" %s ", label[n].idband);
					}
					printf("|");
					
					if(strlen(label[n].namaband)<p2){
						beda=p2-strlen(label[n].namaband);
						printf(" %s ", label[n].namaband);
						for(i=0;i<beda;i++){
							printf(" ");
						}
					}else{
						printf(" %s ", label[n].namaband);
					}
					printf("|");
					
					if(strlen(label[n].idlabelband)<p3){
						beda=p3-strlen(label[n].idlabelband);
						printf(" %s ", label[n].idlabelband);
						for(i=0;i<beda;i++){
							printf(" ");
						}
					}else{
						printf(" %s ", label[n].idlabelband);
					}
					printf("|");
					n++;
				}
				printf("\n");
				printf("+");
				for(i=0;i<p1+2;i++){
					printf("=");
				}
				printf("+");
				for(i=0;i<p2+2;i++){
					printf("=");
				}
				printf("+");
				for(i=0;i<p3+2;i++){
					printf("=");
				}
				printf("+");
				printf("\n");
				
			}
		}else{
			printf("\nPerintahmu tidak terdengar oleh diriku\n\n");
		}
	}else if(tabel==3){//ini kalo diminta join
		if(cekbenarpilih(2)==1){
			
			printf("\nSkuy join lah ?!\n\n");
			
			bacagabung();//baca filenya
			gabunginaja();//gabungin isi filenya di bungkusan
			//dan selebihnya sama kaya diatas
			p1=6;
			p2=8;
			p3=7;
			p4=9;
			p5=11;
			
			if(strcmp(gabungan[0].idband, "####")==0){
				printf("tabelkosong\n");
			}else{
				while(strcmp(gabungan[n].idband, "####") != 0){
					if(strlen(gabungan[n].idband)>p1){
						p1=strlen(gabungan[n].idband);
					}
					if(strlen(gabungan[n].namaband)>p2){
						p2=strlen(gabungan[n].namaband);
					}
					if(strlen(gabungan[n].idlabel)>p3){
						p3=strlen(gabungan[n].idlabel);
					}
					if(strlen(gabungan[n].namalabel)>p4){
						p4=strlen(gabungan[n].namalabel);
					}
					if(strlen(gabungan[n].namapemilik)>p5){
						p5=strlen(gabungan[n].namapemilik);
					}
					n++;
				}
				
				printf("+");
				for(i=0;i<p1+2;i++){
					printf("=");
				}
				printf("+");
				for(i=0;i<p2+2;i++){
					printf("=");
				}
				printf("+");
				for(i=0;i<p3+2;i++){
					printf("=");
				}
				printf("+");
				for(i=0;i<p4+2;i++){
					printf("=");
				}
				printf("+");
				for(i=0;i<p5+2;i++){
					printf("=");
				}
				printf("+\n");
				
				while(strcmp(gabungan[n].idband, "####") !=0){//cek beda
					if(strlen(gabungan[n].idband)<p1){
						beda=p1-strlen(gabungan[n].idband);
					}
					if(strlen(gabungan[n].namaband)<p2){
						beda=p2-strlen(gabungan[n].namaband);	
					}
					if(strlen(gabungan[n].idlabel)<p3){
						beda=p3-strlen(gabungan[n].idlabel);
					}
					if(strlen(gabungan[n].namalabel)<p4){
						beda=p4-strlen(gabungan[n].namalabel);
					}
					if(strlen(gabungan[n].namapemilik)<p5){
						beda=p5-strlen(gabungan[n].namapemilik);
					}
					n++;
				}
				
				printf("|");
				if(p1>6){
					beda=p1-6;
					printf(" IDBand ");
					for(i=0;i<beda;i++){
						printf(" ");
					}
				}else{
					printf(" IDBand ");
				}
				printf("|");
				if(p2>8){
					beda=p2-8;
					printf(" NamaBand ");
					for(i=0;i<beda;i++){
						printf(" ");
					}
				}else{
					printf(" NamaBand ");
				}
				printf("|");
				if(p3>7){
					beda=p3-7;
					printf(" IDLabel ");
					for(i=0;i<beda;i++){
						printf(" ");
					}
				}else{
					printf(" IDLabel ");
				}
				printf("|");
				if(p4>9){
					beda=p4-9;
					printf(" NamaLabel ");
					for(i=0;i<beda;i++){
						printf(" ");
					}
				}else{
					printf(" NamaLabel ");
				}
				printf("|");
				if(p5>11){
					beda=p5-11;
					printf(" NamaPemilik ");
					for(i=0;i<beda;i++){
						printf(" ");
					}
				}else{
					printf(" NamaPemilik ");
				}
				printf("|\n");
				
				printf("+");
				for(i=0;i<p1+2;i++){
					printf("=");
				}
				printf("+");
				for(i=0;i<p2+2;i++){
					printf("=");
				}
				printf("+");
				for(i=0;i<p3+2;i++){
					printf("=");
				}
				printf("+");
				for(i=0;i<p4+2;i++){
					printf("=");
				}
				printf("+");
				for(i=0;i<p5+2;i++){
					printf("=");
				}
				printf("+");
				
				n=0;
		
				while(strcmp(gabungan[n].idband, "####") !=0){//print yang bagian bawahnya atas tabel
					printf("\n");
					printf("|");//print yang bagian band
					if(strlen(gabungan[n].idband)<p1){
						beda=p1-strlen(gabungan[n].idband);
						printf(" %s ", gabungan[n].idband);
						for(i=0;i<beda;i++){
							printf(" ");
						}
					}else{
						printf(" %s ", gabungan[n].idband);
					}
					printf("|");
					
					if(strlen(gabungan[n].namaband)<p2){
						beda=p2-strlen(gabungan[n].namaband);
						printf(" %s ", gabungan[n].namaband);
						for(i=0;i<beda;i++){
							printf(" ");
						}
					}else{
						printf(" %s ", gabungan[n].namaband);
					}
					printf("|");
					
					if(strlen(gabungan[n].idlabel)<p3){
						beda=p3-strlen(gabungan[n].idlabel);
						printf(" %s ", gabungan[n].idlabel);
						for(i=0;i<beda;i++){
							printf(" ");
						}
					}else{
						printf(" %s ", gabungan[n].idlabel);
					}
					printf("|");
					
					if(strlen(gabungan[n].namalabel)<p4){
						beda=p4-strlen(gabungan[n].namalabel);
						printf(" %s ", gabungan[n].namalabel);
						for(i=0;i<beda;i++){
							printf(" ");
						}
					}else{
						printf(" %s ", gabungan[n].namalabel);
					}
					printf("|");
					
					if(strlen(gabungan[n].namapemilik)<p5){
						beda=p5-strlen(gabungan[n].namapemilik);
						printf(" %s ", gabungan[n].namapemilik);
						for(i=0;i<beda;i++){
							printf(" ");
						}
					}else{
						printf(" %s ", gabungan[n].namapemilik);
					}
					printf("|");
					n++;
				}
				printf("\n");
				printf("+");
				for(i=0;i<p1+2;i++){
					printf("=");
				}
				printf("+");
				for(i=0;i<p2+2;i++){
					printf("=");
				}
				printf("+");
				for(i=0;i<p3+2;i++){
					printf("=");
				}
				printf("+");
				for(i=0;i<p4+2;i++){
					printf("=");
				}
				printf("+");
				for(i=0;i<p5+2;i++){
					printf("=");
				}
				printf("+");
				printf("\n");
				
			}
		}else{
			printf("\nPerintahmu tidak terdengar oleh diriku\n\n");
		}
	}
}

void gabunginaja(){//prosedur buat gabung kalo join
	int n=0;
	int m=0;
	
	while(strcmp(gabungan[n].idband, "####")!=0){//langsung masukin yang label ke bungkusan gabung karena sebelumnya udah ada band di gabung
		m=0;
		while(strcmp(label[m].idlabel, "####")!=0){
			
			if(strcmp(label[m].idlabel, gabungan[n].idlabelband)==0){
				strcpy(gabungan[n].idlabel, label[m].idlabel);
				strcpy(gabungan[n].namalabel, label[m].namalabel);
				strcpy(gabungan[n].namapemilik, label[m].namapemilik);
			}
			m++;
		}
		n++;
	}
	n=0;
	
}

void bacagabung(){//buat baca file band dan masukin ke bungkusan gabung
	int i;//iterator
	int n=0;//indeks file
	
	FILE *flabel;
	if(tabel==3){//cek tabelnya bener minta gabung gak
		flabel = fopen("tlabel.dat", "r");//ini baca yang label dan masukin ke bungkusan label
		fscanf(flabel, "%s %s %s", label[n].idlabel, label[n].namalabel, label[n].namapemilik);
	
		while(strcmp(label[n].idlabel, "####") !=0){
			++n;
			fscanf(flabel, "%s %s %s", label[n].idlabel, label[n].namalabel, label[n].namapemilik);
		}
		
		fclose(flabel);
		
		n=0;
		flabel = fopen("tband.dat", "r");//ini baca yang band dan masukin ke bungkusan gabung
		fscanf(flabel, "%s %s %s", gabungan[n].idband, gabungan[n].namaband, gabungan[n].idlabelband);
	
		while(strcmp(gabungan[n].idband, "####") !=0){
			++n;
			fscanf(flabel, "%s %s %s", gabungan[n].idband, gabungan[n].namaband, gabungan[n].idlabelband);
		}
		fclose(flabel);
		
	}
	tandaindeks=n;
	//kenapa saya tidak langsung gabung saja di prosedur ini ?
	//saya juga baru kepikiran sekarang, saya lupa
	//mohon maaf
}

int cekiddelete(){//buat cek id kalo diminta delete
	int i;
	int n=0;
	bacabaca();//baca filenya
	int benar=0;
	
	startKata();
	incKata();
	incKata();
	strcpy(temp[0], kata);
	
	if(tabel==1){//cek tabel
		while(strcmp(label[n].idlabel, "####") !=0){
			if(strcmp(label[n].idlabel, temp[0])==0){//kalo ternyata yang di temp0 yang mana isinya adlah isi sama dengan di file, maka benarnya true
				benar=1;
				tandasama=n;//masukin tanda dimana yang sama
			}
			++n;
		}
	}else if(tabel==2){//sama persis kaya di tabel 1, cuma beda kalo ini di band
		while(strcmp(label[n].idband, "####") !=0){
			if(strcmp(label[n].idband, temp[0])==0){
				benar=1;
				tandasama=n;
			}
			++n;
		}
	}
	
	
	if(benar==1){//kalo bener maka kirim true yang menandakan kalau bener karena bener itu true
		return 1;
	}else{
		return 0;	
	}
}

int cekbenardelete(){//buat cek query kalo diminta delete
	int i=0;
	int benar=0;
	
	incKata();//cek berapa katanya
	while(eopKata()==0){
		i++;
		incKata();
	}
	i++;
		
	if(i==1){//kalau ternyata katanya itu satu, maka bener, misal delete tlabel A999, itu yang dicek setelah tlabelnya ada berapa kata
		benar=1;
	}
	
	return benar;
}

int cekid(){//buat cek id
	int i;
	int n=0;
	bacabaca();//baca file
	int benar=0;
	
	if(prosedur==1){//cek prosedur
		startKata();//balik ke awal
		incKata();
		incKata();
		incKata();//balik ke nama tabel
		for(i=0;i<3;i++){
			strcpy(temp[i], kata);
			incKata();
			
		}
	}else{
		startKata();//balik ke awal
		incKata();
		incKata();//balik ke nama tabel
		for(i=0;i<3;i++){
			strcpy(temp[i], kata);
			incKata();
			
		}
	}
	
	if(tabel==1){//cek tabel
		while(strcmp(label[n].idlabel, "####") !=0){
			if(strcmp(label[n].idlabel, temp[0])==0){//kalau ada yang sama benarnya jadi true
				benar=1;
				tandasama=n;
			}
			++n;
		}
	}else if(tabel==2){
		while(strcmp(label[n].idband, "####") !=0){
			if(strcmp(label[n].idband, temp[0])==0){
				benar=1;
				tandasama=n;
			}
			++n;
		}
	}
	
	if(benar==1){//balikin nilai benar
		return 1;
	}else{
		return 0;	
	}
	
	
}

void bacabaca(){//buat baca file
	int i;
	int n=0;
	
	FILE *flabel;
	if(tabel==1){//baca file label
		flabel = fopen("tlabel.dat", "r");
		fscanf(flabel, "%s %s %s", label[n].idlabel, label[n].namalabel, label[n].namapemilik);
	
		while(strcmp(label[n].idlabel, "####") !=0){
			++n;
			fscanf(flabel, "%s %s %s", label[n].idlabel, label[n].namalabel, label[n].namapemilik);
		}
		
		fclose(flabel);
	}else if(tabel==2){//baca file band
		flabel = fopen("tband.dat", "r");
		fscanf(flabel, "%s %s %s", label[n].idband, label[n].namaband, label[n].idlabelband);
	
		while(strcmp(label[n].idband, "####") !=0){
			++n;
			fscanf(flabel, "%s %s %s", label[n].idband, label[n].namaband, label[n].idlabelband);
		}
		fclose(flabel);
	}
	tandaindeks=n;
	
}

int cekbenar(){//buat cek querynya bener atau nggak di bagian insert
	int i=0;
	int benar=0;
	
	incKata();
	while(eopKata()==0){
		i++;
		incKata();
	}
	i++;
		
	if(i==3){//kalau ada 3 kata maka bener, karena kan attributnya cuma ada 3
		benar=1;
	}
	
	return benar;
}


void tessaja(){//buat ngetes aja
	startKata();
	printf("%s\n", getKata());
	while(eopKata() == 0){
		
		incKata();
		printf("%s\n", getKata());
	}
	
}
/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/