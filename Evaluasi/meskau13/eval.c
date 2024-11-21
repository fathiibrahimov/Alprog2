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
	int i;//iterator
	int j=1;//iterator juga
	int batas;//buat tau batas loop
	int count=0;//buat ngitung jumlah a
	
	startKata(pita);//mulai mesin
	batas=getPanjang();//dapetin batas buat loop, yaitu panjang kata
	strcpy(tempk[0], kata);//copy kata awal
	
	for(i=0;i<batas;i++){//cek kata awal ada huruf a nya
		if((kata[i]=='a')||(kata[i]=='a')){
			count++;
		}
	}
	jumlaha[0]=count;//masukin jumlah a
	
	while(eopKata(pita) == 0){//sama kaya diatas, bedanya ini diloop biar keambil semua kata sampai ketemu eop
		incKata(pita);
		strcpy(tempk[j], kata);
		count=0;
		batas=getPanjang();
		for(i=0;i<batas;i++){
			if((kata[i]=='a')||(kata[i]=='a')){
				count++;
			}
		}
		jumlaha[j]=count;
		strcpy(tempk[j], kata);
		j++;
	}
	
	banyakkata=j;//masukin banyak kata ke variabel global biar gak ribet
	urut();//urutin
	
}


void urut(){//urut pake bubble sort
	int i, temp, pindah;//variabel yang akan digunakan dalam sorting
	char tempc[300];
	
	do{//perulangan untuk mengecek setiap anggota data
		pindah = 0;
		
		for(i=0;i<(banyakkata-1);i++){
			/*perulangan untuk mengecek data yang dipilih terhadap data yang
			*/
			if(jumlaha[i]<jumlaha[i+1]){//proses membandingkan data
				//proses pemindahan data
				temp = jumlaha[i];
				strcpy(tempc, tempk[i]);
				jumlaha[i]=jumlaha[i+1];
				strcpy(tempk[i], tempk[i+1]);
				jumlaha[i+1]=temp;
				strcpy(tempk[i+1], tempc);
				pindah =1;
			}
			
		}
	}while(pindah==1);
}


void cetak(){//cetak disini
	int i=0;
	int benar=0;//buat tau apa ada yang gak ada a nya
	int berhenti=0;//buat batas kalo misalnya ada yang gak ada a
	
	while((i<banyakkata)&&(benar==0)){//ngecek apa ada yang gak ada a nya
		if(jumlaha[i]==0){
			benar=1;
			berhenti=i;
		}
		i++;
	}	
	if(benar==0){//kalo gak ada yang gak ada a nya
		for(i=0;i<banyakkata;i++){
			if(i==banyakkata-1){
				printf("%s", tempk[i]);
			}else{
				printf("%s ", tempk[i]);
			}
		}
	}else{//kalo ada yang gak ada a nya, dia cuma print sampe batas ada a
		for(i=0;i<berhenti;i++){
			if(i==berhenti-1){
				printf("%s", tempk[i]);
			}else{
				printf("%s ", tempk[i]);
			}
		}
	}
	
	printf("\n");
	//sebenernya kodingan diatas gak efisien tapi saya pusing benerinnya karena sudah pusing ngerjain tmd
	//yang error terus padahal waktu saya coba di java gak error sama sekali, mantap djiwa
	
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Kompetisi Latihan Alpro 2 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/